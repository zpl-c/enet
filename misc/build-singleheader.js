const fs = require('fs')

function read_file(name) {
    return fs
        .readFileSync(name)
        .toString('utf-8')
        .trim()
}

function include_enet(src) {
    return src
        .split('\n')
        .map(line => {
            // include enet header files for header
            if (line.indexOf('#include "enet/') !== -1) {
                return read_file('include/' + line.slice(10, -1))
            }

            return line
        })
        .join('\n')
}

function filter_libs(src, unqiue_lib_list) {
    return src
        .split('\n')
        .map((line, i) => {
            // remove references to enet across all file
            if (line.indexOf('#include "enet/') !== -1) {
                return ''
            }

            // reduce amount of includes to get rid of dublications
            if (line.indexOf('#include <') !== -1) {
                if (!unqiue_lib_list[line.slice(10, -1)]) {
                    unqiue_lib_list[line.slice(10, -1)] = 1;
                    return line
                } else {
                    unqiue_lib_list[line.slice(10, -1)]++
                    return ''
                }
            }

            return line
                .replace(/\s*$/, '') /* remove trailing spaces */
                .replace(/^\s{3}(\w)/, '    $1') /* make sure all tabulated lines have minumun 4 spaces */
        })
        .join('\n')
}

function attach_src(src, unqiue_lib_list, sources_list, scr_template) {
    let files = sources_list
        .map(file => {
            return '\n// @from_file: ' + file + '\n' +
                filter_libs(read_file(file), unqiue_lib_list)
        })
        .join('\n')

    // add 4 spaces in front
    files = files
        .split('\n')
        .map(line => line !== '' ? "    " + line : line)
        .join('\n')

    src = src.replace('#endif /* __ENET_ENET_H__ */', '')
    src = src + scr_template[0] + files + scr_template[1]

    return src
}

let sources = [
    'src/callbacks.c',
    'src/compress.c',
    'src/host.c',
    'src/list.c',
    'src/packet.c',
    'src/peer.c',
    'src/protocol.c',
    'src/unix.c',
    'src/win32.c',
]

let scr_template = [
`
#if defined(ENET_IMPLEMENTATION) && !defined(ENET_IMPLEMENTATION_DONE)
#define ENET_IMPLEMENTATION_DONE

    #ifdef __cplusplus
    extern "C"
    {
    #endif
`,
    // code there
`
    #ifdef __cplusplus
    }
    #endif

#endif

#endif /* __ENET_ENET_H__ */
`];

let prefix =
`/**
 * include/enet.h - a Single-Header auto-generated variant of enet.h library.
 *
 * Usage:
 * #define ENET_IMPLEMENTATION exactly in ONE source file right BEFORE including the library, like:
 *
 * #define ENET_IMPLEMENTATION
 * #include <enet.h>
 *
 */

#ifdef ENET_IMPLEMENTATION
#define ENET_BUILDING_LIB 1
#endif

`;

(function main() {
    let list = {};
    let src  = read_file('include/enet/enet.h')

    src = include_enet(src)
    src = filter_libs(src, list)
    src = attach_src(src, list, sources, scr_template)

    console.log(list)
    // console.log('all included libs:\n', Object.keys(list).sort())

    fs.writeFileSync('include/enet.h', prefix + src)
})();
