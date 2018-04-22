/*

  ZPL - Global module

Usage:
  #define ZPL_IMPLEMENTATION exactly in ONE source file right BEFORE including the library, like:

  #define ZPL_IMPLEMENTATION
  #include "zpl.h"

  To make use of platform layer, define ZPL_PLATFORM, like:

  #define ZPL_IMPLEMENTATION
  #define ZPL_PLATFORM
  #include "zpl.h"

Credits:
  Read AUTHORS.md

GitHub:
  https://github.com/zpl-c/zpl

Version History:
  6.6.0 - Several significant changes made to the repository
  6.5.0 - Ported platform layer from https://github.com/gingerBill/gb/
  6.4.1 - Use zpl_strlen in zpl_strdup
  6.4.0 - Deprecated zpl_buffer_free and added zpl_array_end, zpl_buffer_end
  6.3.0 - Added zpl_strdup
  6.2.1 - Remove math redundancies
  6.2.0 - Integrated zpl_math.h into zpl.h
  6.1.1 - Added direct.h include for win c++ dir methods
  6.1.0 - Added zpl_path_mkdir, zpl_path_rmdir, and few new zplFileErrors
  6.0.4 - More MSVC(++) satisfaction by fixing warnings
  6.0.3 - Satisfy MSVC by fixing a warning
  6.0.2 - Fixed warnings for json5 i64 printfs
  6.0.1 - Fixed warnings for particual win compiler in dirlist method
  6.0.0 - New build, include/ was renamed to code/

  5.8.3 - Naming fixes
  5.8.2 - Job system now supports prioritized tasks
  5.8.1 - Renames zpl_pad to zpl_ring
  5.8.0 - Added instantiated scratch pad (circular buffer)
  5.7.2 - Added Windows support for zpl_path_dirlist
  5.7.1 - Fixed few things in job system + macOS support for zpl_path_dirlist
  5.7.0 - Added a job system (zpl_thread_pool)
  5.6.5 - Fixes extra error cases for zpl_opts when input is:
        - missing a value for an option,
        - having an extra value for a flag (e.g. --enable-log shouldn't get a value.)
  5.6.4 - Several tweaks to the zpl_opts API
  5.6.3 - Added support for flags without values
  5.6.2 - Improve error handling for zpl_opts
  5.6.1 - Added support for strings with spaces in zpl_opts
  5.6.0 - Added zpl_opts for CLI argument parsing
  5.5.1 - Fixed time method for win
  5.5.0 - Integrate JSON5 writer into the core
  5.4.0 - Improved storage support for numbers in JSON5 parser
  5.3.0 - Integrated zpl_json into ZPL
  5.2.0 - Added zpl_string_sprintf
  5.1.1 - Added zpl_system_command_nores for output-less execution
  5.1.0 - Added event handler
  5.0.4 - Fix alias for zpl_list
  5.0.3 - Finalizing syntax changes
  5.0.2 - Fix segfault when using zpl_stack_memory
  5.0.1 - Small code improvements
  5.0.0 - Project structure changes

  4.7.2 - Got rid of size arg for zpl_str_split_lines
  4.7.1 - Added an example
  4.7.0 - Added zpl_path_dirlist
  4.6.1 - zpl_memcopy x86 patch from upstream
  4.6.0 - Added few string-related functions
  4.5.9 - Error fixes
  4.5.8 - Warning fixes
  4.5.7 - Fixed timer loops. zpl_time* related functions work with seconds now
  4.5.6 - Fixed zpl_time_now() for Windows and Linux
  4.5.5 - Small cosmetic changes
  4.5.4 - Fixed issue when zpl_list_add would break the links
        - when adding a new item between nodes
  4.5.3 - Fixed malformed enum values
  4.5.1 - Fixed some warnings
  4.5.0 - Added zpl_array_append_at
  4.4.0 - Added zpl_array_back, zpl_array_front
  4.3.0 - Added zpl_list
  4.2.0 - Added zpl_system_command_str
  4.1.2 - GG, fixed small compilation error
  4.1.1 - Fixed possible security issue in zpl_system_command
  4.1.0 - Added zpl_string_make_reserve and small fixes
  4.0.2 - Warning fix for _LARGEFILE64_SOURCE
  4.0.1 - include stdlib.h for getenv (temp)
  4.0.0 - ARM support, coding style changes and various improvements

  3.4.1 - zpl_memcopy now uses memcpy for ARM arch-family
  3.4.0 - Removed obsolete code
  3.3.4 - Added Travis CI config
  3.3.3 - Small macro formatting changes + ZPL_SYSTEM_IOS
  3.3.2 - Fixes for android arm
  3.3.1 - Fixed some type cast warnings
  3.3.0 - Added Android support
  3.1.5 - Renamed userptr to user_data in timer
  3.1.4 - Fix for zpl_buffer not allocating correctly
  3.1.2 - Small fix in zpl_memcompare
  3.1.1 - Added char* conversion for data field in zpl_array_header
  3.1.0 - Added data field to zpl_array_header
  3.0.7 - Added timer userptr as argument to callback
  3.0.6 - Small changes
  3.0.5 - Fixed compilation for emscripten
  3.0.4 - Small fixes for tiny cpp warnings
  3.0.3 - Small fixes for various cpp warnings and errors
  3.0.2 - Fixed linux part, and removed trailing spaces
  3.0.1 - Small bugfix in zpl_file_open
  3.0.0 - Added several fixes and features

  2.4.0 - Added remove to hash table
  2.3.3 - Removed redundant code
  2.3.2 - Eliminated extra warnings
  2.3.1 - Warning hunt
  2.3.0 - Added the ability to copy array/buffer and fixed bug in hash table.
  2.2.1 - Used tmpfile() for Windows
  2.2.0 - Added zpl_file_temp
  2.1.1 - Very small fix (forgive me)
  2.1.0 - Added the ability to resize bitstream
  2.0.8 - Small adjustments
  2.0.7 - MinGW related fixes
  2.0.0 - New NPM based version

  1.2.2 - Small fix
  1.2.1 - Macro fixes
  1.2.0 - Added zpl_async macro
  1.1.0 - Added timer feature
  1.0.0 - Initial version

  Copyright 2017-2018 Dominik Madarász <zaklaus@outlook.com>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

//
// TOP
//

#ifndef ZPL_INCLUDE_ZPL_H
#define ZPL_INCLUDE_ZPL_H

#if defined(__cplusplus)
  extern "C" {
#endif

#if defined(__cplusplus)
  #define ZPL_EXTERN extern "C"
#else
  #define ZPL_EXTERN extern
#endif

#if defined(_WIN32)
  #define ZPL_DLL_EXPORT ZPL_EXTERN __declspec(dllexport)
  #define ZPL_DLL_IMPORT ZPL_EXTERN __declspec(dllimport)
#else
  #define ZPL_DLL_EXPORT ZPL_EXTERN __attribute__((visibility("default")))
  #define ZPL_DLL_IMPORT ZPL_EXTERN
#endif

#ifndef ZPL_DEF
  #ifdef ZPL_STATIC
    #define ZPL_DEF static
  #else
    #define ZPL_DEF extern
  #endif
#endif

#if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64) || defined(__64BIT__) || defined(__powerpc64__) || defined(__ppc64__) || defined(__aarch64__)
  #ifndef ZPL_ARCH_64_BIT
  #define ZPL_ARCH_64_BIT 1
  #endif
#else
  #ifndef ZPL_ARCH_32_BIT
  #define ZPL_ARCH_32_BIT 1
  #endif
#endif


#ifndef ZPL_ENDIAN_ORDER
#define ZPL_ENDIAN_ORDER
#define ZPL_IS_BIG_ENDIAN    (!*(u8*)&(u16){1})
#define ZPL_IS_LITTLE_ENDIAN (!ZPL_IS_BIG_ENDIAN)
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifndef ZPL_SYSTEM_WINDOWS
  #define ZPL_SYSTEM_WINDOWS 1
  #endif
#elif defined(__APPLE__) && defined(__MACH__)
  #ifndef ZPL_SYSTEM_OSX
  #define ZPL_SYSTEM_OSX 1
  #endif
  #ifndef ZPL_SYSTEM_MACOS
  #define ZPL_SYSTEM_MACOS 1
  #endif
  #include <TargetConditionals.h>
  #if TARGET_IPHONE_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
    #ifndef ZPL_SYSTEM_IOS
    #define ZPL_SYSTEM_IOS 1
    #endif
  #endif
#elif defined(__unix__)
  #ifndef ZPL_SYSTEM_UNIX
  #define ZPL_SYSTEM_UNIX 1
  #endif

  #if defined(ANDROID) || defined(__ANDROID__)
    #ifndef ZPL_SYSTEM_ANDROID
    #define ZPL_SYSTEM_ANDROID 1
    #endif
    #ifndef ZPL_SYSTEM_LINUX
    #define ZPL_SYSTEM_LINUX 1
    #endif
  #elif defined(__linux__)
    #ifndef ZPL_SYSTEM_LINUX
    #define ZPL_SYSTEM_LINUX 1
    #endif
  #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    #ifndef ZPL_SYSTEM_FREEBSD
    #define ZPL_SYSTEM_FREEBSD 1
    #endif
  #elif defined(__EMSCRIPTEN__)
    #ifndef ZPL_SYSTEM_EMSCRIPTEN
    #define ZPL_SYSTEM_EMSCRIPTEN 1
    #endif
  #else
    #error This UNIX operating system is not supported
  #endif
#else
  #error This operating system is not supported
#endif

#if defined(_MSC_VER)
  #define ZPL_COMPILER_MSVC 1
#elif defined(__GNUC__)
  #define ZPL_COMPILER_GCC 1
#elif defined(__clang__)
  #define ZPL_COMPILER_CLANG 1
#else
  #error Unknown compiler
#endif

#if defined(__arm__) || defined(__aarch64__)
  #ifndef ZPL_CPU_ARM
  #define ZPL_CPU_ARM 1
  #endif
  #ifndef ZPL_CACHE_LINE_SIZE
  #define ZPL_CACHE_LINE_SIZE 64
  #endif
#elif defined(_M_IX86) || defined(_M_X64) || defined(__i386__) || defined(__x86_64__) || defined(ZPL_SYSTEM_EMSCRIPTEN)
  #ifndef ZPL_CPU_X86
  #define ZPL_CPU_X86 1
  #endif
  #ifndef ZPL_CACHE_LINE_SIZE
  #define ZPL_CACHE_LINE_SIZE 64
  #endif
#elif defined(_M_PPC) || defined(__powerpc__) || defined(__powerpc64__)
  #ifndef ZPL_CPU_PPC
  #define ZPL_CPU_PPC 1
  #endif
  #ifndef ZPL_CACHE_LINE_SIZE
  #define ZPL_CACHE_LINE_SIZE 128
  #endif
#elif defined(__MIPSEL__) || defined(__mips_isa_rev)
  #ifndef ZPL_CPU_MIPS
  #define ZPL_CPU_MIPS 1
  #endif
  #ifndef ZPL_CACHE_LINE_SIZE
  #define ZPL_CACHE_LINE_SIZE 64
  #endif
#else
  #error Unknown CPU Type
#endif

#if !defined(ZPL_SYSTEM_EMSCRIPTEN) && !defined(ZPL_CPU_ARM) // disabled for __EMSCRIPTEN__
  #ifndef ZPL_THREADING
  #define ZPL_THREADING 1
  #endif
#endif

#ifndef ZPL_STATIC_ASSERT
  #define ZPL_STATIC_ASSERT3(cond, msg) typedef char static_assertion_##msg[(!!(cond))*2-1]
  #define ZPL_STATIC_ASSERT2(cond, line) ZPL_STATIC_ASSERT3(cond, static_assertion_at_line_##line)
  #define ZPL_STATIC_ASSERT1(cond, line) ZPL_STATIC_ASSERT2(cond, line)
  #define ZPL_STATIC_ASSERT(cond)        ZPL_STATIC_ASSERT1(cond, __LINE__)
#endif


    ////////////////////////////////////////////////////////////////
    //
    // Headers
    //
    //

#if defined(_WIN32) && !defined(__MINGW32__)
  #ifndef _CRT_SECURE_NO_WARNINGS
  #define _CRT_SECURE_NO_WARNINGS
  #endif
#endif

#if defined(ZPL_SYSTEM_UNIX)
  #ifndef _GNU_SOURCE
  #define _GNU_SOURCE
  #endif
  #ifndef _LARGEFILE64_SOURCE
  #define _LARGEFILE64_SOURCE
  #endif
#endif

#include <math.h>

#if defined(ZPL_SYSTEM_WINDOWS)
  #include <io.h>
  #include <stdio.h>
  #include <direct.h> // TODO: remove and use native winapi methods

  #if !defined(ZPL_NO_WINDOWS_H)
    #define NOMINMAX            1
    #define WIN32_LEAN_AND_MEAN 1
    #define WIN32_MEAN_AND_LEAN 1
    #define VC_EXTRALEAN        1
    #include <windows.h>
    #undef NOMINMAX
    #undef WIN32_LEAN_AND_MEAN
    #undef WIN32_MEAN_AND_LEAN
    #undef VC_EXTRALEAN
  #endif

  #include <malloc.h> // NOTE: _aligned_*()
  #include <intrin.h>

    // TODO(ZaKlaus): Find a better way to get this flag in MinGW.
  #if defined(ZPL_COMPILER_GCC) && !defined(WC_ERR_INVALID_CHARS)
    #define WC_ERR_INVALID_CHARS 0x0080
  #endif

#else

  #if !defined(ZPL_SYSTEM_EMSCRIPTEN)
    #include <pthread.h>
  #endif

  #include <dlfcn.h>
  #include <errno.h>
  #include <fcntl.h>
  #ifndef _IOSC11_SOURCE
  #define _IOSC11_SOURCE
  #endif
  #include <stdlib.h> // NOTE: malloc on linux
  #include <sys/mman.h>

  #if !defined(ZPL_SYSTEM_OSX)
    #include <sys/sendfile.h>
  #endif

  #include <sys/stat.h>
  #include <sys/time.h>
  #include <sys/types.h>
  #include <time.h>
  #include <unistd.h>
  #include <dirent.h>

  #if !defined(ZPL_SYSTEM_ANDROID)
    #include <spawn.h>
  #endif

  #if !defined(ZPL_SYSTEM_ANDROID) && !defined(ZPL_SYSTEM_IOS)
    #if !defined(ZPL_SYSTEM_EMSCRIPTEN)
      #include <emmintrin.h>
    #elif defined(ZPL_CPU_X86) && !defined(ZPL_SYSTEM_EMSCRIPTEN)
      #include <xmmintrin.h>
    #else
      #include <sched.h>
    #endif
  #endif

#endif

#if defined(ZPL_SYSTEM_OSX)
  #include <stdio.h>
  #include <mach/mach.h>
  #include <mach/mach_init.h>
  #include <mach/mach_time.h>
  #include <mach/thread_act.h>
  #include <mach/thread_policy.h>
  #include <sys/sysctl.h>
  #include <copyfile.h>
  #include <mach/clock.h>
#endif

#if defined(ZPL_SYSTEM_UNIX)
  #include <semaphore.h>
#endif

#if !defined(ZPL_SYSTEM_WINDOWS)
  #include <stdarg.h>
  #include <stddef.h>
#endif

    ////////////////////////////////////////////////////////////////
    //
    // Base Types
    //
    //

#if defined(ZPL_COMPILER_MSVC)
#if _MSC_VER < 1300
    typedef unsigned char     u8;
    typedef   signed char     i8;
    typedef unsigned short   u16;
    typedef   signed short   i16;
    typedef unsigned int     u32;
    typedef   signed int     i32;
#else
    typedef unsigned __int8   u8;
    typedef   signed __int8   i8;
    typedef unsigned __int16 u16;
    typedef   signed __int16 i16;
    typedef unsigned __int32 u32;
    typedef   signed __int32 i32;
#endif
    typedef unsigned __int64 u64;
    typedef   signed __int64 i64;
#else
#include <stdint.h>
    typedef uint8_t   u8;
    typedef  int8_t   i8;
    typedef uint16_t u16;
    typedef  int16_t i16;
    typedef uint32_t u32;
    typedef  int32_t i32;
    typedef uint64_t u64;
    typedef  int64_t i64;
#endif

    ZPL_STATIC_ASSERT(sizeof(u8)  == sizeof(i8));
    ZPL_STATIC_ASSERT(sizeof(u16) == sizeof(i16));
    ZPL_STATIC_ASSERT(sizeof(u32) == sizeof(i32));
    ZPL_STATIC_ASSERT(sizeof(u64) == sizeof(i64));

    ZPL_STATIC_ASSERT(sizeof(u8)  == 1);
    ZPL_STATIC_ASSERT(sizeof(u16) == 2);
    ZPL_STATIC_ASSERT(sizeof(u32) == 4);
    ZPL_STATIC_ASSERT(sizeof(u64) == 8);

    typedef size_t    usize;
    typedef ptrdiff_t isize;

    ZPL_STATIC_ASSERT(sizeof(usize) == sizeof(isize));

    // NOTE: (u)intptr is only here for semantic reasons really as this library will only support 32/64 bit OSes.
#if defined(_WIN64)
    typedef signed   __int64  intptr;
    typedef unsigned __int64 uintptr;
#elif defined(_WIN32)
    // NOTE; To mark types changing their size, e.g. intptr
#ifndef _W64
  #if !defined(__midl) && (defined(_X86_) || defined(_M_IX86)) && _MSC_VER >= 1300
    #define _W64 __w64
  #else
    #define _W64
  #endif
#endif

    typedef _W64   signed int  intptr;
    typedef _W64 unsigned int uintptr;
#else
    typedef uintptr_t uintptr;
    typedef  intptr_t  intptr;
#endif

    ZPL_STATIC_ASSERT(sizeof(uintptr) == sizeof(intptr));

    typedef float  f32;
    typedef double f64;

    ZPL_STATIC_ASSERT(sizeof(f32) == 4);
    ZPL_STATIC_ASSERT(sizeof(f64) == 8);

    typedef i32 Rune; // NOTE: Unicode codepoint
    typedef i32 char32;
#define ZPL_RUNE_INVALID cast(Rune)(0xfffd)
#define ZPL_RUNE_MAX     cast(Rune)(0x0010ffff)
#define ZPL_RUNE_BOM     cast(Rune)(0xfeff)
#define ZPL_RUNE_EOF     cast(Rune)(-1)


    typedef i8  b8;
    typedef i16 b16;
    typedef i32 b32;

#if !defined(__cplusplus)
  #if (defined(_MSC_VER) && _MSC_VER < 1800) || (!defined(_MSC_VER) && !defined(__STDC_VERSION__))
    #ifndef true
    #define true  (0 == 0)
    #endif
    #ifndef false
    #define false (0 != 0)
    #endif
      typedef b8 bool;
  #else
    #include <stdbool.h>
  #endif
#endif

#ifndef U8_MIN
  #define U8_MIN 0u
  #define U8_MAX 0xffu
  #define I8_MIN (-0x7f - 1)
  #define I8_MAX 0x7f

  #define U16_MIN 0u
  #define U16_MAX 0xffffu
  #define I16_MIN (-0x7fff - 1)
  #define I16_MAX 0x7fff

  #define U32_MIN 0u
  #define U32_MAX 0xffffffffu
  #define I32_MIN (-0x7fffffff - 1)
  #define I32_MAX 0x7fffffff

  #define U64_MIN 0ull
  #define U64_MAX 0xffffffffffffffffull
  #define I64_MIN (-0x7fffffffffffffffll - 1)
  #define I64_MAX 0x7fffffffffffffffll

  #if defined(ZPL_ARCH_32_BIT)
  #define USIZE_MIX U32_MIN
  #define USIZE_MAX U32_MAX

  #define ISIZE_MIX S32_MIN
  #define ISIZE_MAX S32_MAX
  #elif defined(ZPL_ARCH_64_BIT)
  #define USIZE_MIX U64_MIN
  #define USIZE_MAX U64_MAX

  #define ISIZE_MIX I64_MIN
  #define ISIZE_MAX I64_MAX
#else
  #error Unknown architecture size. This library only supports 32 bit and 64 bit architectures.
#endif

#define F32_MIN 1.17549435e-38f
#define F32_MAX 3.40282347e+38f

#define F64_MIN 2.2250738585072014e-308
#define F64_MAX 1.7976931348623157e+308

#endif

#ifndef NULL
#if defined(__cplusplus)
#if __cplusplus >= 201103L
#define NULL nullptr
#else
#define NULL 0
#endif
#else
#define NULL ((void *)0)
#endif
#endif

#if !defined(__cplusplus)
#if defined(_MSC_VER) && _MSC_VER <= 1800
#define inline __inline
#elif !defined(__STDC_VERSION__)
#define inline __inline__
#else
#define inline
#endif
#endif

#if !defined(zpl_restrict)
#if defined(_MSC_VER)
#define zpl_restrict __restrict
#elif defined(__STDC_VERSION__)
#define zpl_restrict restrict
#else
#define zpl_restrict
#endif
#endif

#if !defined(zpl_inline)
#if defined(_MSC_VER)
#if _MSC_VER < 1300
#define zpl_inline
#else
#define zpl_inline __forceinline
#endif
#else
#define zpl_inline inline //__attribute__ ((__always_inline__)) inline
#endif
#endif

#if !defined(zpl_no_inline)
#if defined(_MSC_VER)
#define zpl_no_inline __declspec(noinline)
#else
#define zpl_no_inline __attribute__ ((noinline))
#endif
#endif


#if !defined(zpl_thread_local)
#if defined(_MSC_VER) && _MSC_VER >= 1300
#define zpl_thread_local __declspec(thread)
#elif defined(__GNUC__)
#define zpl_thread_local __thread
#else
#define zpl_thread_local thread_local
#endif
#endif

#ifndef cast
#define cast(Type) (Type)
#endif

#ifndef zpl_size_of
#define zpl_size_of(x) (isize)(sizeof(x))
#endif

#ifndef zpl_count_of
#define zpl_count_of(x) ((zpl_size_of(x)/zpl_size_of(0[x])) / ((isize)(!(zpl_size_of(x) % zpl_size_of(0[x])))))
#endif

#ifndef zpl_offset_of
#define zpl_offset_of(Type, element) ((isize)&(((Type *)0)->element))
#endif

#if defined(__cplusplus)
#ifndef zpl_align_of
#if __cplusplus >= 201103L
#define zpl_align_of(Type) (isize)alignof(Type)
#else
    extern "C++" {
        template <typename T> struct zpl_alignment_trick { char c; T member; };
#define zpl_align_of(Type) zpl_offset_of(zpl_alignment_trick<Type>, member)
    }
#endif
#endif
#else
#ifndef zpl_align_of
#define zpl_align_of(Type) zpl_offset_of(struct { char c; Type member; }, member)
#endif
#endif

#ifndef zpl_swap
#define zpl_swap(Type, a, b) do { Type tmp = (a); (a) = (b); (b) = tmp; } while (0)
#endif

#ifndef zpl_global
#define zpl_global        static // Global variables
#define zpl_internal      static // Internal linkage
#define zpl_local_persist static // Local Persisting variables
#endif


#ifndef zpl_unused
#if defined(_MSC_VER)
#define zpl_unused(x) (__pragma(warning(suppress:4100))(x))
#elif defined (__GCC__)
#define zpl_unused(x) __attribute__((__unused__))(x)
#else
#define zpl_unused(x) ((void)(zpl_size_of(x)))
#endif
#endif

    ////////////////////////////////////////////////////////////////
    //
    // Macro Fun!
    //
    //

#ifndef ZPL_JOIN_MACROS
#define ZPL_JOIN_MACROS
#define ZPL_JOIN2_IND(a, b) a##b

#define ZPL_JOIN2(a, b)       ZPL_JOIN2_IND(a, b)
#define ZPL_JOIN3(a, b, c)    ZPL_JOIN2(ZPL_JOIN2(a, b), c)
#define ZPL_JOIN4(a, b, c, d) ZPL_JOIN2(ZPL_JOIN2(ZPL_JOIN2(a, b), c), d)
#endif


#ifndef ZPL_BIT
#define ZPL_BIT(x) (1<<(x))
#endif

#ifndef zpl_min
#define zpl_min(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef zpl_max
#define zpl_max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef zpl_min3
#define zpl_min3(a, b, c) zpl_min(zpl_min(a, b), c)
#endif

#ifndef zpl_max3
#define zpl_max3(a, b, c) zpl_max(zpl_max(a, b), c)
#endif

#ifndef zpl_clamp
#define zpl_clamp(x, lower, upper) zpl_min(zpl_max((x), (lower)), (upper))
#endif

#ifndef zpl_clamp01
#define zpl_clamp01(x) zpl_clamp((x), 0, 1)
#endif

#ifndef zpl_is_between
#define zpl_is_between(x, lower, upper) (((lower) <= (x)) && ((x) <= (upper)))
#endif

#ifndef zpl_abs
#define zpl_abs(x) ((x) < 0 ? -(x) : (x))
#endif

#ifndef hard_cast
#define hard_cast(type) *cast(type)&
#endif

    // WARN(ZaKlaus): Supported only on GCC via GNU extensions!!!
#ifndef zpl_lambda
#define zpl_lambda(b_) ({b_ _;})
#endif

#ifndef zpl_when
#define zpl_when(init, type, name) type name = init; if (name)
#endif

    /* NOTE: Very useful bit setting */
#ifndef ZPL_MASK_SET
#define ZPL_MASK_SET(var, set, mask) do {       \
        if (set) (var) |=  (mask);              \
        else     (var) &= ~(mask);              \
    } while (0)
#endif


    // NOTE: Some compilers support applying printf-style warnings to user functions.
#if defined(__clang__) || defined(__GNUC__)
#define ZPL_PRINTF_ARGS(FMT) __attribute__((format(printf, FMT, (FMT+1))))
#else
#define ZPL_PRINTF_ARGS(FMT)
#endif

    ////////////////////////////////////////////////////////////////
    //
    // Debug
    //
    //


#ifndef ZPL_DEBUG_TRAP
#if defined(_MSC_VER)
#if _MSC_VER < 1300
#define ZPL_DEBUG_TRAP() __asm int 3 /* Trap to debugger! */
#else
#define ZPL_DEBUG_TRAP() __debugbreak()
#endif
#else
#define ZPL_DEBUG_TRAP() __builtin_trap()
#endif
#endif

#ifndef ZPL_ASSERT_MSG
#define ZPL_ASSERT_MSG(cond, msg, ...) do {                             \
        if (!(cond)) {                                                  \
            zpl_assert_handler(#cond, __FILE__, cast(i64)__LINE__, msg, ##__VA_ARGS__); \
            ZPL_DEBUG_TRAP();                                           \
        }                                                               \
    } while (0)
#endif

#ifndef ZPL_ASSERT
#define ZPL_ASSERT(cond) ZPL_ASSERT_MSG(cond, NULL)
#endif

#ifndef ZPL_ASSERT_NOT_NULL
#define ZPL_ASSERT_NOT_NULL(ptr) ZPL_ASSERT_MSG((ptr) != NULL, #ptr " must not be NULL")
#endif

    // NOTE: Things that shouldn't happen with a message!
#ifndef ZPL_PANIC
#define ZPL_PANIC(msg, ...) ZPL_ASSERT_MSG(0, msg, ##__VA_ARGS__)
#endif

ZPL_DEF void zpl_assert_handler(char const *condition, char const *file, i32 line, char const *msg, ...);
ZPL_DEF i32  zpl_assert_crash(char const *condition);


////////////////////////////////////////////////////////////////
//
// Memory
//
//


ZPL_DEF b32 zpl_is_power_of_two(isize x);

ZPL_DEF void *      zpl_align_forward(void *ptr, isize alignment);

ZPL_DEF void *      zpl_pointer_add      (void *ptr, isize bytes);
ZPL_DEF void *      zpl_pointer_sub      (void *ptr, isize bytes);
ZPL_DEF void const *zpl_pointer_add_const(void const *ptr, isize bytes);
ZPL_DEF void const *zpl_pointer_sub_const(void const *ptr, isize bytes);
ZPL_DEF isize       zpl_pointer_diff     (void const *begin, void const *end);

#define zpl_ptr_add       zpl_pointer_add
#define zpl_ptr_sub       zpl_pointer_sub
#define zpl_ptr_add_const zpl_pointer_add_const
#define zpl_ptr_sub_const zpl_pointer_sub_const
#define zpl_ptr_diff      zpl_pointer_diff


ZPL_DEF void zpl_zero_size(void *ptr, isize size);
#ifndef     zpl_zero_item
#define     zpl_zero_item(t)         zpl_zero_size((t), zpl_size_of(*(t))) // NOTE: Pass pointer of struct
#define     zpl_zero_array(a, count) zpl_zero_size((a), zpl_size_of(*(a))*count)
#endif

ZPL_DEF void *      zpl_memcopy   (void *dest, void const *source, isize size);
ZPL_DEF void *      zpl_memmove   (void *dest, void const *source, isize size);
ZPL_DEF void *      zpl_memset    (void *data, u8 byte_value, isize size);
ZPL_DEF i32         zpl_memcompare(void const *s1, void const *s2, isize size);
ZPL_DEF void        zpl_memswap   (void *i, void *j, isize size);
ZPL_DEF void const *zpl_memchr    (void const *data, u8 byte_value, isize size);
ZPL_DEF void const *zpl_memrchr   (void const *data, u8 byte_value, isize size);

#ifndef zpl_memcopy_array
#define zpl_memcopy_array(dst, src, count) zpl_memcopy((dst), (src), zpl_size_of(*(dst))*(count))
#endif

#ifndef zpl_memmove_array
#define zpl_memmove_array(dst, src, count) zpl_memmove((dst), (src), zpl_size_of(*(dst))*(count))
#endif

#ifndef ZPL_BIT_CAST
#define ZPL_BIT_CAST(dest, source) do {                                 \
    ZPL_STATIC_ASSERT(zpl_size_of(*(dest)) <= zpl_size_of(source)); \
    zpl_memcopy((dest), &(source), zpl_size_of(*dest));             \
} while (0)
#endif




#ifndef zpl_kilobytes
#define zpl_kilobytes(x) (             (x) * (i64)(1024))
#define zpl_megabytes(x) (zpl_kilobytes(x) * (i64)(1024))
#define zpl_gigabytes(x) (zpl_megabytes(x) * (i64)(1024))
#define zpl_terabytes(x) (zpl_gigabytes(x) * (i64)(1024))
#endif


#ifdef ZPL_THREADING

// Atomics

// TODO: Be specific with memory order?
// e.g. relaxed, acquire, release, acquire_release

#if defined(ZPL_COMPILER_MSVC)
#define zpl_atomic32_t zpl_atomic32
typedef struct zpl_atomic32  { i32   volatile value; } zpl_atomic32;
#define zpl_atomic64_t zpl_atomic64
typedef struct zpl_atomic64  { i64   volatile value; } zpl_atomic64;
#define zpl_atomic_ptr_t zpl_atomic_ptr
typedef struct zpl_atomic_ptr { void *volatile value; } zpl_atomic_ptr;
#else
#if defined(ZPL_ARCH_32_BIT)
#define ZPL_ATOMIC_PTR_ALIGNMENT 4
#elif defined(ZPL_ARCH_64_BIT)
#define ZPL_ATOMIC_PTR_ALIGNMENT 8
#else
#error Unknown architecture
#endif

#define zpl_atomic32_t zpl_atomic32
typedef struct zpl_atomic32  { i32   volatile value; } __attribute__ ((aligned(4))) zpl_atomic32;
#define zpl_atomic64_t zpl_atomic64
typedef struct zpl_atomic64  { i64   volatile value; } __attribute__ ((aligned(8))) zpl_atomic64;
#define zpl_atomic_ptr_t zpl_atomic_ptr
typedef struct zpl_atomic_ptr { void *volatile value; } __attribute__ ((aligned(ZPL_ATOMIC_PTR_ALIGNMENT))) zpl_atomic_ptr;
#endif

ZPL_DEF i32  zpl_atomic32_load            (zpl_atomic32 const volatile *a);
ZPL_DEF void zpl_atomic32_store           (zpl_atomic32 volatile *a, i32 value);
ZPL_DEF i32  zpl_atomic32_compare_exchange(zpl_atomic32 volatile *a, i32 expected, i32 desired);
ZPL_DEF i32  zpl_atomic32_exchange       (zpl_atomic32 volatile *a, i32 desired);
ZPL_DEF i32  zpl_atomic32_fetch_add       (zpl_atomic32 volatile *a, i32 operand);
ZPL_DEF i32  zpl_atomic32_fetch_and       (zpl_atomic32 volatile *a, i32 operand);
ZPL_DEF i32  zpl_atomic32_fetch_or        (zpl_atomic32 volatile *a, i32 operand);
ZPL_DEF b32  zpl_atomic32_spin_lock       (zpl_atomic32 volatile *a, isize time_out); // NOTE: time_out = -1 as default
ZPL_DEF void zpl_atomic32_spin_unlock     (zpl_atomic32 volatile *a);
ZPL_DEF b32  zpl_atomic32_try_acquire_lock(zpl_atomic32 volatile *a);


ZPL_DEF i64  zpl_atomic64_load            (zpl_atomic64 const volatile *a);
ZPL_DEF void zpl_atomic64_store           (zpl_atomic64 volatile *a, i64 value);
ZPL_DEF i64  zpl_atomic64_compare_exchange(zpl_atomic64 volatile *a, i64 expected, i64 desired);
ZPL_DEF i64  zpl_atomic64_exchange       (zpl_atomic64 volatile *a, i64 desired);
ZPL_DEF i64  zpl_atomic64_fetch_add       (zpl_atomic64 volatile *a, i64 operand);
ZPL_DEF i64  zpl_atomic64_fetch_and       (zpl_atomic64 volatile *a, i64 operand);
ZPL_DEF i64  zpl_atomic64_fetch_or        (zpl_atomic64 volatile *a, i64 operand);
ZPL_DEF b32  zpl_atomic64_spin_lock       (zpl_atomic64 volatile *a, isize time_out); // NOTE: time_out = -1 as default
ZPL_DEF void zpl_atomic64_spin_unlock     (zpl_atomic64 volatile *a);
ZPL_DEF b32  zpl_atomic64_try_acquire_lock(zpl_atomic64 volatile *a);


ZPL_DEF void *zpl_atomic_ptr_load            (zpl_atomic_ptr const volatile *a);
ZPL_DEF void  zpl_atomic_ptr_store           (zpl_atomic_ptr volatile *a, void *value);
ZPL_DEF void *zpl_atomic_ptr_compare_exchange(zpl_atomic_ptr volatile *a, void *expected, void *desired);
ZPL_DEF void *zpl_atomic_ptr_exchange       (zpl_atomic_ptr volatile *a, void *desired);
ZPL_DEF void *zpl_atomic_ptr_fetch_add       (zpl_atomic_ptr volatile *a, void *operand);
ZPL_DEF void *zpl_atomic_ptr_fetch_and       (zpl_atomic_ptr volatile *a, void *operand);
ZPL_DEF void *zpl_atomic_ptr_fetch_or        (zpl_atomic_ptr volatile *a, void *operand);
ZPL_DEF b32   zpl_atomic_ptr_spin_lock       (zpl_atomic_ptr volatile *a, isize time_out); // NOTE: time_out = -1 as default
ZPL_DEF void  zpl_atomic_ptr_spin_unlock     (zpl_atomic_ptr volatile *a);
ZPL_DEF b32   zpl_atomic_ptr_try_acquire_lock(zpl_atomic_ptr volatile *a);


// Fences
ZPL_DEF void zpl_yield_thread(void);
ZPL_DEF void zpl_mfence      (void);
ZPL_DEF void zpl_sfence      (void);
ZPL_DEF void zpl_lfence      (void);


#if defined(ZPL_SYSTEM_WINDOWS)
#define zpl_semaphore_t zpl_semaphore
typedef struct zpl_semaphore { void *win32_handle; }     zpl_semaphore;
#elif defined(ZPL_SYSTEM_OSX)
#define zpl_semaphore_t zpl_semaphore
typedef struct zpl_semaphore { semaphore_t osx_handle; } zpl_semaphore;
#elif defined(ZPL_SYSTEM_UNIX)
#define zpl_semaphore_t zpl_semaphore
typedef struct zpl_semaphore { sem_t unix_handle; }      zpl_semaphore;
#else
#error
#endif

ZPL_DEF void zpl_semaphore_init   (zpl_semaphore *s);
ZPL_DEF void zpl_semaphore_destroy(zpl_semaphore *s);
ZPL_DEF void zpl_semaphore_post   (zpl_semaphore *s, i32 count);
ZPL_DEF void zpl_semaphore_release(zpl_semaphore *s); // NOTE: zpl_semaphore_post(s, 1)
ZPL_DEF void zpl_semaphore_wait   (zpl_semaphore *s);


// Mutex
#define zpl_mutex_t zpl_mutex
typedef struct zpl_mutex {
#if defined(ZPL_SYSTEM_WINDOWS)
    CRITICAL_SECTION win32_critical_section;
#else
    pthread_mutex_t pthread_mutex;
#endif
} zpl_mutex;

ZPL_DEF void zpl_mutex_init    (zpl_mutex *m);
ZPL_DEF void zpl_mutex_destroy (zpl_mutex *m);
ZPL_DEF void zpl_mutex_lock    (zpl_mutex *m);
ZPL_DEF b32  zpl_mutex_try_lock(zpl_mutex *m);
ZPL_DEF void zpl_mutex_unlock  (zpl_mutex *m);

struct zpl_thread;

#define ZPL_THREAD_PROC(name) isize name(struct zpl_thread *thread)
typedef ZPL_THREAD_PROC(zpl_thread_proc);

ZPL_THREAD_PROC(zpl__async_handler);

// TODO(ZaKlaus): @fixme
#ifndef zpl_async
#define ZPL_ASYNC_CB(name) void name(void *data)
typedef ZPL_ASYNC_CB(zpl_async_cb);
typedef struct {
    void *data;
    zpl_async_cb *work;
    zpl_async_cb *cb;
} zpl_async_ctl;
#define zpl_async(data, work, cb) do {                            \
    zpl_thread td = {0};                                          \
    zpl_thread_init(&td);                                         \
    zpl_async_ctl  ctl_ = {data, work, cb};                       \
    zpl_async_ctl *ctl = zpl_malloc(zpl_size_of(zpl_async_ctl));  \
    *ctl = ctl_;                                                  \
    zpl_thread_start(&td, zpl__async_handler, ctl);} while (0)
#endif

#define zpl_thread_t zpl_thread
typedef struct zpl_thread {
#if defined(ZPL_SYSTEM_WINDOWS)
    void *        win32_handle;
#else
    pthread_t     posix_handle;
#endif

    zpl_thread_proc *proc;
    void *           user_data;
    isize            user_index;
    isize            return_value;

    zpl_semaphore    semaphore;
    isize            stack_size;
    b32              is_running;
} zpl_thread;

ZPL_DEF void zpl_thread_init            (zpl_thread *t);
ZPL_DEF void zpl_thread_destroy         (zpl_thread *t);
ZPL_DEF void zpl_thread_start           (zpl_thread *t, zpl_thread_proc *proc, void *data);
ZPL_DEF void zpl_thread_start_with_stack(zpl_thread *t, zpl_thread_proc *proc, void *data, isize stack_size);
ZPL_DEF void zpl_thread_join            (zpl_thread *t);
ZPL_DEF b32  zpl_thread_is_running      (zpl_thread const *t);
ZPL_DEF u32  zpl_thread_current_id      (void);
ZPL_DEF void zpl_thread_set_name        (zpl_thread *t, char const *name);


// NOTE: Thread Merge Operation
// Based on Sean Barrett's stb_sync
#define zpl_sync_t zpl_sync
typedef struct zpl_sync {
    i32 target;  // Target Number of threads
    i32 current; // Threads to hit
    i32 waiting; // Threads waiting

    zpl_mutex start;
    zpl_mutex mutex;
    zpl_semaphore release;
} zpl_sync;

ZPL_DEF void zpl_sync_init          (zpl_sync *s);
ZPL_DEF void zpl_sync_destroy       (zpl_sync *s);
ZPL_DEF void zpl_sync_set_target    (zpl_sync *s, i32 count);
ZPL_DEF void zpl_sync_release       (zpl_sync *s);
ZPL_DEF i32  zpl_sync_reach         (zpl_sync *s);
ZPL_DEF void zpl_sync_reach_and_wait(zpl_sync *s);



#if defined(ZPL_SYSTEM_WINDOWS)

#define zpl_affinity_t zpl_affinity
typedef struct zpl_affinity {
    b32   is_accurate;
    isize core_count;
    isize thread_count;
#define zpl_WIN32_MAXHREADS (8 * zpl_size_of(usize))
    usize core_masks[zpl_WIN32_MAXHREADS];

} zpl_affinity;

#elif defined(ZPL_SYSTEM_OSX)
#define zpl_affinity_t zpl_affinity
typedef struct zpl_affinity {
    b32   is_accurate;
    isize core_count;
    isize thread_count;
    isize threads_per_core;
} zpl_affinity;

#elif defined(ZPL_SYSTEM_LINUX) || defined(ZPL_SYSTEM_EMSCRIPTEN)
#define zpl_affinity_t zpl_affinity
typedef struct zpl_affinity {
    b32   is_accurate;
    isize core_count;
    isize thread_count;
    isize threads_per_core;
} zpl_affinity;
#else
#error TODO: Unknown system
#endif

ZPL_DEF void  zpl_affinity_init   (zpl_affinity *a);
ZPL_DEF void  zpl_affinity_destroy(zpl_affinity *a);
ZPL_DEF b32   zpl_affinity_set    (zpl_affinity *a, isize core, isize thread);
ZPL_DEF isize zpl_affinity_thread_count_for_core(zpl_affinity *a, isize core);

#endif


////////////////////////////////////////////////////////////////
//
// Virtual Memory
//
//

#define zpl_virtual_memory_t zpl_virtual_memory
typedef struct zpl_virtual_memory {
    void *data;
    isize size;
} zpl_virtual_memory;

ZPL_DEF zpl_virtual_memory zpl_vm         (void *data, isize size);
ZPL_DEF zpl_virtual_memory zpl_vm_alloc   (void *addr, isize size);
ZPL_DEF b32                  zpl_vm_free  (zpl_virtual_memory vm);
ZPL_DEF zpl_virtual_memory zpl_vm_trim      (zpl_virtual_memory vm, isize lead_size, isize size);
ZPL_DEF b32                  zpl_vm_purge (zpl_virtual_memory vm);
ZPL_DEF isize zpl_virtual_memory_page_size(isize *alignment_out);




////////////////////////////////////////////////////////////////
//
// Custom Allocation
//
//

typedef enum zplAllocationType {
    ZPL_ALLOCATION_ALLOC,
    ZPL_ALLOCATION_FREE,
    ZPL_ALLOCATION_FREE_ALL,
    ZPL_ALLOCATION_RESIZE,
} zplAllocationType;

// NOTE: This is useful so you can define an allocator of the same type and parameters
#define ZPL_ALLOCATOR_PROC(name)                          \
void *name(void *allocator_data, zplAllocationType type,  \
            isize size, isize alignment,                  \
            void *old_memory, isize old_size,             \
            u64 flags)
typedef ZPL_ALLOCATOR_PROC(zpl_allocator_proc);

#define zpl_allocator_t zpl_allocator
typedef struct zpl_allocator {
    zpl_allocator_proc *proc;
    void *              data;
} zpl_allocator;

typedef enum zplAllocatorFlag {
    ZPL_ALLOCATOR_FLAG_CLEAR_TO_ZERO = ZPL_BIT(0),
} zplAllocatorFlag;

#ifndef ZPL_DEFAULT_MEMORY_ALIGNMENT
#define ZPL_DEFAULT_MEMORY_ALIGNMENT (2 * zpl_size_of(void *))
#endif

#ifndef ZPL_DEFAULT_ALLOCATOR_FLAGS
#define ZPL_DEFAULT_ALLOCATOR_FLAGS (ZPL_ALLOCATOR_FLAG_CLEAR_TO_ZERO)
#endif

ZPL_DEF void *zpl_alloc_align (zpl_allocator a, isize size, isize alignment);
ZPL_DEF void *zpl_alloc       (zpl_allocator a, isize size);
ZPL_DEF void  zpl_free        (zpl_allocator a, void *ptr);
ZPL_DEF void  zpl_free_all    (zpl_allocator a);
ZPL_DEF void *zpl_resize      (zpl_allocator a, void *ptr, isize old_size, isize new_size);
ZPL_DEF void *zpl_resize_align(zpl_allocator a, void *ptr, isize old_size, isize new_size, isize alignment);

ZPL_DEF void *zpl_alloc_copy      (zpl_allocator a, void const *src, isize size);
ZPL_DEF void *zpl_alloc_copy_align(zpl_allocator a, void const *src, isize size, isize alignment);
ZPL_DEF char *zpl_alloc_str       (zpl_allocator a, char const *str);
ZPL_DEF char *zpl_alloc_str_len   (zpl_allocator a, char const *str, isize len);

#ifndef zpl_alloc_item
#define zpl_alloc_item(allocator_, Type)         (Type *)zpl_alloc(allocator_, zpl_size_of(Type))
#define zpl_alloc_array(allocator_, Type, count) (Type *)zpl_alloc(allocator_, zpl_size_of(Type) * (count))
#endif

// NOTE: Use this if you don't need a "fancy" resize allocation
ZPL_DEF void *zpl_default_resize_align(zpl_allocator a, void *ptr, isize old_size, isize new_size, isize alignment);

ZPL_DEF zpl_allocator zpl_heap_allocator(void);
ZPL_DEF ZPL_ALLOCATOR_PROC(zpl_heap_allocator_proc);

#ifndef zpl_malloc
#define zpl_malloc(sz) zpl_alloc(zpl_heap_allocator(), sz)
#define zpl_mfree(ptr) zpl_free(zpl_heap_allocator(), ptr)
#define zpl_heap zpl_heap_allocator
#endif



//
// Arena Allocator
//
#define zpl_arena_t zpl_arena
typedef struct zpl_arena {
    zpl_allocator backing;
    void *        physical_start;
    isize         total_size;
    isize         total_allocated;
    isize         temp_count;
} zpl_arena;

ZPL_DEF void zpl_arena_init_from_memory   (zpl_arena *arena, void *start, isize size);
ZPL_DEF void zpl_arena_init_from_allocator(zpl_arena *arena, zpl_allocator backing, isize size);
ZPL_DEF void zpl_arena_init_sub           (zpl_arena *arena, zpl_arena *parent_arena, isize size);
ZPL_DEF void zpl_arena_free               (zpl_arena *arena);

ZPL_DEF isize zpl_arena_alignment_of  (zpl_arena *arena, isize alignment);
ZPL_DEF isize zpl_arena_size_remaining(zpl_arena *arena, isize alignment);
ZPL_DEF void  zpl_arena_check         (zpl_arena *arena);


// Allocation Types: alloc, free_all, resize
ZPL_DEF zpl_allocator zpl_arena_allocator(zpl_arena *arena);
ZPL_DEF ZPL_ALLOCATOR_PROC(zpl_arena_allocator_proc);



#define zpl_temp_arena_memory_t zpl_temp_arena_memory
typedef struct zpl_temp_arena_memory {
    zpl_arena *arena;
    isize    original_count;
} zpl_temp_arena_memory;

ZPL_DEF zpl_temp_arena_memory zpl_temp_arena_memory_begin(zpl_arena *arena);
ZPL_DEF void              zpl_temp_arena_memory_end  (zpl_temp_arena_memory tmp_mem);







//
// Pool Allocator
//


#define zpl_pool_t zpl_pool
typedef struct zpl_pool {
    zpl_allocator backing;
    void *      physical_start;
    void *      free_list;
    isize       block_size;
    isize       block_align;
    isize       total_size;
} zpl_pool;

ZPL_DEF void zpl_pool_init      (zpl_pool *pool, zpl_allocator backing, isize num_blocks, isize block_size);
ZPL_DEF void zpl_pool_init_align(zpl_pool *pool, zpl_allocator backing, isize num_blocks, isize block_size, isize block_align);
ZPL_DEF void zpl_pool_free      (zpl_pool *pool);

// Allocation Types: alloc, free
ZPL_DEF zpl_allocator zpl_pool_allocator(zpl_pool *pool);
ZPL_DEF ZPL_ALLOCATOR_PROC(zpl_pool_allocator_proc);

#define zpl_allocation_header_ev_t zpl_allocation_header_ev
typedef struct zpl_allocation_header_ev {
    isize size;
} zpl_allocation_header_ev;

ZPL_DEF zpl_allocation_header_ev *zpl_allocation_header     (void *data);
ZPL_DEF void                zpl_allocation_header_fill(zpl_allocation_header_ev *header, void *data, isize size);

#if defined(ZPL_ARCH_32_BIT)
#define ZPL_ISIZE_HIGH_BIT 0x80000000
#elif defined(ZPL_ARCH_64_BIT)
#define ZPL_ISIZE_HIGH_BIT 0x8000000000000000ll
#else
#error
#endif

//
// Scratch Memory Allocator - Ring Buffer Based Arena
//

#define zpl_scratch_memory_t zpl_scratch_memory
typedef struct zpl_scratch_memory {
    void *physical_start;
    isize total_size;
    void *alloc_point;
    void *free_point;
} zpl_scratch_memory;

ZPL_DEF void zpl_scratch_memory_init     (zpl_scratch_memory *s, void *start, isize size);
ZPL_DEF b32  zpl_scratch_memory_is_in_use(zpl_scratch_memory *s, void *ptr);


// Allocation Types: alloc, free, free_all, resize
ZPL_DEF zpl_allocator zpl_scratch_allocator(zpl_scratch_memory *s);
ZPL_DEF ZPL_ALLOCATOR_PROC(zpl_scratch_allocator_proc);

//
// Stack Memory Allocator
//

#define zpl_stack_memory_t zpl_stack_memory
typedef struct zpl_stack_memory {
    zpl_allocator backing;

    void *physical_start;
    usize total_size;
    usize allocated;
} zpl_stack_memory;

ZPL_DEF void zpl_stack_memory_init_from_memory(zpl_stack_memory *s, void *start, isize size);
ZPL_DEF void zpl_stack_memory_init            (zpl_stack_memory *s, zpl_allocator backing, isize size);
ZPL_DEF b32  zpl_stack_memory_is_in_use       (zpl_stack_memory *s, void *ptr);
ZPL_DEF void zpl_stack_memory_free            (zpl_stack_memory *s);

// Allocation Types: alloc, free, free_all, resize
ZPL_DEF zpl_allocator zpl_stack_allocator(zpl_stack_memory *s);
ZPL_DEF ZPL_ALLOCATOR_PROC(zpl_stack_allocator_proc);

// TODO: Fixed heap allocator
// TODO: General heap allocator. Maybe a TCMalloc like clone?


////////////////////////////////////////////////////////////////
//
// Sort & Search
//
//

#define ZPL_COMPARE_PROC(name) int name(void const *a, void const *b)
typedef ZPL_COMPARE_PROC(zpl_compare_proc);

#define ZPL_COMPARE_PROC_PTR(def) ZPL_COMPARE_PROC((*def))

// Procedure pointers
// NOTE: The offset parameter specifies the offset in the structure
// e.g. zpl_i32_cmp(zpl_offset_of(Thing, value))
// Use 0 if it's just the type instead.

ZPL_DEF ZPL_COMPARE_PROC_PTR(zpl_i16_cmp  (isize offset));
ZPL_DEF ZPL_COMPARE_PROC_PTR(zpl_i32_cmp  (isize offset));
ZPL_DEF ZPL_COMPARE_PROC_PTR(zpl_i64_cmp  (isize offset));
ZPL_DEF ZPL_COMPARE_PROC_PTR(zpl_isize_cmp(isize offset));
ZPL_DEF ZPL_COMPARE_PROC_PTR(zpl_str_cmp  (isize offset));
ZPL_DEF ZPL_COMPARE_PROC_PTR(zpl_f32_cmp  (isize offset));
ZPL_DEF ZPL_COMPARE_PROC_PTR(zpl_f64_cmp  (isize offset));
ZPL_DEF ZPL_COMPARE_PROC_PTR(zpl_char_cmp (isize offset));

// TODO: Better sorting algorithms
// NOTE: Uses quick sort for large arrays but insertion sort for small
#define zpl_sort_array(array, count, compare_proc) zpl_sort(array, count, zpl_size_of(*(array)), compare_proc)
ZPL_DEF void zpl_sort(void *base, isize count, isize size, zpl_compare_proc compare_proc);

// NOTE: the count of temp == count of items
#define zpl_radix_sort(Type) zpl_radix_sort_##Type
#define ZPL_RADIX_SORT_PROC(Type) void zpl_radix_sort(Type)(Type *items, Type *temp, isize count)

ZPL_DEF ZPL_RADIX_SORT_PROC(u8);
ZPL_DEF ZPL_RADIX_SORT_PROC(u16);
ZPL_DEF ZPL_RADIX_SORT_PROC(u32);
ZPL_DEF ZPL_RADIX_SORT_PROC(u64);


// NOTE: Returns index or -1 if not found
#define zpl_binary_search_array(array, count, key, compare_proc) zpl_binary_search(array, count, zpl_size_of(*(array)), key, compare_proc)
ZPL_DEF isize zpl_binary_search(void const *base, isize count, isize size, void const *key, zpl_compare_proc compare_proc);

#define zpl_shuffle_array(array, count) zpl_shuffle(array, count, zpl_size_of(*(array)))
ZPL_DEF void zpl_shuffle(void *base, isize count, isize size);

#define zpl_reverse_array(array, count) zpl_reverse(array, count, zpl_size_of(*(array)))
ZPL_DEF void zpl_reverse(void *base, isize count, isize size);

////////////////////////////////////////////////////////////////
//
// Char Functions
//
//

ZPL_DEF char zpl_char_to_lower       (char c);
ZPL_DEF char zpl_char_to_upper       (char c);
ZPL_DEF b32  zpl_char_is_space       (char c);
ZPL_DEF b32  zpl_char_is_digit       (char c);
ZPL_DEF b32  zpl_char_is_hex_digit   (char c);
ZPL_DEF b32  zpl_char_is_alpha       (char c);
ZPL_DEF b32  zpl_char_is_alphanumeric(char c);
ZPL_DEF i32  zpl_digit_to_int        (char c);
ZPL_DEF i32  zpl_hex_digit_to_int    (char c);

// NOTE: ASCII only
ZPL_DEF void zpl_str_to_lower(char *str);
ZPL_DEF void zpl_str_to_upper(char *str);

ZPL_DEF isize zpl_strlen (char const *str);
ZPL_DEF isize zpl_strnlen(char const *str, isize max_len);
ZPL_DEF i32   zpl_strcmp (char const *s1, char const *s2);
ZPL_DEF i32   zpl_strncmp(char const *s1, char const *s2, isize len);
ZPL_DEF char *zpl_strcpy (char *dest, char const *source);
ZPL_DEF char *zpl_strdup (zpl_allocator a, char *src, isize max_len);
ZPL_DEF char *zpl_strncpy(char *dest, char const *source, isize len);
ZPL_DEF isize zpl_strlcpy(char *dest, char const *source, isize len);
ZPL_DEF char *zpl_strrev (char *str); // NOTE: ASCII only

ZPL_DEF char const *zpl_strtok(char *output, char const *src, char const *delimit);

// NOTE: This edits *source* string.
// Returns: zpl_array
ZPL_DEF char **zpl_str_split_lines(zpl_allocator alloc, char *source, b32 strip_whitespace);

ZPL_DEF b32 zpl_str_has_prefix(char const *str, char const *prefix);
ZPL_DEF b32 zpl_str_has_suffix(char const *str, char const *suffix);

ZPL_DEF char const *zpl_char_first_occurence(char const *str, char c);
ZPL_DEF char const *zpl_char_last_occurence (char const *str, char c);

ZPL_DEF void zpl_str_concat(char *dest, isize dest_len,
                            char const *src_a, isize src_a_len,
                            char const *src_b, isize src_b_len);

ZPL_DEF u64   zpl_str_to_u64(char const *str, char **end_ptr, i32 base); // TODO: Support more than just decimal and hexadecimal
ZPL_DEF i64   zpl_str_to_i64(char const *str, char **end_ptr, i32 base); // TODO: Support more than just decimal and hexadecimal
ZPL_DEF f32   zpl_str_to_f32(char const *str, char **end_ptr);
ZPL_DEF f64   zpl_str_to_f64(char const *str, char **end_ptr);
ZPL_DEF void  zpl_i64_to_str(i64 value, char *string, i32 base);
ZPL_DEF void  zpl_u64_to_str(u64 value, char *string, i32 base);


////////////////////////////////////////////////////////////////
//
// UTF-8 Handling
//
//

// NOTE: Does not check if utf-8 string is valid
ZPL_DEF isize zpl_utf8_strlen (u8 const *str);
ZPL_DEF isize zpl_utf8_strnlen(u8 const *str, isize max_len);

// NOTE: Windows doesn't handle 8 bit filenames well ('cause Micro$hit)
ZPL_DEF u16 *zpl_utf8_to_ucs2    (u16 *buffer, isize len, u8 const *str);
ZPL_DEF u8 * zpl_ucs2_to_utf8    (u8 *buffer, isize len, u16 const *str);
ZPL_DEF u16 *zpl_utf8_to_ucs2_buf(u8 const *str);   // NOTE: Uses locally persisting buffer
ZPL_DEF u8 * zpl_ucs2_to_utf8_buf(u16 const *str); // NOTE: Uses locally persisting buffer

// NOTE: Returns size of codepoint in bytes
ZPL_DEF isize zpl_utf8_decode        (u8 const *str, isize str_len, Rune *codepoint);
ZPL_DEF isize zpl_utf8_codepoint_size(u8 const *str, isize str_len);
ZPL_DEF isize zpl_utf8_encode_rune   (u8 buf[4], Rune r);

////////////////////////////////////////////////////////////////
//
// zpl_string - C Read-Only-Compatible
//
//
/*
    Reasoning:

    By default, strings in C are null terminated which means you have to count
    the number of character up to the null character to calculate the length.
    Many "better" C string libraries will create a struct for a string.
    i.e.

    struct String {
    Allocator allocator;
    size_t    length;
    size_t    capacity;
    char *    cstring;
    };

    This library tries to augment normal C strings in a better way that is still
    compatible with C-style strings.

    +--------+-----------------------+-----------------+
    | Header | Binary C-style String | Null Terminator |
    +--------+-----------------------+-----------------+
    |
    +-> Pointer returned by functions

    Due to the meta-data being stored before the string pointer and every zpl string
    having an implicit null terminator, zpl strings are full compatible with c-style
    strings and read-only functions.

    Advantages:

    * zpl strings can be passed to C-style string functions without accessing a struct
    member of calling a function, i.e.

    zpl_printf("%s\n", zpl_str);

    Many other libraries do either of these:

    zpl_printf("%s\n", string->cstr);
    zpl_printf("%s\n", get_cstring(string));

    * You can access each character just like a C-style string:

    zpl_printf("%c %c\n", str[0], str[13]);

    * zpl strings are singularly allocated. The meta-data is next to the character
    array which is better for the cache.

    Disadvantages:

    * In the C version of these functions, many return the new string. i.e.
    str = zpl_string_appendc(str, "another string");
    This could be changed to zpl_string_appendc(&str, "another string"); but I'm still not sure.
*/

#if 0
#define ZPL_IMPLEMENTATION
#include "zpl.h"
int main(int argc, char **argv) {
    zpl_string str = zpl_string_make("Hello");
    zpl_string other_str = zpl_string_make_length(", ", 2);
    str = zpl_string_append(str, other_str);
    str = zpl_string_appendc(str, "world!");

    zpl_printf("%s\n", str); // Hello, world!

    zpl_printf("str length = %d\n", zpl_string_length(str));

    str = zpl_string_set(str, "Potato soup");
    zpl_printf("%s\n", str); // Potato soup

    str = zpl_string_set(str, "Hello");
    other_str = zpl_string_set(other_str, "Pizza");
    if (zpl_strings_are_equal(str, other_str))
        zpl_printf("Not called\n");
    else
        zpl_printf("Called\n");

    str = zpl_string_set(str, "Ab.;!...AHello World       ??");
    str = zpl_string_trim(str, "Ab.;!. ?");
    zpl_printf("%s\n", str); // "Hello World"

    zpl_string_free(str);
    zpl_string_free(other_str);

    return 0;
}
#endif

#define zpl_string_t zpl_string
typedef char *zpl_string;

// NOTE: If you only need a small string, just use a standard c string or change the size from isize to u16, etc.
#define zpl_string_header_t zpl_string_header
typedef struct zpl_string_header {
    zpl_allocator allocator;
    isize       length;
    isize       capacity;
} zpl_string_header;

#define ZPL_STRING_HEADER(str) (cast(zpl_string_header *)(str) - 1)

ZPL_DEF zpl_string zpl_string_make_reserve   (zpl_allocator a, isize capacity);
ZPL_DEF zpl_string zpl_string_make           (zpl_allocator a, char const *str);
ZPL_DEF zpl_string zpl_string_make_length    (zpl_allocator a, void const *str, isize num_bytes);
ZPL_DEF zpl_string zpl_string_sprintf     (zpl_allocator a, char *buf, isize num_bytes, char const *fmt, ...);
ZPL_DEF zpl_string zpl_string_sprintf_buf     (zpl_allocator a, char const *fmt, ...); // NOTE: Uses locally persistent buffer
ZPL_DEF void     zpl_string_free           (zpl_string str);
ZPL_DEF zpl_string zpl_string_duplicate      (zpl_allocator a, zpl_string const str);
ZPL_DEF isize    zpl_string_length         (zpl_string const str);
ZPL_DEF isize    zpl_string_capacity       (zpl_string const str);
ZPL_DEF isize    zpl_string_available_space(zpl_string const str);
ZPL_DEF void     zpl_string_clear          (zpl_string str);
ZPL_DEF zpl_string zpl_string_append         (zpl_string str, zpl_string const other);
ZPL_DEF zpl_string zpl_string_append_length  (zpl_string str, void const *other, isize num_bytes);
ZPL_DEF zpl_string zpl_string_appendc        (zpl_string str, char const *other);
ZPL_DEF zpl_string zpl_string_set            (zpl_string str, char const *cstr);
ZPL_DEF zpl_string zpl_string_make_space_for (zpl_string str, isize add_len);
ZPL_DEF isize    zpl_string_allocation_size(zpl_string const str);
ZPL_DEF b32      zpl_string_are_equal      (zpl_string const lhs, zpl_string const rhs);
ZPL_DEF zpl_string zpl_string_trim           (zpl_string str, char const *cut_set);
ZPL_DEF zpl_string zpl_string_trim_space     (zpl_string str); // Whitespace ` \t\r\n\v\f`
ZPL_DEF zpl_string zpl_string_append_rune(zpl_string str, Rune r);
ZPL_DEF zpl_string zpl_string_append_fmt(zpl_string str, char const *fmt, ...);


////////////////////////////////////////////////////////////////
//
// Fixed Capacity Buffer (POD Types)
//
//
// zpl_buffer(Type) works like zpl_string or zpl_array where the actual type is just a pointer to the first
// element.
//
// Available Procedures for zpl_buffer(Type)
// zpl_buffer_init
// zpl_buffer_free
// zpl_buffer_append
// zpl_buffer_appendv
// zpl_buffer_pop
// zpl_buffer_clear

#define zpl_buffer_header_t zpl_buffer_header
typedef struct zpl_buffer_header {
    zpl_allocator backing;
    isize count;
    isize capacity;
} zpl_buffer_header;

#define zpl_buffer(Type) Type *
#define zpl_buffer_t zpl_buffer

#define ZPL_BUFFER_HEADER(x)   (cast(zpl_buffer_header *)(x) - 1)
#define zpl_buffer_count(x)    (ZPL_BUFFER_HEADER(x)->count)
#define zpl_buffer_capacity(x) (ZPL_BUFFER_HEADER(x)->capacity)
#define zpl_buffer_end(x)      (x + (zpl_buffer_count(x) - 1))

#define zpl_buffer_init(x, allocator, cap) do {                         \
    void **nx = cast(void **)&(x);                                  \
    zpl_buffer_header *zpl__bh = cast(zpl_buffer_header *)zpl_alloc((allocator), sizeof(zpl_buffer_header)+(cap)*zpl_size_of(*(x))); \
    zpl__bh->backing = allocator; \
    zpl__bh->count = 0;                                             \
    zpl__bh->capacity = cap;                                        \
    *nx = cast(void *)(zpl__bh+1);                                  \
} while (0)


// DEPRECATED(zpl_buffer_free): Use zpl_buffer_free2 instead
#define zpl_buffer_free(x, allocator) (zpl_free(allocator, ZPL_BUFFER_HEADER(x)))
#define zpl_buffer_free2(x) (zpl_free(ZPL_BUFFER_HEADER(x)->backing, ZPL_BUFFER_HEADER(x)))

#define zpl_buffer_append(x, item) do { (x)[zpl_buffer_count(x)++] = (item); } while (0)

#define zpl_buffer_appendv(x, items, item_count) do {                   \
    ZPL_ASSERT(zpl_size_of(*(items)) == zpl_size_of(*(x)));         \
    ZPL_ASSERT(zpl_buffer_count(x)+item_count <= zpl_buffer_capacity(x)); \
    zpl_memcopy(&(x)[zpl_buffer_count(x)], (items), zpl_size_of(*(x))*(item_count)); \
    zpl_buffer_count(x) += (item_count);                            \
} while (0)

#define zpl_buffer_copy_init(y, x) do { \
    zpl_buffer_init_reserve(y, zpl_buffer_allocator(x), zpl_buffer_capacity(x)); \
    zpl_memcopy(y, x, zpl_buffer_capacity(x) * zpl_size_of(*x)); \
    zpl_buffer_count(y) = zpl_buffer_count(x); \
} while (0)

#define zpl_buffer_pop(x)   do { ZPL_ASSERT(zpl_buffer_count(x) > 0); zpl_buffer_count(x)--; } while (0)
#define zpl_buffer_clear(x) do { zpl_buffer_count(x) = 0; } while (0)

////////////////////////////////////////////////////////////////
//
// Linked List
//
// zpl_list encapsulates pointer to data and points to the next and the previous element in the list.
//
// Available Procedures for zpl_list
// zpl_list_init
// zpl_list_add
// zpl_list_remove

#if 0
#define ZPL_IMPLEMENTATION
#include "zpl.h"
int main(void)
{
zpl_list s, *head, *cursor;
zpl_list_init(&s, "it is optional to call init: ");
head = cursor = &s;

// since we can construct an element implicitly this way
// the second field gets overwritten once we add it to a list.
zpl_list a = {"hello"};
cursor = zpl_list_add(cursor, &a);

zpl_list b = {"world"};
cursor = zpl_list_add(cursor, &b);

zpl_list c = {"!!! OK"};
cursor = zpl_list_add(cursor, &c);

for (zpl_list *l=head; l; l=l->next) {
    zpl_printf("%s ", cast(char *)l->ptr);
}
zpl_printf("\n");

return 0;
}
#endif

#define zpl_list_t zpl_list
typedef struct zpl__list {
    void const *ptr;
    struct zpl__list *next, *prev;
} zpl_list;

ZPL_DEF void        zpl_list_init  (zpl_list *list, void const *ptr);
ZPL_DEF zpl_list *zpl_list_add   (zpl_list *list, zpl_list *item);

// NOTE(zaklaus): Returns a pointer to the next node (or NULL if the removed node has no trailing node.)
ZPL_DEF zpl_list *zpl_list_remove(zpl_list *list);


////////////////////////////////////////////////////////////////
//
// Dynamic Array (POD Types)
//
// zpl_array(Type) works like zpl_string or zpl_buffer where the actual type is just a pointer to the first
// element.
//
// Available Procedures for zpl_array(Type)
// zpl_array_init
// zpl_array_free
// zpl_array_set_capacity
// zpl_array_grow
// zpl_array_append
// zpl_array_appendv
// zpl_array_pop
// zpl_array_clear
// zpl_array_back
// zpl_array_front
// zpl_array_resize
// zpl_array_reserve
//

#if 0 // Example
void foo(void) {
    isize i;
    int test_values[] = {4, 2, 1, 7};
    zpl_allocator a = zpl_heap_allocator();
    zpl_array(int) items;

    zpl_array_init(items, a);

    zpl_array_append(items, 1);
    zpl_array_append(items, 4);
    zpl_array_append(items, 9);
    zpl_array_append(items, 16);

    items[1] = 3; // Manually set value
    // NOTE: No array bounds checking

    for (i = 0; i < items.count; i++)
        zpl_printf("%d\n", items[i]);
    // 1
    // 3
    // 9
    // 16

    zpl_array_clear(items);

    zpl_array_appendv(items, test_values, zpl_count_of(test_values));
    for (i = 0; i < items.count; i++)
        zpl_printf("%d\n", items[i]);
    // 4
    // 2
    // 1
    // 7

    zpl_array_free(items);
}
#endif

#define zpl_array_header_t zpl_array_header
typedef struct zpl_array_header {
    char           *data;
    isize           count;
    isize           capacity;
    zpl_allocator allocator;
} zpl_array_header;

#define zpl_array(Type) Type *
#define zpl_array_t zpl_array

#ifndef ZPL_ARRAY_GROW_FORMULA
#define ZPL_ARRAY_GROW_FORMULA(x) (2*(x) + 8)
#endif

ZPL_STATIC_ASSERT(ZPL_ARRAY_GROW_FORMULA(0) > 0);

#define ZPL_ARRAY_HEADER(x)    (cast(zpl_array_header *)(x) - 1)
#define zpl_array_allocator(x) (ZPL_ARRAY_HEADER(x)->allocator)
#define zpl_array_count(x)     (ZPL_ARRAY_HEADER(x)->count)
#define zpl_array_capacity(x)  (ZPL_ARRAY_HEADER(x)->capacity)
#define zpl_array_end(x)       (x + (zpl_array_count(x) - 1))

#define zpl_array_init_reserve(x, allocator_, cap) do {                 \
    void **zpl__array_ = cast(void **)&(x);                         \
    zpl_array_header *zpl__ah = cast(zpl_array_header *)zpl_alloc(allocator_, zpl_size_of(zpl_array_header)+zpl_size_of(*(x))*(cap)); \
    zpl__ah->allocator = allocator_;                                \
    zpl__ah->count = 0;                                             \
    zpl__ah->data = (char *)x;                                              \
    zpl__ah->capacity = cap;                                        \
    *zpl__array_ = cast(void *)(zpl__ah+1);                         \
} while (0)

// NOTE: Give it an initial default capacity
#define zpl_array_init(x, allocator) zpl_array_init_reserve(x, allocator, ZPL_ARRAY_GROW_FORMULA(0))

#define zpl_array_free(x) do {                              \
    zpl_array_header *zpl__ah = ZPL_ARRAY_HEADER(x);  \
    zpl_free(zpl__ah->allocator, zpl__ah);              \
} while (0)

#define zpl_array_set_capacity(x, capacity) do {                        \
    if (x) {                                                        \
        void **zpl__array_ = cast(void **)&(x);                     \
        *zpl__array_ = zpl__array_set_capacity((x), (capacity), zpl_size_of(*(x))); \
    }                                                               \
} while (0)

// NOTE: Do not use the thing below directly, use the macro
ZPL_DEF void *zpl__array_set_capacity(void *array, isize capacity, isize element_size);


#define zpl_array_grow(x, min_capacity) do {                            \
    isize new_capacity = ZPL_ARRAY_GROW_FORMULA(zpl_array_capacity(x)); \
    if (new_capacity < (min_capacity))                              \
        new_capacity = (min_capacity);                              \
    zpl_array_set_capacity(x, new_capacity);                        \
} while (0)


#define zpl_array_append(x, item) do {                    \
    if (zpl_array_capacity(x) < zpl_array_count(x)+1) \
        zpl_array_grow(x, 0);                         \
    (x)[zpl_array_count(x)++] = (item);               \
} while (0)

#define zpl_array_append_at(x, item, ind) do { \
    zpl_array_header *zpl__ah = ZPL_ARRAY_HEADER(x); \
    zpl_array_grow(x, zpl__ah->count + 1); \
    zpl_memcopy(x+ind+1, x+ind, zpl_size_of(x[0])*(zpl__ah->count - ind)); \
    x[ind] = item; \
} while (0)

#define zpl_array_appendv(x, items, item_count) do {                    \
    zpl_array_header *zpl__ah = ZPL_ARRAY_HEADER(x);              \
    ZPL_ASSERT(zpl_size_of((items)[0]) == zpl_size_of((x)[0]));     \
    if (zpl__ah->capacity < zpl__ah->count+(item_count))            \
        zpl_array_grow(x, zpl__ah->count+(item_count));             \
    zpl_memcopy(&(x)[zpl__ah->count], (items), zpl_size_of((x)[0])*(item_count)); \
    zpl__ah->count += (item_count);                                 \
} while (0)


#define zpl_array_remove_at(x, index) do {                              \
    zpl_array_header *zpl__ah = ZPL_ARRAY_HEADER(x);              \
    ZPL_ASSERT(index < zpl__ah->count);                             \
    zpl_memcopy(x+index, x+index+1, zpl_size_of(x[0])*(zpl__ah->count - index)); \
    --zpl__ah->count;                                               \
} while (0)

#define zpl_array_copy_init(y, x) do { \
    zpl_array_init_reserve(y, zpl_array_allocator(x), zpl_array_capacity(x)); \
    zpl_memcopy(y, x, zpl_array_capacity(x) * zpl_size_of(*x)); \
    zpl_array_count(y) = zpl_array_count(x); \
} while (0)



#define zpl_array_pop(x)   do { ZPL_ASSERT(ZPL_ARRAY_HEADER(x)->count > 0); ZPL_ARRAY_HEADER(x)->count--; } while (0)
#define zpl_array_back(x)  x[ZPL_ARRAY_HEADER(x)->count - 1]
#define zpl_array_front(x) x[0]
#define zpl_array_clear(x) do { ZPL_ARRAY_HEADER(x)->count = 0; } while (0)

#define zpl_array_resize(x, new_count) do {               \
    if (ZPL_ARRAY_HEADER(x)->capacity < (new_count))  \
        zpl_array_grow(x, (new_count));               \
    ZPL_ARRAY_HEADER(x)->count = (new_count);         \
} while (0)


#define zpl_array_reserve(x, new_capacity) do {             \
    if (ZPL_ARRAY_HEADER(x)->capacity < (new_capacity)) \
        zpl_array_set_capacity(x, new_capacity);        \
} while (0)


////////////////////////////////////////////////////////////////
//
// Hashing and Checksum Functions
//
//

ZPL_EXTERN u32 zpl_adler32(void const *data, isize len);

ZPL_EXTERN u32 zpl_crc32(void const *data, isize len);
ZPL_EXTERN u64 zpl_crc64(void const *data, isize len);

ZPL_EXTERN u32 zpl_fnv32 (void const *data, isize len);
ZPL_EXTERN u64 zpl_fnv64 (void const *data, isize len);
ZPL_EXTERN u32 zpl_fnv32a(void const *data, isize len);
ZPL_EXTERN u64 zpl_fnv64a(void const *data, isize len);

// NOTE: Default seed of 0x9747b28c
// NOTE: I prefer using murmur64 for most hashes
ZPL_EXTERN u32 zpl_murmur32(void const *data, isize len);
ZPL_EXTERN u64 zpl_murmur64(void const *data, isize len);

ZPL_EXTERN u32 zpl_murmur32_seed(void const *data, isize len, u32 seed);
ZPL_EXTERN u64 zpl_murmur64_seed(void const *data, isize len, u64 seed);


////////////////////////////////////////////////////////////////
//
// Instantiated Hash Table
//
// This is an attempt to implement a templated hash table
// NOTE: The key is always a u64 for simplicity and you will _probably_ _never_ need anything bigger.
//
// Hash table type and function declaration, call: ZPL_TABLE_DECLARE(PREFIX, NAME, N, VALUE)
// Hash table function definitions, call: ZPL_TABLE_DEFINE(NAME, N, VALUE)
//
//     PREFIX  - a prefix for function prototypes e.g. extern, static, etc.
//     NAME    - Name of the Hash Table
//     FUNC    - the name will prefix function names
//     VALUE   - the type of the value to be stored
//

#define zpl_hash_table_find_result_t zpl_hash_table_find_result
typedef struct zpl_hash_table_find_result {
    isize hash_index;
    isize entry_prev;
    isize entry_index;
} zpl_hash_table_find_result;

#define ZPL_TABLE(PREFIX, NAME, FUNC, VALUE)      \
ZPL_TABLE_DECLARE(PREFIX, NAME, FUNC, VALUE); \
ZPL_TABLE_DEFINE(NAME, FUNC, VALUE);

#define ZPL_TABLE_DECLARE(PREFIX, NAME, FUNC, VALUE)                    \
typedef struct ZPL_JOIN2(NAME,Entry) {                              \
    u64 key;                                                        \
    isize next;                                                     \
    VALUE value;                                                    \
} ZPL_JOIN2(NAME,Entry);                                            \
                                                                    \
typedef struct NAME {                                               \
    zpl_array(isize) hashes;                                      \
    zpl_array(ZPL_JOIN2(NAME,Entry)) entries;                     \
} NAME;                                                             \
                                                                    \
PREFIX void                  ZPL_JOIN2(FUNC,init)       (NAME *h, zpl_allocator a); \
PREFIX void                  ZPL_JOIN2(FUNC,destroy)    (NAME *h);  \
PREFIX VALUE *               ZPL_JOIN2(FUNC,get)        (NAME *h, u64 key); \
PREFIX void                  ZPL_JOIN2(FUNC,set)        (NAME *h, u64 key, VALUE value); \
PREFIX void                  ZPL_JOIN2(FUNC,grow)       (NAME *h);  \
PREFIX void                  ZPL_JOIN2(FUNC,rehash)     (NAME *h, isize new_count); \
PREFIX void                  ZPL_JOIN2(FUNC,remove)     (NAME *h, u64 key); \




#define ZPL_TABLE_DEFINE(NAME, FUNC, VALUE)                             \
void ZPL_JOIN2(FUNC,init)(NAME *h, zpl_allocator a) {             \
    zpl_array_init(h->hashes,  a);                                  \
    zpl_array_init(h->entries, a);                                  \
}                                                                   \
                                                                    \
void ZPL_JOIN2(FUNC,destroy)(NAME *h) {                             \
    if (h->entries) zpl_array_free(h->entries);                     \
    if (h->hashes)  zpl_array_free(h->hashes);                      \
}                                                                   \
                                                                    \
zpl_internal isize ZPL_JOIN2(FUNC,_add_entry)(NAME *h, u64 key) {   \
    isize index;                                                    \
    ZPL_JOIN2(NAME,Entry) e = {0};                                  \
    e.key = key;                                                    \
    e.next = -1;                                                    \
    index = zpl_array_count(h->entries);                            \
    zpl_array_append(h->entries, e);                                \
    return index;                                                   \
}                                                                   \
                                                                    \
zpl_internal zpl_hash_table_find_result ZPL_JOIN2(FUNC,_find)(NAME *h, u64 key) { \
    zpl_hash_table_find_result r = {-1, -1, -1};                  \
    if (zpl_array_count(h->hashes) > 0) {                           \
        r.hash_index  = key % zpl_array_count(h->hashes);           \
        r.entry_index = h->hashes[r.hash_index];                    \
        while (r.entry_index >= 0) {                                \
            if (h->entries[r.entry_index].key == key)               \
                return r;                                           \
            r.entry_prev = r.entry_index;                           \
            r.entry_index = h->entries[r.entry_index].next;         \
        }                                                           \
    }                                                               \
    return r;                                                       \
}                                                                   \
                                                                    \
zpl_internal b32 ZPL_JOIN2(FUNC,_full)(NAME *h) {                   \
    return 0.75f * zpl_array_count(h->hashes) < zpl_array_count(h->entries); \
}                                                                   \
                                                                    \
void ZPL_JOIN2(FUNC,grow)(NAME *h) {                                \
    isize new_count = ZPL_ARRAY_GROW_FORMULA(zpl_array_count(h->entries)); \
    ZPL_JOIN2(FUNC,rehash)(h, new_count);                           \
}                                                                   \
                                                                    \
void ZPL_JOIN2(FUNC,rehash)(NAME *h, isize new_count) {             \
    isize i, j;                                                     \
    NAME nh = {0};                                                  \
    ZPL_JOIN2(FUNC,init)(&nh, zpl_array_allocator(h->hashes));      \
    zpl_array_resize(nh.hashes, new_count);                         \
    zpl_array_reserve(nh.entries, zpl_array_count(h->entries));     \
    for (i = 0; i < new_count; i++)                                 \
        nh.hashes[i] = -1;                                          \
    for (i = 0; i < zpl_array_count(h->entries); i++) {             \
        ZPL_JOIN2(NAME,Entry) *e;                                   \
        zpl_hash_table_find_result fr;                            \
        if (zpl_array_count(nh.hashes) == 0)                        \
            ZPL_JOIN2(FUNC,grow)(&nh);                              \
        e = &h->entries[i];                                         \
        fr = ZPL_JOIN2(FUNC,_find)(&nh, e->key);                    \
        j = ZPL_JOIN2(FUNC,_add_entry)(&nh, e->key);                \
        if (fr.entry_prev < 0)                                      \
            nh.hashes[fr.hash_index] = j;                           \
        else                                                        \
            nh.entries[fr.entry_prev].next = j;                     \
        nh.entries[j].next = fr.entry_index;                        \
        nh.entries[j].value = e->value;                             \
    }                                                               \
    ZPL_JOIN2(FUNC,destroy)(h);                                     \
    h->hashes  = nh.hashes;                                         \
    h->entries = nh.entries;                                        \
}                                                                   \
                                                                    \
VALUE *ZPL_JOIN2(FUNC,get)(NAME *h, u64 key) {                      \
    isize index = ZPL_JOIN2(FUNC,_find)(h, key).entry_index;        \
    if (index >= 0)                                                 \
        return &h->entries[index].value;                            \
    return NULL;                                                    \
}                                                                   \
                                                                    \
void ZPL_JOIN2(FUNC,remove)(NAME *h, u64 key) {                     \
    zpl_hash_table_find_result fr = ZPL_JOIN2(FUNC,_find)(h, key);\
    if (fr.entry_index >= 0) {                                      \
        if (fr.entry_prev >= 0) {                                   \
            h->entries[fr.entry_prev].next = h->entries[fr.entry_index].next; \
        }                                                           \
        else {                                                      \
            h->hashes[fr.hash_index] = fr.entry_index;              \
        }                                                           \
        zpl_array_remove_at(h->entries, fr.entry_index);            \
    }                                                               \
    ZPL_JOIN2(FUNC,rehash)(h, zpl_array_count(h->entries));         \
}                                                                   \
                                                                    \
void ZPL_JOIN2(FUNC,set)(NAME *h, u64 key, VALUE value) {           \
    isize index;                                                    \
    zpl_hash_table_find_result fr;                                \
    if (zpl_array_count(h->hashes) == 0)                            \
        ZPL_JOIN2(FUNC,grow)(h);                                    \
    fr = ZPL_JOIN2(FUNC,_find)(h, key);                             \
    if (fr.entry_index >= 0) {                                      \
        index = fr.entry_index;                                     \
    } else {                                                        \
        index = ZPL_JOIN2(FUNC,_add_entry)(h, key);                 \
        if (fr.entry_prev >= 0) {                                   \
            h->entries[fr.entry_prev].next = index;                 \
        } else {                                                    \
            h->hashes[fr.hash_index] = index;                       \
        }                                                           \
    }                                                               \
    h->entries[index].value = value;                                \
    if (ZPL_JOIN2(FUNC,_full)(h))                                   \
        ZPL_JOIN2(FUNC,grow)(h);                                    \
}                                                                   \

////////////////////////////////////////////////////////////////
//
// Instantiated Circular buffer
//
/*
int main()
{
    zpl_ring_u32 pad={0};
    zpl_ring_u32_init(&pad, zpl_heap(), 3);
    zpl_ring_u32_append(&pad, 1);
    zpl_ring_u32_append(&pad, 2);
    zpl_ring_u32_append(&pad, 3);

    while (!zpl_ring_u32_empty(&pad)) {
        zpl_printf("Result is %d\n", *zpl_ring_u32_get(&pad));
    }

    zpl_ring_u32_free(&pad);

    return 0;
}
*/

#define ZPL_RING_DECLARE(type) \
    typedef struct { \
        zpl_allocator backing; \
        zpl_buffer(type) buf; \
        usize head, tail; \
        usize capacity; \
    } ZPL_JOIN2(zpl_ring_, type); \
        \
        \
    ZPL_DEF void  ZPL_JOIN3(zpl_ring_, type, _init)         (ZPL_JOIN2(zpl_ring_, type) *pad, zpl_allocator a, isize max_size);\
    ZPL_DEF void  ZPL_JOIN3(zpl_ring_, type, _free)         (ZPL_JOIN2(zpl_ring_, type) *pad);\
    ZPL_DEF b32   ZPL_JOIN3(zpl_ring_, type, _full)         (ZPL_JOIN2(zpl_ring_, type) *pad);\
    ZPL_DEF b32   ZPL_JOIN3(zpl_ring_, type, _empty)        (ZPL_JOIN2(zpl_ring_, type) *pad);\
    ZPL_DEF void  ZPL_JOIN3(zpl_ring_, type, _append)       (ZPL_JOIN2(zpl_ring_, type) *pad, type data);\
    ZPL_DEF void  ZPL_JOIN3(zpl_ring_, type, _append_array) (ZPL_JOIN2(zpl_ring_, type) *pad, zpl_array(type) data);\
    ZPL_DEF type *ZPL_JOIN3(zpl_ring_, type, _get)          (ZPL_JOIN2(zpl_ring_, type) *pad);\
    ZPL_DEF zpl_array(type)  ZPL_JOIN3(zpl_ring_, type, _get_array)    (ZPL_JOIN2(zpl_ring_, type) *pad, usize max_size, zpl_allocator a);\

#define ZPL_RING_DEFINE(type) \
    void ZPL_JOIN3(zpl_ring_, type, _init)(ZPL_JOIN2(zpl_ring_, type) *pad, zpl_allocator a, isize max_size) \
    { \
        ZPL_JOIN2(zpl_ring_, type) pad_={0}; \
        *pad=pad_; \
            \
        pad->backing=a; \
        zpl_buffer_init(pad->buf, a, max_size+1); \
        pad->capacity=max_size+1; \
        pad->head=pad->tail=0; \
    } \
    void ZPL_JOIN3(zpl_ring_, type, _free)(ZPL_JOIN2(zpl_ring_, type) *pad) \
    { \
        zpl_buffer_free(pad->buf, pad->backing); \
    } \
        \
    b32 ZPL_JOIN3(zpl_ring_, type, _full)(ZPL_JOIN2(zpl_ring_, type) *pad) \
    { \
        return ((pad->head+1)%pad->capacity)==pad->tail; \
    } \
        \
    b32 ZPL_JOIN3(zpl_ring_, type, _empty)(ZPL_JOIN2(zpl_ring_, type) *pad) \
    { \
        return pad->head==pad->tail; \
    } \
        \
    void ZPL_JOIN3(zpl_ring_, type, _append)(ZPL_JOIN2(zpl_ring_, type) *pad, type data) \
    { \
        pad->buf[pad->head]=data; \
        pad->head=(pad->head+1)%pad->capacity; \
            \
        if (pad->head==pad->tail) { \
            pad->tail=(pad->tail+1)%pad->capacity; \
        } \
            \
    } \
        \
    void ZPL_JOIN3(zpl_ring_, type, _append_array) (ZPL_JOIN2(zpl_ring_, type) *pad, zpl_array(type) data) \
    { \
        usize c=zpl_array_count(data); \
        for (usize i=0; i<c; ++i) { \
            ZPL_JOIN3(zpl_ring_, type, _append)(pad, data[i]); \
        } \
    } \
        \
    type * ZPL_JOIN3(zpl_ring_, type, _get)(ZPL_JOIN2(zpl_ring_, type) *pad) \
    { \
        if (ZPL_JOIN3(zpl_ring_, type, _empty)(pad)) { \
            return NULL; \
        } \
            \
        type *data=&pad->buf[pad->tail]; \
        pad->tail=(pad->tail+1)%pad->capacity; \
            \
        return data; \
    } \
        \
    zpl_array(type) ZPL_JOIN3(zpl_ring_, type, _get_array)(ZPL_JOIN2(zpl_ring_, type) *pad, usize max_size, zpl_allocator a) \
    { \
        zpl_array(type) vals; \
        zpl_array_init(vals, a); \
        while (--max_size && ! ZPL_JOIN3(zpl_ring_, type, _empty)(pad)) {\
            zpl_array_append(vals, *ZPL_JOIN3(zpl_ring_, type, _get)(pad)); \
        } \
        return vals; \
    }

ZPL_RING_DECLARE(u8);
ZPL_RING_DECLARE(char);
ZPL_RING_DECLARE(u16);
ZPL_RING_DECLARE(i16);
ZPL_RING_DECLARE(u32);
ZPL_RING_DECLARE(i32);
ZPL_RING_DECLARE(u64);
ZPL_RING_DECLARE(i64);
ZPL_RING_DECLARE(f32);
ZPL_RING_DECLARE(f64);
ZPL_RING_DECLARE(usize);
ZPL_RING_DECLARE(isize);
ZPL_RING_DECLARE(uintptr);


////////////////////////////////////////////////////////////////
//
// File Handling
//


typedef u32 zpl_file_mode;
typedef enum zplFileModeFlag {
    ZPL_FILE_MODE_READ       = ZPL_BIT(0),
    ZPL_FILE_MODE_WRITE      = ZPL_BIT(1),
    ZPL_FILE_MODE_APPEND     = ZPL_BIT(2),
    ZPL_FILE_MODE_RW         = ZPL_BIT(3),

    zpl_file_mode_modes_ev = ZPL_FILE_MODE_READ | ZPL_FILE_MODE_WRITE | ZPL_FILE_MODE_APPEND | ZPL_FILE_MODE_RW,
} zplFileModeFlag;

// NOTE: Only used internally and for the file operations
typedef enum zplSeekWhenceType {
    ZPL_SEEK_WHENCE_BEGIN   = 0,
    ZPL_SEEK_WHENCE_CURRENT = 1,
    ZPL_SEEK_WHENCE_END     = 2,
} zplSeekWhenceType;

typedef enum zplFileError {
    ZPL_FILE_ERROR_NONE,
    ZPL_FILE_ERROR_INVALID,
    ZPL_FILE_ERROR_INVALID_FILENAME,
    ZPL_FILE_ERROR_EXISTS,
    ZPL_FILE_ERROR_NOT_EXISTS,
    ZPL_FILE_ERROR_PERMISSION,
    ZPL_FILE_ERROR_TRUNCATION_FAILURE,
    ZPL_FILE_ERROR_NOT_EMPTY,
    ZPL_FILE_ERROR_NAME_TOO_LONG,
    ZPL_FILE_ERROR_UNKNOWN,
} zplFileError;

#define zpl_file_descriptor_t zpl_file_descriptor
typedef union zpl_file_descriptor {
    void *  p;
    intptr  i;
    uintptr u;
} zpl_file_descriptor;

#define zpl_file_operations_t zpl_file_operations
typedef struct zpl_file_operations zpl_file_operations;

#define ZPL_FILE_OPEN_PROC(name)     zplFileError name(zpl_file_descriptor *fd, zpl_file_operations *ops, zpl_file_mode mode, char const *filename)
#define ZPL_FILE_READ_AT_PROC(name)  b32         name(zpl_file_descriptor fd, void *buffer, isize size, i64 offset, isize *bytes_read, b32 stop_at_newline)
#define ZPL_FILE_WRITE_AT_PROC(name) b32         name(zpl_file_descriptor fd, void const *buffer, isize size, i64 offset, isize *bytes_written)
#define ZPL_FILE_SEEK_PROC(name)     b32         name(zpl_file_descriptor fd, i64 offset, zplSeekWhenceType whence, i64 *new_offset)
#define ZPL_FILE_CLOSE_PROC(name)    void        name(zpl_file_descriptor fd)
typedef ZPL_FILE_OPEN_PROC(zpl_file_open_proc);
typedef ZPL_FILE_READ_AT_PROC(zpl_file_read_proc);
typedef ZPL_FILE_WRITE_AT_PROC(zpl_file_write_proc);
typedef ZPL_FILE_SEEK_PROC(zpl_file_seek_proc);
typedef ZPL_FILE_CLOSE_PROC(zpl_file_close_proc);

struct zpl_file_operations {
    zpl_file_read_proc  *read_at;
    zpl_file_write_proc *write_at;
    zpl_file_seek_proc  *seek;
    zpl_file_close_proc *close;
};

extern zpl_file_operations const zpl_default_file_operations;


// typedef struct zpl_dir_info {
//  u8 *buf;
//  isize buf_count;
//  isize buf_pos;
// } zpl_dir_info;

typedef u64 zpl_file_time;

#define zpl_file_t zpl_file
typedef struct zpl_file {
    zpl_file_operations ops;
    zpl_file_descriptor fd;
    char const *     filename;
    zpl_file_time       last_write_time;
    // zpl_dir_info *   dir_info; // TODO: Get directory info
} zpl_file;

#ifdef ZPL_THREADING

#define zpl_async_file_t zpl_async_file
typedef struct zpl_async_file {
    zpl_file handle;
    isize size;
    void *data;
} zpl_async_file;

#define ZPL_ASYNC_FILE_CB(name) void name(zpl_async_file *file)
typedef ZPL_ASYNC_FILE_CB(zpl_async_file_cb);

#endif // ZPL_THREADING

typedef enum zplFileStandardType {
    ZPL_FILE_STANDARD_INPUT,
    ZPL_FILE_STANDARD_OUTPUT,
    ZPL_FILE_STANDARD_ERROR,

    ZPL_FILE_STANDARD_COUNT,
} zplFileStandardType;

ZPL_DEF zpl_file *zpl_file_get_standard(zplFileStandardType std);

ZPL_DEF zplFileError  zpl_file_create        (zpl_file *file, char const *filename);
ZPL_DEF zplFileError  zpl_file_open          (zpl_file *file, char const *filename);
ZPL_DEF zplFileError  zpl_file_open_mode     (zpl_file *file, zpl_file_mode mode, char const *filename);
ZPL_DEF zplFileError  zpl_file_new           (zpl_file *file, zpl_file_descriptor fd, zpl_file_operations ops, char const *filename);
ZPL_DEF b32           zpl_file_read_at_check (zpl_file *file, void *buffer, isize size, i64 offset, isize *bytes_read);
ZPL_DEF b32           zpl_file_write_at_check(zpl_file *file, void const *buffer, isize size, i64 offset, isize *bytes_written);
ZPL_DEF b32           zpl_file_read_at       (zpl_file *file, void *buffer, isize size, i64 offset);
ZPL_DEF b32           zpl_file_write_at      (zpl_file *file, void const *buffer, isize size, i64 offset);
ZPL_DEF i64           zpl_file_seek          (zpl_file *file, i64 offset);
ZPL_DEF i64           zpl_file_seek_to_end   (zpl_file *file);
ZPL_DEF i64           zpl_file_skip          (zpl_file *file, i64 bytes); // NOTE: Skips a certain amount of bytes
ZPL_DEF i64           zpl_file_tell          (zpl_file *file);
ZPL_DEF zplFileError  zpl_file_close         (zpl_file *file);
ZPL_DEF b32           zpl_file_read          (zpl_file *file, void *buffer, isize size);
ZPL_DEF b32           zpl_file_write         (zpl_file *file, void const *buffer, isize size);
ZPL_DEF i64           zpl_file_size          (zpl_file *file);
ZPL_DEF char const   *zpl_file_name          (zpl_file *file);
ZPL_DEF zplFileError  zpl_file_truncate      (zpl_file *file, i64 size);
ZPL_DEF b32           zpl_file_has_changed   (zpl_file *file); // NOTE: Changed since lasted checked

#ifdef ZPL_THREADING
ZPL_DEF void zpl_async_file_read(zpl_file *file, zpl_async_file_cb *proc);
ZPL_DEF void zpl_async_file_write(zpl_file *file, void const* buffer, isize size, zpl_async_file_cb *proc);
#endif

zplFileError zpl_file_temp(zpl_file *file);

#define zpl_file_contents_t zpl_file_contents
typedef struct zpl_file_contents {
    zpl_allocator allocator;
    void *      data;
    isize       size;
} zpl_file_contents;


ZPL_DEF zpl_file_contents zpl_file_read_contents(zpl_allocator a, b32 zero_terminate, char const *filepath);
ZPL_DEF void              zpl_file_free_contents(zpl_file_contents *fc);

// NOTE: Make sure you free both the returned buffer and the lines (zpl_array)
ZPL_DEF char             *zpl_file_read_lines   (zpl_allocator alloc, zpl_array(char *) *lines, char const *filename, b32 strip_whitespace);


// TODO: Should these have different names as they do not take in a zpl_file * ???
ZPL_DEF b32           zpl_file_exists         (char const *filepath);
ZPL_DEF zpl_file_time zpl_file_last_write_time(char const *filepath);
ZPL_DEF b32           zpl_file_copy           (char const *existing_filename, char const *new_filename, b32 fail_if_exists);
ZPL_DEF b32           zpl_file_move           (char const *existing_filename, char const *new_filename);
ZPL_DEF b32           zpl_file_remove         (char const *filename);

#ifndef ZPL_PATH_SEPARATOR
#if defined(ZPL_SYSTEM_WINDOWS)
#define ZPL_PATH_SEPARATOR '\\'
#else
#define ZPL_PATH_SEPARATOR '/'
#endif
#endif

ZPL_DEF b32         zpl_path_is_absolute  (char const *path);
ZPL_DEF b32         zpl_path_is_relative  (char const *path);
ZPL_DEF b32         zpl_path_is_root      (char const *path);
ZPL_DEF char const *zpl_path_base_name    (char const *path);
ZPL_DEF char const *zpl_path_extension    (char const *path);
ZPL_DEF char *      zpl_path_get_full_name(zpl_allocator a, char const *path);

ZPL_DEF zplFileError zpl_path_mkdir(char const *path, i32 mode);
ZPL_DEF zplFileError zpl_path_rmdir(char const *path);

// NOTE: Returns file paths terminated by newline (\n)
zpl_string zpl_path_dirlist(zpl_allocator alloc, char const *dirname, b32 recurse);

////////////////////////////////////////////////////////////////
//
// Printing
//
//

ZPL_DEF isize zpl_printf        (char const *fmt, ...) ZPL_PRINTF_ARGS(1);
ZPL_DEF isize zpl_printf_va     (char const *fmt, va_list va);
ZPL_DEF isize zpl_printf_err    (char const *fmt, ...) ZPL_PRINTF_ARGS(1);
ZPL_DEF isize zpl_printf_err_va (char const *fmt, va_list va);
ZPL_DEF isize zpl_fprintf       (zpl_file *f, char const *fmt, ...) ZPL_PRINTF_ARGS(2);
ZPL_DEF isize zpl_fprintf_va    (zpl_file *f, char const *fmt, va_list va);

ZPL_DEF char *zpl_bprintf    (char const *fmt, ...) ZPL_PRINTF_ARGS(1); // NOTE: A locally persisting buffer is used internally
ZPL_DEF char *zpl_bprintf_va (char const *fmt, va_list va);            // NOTE: A locally persisting buffer is used internally
ZPL_DEF isize zpl_snprintf   (char *str, isize n, char const *fmt, ...) ZPL_PRINTF_ARGS(3);
ZPL_DEF isize zpl_snprintf_va(char *str, isize n, char const *fmt, va_list va);

////////////////////////////////////////////////////////////////
//
// DLL Handling
//
//

typedef void *zpl_dll_handle;
typedef void (*zpl_dll_proc)(void);

ZPL_DEF zpl_dll_handle zpl_dll_load        (char const *filepath);
ZPL_DEF void             zpl_dll_unload      (zpl_dll_handle dll);
ZPL_DEF zpl_dll_proc   zpl_dll_proc_address(zpl_dll_handle dll, char const *proc_name);


////////////////////////////////////////////////////////////////
//
// Time
//
//

ZPL_DEF u64  zpl_rdtsc       (void);
ZPL_DEF f64  zpl_time_now    (void); // NOTE: This is only for relative time e.g. game loops
ZPL_DEF f64  zpl_utc_time_now(void); // NOTE: Number of microseconds since 1601-01-01 UTC
ZPL_DEF void zpl_sleep_ms    (u32 ms);


//////////////////////////////////////////////////////
//
// Event handler
//
// Uses hash table to store array of callbacks per
// each valid event type.
//
// Each event callback receives an anonymous pointer
// which has to be casted to proper base type.
//
// Usage:
// - Initialize event pool.
// - Declare your event callbacks and any data layout
//   used by the events.
// - Add event callbacks to the pool. (Returns callback ID.)
// - Trigger arbitrary event in pool with specified dataset.
// - (Optional) Remove arbitrary event callback
//   by refering to it through event type and its callback ID.
//

typedef void *zpl_event_data;

#define ZPL_EVENT(name) void name(zpl_event_data evt)
typedef ZPL_EVENT(zpl_event_cb);

#define ZPL_EVENT_CAST(Type, name) Type * name = cast(Type *)evt

typedef zpl_array(zpl_event_cb*) zpl_event_block;

ZPL_TABLE_DECLARE(static, zpl_event_pool, zpl_event_pool_, zpl_event_block);

ZPL_DEF void zpl_event_init   (zpl_event_pool *pool, zpl_allocator alloc);
ZPL_DEF void zpl_event_destroy(zpl_event_pool *pool);
ZPL_DEF u64  zpl_event_add    (zpl_event_pool *pool, u64 slot, zpl_event_cb cb);
ZPL_DEF void zpl_event_remove (zpl_event_pool *pool, u64 slot, u64 index);
ZPL_DEF void zpl_event_trigger(zpl_event_pool *pool, u64 slot, zpl_event_data evt);


////////////////////////////////////////////////////////////////
//
// Timer
//
//

#define ZPL_TIMER_CB(name) void name(void *user_data)
typedef ZPL_TIMER_CB(zpl_timer_cb);

#define zpl_timer_t zpl_timer
typedef struct zpl_timer {
    zpl_timer_cb *callback;
    b32           enabled;
    i32           remaining_calls;
    i32           initial_calls;
    f64           next_call_ts;
    f64           duration;
    void         *user_data;
} zpl_timer;

typedef zpl_array(zpl_timer) zpl_timer_pool;

ZPL_DEF zpl_timer   *zpl_timer_add(zpl_timer_pool pool);
ZPL_DEF void         zpl_timer_update(zpl_timer_pool pool);

ZPL_DEF void         zpl_timer_set(zpl_timer *timer, f64 /* microseconds */ duration, i32 /* -1 for INFINITY */ count, zpl_timer_cb *callback);
ZPL_DEF void         zpl_timer_start(zpl_timer *timer, f64 delay_start);
ZPL_DEF void         zpl_timer_stop(zpl_timer *timer);

////////////////////////////////////////////////////////////////
//
// Miscellany
//
//

#define zpl_random_t zpl_random
typedef struct zpl_random {
    u32 offsets[8];
    u32 value;
} zpl_random;

// NOTE: Generates from numerous sources to produce a decent pseudo-random seed
ZPL_DEF void  zpl_random_init          (zpl_random *r);
ZPL_DEF u32   zpl_random_gen_u32       (zpl_random *r);
ZPL_DEF u32   zpl_random_gen_u32_unique(zpl_random *r);
ZPL_DEF u64   zpl_random_gen_u64       (zpl_random *r); // NOTE: (zpl_random_gen_u32() << 32) | zpl_random_gen_u32()
ZPL_DEF isize zpl_random_gen_isize     (zpl_random *r);
ZPL_DEF i64   zpl_random_range_i64     (zpl_random *r, i64 lower_inc, i64 higher_inc);
ZPL_DEF isize zpl_random_range_isize   (zpl_random *r, isize lower_inc, isize higher_inc);
ZPL_DEF f64   zpl_random_range_f64     (zpl_random *r, f64 lower_inc, f64 higher_inc);

ZPL_DEF void        zpl_exit     (u32 code);
ZPL_DEF void        zpl_yield    (void);
ZPL_DEF char const *zpl_get_env  (char const *name);
ZPL_DEF void        zpl_set_env  (char const *name, char const *value);
ZPL_DEF void        zpl_unset_env(char const *name);

ZPL_DEF u16 zpl_endian_swap16(u16 i);
ZPL_DEF u32 zpl_endian_swap32(u32 i);
ZPL_DEF u64 zpl_endian_swap64(u64 i);

ZPL_DEF isize zpl_count_set_bits(u64 mask);

ZPL_DEF u32 zpl_system_command(char const *command, usize buffer_len, char *buffer);
ZPL_DEF u32 zpl_system_command_str(char const *command, zpl_array(u8) *str);
#define zpl_system_command_nores(cmd) zpl_system_command_str(cmd, NULL)


////////////////////////////////////////////////////////////////
//
// JSON5 Parser
//
//

#ifdef ZPL_JSON_DEBUG
#define ZPL_JSON_ASSERT ZPL_ASSERT(0)
#else
#define ZPL_JSON_ASSERT
#endif

typedef enum zpljType {
    ZPL_JSON_TYPE_OBJECT,
    ZPL_JSON_TYPE_STRING,
    ZPL_JSON_TYPE_MULTISTRING,
    ZPL_JSON_TYPE_ARRAY,
    ZPL_JSON_TYPE_INTEGER,
    ZPL_JSON_TYPE_REAL,
    ZPL_JSON_TYPE_CONSTANT
} zpljType;

typedef enum zpljProps {
    ZPL_JSON_PROPS_NONE         = 0,
    ZPL_JSON_PROPS_NAN          = 1,
    ZPL_JSON_PROPS_NAN_NEG      = 2,
    ZPL_JSON_PROPS_INFINITY     = 3,
    ZPL_JSON_PROPS_INFINITY_NEG = 4,
    ZPL_JSON_PROPS_IS_EXP       = 5,
    ZPL_JSON_PROPS_IS_HEX       = 6,
} zpljProps;

typedef enum zpljConst {
    ZPL_JSON_CONST_NULL,
    ZPL_JSON_CONST_FALSE,
    ZPL_JSON_CONST_TRUE,
} zpljConst;

// TODO(ZaKlaus): Error handling
typedef enum zpljError {
    ZPL_JSON_ERROR_NONE,
    ZPL_JSON_ERROR_INVALID_NAME,
    ZPL_JSON_ERROR_INVALID_VALUE,
} zpljError;

typedef enum zpljNameStyle {
    ZPL_JSON_NAME_STYLE_DOUBLE_QUOTE,
    ZPL_JSON_NAME_STYLE_SINGLE_QUOTE,
    ZPL_JSON_NAME_STYLE_NO_QUOTES,
} zpljNameStyle;

#define zpl_json_object_t zpl_json_object
typedef struct zpl_json_object {
    zpl_allocator backing;
    u8    name_style;
    char *name;
    u8    type;
    u8    props;
    b32   cfg_mode;
    zpl_array(struct zpl_json_object) nodes;

    union {
        char *string;
        zpl_array(struct zpl_json_object) elements;
        i64   integer;
        struct {
            f64 real;
            i64 base;
            i64 base2;
            i64 exp;
            b32 exp_neg;
            b32 lead_digit;
            u8  frac;
        };
        u8    constant;
    };
} zpl_json_object;

ZPL_DEF void zpl_json_parse(zpl_json_object *root, usize len, char *const source, zpl_allocator a, b32 strip_comments, u8 *err_code);
ZPL_DEF void zpl_json_write(zpl_file *f, zpl_json_object *o, isize indent);
ZPL_DEF void zpl_json_free (zpl_json_object *obj);

ZPL_DEF char *zpl__json_parse_object(zpl_json_object *obj, char *base, zpl_allocator a, u8 *err_code);
ZPL_DEF char *zpl__json_parse_value (zpl_json_object *obj, char *base, zpl_allocator a, u8 *err_code);
ZPL_DEF char *zpl__json_parse_array (zpl_json_object *obj, char *base, zpl_allocator a, u8 *err_code);

// TODO: Make it generic
#define zpl__trim zpl__json_trim
#define zpl__skip zpl__json_skip
ZPL_DEF char *zpl__json_trim        (char *str);
ZPL_DEF char *zpl__json_skip        (char *str, char c);
ZPL_DEF b32 zpl__json_validate_name (char *str, char *err);


////////////////////////////////////////////////////////////////
//
// CLI Options
//
//
/*
int main(int argc, char **argv)
{
    zpl_opts opts={0};

    zpl_opts_init(&opts, zpl_heap(), argv[0]);

    zpl_opts_add(&opts, "?", "help", "the HELP section", ZPL_OPTS_FLAG);
    zpl_opts_add(&opts, "f", "foo", "the test *foo* entry.", ZPL_OPTS_STRING);
    zpl_opts_add(&opts, "p", "pi", "PI Value Redefined !!!", ZPL_OPTS_FLOAT);
    zpl_opts_add(&opts, "4", "4pay", "hmmmm", ZPL_OPTS_INT);
    zpl_opts_add(&opts, "E", "enablegfx", "Enables HD resource pack", ZPL_OPTS_FLAG);

    zpl_opts_positional_add(&opts, "4pay");

    b32 ok=zpl_opts_compile(&opts, argc, argv);

    if (ok && zpl_opts_positionals_filled(&opts)) {

        b32 help=zpl_opts_has_arg(&opts, "help");
        if (help) {
            zpl_opts_print_help(&opts);
            return 0;
        }
        zpl_string foo=zpl_opts_string(&opts, "foo", "WRONG!");
        f64 some_num=zpl_opts_real(&opts, "pi", 0.0);
        i32 right=zpl_opts_integer(&opts, "4pay", 42);
        zpl_printf("The arg is %s\nPI value is: %f\nright: %d?\n", foo, some_num,
                                                                right);

        b32 gfx=zpl_opts_has_arg(&opts, "enablegfx");
        if (gfx) {
            zpl_printf("You wanted HD graphics? Here:\n\n");
            for (int i=0; i<5; ++i) {
                zpl_printf("iiiii\n");
            }
        }
    }
    else {
        zpl_opts_print_errors(&opts);
        zpl_opts_print_help(&opts);
    }

    return 0;
}
*/

typedef enum {
    ZPL_OPTS_STRING,
    ZPL_OPTS_FLOAT,
    ZPL_OPTS_FLAG,
    ZPL_OPTS_INT,
} zpl_opts_types;

typedef struct {
    char const *name, *lname, *desc;
    u8 type;
    b32 met, pos;

    union {
        zpl_string text;
        i64 integer;
        f64 real;
    };
} zpl_opts_entry;

typedef enum {
    ZPL_OPTS_ERR_VALUE,
    ZPL_OPTS_ERR_OPTION,
    ZPL_OPTS_ERR_EXTRA_VALUE,
    ZPL_OPTS_ERR_MISSING_VALUE,
} zpl_opts_err_type;

typedef struct {
    char *val;
    u8 type;
} zpl_opts_err;

typedef struct {
    zpl_allocator alloc;
    zpl_array(zpl_opts_entry) entries;
    zpl_array(zpl_opts_err) errors;
    zpl_array(zpl_opts_entry *) positioned;
    char const *appname;
} zpl_opts;


ZPL_DEF void zpl_opts_init(zpl_opts *opts, zpl_allocator a, char const *app);
ZPL_DEF void zpl_opts_free(zpl_opts *opts);
ZPL_DEF void zpl_opts_add(zpl_opts *opts, char const *name, char const *lname, const char *desc, u8 type);
ZPL_DEF void zpl_opts_positional_add(zpl_opts *opts, char const *name);
ZPL_DEF b32  zpl_opts_compile(zpl_opts *opts, int argc, char **argv);
ZPL_DEF void zpl_opts_print_help(zpl_opts *opts);
ZPL_DEF void zpl_opts_print_errors(zpl_opts *opts);
ZPL_DEF zpl_string zpl_opts_string(zpl_opts *opts, char const *name, char const *fallback);
ZPL_DEF f64 zpl_opts_real(zpl_opts *opts, char const *name, f64 fallback);
ZPL_DEF i64 zpl_opts_integer(zpl_opts *opts, char const *name, i64 fallback);
ZPL_DEF b32 zpl_opts_has_arg(zpl_opts *opts, char const *name);
ZPL_DEF b32 zpl_opts_positionals_filled(zpl_opts *opts);

///////////////////////////////////////////////////////////////
//
// Thread Pool
//
// This job system follows thread pool pattern to minimize the costs of thread initialization.
// It reuses fixed number of threads to process variable number of jobs.
//
/*
#define TEST_ENQUEUE_JOB 0.8

zpl_mutex print_mut;

ZPL_JOBS_PROC(calc_nums)
{
    zpl_unused(data);
    i64 nums=0;
    zpl_random rnd={0};
    zpl_random_init(&rnd);

    for (int i=0; i<100; ++i) {
        nums+=(zpl_random_gen_u64(&rnd) & 100);
    }

    //zpl_sleep_ms(50*zpl_random_range_i64(&rnd, 2, 8));

    zpl_mutex_lock(&print_mut);
    zpl_printf("Result is: %ld\n", nums);
    zpl_mutex_unlock(&print_mut);
}

int main()
{
    zpl_random rng={0};
    zpl_thread_pool p={0};
    zpl_jobs_init(&p, zpl_heap(), 2);
    zpl_random_init(&rng);
    zpl_mutex_init(&print_mut);

    zpl_jobs_enqueue(&p, calc_nums, NULL);

    f64 time=zpl_time_now();

    for (;;) {
        f64 now=zpl_time_now();
        f64 dt =now-time;
        if (dt > TEST_ENQUEUE_JOB) {
            time=now;
            zpl_jobs_enqueue(&p, calc_nums, NULL);
        }

        zpl_jobs_process(&p);
    }

    return 0;
}
*/

#ifdef ZPL_THREADING
#define ZPL_JOBS_PROC(name) void name(void *data)
typedef ZPL_JOBS_PROC(zpl_jobs_proc);

#define ZPL_INVALID_JOB U32_MAX

typedef enum {
    ZPL_JOBS_STATUS_READY,
    ZPL_JOBS_STATUS_BUSY,
    ZPL_JOBS_STATUS_WAITING,
    ZPL_JOBS_STATUS_TERM,
} zpl_jobs_status;

typedef struct {
    zpl_jobs_proc *proc;
    void *data;

    i32 priority;
} zpl_thread_job;

typedef struct {
    zpl_thread thread;
    zpl_atomic32 status;
    u32 jobid;
    void *pool;
} zpl_thread_worker;

typedef struct {
    zpl_allocator alloc;
    u32 max_threads;
    f32 job_spawn_treshold;
    zpl_mutex access;
    zpl_buffer(zpl_thread_worker) workers;
    zpl_array(zpl_thread_job) jobs;
    zpl_array(u32) queue;
    zpl_array(u32) available;
} zpl_thread_pool;

ZPL_DEF void zpl_jobs_init(zpl_thread_pool *pool, zpl_allocator a, u32 max_threads);
ZPL_DEF void zpl_jobs_free(zpl_thread_pool *pool);
ZPL_DEF void zpl_jobs_enqueue(zpl_thread_pool *pool, zpl_jobs_proc proc, void *data);
ZPL_DEF void zpl_jobs_enqueue_with_priority(zpl_thread_pool *pool, zpl_jobs_proc proc, void *data, i32 priority);
ZPL_DEF b32  zpl_jobs_process(zpl_thread_pool *pool);
#endif

////////////////////////////////////////////////////////////////
//
// Math
//

#define zpl_vec2_t zpl_vec2
typedef union zpl_vec2 {
    struct {
        f32 x, y;
    };
    f32 e[2];
} zpl_vec2;

#define zpl_vec3_t zpl_vec3
typedef union zpl_vec3 {
    struct {
        f32 x, y, z;
    };
    struct {
        f32 r, g, b;
    };

    zpl_vec2 xy;
    f32 e[3];
} zpl_vec3;

#define zpl_vec4_t zpl_vec4
typedef union zpl_vec4 {
    struct {
        f32 x, y, z, w;
    };
    struct {
        f32 r, g, b, a;
    };
    struct {
        zpl_vec2 xy, zw;
    };
    zpl_vec3 xyz;
    zpl_vec3 rgb;
    f32 e[4];
} zpl_vec4;

#define zpl_mat2_t zpl_mat2
typedef union zpl_mat2 {
    struct {
        zpl_vec2 x, y;
    };
    zpl_vec2 col[2];
    f32 e[4];
} zpl_mat2;

#define zpl_mat3_t zpl_mat3
typedef union zpl_mat3 {
    struct {
        zpl_vec3 x, y, z;
    };
    zpl_vec3 col[3];
    f32 e[9];
} zpl_mat3;

#define zpl_mat4_t zpl_mat4
typedef union zpl_mat4 {
    struct {
        zpl_vec4 x, y, z, w;
    };
    zpl_vec4 col[4];
    f32 e[16];
} zpl_mat4;

#define zpl_quat_t zpl_quat
typedef union zpl_quat {
    struct {
        f32 x, y, z, w;
    };
    zpl_vec4 xyzw;
    zpl_vec3 xyz;
    f32 e[4];
} zpl_quat;

typedef f32 zpl_float2[2];
typedef f32 zpl_float3[3];
typedef f32 zpl_float4[4];

typedef struct zpl_rect2 {
    zpl_vec2 pos, dim;
} zpl_rect2;
typedef struct zpl_rect3 {
    zpl_vec3 pos, dim;
} zpl_rect3;

typedef struct zpl_aabb2 {
    zpl_vec2 centre, half_size;
} zpl_aabb2;
typedef struct zpl_aabb3 {
    zpl_vec3 centre, half_size;
} zpl_aabb3;

typedef short zpl_half;

#ifndef ZPL_CONSTANTS
#define ZPL_CONSTANTS
#define ZPL_EPSILON 1.19209290e-7f
#define ZPL_ZERO 0.0f
#define ZPL_ONE 1.0f
#define ZPL_TWO_THIRDS 0.666666666666666666666666666666666666667f

#define ZPL_TAU 6.28318530717958647692528676655900576f
#define ZPL_PI 3.14159265358979323846264338327950288f
#define ZPL_ONE_OVER_TAU 0.636619772367581343075535053490057448f
#define ZPL_ONE_OVER_PI 0.159154943091895335768883763372514362f

#define ZPL_TAU_OVER_2 3.14159265358979323846264338327950288f
#define ZPL_TAU_OVER_4 1.570796326794896619231321691639751442f
#define ZPL_TAU_OVER_8 0.785398163397448309615660845819875721f

#define ZPL_E 2.71828182845904523536f
#define ZPL_SQRT_TWO 1.41421356237309504880168872420969808f
#define ZPL_SQRT_THREE 1.73205080756887729352744634150587236f
#define ZPL_SQRT_FIVE 2.23606797749978969640917366873127623f

#define ZPL_LOG_TWO 0.693147180559945309417232121458176568f
#define ZPL_LOG_TEN 2.30258509299404568401799145468436421f
#endif

#ifndef zpl_square
#define zpl_square(x) ((x) * (x))
#endif

#ifndef zpl_cube
#define zpl_cube(x) ((x) * (x) * (x))
#endif

#ifndef zpl_sign
#define zpl_sign(x) ((x) >= 0 ? 1 : -1)
#endif

ZPL_DEF f32 zpl_to_radians(f32 degrees);
ZPL_DEF f32 zpl_to_degrees(f32 radians);

/* NOTE: Because to interpolate angles */
ZPL_DEF f32 zpl_angle_diff(f32 radians_a, f32 radians_b);

ZPL_DEF f32 zpl_copy_sign(f32 x, f32 y);
ZPL_DEF f32 zpl_remainder(f32 x, f32 y);
ZPL_DEF f32 zpl_mod(f32 x, f32 y);
ZPL_DEF f64 zpl_copy_sign64(f64 x, f64 y);
ZPL_DEF f64 zpl_floor64    (f64 x);
ZPL_DEF f64 zpl_ceil64     (f64 x);
ZPL_DEF f64 zpl_round64    (f64 x);
ZPL_DEF f64 zpl_remainder64(f64 x, f64 y);
ZPL_DEF f64 zpl_abs64      (f64 x);
ZPL_DEF f64 zpl_sign64     (f64 x);
ZPL_DEF f64 zpl_mod64(f64 x, f64 y);
ZPL_DEF f32 zpl_sqrt(f32 a);
ZPL_DEF f32 zpl_rsqrt(f32 a);
ZPL_DEF f32 zpl_quake_rsqrt(f32 a); /* NOTE: It's probably better to use 1.0f/zpl_sqrt(a)
                                          * And for simd, there is usually isqrt functions too!
                                          */
ZPL_DEF f32 zpl_sin(f32 radians);
ZPL_DEF f32 zpl_cos(f32 radians);
ZPL_DEF f32 zpl_tan(f32 radians);
ZPL_DEF f32 zpl_arcsin(f32 a);
ZPL_DEF f32 zpl_arccos(f32 a);
ZPL_DEF f32 zpl_arctan(f32 a);
ZPL_DEF f32 zpl_arctan2(f32 y, f32 x);

ZPL_DEF f32 zpl_exp(f32 x);
ZPL_DEF f32 zpl_exp2(f32 x);
ZPL_DEF f32 zpl_log(f32 x);
ZPL_DEF f32 zpl_log2(f32 x);
ZPL_DEF f32 zpl_fast_exp(f32 x);     /* NOTE: Only valid from -1 <= x <= +1 */
ZPL_DEF f32 zpl_fast_exp2(f32 x);    /* NOTE: Only valid from -1 <= x <= +1 */
ZPL_DEF f32 zpl_pow(f32 x, f32 y); /* x^y */

ZPL_DEF f32 zpl_round(f32 x);
ZPL_DEF f32 zpl_floor(f32 x);
ZPL_DEF f32 zpl_ceil(f32 x);

ZPL_DEF f32 zpl_half_to_float(zpl_half value);
ZPL_DEF zpl_half zpl_float_to_half(f32 value);

ZPL_DEF zpl_vec2 zpl_vec2f_zero(void);
ZPL_DEF zpl_vec2 zpl_vec2f(f32 x, f32 y);
ZPL_DEF zpl_vec2 zpl_vec2fv(f32 x[2]);

ZPL_DEF zpl_vec3 zpl_vec3f_zero(void);
ZPL_DEF zpl_vec3 zpl_vec3f(f32 x, f32 y, f32 z);
ZPL_DEF zpl_vec3 zpl_vec3fv(f32 x[3]);

ZPL_DEF zpl_vec4 zpl_vec4f_zero(void);
ZPL_DEF zpl_vec4 zpl_vec4f(f32 x, f32 y, f32 z, f32 w);
ZPL_DEF zpl_vec4 zpl_vec4fv(f32 x[4]);

ZPL_DEF void zpl_vec2_add(zpl_vec2 *d, zpl_vec2 v0, zpl_vec2 v1);
ZPL_DEF void zpl_vec2_sub(zpl_vec2 *d, zpl_vec2 v0, zpl_vec2 v1);
ZPL_DEF void zpl_vec2_mul(zpl_vec2 *d, zpl_vec2 v, f32 s);
ZPL_DEF void zpl_vec2_div(zpl_vec2 *d, zpl_vec2 v, f32 s);

ZPL_DEF void zpl_vec3_add(zpl_vec3 *d, zpl_vec3 v0, zpl_vec3 v1);
ZPL_DEF void zpl_vec3_sub(zpl_vec3 *d, zpl_vec3 v0, zpl_vec3 v1);
ZPL_DEF void zpl_vec3_mul(zpl_vec3 *d, zpl_vec3 v, f32 s);
ZPL_DEF void zpl_vec3_div(zpl_vec3 *d, zpl_vec3 v, f32 s);

ZPL_DEF void zpl_vec4_add(zpl_vec4 *d, zpl_vec4 v0, zpl_vec4 v1);
ZPL_DEF void zpl_vec4_sub(zpl_vec4 *d, zpl_vec4 v0, zpl_vec4 v1);
ZPL_DEF void zpl_vec4_mul(zpl_vec4 *d, zpl_vec4 v, f32 s);
ZPL_DEF void zpl_vec4_div(zpl_vec4 *d, zpl_vec4 v, f32 s);

ZPL_DEF void zpl_vec2_addeq(zpl_vec2 *d, zpl_vec2 v);
ZPL_DEF void zpl_vec2_subeq(zpl_vec2 *d, zpl_vec2 v);
ZPL_DEF void zpl_vec2_muleq(zpl_vec2 *d, f32 s);
ZPL_DEF void zpl_vec2_diveq(zpl_vec2 *d, f32 s);

ZPL_DEF void zpl_vec3_addeq(zpl_vec3 *d, zpl_vec3 v);
ZPL_DEF void zpl_vec3_subeq(zpl_vec3 *d, zpl_vec3 v);
ZPL_DEF void zpl_vec3_muleq(zpl_vec3 *d, f32 s);
ZPL_DEF void zpl_vec3_diveq(zpl_vec3 *d, f32 s);

ZPL_DEF void zpl_vec4_addeq(zpl_vec4 *d, zpl_vec4 v);
ZPL_DEF void zpl_vec4_subeq(zpl_vec4 *d, zpl_vec4 v);
ZPL_DEF void zpl_vec4_muleq(zpl_vec4 *d, f32 s);
ZPL_DEF void zpl_vec4_diveq(zpl_vec4 *d, f32 s);

ZPL_DEF f32 zpl_vec2_dot(zpl_vec2 v0, zpl_vec2 v1);
ZPL_DEF f32 zpl_vec3_dot(zpl_vec3 v0, zpl_vec3 v1);
ZPL_DEF f32 zpl_vec4_dot(zpl_vec4 v0, zpl_vec4 v1);

ZPL_DEF void zpl_vec2_cross(f32 *d, zpl_vec2 v0, zpl_vec2 v1);
ZPL_DEF void zpl_vec3_cross(zpl_vec3 *d, zpl_vec3 v0, zpl_vec3 v1);

ZPL_DEF f32 zpl_vec2_mag2(zpl_vec2 v);
ZPL_DEF f32 zpl_vec3_mag2(zpl_vec3 v);
ZPL_DEF f32 zpl_vec4_mag2(zpl_vec4 v);

ZPL_DEF f32 zpl_vec2_mag(zpl_vec2 v);
ZPL_DEF f32 zpl_vec3_mag(zpl_vec3 v);
ZPL_DEF f32 zpl_vec4_mag(zpl_vec4 v);

ZPL_DEF void zpl_vec2_norm(zpl_vec2 *d, zpl_vec2 v);
ZPL_DEF void zpl_vec3_norm(zpl_vec3 *d, zpl_vec3 v);
ZPL_DEF void zpl_vec4_norm(zpl_vec4 *d, zpl_vec4 v);

ZPL_DEF void zpl_vec2_norm0(zpl_vec2 *d, zpl_vec2 v);
ZPL_DEF void zpl_vec3_norm0(zpl_vec3 *d, zpl_vec3 v);
ZPL_DEF void zpl_vec4_norm0(zpl_vec4 *d, zpl_vec4 v);

ZPL_DEF void zpl_vec2_reflect(zpl_vec2 *d, zpl_vec2 i, zpl_vec2 n);
ZPL_DEF void zpl_vec3_reflect(zpl_vec3 *d, zpl_vec3 i, zpl_vec3 n);
ZPL_DEF void zpl_vec2_refract(zpl_vec2 *d, zpl_vec2 i, zpl_vec2 n, f32 eta);
ZPL_DEF void zpl_vec3_refract(zpl_vec3 *d, zpl_vec3 i, zpl_vec3 n, f32 eta);

ZPL_DEF f32 zpl_vec2_aspect_ratio(zpl_vec2 v);

ZPL_DEF void zpl_mat2_identity(zpl_mat2 *m);
ZPL_DEF void zpl_float22_identity(f32 m[2][2]);

ZPL_DEF void zpl_mat2_transpose(zpl_mat2 *m);
ZPL_DEF void zpl_mat2_mul(zpl_mat2 *out, zpl_mat2 *m1, zpl_mat2 *m2);
ZPL_DEF void zpl_mat2_mul_vec2(zpl_vec2 *out, zpl_mat2 *m, zpl_vec2 in);
ZPL_DEF void zpl_mat2_inverse(zpl_mat2 *out, zpl_mat2 *in);
ZPL_DEF f32 zpl_mat2_determinate(zpl_mat2 *m);

ZPL_DEF zpl_mat2 *zpl_mat2_v(zpl_vec2 m[2]);
ZPL_DEF zpl_mat2 *zpl_mat2_f(f32 m[2][2]);
ZPL_DEF zpl_float2 *zpl_float22_m(zpl_mat2 *m);
ZPL_DEF zpl_float2 *zpl_float22_v(zpl_vec2 m[2]);
ZPL_DEF zpl_float2 *zpl_float22_4(f32 m[4]);

ZPL_DEF void zpl_float22_transpose(f32 (*vec)[2]);
ZPL_DEF void zpl_float22_mul(f32 (*out)[2], f32 (*mat1)[2], f32 (*mat2)[2]);
ZPL_DEF void zpl_float22_mul_vec2(zpl_vec2 *out, f32 m[2][2], zpl_vec2 in);

ZPL_DEF void zpl_mat3_identity(zpl_mat3 *m);
ZPL_DEF void zpl_float33_identity(f32 m[3][3]);

ZPL_DEF void zpl_mat3_transpose(zpl_mat3 *m);
ZPL_DEF void zpl_mat3_mul(zpl_mat3 *out, zpl_mat3 *m1, zpl_mat3 *m2);
ZPL_DEF void zpl_mat3_mul_vec3(zpl_vec3 *out, zpl_mat3 *m, zpl_vec3 in);
ZPL_DEF void zpl_mat3_inverse(zpl_mat3 *out, zpl_mat3 *in);
ZPL_DEF f32 zpl_mat3_determinate(zpl_mat3 *m);

ZPL_DEF zpl_mat3 *zpl_mat3_v(zpl_vec3 m[3]);
ZPL_DEF zpl_mat3 *zpl_mat3_f(f32 m[3][3]);

ZPL_DEF zpl_float3 *zpl_float33_m(zpl_mat3 *m);
ZPL_DEF zpl_float3 *zpl_float33_v(zpl_vec3 m[3]);
ZPL_DEF zpl_float3 *zpl_float33_9(f32 m[9]);

ZPL_DEF void zpl_float33_transpose(f32 (*vec)[3]);
ZPL_DEF void zpl_float33_mul(f32 (*out)[3], f32 (*mat1)[3], f32 (*mat2)[3]);
ZPL_DEF void zpl_float33_mul_vec3(zpl_vec3 *out, f32 m[3][3], zpl_vec3 in);

ZPL_DEF void zpl_mat4_identity(zpl_mat4 *m);
ZPL_DEF void zpl_float44_identity(f32 m[4][4]);

ZPL_DEF void zpl_mat4_transpose(zpl_mat4 *m);
ZPL_DEF void zpl_mat4_mul(zpl_mat4 *out, zpl_mat4 *m1, zpl_mat4 *m2);
ZPL_DEF void zpl_mat4_mul_vec4(zpl_vec4 *out, zpl_mat4 *m, zpl_vec4 in);
ZPL_DEF void zpl_mat4_inverse(zpl_mat4 *out, zpl_mat4 *in);

ZPL_DEF zpl_mat4 *zpl_mat4_v(zpl_vec4 m[4]);
ZPL_DEF zpl_mat4 *zpl_mat4_f(f32 m[4][4]);

ZPL_DEF zpl_float4 *zpl_float44_m(zpl_mat4 *m);
ZPL_DEF zpl_float4 *zpl_float44_v(zpl_vec4 m[4]);
ZPL_DEF zpl_float4 *zpl_float44_16(f32 m[16]);

ZPL_DEF void zpl_float44_transpose(f32 (*vec)[4]);
ZPL_DEF void zpl_float44_mul(f32 (*out)[4], f32 (*mat1)[4], f32 (*mat2)[4]);
ZPL_DEF void zpl_float44_mul_vec4(zpl_vec4 *out, f32 m[4][4], zpl_vec4 in);

ZPL_DEF void zpl_mat4_translate(zpl_mat4 *out, zpl_vec3 v);
ZPL_DEF void zpl_mat4_rotate(zpl_mat4 *out, zpl_vec3 v, f32 angle_radians);
ZPL_DEF void zpl_mat4_scale(zpl_mat4 *out, zpl_vec3 v);
ZPL_DEF void zpl_mat4_scalef(zpl_mat4 *out, f32 s);
ZPL_DEF void zpl_mat4_ortho2d(zpl_mat4 *out, f32 left, f32 right, f32 bottom, f32 top);
ZPL_DEF void zpl_mat4_ortho3d(zpl_mat4 *out, f32 left, f32 right, f32 bottom, f32 top, f32 z_near,
                               f32 z_far);
ZPL_DEF void zpl_mat4_perspective(zpl_mat4 *out, f32 fovy, f32 aspect, f32 z_near, f32 z_far);
ZPL_DEF void zpl_mat4_infinite_perspective(zpl_mat4 *out, f32 fovy, f32 aspect, f32 z_near);

ZPL_DEF void zpl_mat4_look_at(zpl_mat4 *out, zpl_vec3 eye, zpl_vec3 centre, zpl_vec3 up);

ZPL_DEF zpl_quat zpl_quatf(f32 x, f32 y, f32 z, f32 w);
ZPL_DEF zpl_quat zpl_quatfv(f32 e[4]);
ZPL_DEF zpl_quat zpl_quat_axis_angle(zpl_vec3 axis, f32 angle_radians);
ZPL_DEF zpl_quat zpl_quat_euler_angles(f32 pitch, f32 yaw, f32 roll);
ZPL_DEF zpl_quat zpl_quat_identity(void);

ZPL_DEF void zpl_quat_add(zpl_quat *d, zpl_quat q0, zpl_quat q1);
ZPL_DEF void zpl_quat_sub(zpl_quat *d, zpl_quat q0, zpl_quat q1);
ZPL_DEF void zpl_quat_mul(zpl_quat *d, zpl_quat q0, zpl_quat q1);
ZPL_DEF void zpl_quat_div(zpl_quat *d, zpl_quat q0, zpl_quat q1);

ZPL_DEF void zpl_quat_mulf(zpl_quat *d, zpl_quat q, f32 s);
ZPL_DEF void zpl_quat_divf(zpl_quat *d, zpl_quat q, f32 s);

ZPL_DEF void zpl_quat_addeq(zpl_quat *d, zpl_quat q);
ZPL_DEF void zpl_quat_subeq(zpl_quat *d, zpl_quat q);
ZPL_DEF void zpl_quat_muleq(zpl_quat *d, zpl_quat q);
ZPL_DEF void zpl_quat_diveq(zpl_quat *d, zpl_quat q);

ZPL_DEF void zpl_quat_muleqf(zpl_quat *d, f32 s);
ZPL_DEF void zpl_quat_diveqf(zpl_quat *d, f32 s);

ZPL_DEF f32 zpl_quat_dot(zpl_quat q0, zpl_quat q1);
ZPL_DEF f32 zpl_quat_mag(zpl_quat q);

ZPL_DEF void zpl_quat_norm(zpl_quat *d, zpl_quat q);
ZPL_DEF void zpl_quat_conj(zpl_quat *d, zpl_quat q);
ZPL_DEF void zpl_quat_inverse(zpl_quat *d, zpl_quat q);

ZPL_DEF void zpl_quat_axis(zpl_vec3 *axis, zpl_quat q);
ZPL_DEF f32 zpl_quat_angle(zpl_quat q);

ZPL_DEF f32 zpl_quat_pitch(zpl_quat q);
ZPL_DEF f32 zpl_quat_yaw(zpl_quat q);
ZPL_DEF f32 zpl_quat_roll(zpl_quat q);

/* NOTE: Rotate v by q */
ZPL_DEF void zpl_quat_rotate_vec3(zpl_vec3 *d, zpl_quat q, zpl_vec3 v);
ZPL_DEF void zpl_mat4_from_quat(zpl_mat4 *out, zpl_quat q);
ZPL_DEF void zpl_quat_from_mat4(zpl_quat *out, zpl_mat4 *m);

/* Interpolations */
ZPL_DEF f32 zpl_lerp(f32 a, f32 b, f32 t);
ZPL_DEF f32 zpl_unlerp(f32 t, f32 a, f32 b);
ZPL_DEF f32 zpl_smooth_step(f32 a, f32 b, f32 t);
ZPL_DEF f32 zpl_smoother_step(f32 a, f32 b, f32 t);

ZPL_DEF void zpl_vec2_lerp(zpl_vec2 *d, zpl_vec2 a, zpl_vec2 b, f32 t);
ZPL_DEF void zpl_vec3_lerp(zpl_vec3 *d, zpl_vec3 a, zpl_vec3 b, f32 t);
ZPL_DEF void zpl_vec4_lerp(zpl_vec4 *d, zpl_vec4 a, zpl_vec4 b, f32 t);

ZPL_DEF void zpl_vec2_cslerp(zpl_vec2 *d, zpl_vec2 a, zpl_vec2 v0, zpl_vec2 b, zpl_vec2 v1, f32 t);
ZPL_DEF void zpl_vec3_cslerp(zpl_vec3 *d, zpl_vec3 a, zpl_vec3 v0, zpl_vec3 b, zpl_vec3 v1, f32 t);
ZPL_DEF void zpl_vec2_dcslerp(zpl_vec2 *d, zpl_vec2 a, zpl_vec2 v0, zpl_vec2 b, zpl_vec2 v1, f32 t);
ZPL_DEF void zpl_vec3_dcslerp(zpl_vec3 *d, zpl_vec3 a, zpl_vec3 v0, zpl_vec3 b, zpl_vec3 v1, f32 t);

ZPL_DEF void zpl_quat_lerp(zpl_quat *d, zpl_quat a, zpl_quat b, f32 t);
ZPL_DEF void zpl_quat_nlerp(zpl_quat *d, zpl_quat a, zpl_quat b, f32 t);
ZPL_DEF void zpl_quat_slerp(zpl_quat *d, zpl_quat a, zpl_quat b, f32 t);
ZPL_DEF void zpl_quat_nquad(zpl_quat *d, zpl_quat p, zpl_quat a, zpl_quat b, zpl_quat q, f32 t);
ZPL_DEF void zpl_quat_squad(zpl_quat *d, zpl_quat p, zpl_quat a, zpl_quat b, zpl_quat q, f32 t);
ZPL_DEF void zpl_quat_slerp_approx(zpl_quat *d, zpl_quat a, zpl_quat b, f32 t);
ZPL_DEF void zpl_quat_squad_approx(zpl_quat *d, zpl_quat p, zpl_quat a, zpl_quat b, zpl_quat q, f32 t);

/* Rects */
ZPL_DEF zpl_rect2 zpl_rect2f(zpl_vec2 pos, zpl_vec2 dim);
ZPL_DEF zpl_rect3 zpl_rect3f(zpl_vec3 pos, zpl_vec3 dim);

ZPL_DEF int zpl_rect2_contains(zpl_rect2 a, f32 x, f32 y);
ZPL_DEF int zpl_rect2_contains_vec2(zpl_rect2 a, zpl_vec2 p);
ZPL_DEF int zpl_rect2_intersects(zpl_rect2 a, zpl_rect2 b);
ZPL_DEF int zpl_rect2_intersection_result(zpl_rect2 a, zpl_rect2 b, zpl_rect2 *intersection);

#ifndef ZPL_MURMUR64_DEFAULT_SEED
#define ZPL_MURMUR64_DEFAULT_SEED 0x9747b28c
#endif

////////////////////////////////////////////////////////////////
//
// Platform Stuff
//
// Ported from https://github.com/gingerBill/zpl/
//

#if defined(ZPL_PLATFORM)

// NOTE(bill):
// Coordinate system - +ve x - left to right
//                  - +ve y - bottom to top
//                  - Relative to window

// TODO(bill): Proper documentation for this with code examples

// Window Support - Complete
// OS X Support (Not ported yet) - Missing:
//     * Software framebuffer
//     * (show|hide) window
//     * show_cursor
//     * toggle (fullscreen|borderless)
//     * set window position
//     * Clipboard
//     * GameControllers
// Linux Support - None
// Other OS Support - None

#ifndef ZPL_MAX_GAME_CONTROLLER_COUNT
#define ZPL_MAX_GAME_CONTROLLER_COUNT 4
#endif

typedef enum zplKeyType {
    ZPL_KEY_UNKNOWN = 0, // Unhandled key

    // NOTE(bill): Allow the basic printable keys to be aliased with their chars
    ZPL_KEY_0 = '0',
    ZPL_KEY_1,
    ZPL_KEY_2,
    ZPL_KEY_3,
    ZPL_KEY_4,
    ZPL_KEY_5,
    ZPL_KEY_6,
    ZPL_KEY_7,
    ZPL_KEY_8,
    ZPL_KEY_9,

    ZPL_KEY_A = 'A',
    ZPL_KEY_B,
    ZPL_KEY_C,
    ZPL_KEY_D,
    ZPL_KEY_E,
    ZPL_KEY_F,
    ZPL_KEY_G,
    ZPL_KEY_H,
    ZPL_KEY_I,
    ZPL_KEY_J,
    ZPL_KEY_K,
    ZPL_KEY_L,
    ZPL_KEY_M,
    ZPL_KEY_N,
    ZPL_KEY_O,
    ZPL_KEY_P,
    ZPL_KEY_Q,
    ZPL_KEY_R,
    ZPL_KEY_S,
    ZPL_KEY_T,
    ZPL_KEY_U,
    ZPL_KEY_V,
    ZPL_KEY_W,
    ZPL_KEY_X,
    ZPL_KEY_Y,
    ZPL_KEY_Z,

    ZPL_KEY_LBRACKET = '[',
    ZPL_KEY_RBRACKET = ']',
    ZPL_KEY_SEMICOLON = ';',
    ZPL_KEY_COMMA = ',',
    ZPL_KEY_PERIOD = '.',
    ZPL_KEY_QUOTE = '\'',
    ZPL_KEY_SLASH = '/',
    ZPL_KEY_BACKSLASH = '\\',
    ZPL_KEY_GRAVE = '`',
    ZPL_KEY_EQUALS = '=',
    ZPL_KEY_MINUS = '-',
    ZPL_KEY_SPACE = ' ',

    ZPL_KEY__PAD = 128, // NOTE(BILL): MAKE SURE ASCII IS RESERVED

    ZPL_KEY_ESCAPE,      // ESCAPE
    ZPL_KEY_LCONTROL,    // LEFT CONTROL
    ZPL_KEY_LSHIFT,      // LEFT SHIFT
    ZPL_KEY_LALT,        // LEFT ALT
    ZPL_KEY_LSYSTEM,     // LEFT OS SPECIFIC: WINDOW (WINDOWS AND LINUX), APPLE/CMD (MACOS X), ...
    ZPL_KEY_RCONTROL,    // RIGHT CONTROL
    ZPL_KEY_RSHIFT,      // RIGHT SHIFT
    ZPL_KEY_RALT,        // RIGHT ALT
    ZPL_KEY_RSYSTEM,     // RIGHT OS SPECIFIC: WINDOW (WINDOWS AND LINUX), APPLE/CMD (MACOS X), ...
    ZPL_KEY_MENU,        // MENU
    ZPL_KEY_RETURN,      // RETURN
    ZPL_KEY_BACKSPACE,   // BACKSPACE
    ZPL_KEY_TAB,         // TABULATION
    ZPL_KEY_PAGEUP,      // PAGE UP
    ZPL_KEY_PAGEDOWN,    // PAGE DOWN
    ZPL_KEY_END,         // END
    ZPL_KEY_HOME,        // HOME
    ZPL_KEY_INSERT,      // INSERT
    ZPL_KEY_DELETE,      // DELETE
    ZPL_KEY_PLUS,        // +
    ZPL_KEY_SUBTRACT,    // -
    ZPL_KEY_MULTIPLY,    // *
    ZPL_KEY_DIVIDE,      // /
    ZPL_KEY_LEFT,        // LEFT ARROW
    ZPL_KEY_RIGHT,       // RIGHT ARROW
    ZPL_KEY_UP,          // UP ARROW
    ZPL_KEY_DOWN,        // DOWN ARROW
    ZPL_KEY_NUMPAD0,     // NUMPAD 0
    ZPL_KEY_NUMPAD1,     // NUMPAD 1
    ZPL_KEY_NUMPAD2,     // NUMPAD 2
    ZPL_KEY_NUMPAD3,     // NUMPAD 3
    ZPL_KEY_NUMPAD4,     // NUMPAD 4
    ZPL_KEY_NUMPAD5,     // NUMPAD 5
    ZPL_KEY_NUMPAD6,     // NUMPAD 6
    ZPL_KEY_NUMPAD7,     // NUMPAD 7
    ZPL_KEY_NUMPAD8,     // NUMPAD 8
    ZPL_KEY_NUMPAD9,     // NUMPAD 9
    ZPL_KEY_NUMPADDOT,   // NUMPAD .
    ZPL_KEY_NUMPADENTER, // NUMPAD ENTER
    ZPL_KEY_F1,          // F1
    ZPL_KEY_F2,          // F2
    ZPL_KEY_F3,          // F3
    ZPL_KEY_F4,          // F4
    ZPL_KEY_F5,          // F5
    ZPL_KEY_F6,          // F6
    ZPL_KEY_F7,          // F7
    ZPL_KEY_F8,          // F8
    ZPL_KEY_F9,          // F8
    ZPL_KEY_F10,         // F10
    ZPL_KEY_F11,         // F11
    ZPL_KEY_F12,         // F12
    ZPL_KEY_F13,         // F13
    ZPL_KEY_F14,         // F14
    ZPL_KEY_F15,         // F15
    ZPL_KEY_PAUSE,       // PAUSE

    ZPL_KEY_COUNT,
} zplKeyType;

typedef u8 zplKeyState;
typedef enum zplKeyStateFlag {
    ZPL_KEY_STATE_DOWN = ZPL_BIT(0),
    ZPL_KEY_STATE_PRESSED = ZPL_BIT(1),
    ZPL_KEY_STATE_RELEASED = ZPL_BIT(2)
} zplKeyStateFlag;

ZPL_DEF void zpl_key_state_update(zplKeyState *s, b32 is_down);

typedef enum zplMouseButtonType {
    ZPL_MOUSEBUTTON_LEFT,
    ZPL_MOUSEBUTTON_MIDDLE,
    ZPL_MOUSEBUTTON_RIGHT,
    ZPL_MOUSEBUTTON_X1,
    ZPL_MOUSEBUTTON_X2,

    ZPL_MOUSEBUTTON_COUNT
} zplMouseButtonType;

typedef enum zplControllerAxisType {
    ZPL_CONTROLLER_AXIS_LEFTX,
    ZPL_CONTROLLER_AXIS_LEFTY,
    ZPL_CONTROLLER_AXIS_RIGHTX,
    ZPL_CONTROLLER_AXIS_RIGHTY,
    ZPL_CONTROLLER_AXIS_LEFTTRIGGER,
    ZPL_CONTROLLER_AXIS_RIGHTTRIGGER,

    ZPL_CONTROLLER_AXIS_COUNT
} zplControllerAxisType;

typedef enum zplControllerButtonType {
    ZPL_CONTROLLER_BUTTON_UP,
    ZPL_CONTROLLER_BUTTON_DOWN,
    ZPL_CONTROLLER_BUTTON_LEFT,
    ZPL_CONTROLLER_BUTTON_RIGHT,
    ZPL_CONTROLLER_BUTTON_A,
    ZPL_CONTROLLER_BUTTON_B,
    ZPL_CONTROLLER_BUTTON_X,
    ZPL_CONTROLLER_BUTTON_Y,
    ZPL_CONTROLLER_BUTTON_LEFTSHOULDER,
    ZPL_CONTROLLER_BUTTON_RIGHTSHOULDER,
    ZPL_CONTROLLER_BUTTON_BACK,
    ZPL_CONTROLLER_BUTTON_START,
    ZPL_CONTROLLER_BUTTON_LEFTTHUMB,
    ZPL_CONTROLLER_BUTTON_RIGHTTHUMB,

    zplControllerButton_Count
} zplControllerButtonType;

typedef struct zpl_game_controller {
    b16 is_connected, is_analog;

    f32 axes[ZPL_CONTROLLER_AXIS_COUNT];
    zplKeyState buttons[zplControllerButton_Count];
} zpl_game_controller;

#if defined(ZPL_SYSTEM_WINDOWS)
typedef struct _XINPUT_GAMEPAD XINPUT_GAMEPAD;
typedef struct _XINPUT_STATE XINPUT_STATE;
typedef struct _XINPUT_VIBRATION XINPUT_VIBRATION;

#define ZPL_XINPUT_GET_STATE(name) unsigned long __stdcall name(unsigned long dwUserIndex, XINPUT_STATE *pState)
typedef ZPL_XINPUT_GET_STATE(zpl_xinput_get_state_proc);

#define ZPL_XINPUT_SET_STATE(name) unsigned long __stdcall name(unsigned long dwUserIndex, XINPUT_VIBRATION *pVibration)
typedef ZPL_XINPUT_SET_STATE(zpl_xinput_set_state_proc);
#endif

typedef enum zplWindowFlag {
    ZPL_WINDOW_FULLSCREEN = ZPL_BIT(0),
    ZPL_WINDOW_HIDDEN = ZPL_BIT(1),
    ZPL_WINDOW_BORDERLESS = ZPL_BIT(2),
    ZPL_WINDOW_RESIZABLE = ZPL_BIT(3),
    ZPL_WINDOW_MINIMIZED = ZPL_BIT(4),
    ZPL_WINDOW_MAXIMIZED = ZPL_BIT(5),
    ZPL_WINDOW_FULLSCREENDESKTOP = ZPL_WINDOW_FULLSCREEN | ZPL_WINDOW_BORDERLESS,
} zplWindowFlag;

typedef enum zplRendererType {
    ZPL_RENDERER_OPENGL,
    ZPL_RENDERER_SOFTWARE,

    ZPL_RENDERER_COUNT,
} zplRendererType;

#if defined(ZPL_SYSTEM_WINDOWS) && !defined(_WINDOWS_)
typedef struct tagBITMAPINFOHEADER {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    u16 biPlanes;
    u16 biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;
typedef struct tagRGBQUAD {
    u8 rgbBlue;
    u8 rgbGreen;
    u8 rgbRed;
    u8 rgbReserved;
} RGBQUAD;
typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[1];
} BITMAPINFO, *PBITMAPINFO;
#endif

typedef struct zpl_platform {
    b32 is_initialized;

    void *window_handle;
    i32 window_x, window_y;
    i32 window_width, window_height;
    i32 outline_x, outline_y;
    i32 outline_width, outline_height;
    u32 window_flags;
    b16 window_is_closed, window_has_focus;

#if defined(ZPL_SYSTEM_WINDOWS)
    void *win32_dc;
#elif defined(ZPL_SYSTEM_OSX)
    void *osx_autorelease_pool; // TODO(bill): Is this really needed?
#endif

    zplRendererType renderer_type;
    union {
        struct {
            void *context;
            i32 major;
            i32 minor;
            b16 core, compatible;
            zpl_dll_handle dll_handle;
        } opengl;

        // NOTE(bill): Software rendering
        struct {
#if defined(ZPL_SYSTEM_WINDOWS)
            BITMAPINFO win32_bmi;
#endif
            void *memory;
            isize memory_size;
            i32 pitch;
            i32 bits_per_pixel;
        } sw_framebuffer;
    };

    zplKeyState keys[ZPL_KEY_COUNT];
    struct {
        zplKeyState control;
        zplKeyState alt;
        zplKeyState shift;
    } key_modifiers;

    Rune char_buffer[256];
    isize char_buffer_count;

    void *window_cursor;
    b32 mouse_clip;
    i32 mouse_x, mouse_y;
    i32 mouse_dx, mouse_dy;         // NOTE(bill): Not raw mouse movement
    i32 mouse_raw_dx, mouse_raw_dy; // NOTE(bill): Raw mouse movement
    f32 mouse_wheel_delta;
    zplKeyState mouse_buttons[ZPL_MOUSEBUTTON_COUNT];

    zpl_game_controller game_controllers[ZPL_MAX_GAME_CONTROLLER_COUNT];

    f64 curr_time;
    f64 dt_for_frame;
    b32 quit_requested;

#if defined(ZPL_SYSTEM_WINDOWS)
    struct {
        zpl_xinput_get_state_proc *get_state;
        zpl_xinput_set_state_proc *set_state;
    } xinput;
#endif
} zpl_platform;

typedef struct zpl_video_mode {
    i32 width, height;
    i32 bits_per_pixel;
} zpl_video_mode;

ZPL_DEF zpl_video_mode zpl_set_video_mode(i32 width, i32 height, i32 bits_per_pixel);
ZPL_DEF b32 zpl_video_mode_is_valid(zpl_video_mode mode);
ZPL_DEF zpl_video_mode zpl_video_mode_get_desktop(void);
ZPL_DEF isize zpl_video_mode_get_fullscreen_modes(zpl_video_mode *modes,
                                                isize max_mode_count); // NOTE(bill): returns mode count
ZPL_DEF ZPL_COMPARE_PROC(zpl_video_mode_cmp);     // NOTE(bill): Sort smallest to largest (Ascending)
ZPL_DEF ZPL_COMPARE_PROC(zpl_video_mode_dsc_cmp); // NOTE(bill): Sort largest to smallest (Descending)

// NOTE(bill): Software rendering
ZPL_DEF b32 zpl_platform_init_with_software(zpl_platform *p, char const *window_title, i32 width, i32 height,
                                          u32 window_flags);
// NOTE(bill): OpenGL Rendering
ZPL_DEF b32 zpl_platform_init_with_opengl(zpl_platform *p, char const *window_title, i32 width, i32 height,
                                        u32 window_flags, i32 major, i32 minor, b32 core, b32 compatible);
ZPL_DEF void zpl_platform_update(zpl_platform *p);
ZPL_DEF void zpl_platform_display(zpl_platform *p);
ZPL_DEF void zpl_platform_destroy(zpl_platform *p);
ZPL_DEF void zpl_platform_show_cursor(zpl_platform *p, b32 show);
ZPL_DEF void zpl_platform_set_cursor(zpl_platform *p, void *handle);
ZPL_DEF void zpl_platform_set_mouse_position(zpl_platform *p, i32 x, i32 y);
ZPL_DEF void zpl_platform_set_controller_vibration(zpl_platform *p, isize index, f32 left_motor, f32 right_motor);
ZPL_DEF b32 zpl_platform_has_clipboard_text(zpl_platform *p);
ZPL_DEF void zpl_platform_set_clipboard_text(zpl_platform *p, char const *str);
ZPL_DEF char *zpl_platform_get_clipboard_text(zpl_platform *p, zpl_allocator a);
ZPL_DEF u32  zpl_platform_get_scancode(zpl_platform *p, zplKeyType key);
ZPL_DEF void zpl_platform_set_window_position(zpl_platform *p, i32 x, i32 y);
ZPL_DEF void zpl_platform_set_window_title(zpl_platform *p, char const *title, ...) ZPL_PRINTF_ARGS(2);
ZPL_DEF void zpl_platform_toggle_fullscreen(zpl_platform *p, b32 fullscreen_desktop);
ZPL_DEF void zpl_platform_toggle_borderless(zpl_platform *p);
ZPL_DEF void zpl_platform_make_opengl_context_current(zpl_platform *p);
ZPL_DEF void zpl_platform_show_window(zpl_platform *p);
ZPL_DEF void zpl_platform_hide_window(zpl_platform *p);

#endif // ZPL_PLATFORM

#if defined(__cplusplus)
}
#endif

#endif // ZPL_INCLUDE_ZPL_H

////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// Implementation
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// MIDDLE
//
// It's turtles all the way down!
////////////////////////////////////////////////////////////////
#if defined(ZPL_IMPLEMENTATION) && !defined(ZPL_IMPLEMENTATION_DONE)
#define ZPL_IMPLEMENTATION_DONE

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__GCC__) || defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
#pragma GCC diagnostic ignored "-Wmissing-braces"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4201)
#pragma warning(disable:4127) // Conditional expression is constant
#endif

void zpl_assert_handler(char const *condition, char const *file, i32 line, char const *msg, ...) {
    zpl_printf_err("%s:(%d): Assert Failure: ", file, line);
    if (condition)
        zpl_printf_err( "`%s` ", condition);
    if (msg) {
        va_list va;
        va_start(va, msg);
        zpl_printf_err_va(msg, va);
        va_end(va);
    }
    zpl_printf_err("\n");
}

i32 zpl_assert_crash(char const *condition) {
    ZPL_PANIC(condition);

    return 0;
}

b32 zpl_is_power_of_two(isize x) {
    if (x <= 0)
        return false;
    return !(x & (x-1));
}

zpl_inline void *zpl_align_forward(void *ptr, isize alignment) {
    uintptr p;

    ZPL_ASSERT(zpl_is_power_of_two(alignment));

    p = cast(uintptr)ptr;
    return cast(void *)((p + (alignment-1)) &~ (alignment-1));
}



zpl_inline void *      zpl_pointer_add      (void *ptr, isize bytes)             { return cast(void *)(cast(u8 *)ptr + bytes); }
zpl_inline void *      zpl_pointer_sub      (void *ptr, isize bytes)             { return cast(void *)(cast(u8 *)ptr - bytes); }
zpl_inline void const *zpl_pointer_add_const(void const *ptr, isize bytes)       { return cast(void const *)(cast(u8 const *)ptr + bytes); }
zpl_inline void const *zpl_pointer_sub_const(void const *ptr, isize bytes)       { return cast(void const *)(cast(u8 const *)ptr - bytes); }
zpl_inline isize       zpl_pointer_diff     (void const *begin, void const *end) { return cast(isize)(cast(u8 const *)end - cast(u8 const *)begin); }

zpl_inline void zpl_zero_size(void *ptr, isize size) { zpl_memset(ptr, 0, size); }


#if defined(_MSC_VER)
#pragma intrinsic(__movsb)
#endif

zpl_inline void *zpl_memcopy(void *dest, void const *source, isize n) {
    if (dest == NULL) {
        return NULL;
    }
#if defined(_MSC_VER)
    __movsb(cast(u8 *)dest, cast(u8 *)source, n);
#elif defined(ZPL_CPU_X86) && !defined(ZPL_SYSTEM_EMSCRIPTEN)
    u8 *__dest8 = cast(u8 *)dest;
    u8 *__source8 = cast(u8 *)source;
    __asm__ __volatile__("rep movsb" : "+D"(__dest8), "+S"(__source8), "+c"(n) : : "memory");
#elif defined(ZPL_CPU_ARM)
    return memcpy(dest, source, n);
#else
    u8 *d = cast(u8 *)dest;
    u8 const *s = cast(u8 const *)source;
    u32 w, x;

    for (; cast(uintptr)s % 4 && n; n--)
        *d++ = *s++;

    if (cast(uintptr)d % 4 == 0) {
        for (; n >= 16;
                s += 16, d += 16, n -= 16) {
            *cast(u32 *)(d+ 0) = *cast(u32 *)(s+ 0);
            *cast(u32 *)(d+ 4) = *cast(u32 *)(s+ 4);
            *cast(u32 *)(d+ 8) = *cast(u32 *)(s+ 8);
            *cast(u32 *)(d+12) = *cast(u32 *)(s+12);
        }
        if (n & 8) {
            *cast(u32 *)(d+0) = *cast(u32 *)(s+0);
            *cast(u32 *)(d+4) = *cast(u32 *)(s+4);
            d += 8;
            s += 8;
        }
        if (n&4) {
            *cast(u32 *)(d+0) = *cast(u32 *)(s+0);
            d += 4;
            s += 4;
        }
        if (n&2) {
            *d++ = *s++; *d++ = *s++;
        }
        if (n&1) {
            *d = *s;
        }
        return dest;
    }

    if (n >= 32) {
#if __BYTE_ORDER == __BIG_ENDIAN
#define LS <<
#define RS >>
#else
#define LS >>
#define RS <<
#endif
        switch (cast(uintptr)d % 4) {
        case 1: {
            w = *cast(u32 *)s;
            *d++ = *s++;
            *d++ = *s++;
            *d++ = *s++;
            n -= 3;
            while (n > 16) {
                x = *cast(u32 *)(s+1);
                *cast(u32 *)(d+0)  = (w LS 24) | (x RS 8);
                w = *cast(u32 *)(s+5);
                *cast(u32 *)(d+4)  = (x LS 24) | (w RS 8);
                x = *cast(u32 *)(s+9);
                *cast(u32 *)(d+8)  = (w LS 24) | (x RS 8);
                w = *cast(u32 *)(s+13);
                *cast(u32 *)(d+12) = (x LS 24) | (w RS 8);

                s += 16;
                d += 16;
                n -= 16;
            }
        } break;
        case 2: {
            w = *cast(u32 *)s;
            *d++ = *s++;
            *d++ = *s++;
            n -= 2;
            while (n > 17) {
                x = *cast(u32 *)(s+2);
                *cast(u32 *)(d+0)  = (w LS 16) | (x RS 16);
                w = *cast(u32 *)(s+6);
                *cast(u32 *)(d+4)  = (x LS 16) | (w RS 16);
                x = *cast(u32 *)(s+10);
                *cast(u32 *)(d+8)  = (w LS 16) | (x RS 16);
                w = *cast(u32 *)(s+14);
                *cast(u32 *)(d+12) = (x LS 16) | (w RS 16);

                s += 16;
                d += 16;
                n -= 16;
            }
        } break;
        case 3: {
            w = *cast(u32 *)s;
            *d++ = *s++;
            n -= 1;
            while (n > 18) {
                x = *cast(u32 *)(s+3);
                *cast(u32 *)(d+0)  = (w LS 8) | (x RS 24);
                w = *cast(u32 *)(s+7);
                *cast(u32 *)(d+4)  = (x LS 8) | (w RS 24);
                x = *cast(u32 *)(s+11);
                *cast(u32 *)(d+8)  = (w LS 8) | (x RS 24);
                w = *cast(u32 *)(s+15);
                *cast(u32 *)(d+12) = (x LS 8) | (w RS 24);

                s += 16;
                d += 16;
                n -= 16;
            }
        } break;
        default: break; // NOTE: Do nowt!
        }
#undef LS
#undef RS
        if (n & 16) {
            *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;
            *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;
            *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;
            *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;
        }
        if (n & 8) {
            *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;
            *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;
        }
        if (n & 4) {
            *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;
        }
        if (n & 2) {
            *d++ = *s++; *d++ = *s++;
        }
        if (n & 1) {
            *d = *s;
        }
    }

#endif
    return dest;
}

zpl_inline void *zpl_memmove(void *dest, void const *source, isize n) {
    if (dest == NULL) {
        return NULL;
    }

    u8 *d = cast(u8 *)dest;
    u8 const *s = cast(u8 const *)source;

    if (d == s)
        return d;
    if (s+n <= d || d+n <= s) // NOTE: Non-overlapping
        return zpl_memcopy(d, s, n);

    if (d < s) {
        if (cast(uintptr)s % zpl_size_of(isize) == cast(uintptr)d % zpl_size_of(isize)) {
            while (cast(uintptr)d % zpl_size_of(isize)) {
                if (!n--) return dest;
                *d++ = *s++;
            }
            while (n>=zpl_size_of(isize)) {
                *cast(isize *)d = *cast(isize *)s;
                n -= zpl_size_of(isize);
                d += zpl_size_of(isize);
                s += zpl_size_of(isize);
            }
        }
        for (; n; n--) *d++ = *s++;
    } else {
        if ((cast(uintptr)s % zpl_size_of(isize)) == (cast(uintptr)d % zpl_size_of(isize))) {
            while (cast(uintptr)(d+n) % zpl_size_of(isize)) {
                if (!n--)
                    return dest;
                d[n] = s[n];
            }
            while (n >= zpl_size_of(isize)) {
                n -= zpl_size_of(isize);
                *cast(isize *)(d+n) = *cast(isize *)(s+n);
            }
        }
        while (n) n--, d[n] = s[n];
    }

    return dest;
}

zpl_inline void *zpl_memset(void *dest, u8 c, isize n) {
    if (dest == NULL) {
        return NULL;
    }

    u8 *s = cast(u8 *)dest;
    isize k;
    u32 c32 = ((u32)-1)/255 * c;

    if (n == 0)
        return dest;
    s[0] = s[n-1] = c;
    if (n < 3)
        return dest;
    s[1] = s[n-2] = c;
    s[2] = s[n-3] = c;
    if (n < 7)
        return dest;
    s[3] = s[n-4] = c;
    if (n < 9)
        return dest;

    k = -cast(intptr)s & 3;
    s += k;
    n -= k;
    n &= -4;

    *cast(u32 *)(s+0) = c32;
    *cast(u32 *)(s+n-4) = c32;
    if (n < 9)
        return dest;
    *cast(u32 *)(s +  4)    = c32;
    *cast(u32 *)(s +  8)    = c32;
    *cast(u32 *)(s+n-12) = c32;
    *cast(u32 *)(s+n- 8) = c32;
    if (n < 25)
        return dest;
    *cast(u32 *)(s + 12) = c32;
    *cast(u32 *)(s + 16) = c32;
    *cast(u32 *)(s + 20) = c32;
    *cast(u32 *)(s + 24) = c32;
    *cast(u32 *)(s+n-28) = c32;
    *cast(u32 *)(s+n-24) = c32;
    *cast(u32 *)(s+n-20) = c32;
    *cast(u32 *)(s+n-16) = c32;

    k = 24 + (cast(uintptr)s & 4);
    s += k;
    n -= k;


    {
        u64 c64 = (cast(u64)c32 << 32) | c32;
        while (n > 31) {
            *cast(u64 *)(s+0) = c64;
            *cast(u64 *)(s+8) = c64;
            *cast(u64 *)(s+16) = c64;
            *cast(u64 *)(s+24) = c64;

            n -= 32;
            s += 32;
        }
    }

    return dest;
}

zpl_inline i32 zpl_memcompare(void const *s1, void const *s2, isize size) {
    u8 const *s1p8 = cast(u8 const *)s1;
    u8 const *s2p8 = cast(u8 const *)s2;

    if (s1 == NULL || s2 == NULL) {
        return 0;
    }

    while (size--) {
        isize d;
        if ((d = (*s1p8++ - *s2p8++)) != 0)
            return cast(i32)d;
    }
    return 0;
}

void zpl_memswap(void *i, void *j, isize size) {
    if (i == j) return;

    if (size == 4) {
        zpl_swap(u32, *cast(u32 *)i, *cast(u32 *)j);
    } else if (size == 8) {
        zpl_swap(u64, *cast(u64 *)i, *cast(u64 *)j);
    } else if (size < 8) {
        u8 *a = cast(u8 *)i;
        u8 *b = cast(u8 *)j;
        if (a != b) {
            while (size--) {
                zpl_swap(u8, *a++, *b++);
            }
        }
    } else {
        char buffer[256];

        while (size > zpl_size_of(buffer)) {
            zpl_memswap(i, j, zpl_size_of(buffer));
            i = zpl_pointer_add(i, zpl_size_of(buffer));
            j = zpl_pointer_add(j, zpl_size_of(buffer));
            size -= zpl_size_of(buffer);
        }

        zpl_memcopy(buffer, i,      size);
        zpl_memcopy(i,      j,      size);
        zpl_memcopy(j,      buffer, size);
    }
}

#define ZPL__ONES        (cast(usize)-1/U8_MAX)
#define ZPL__HIGHS       (ZPL__ONES * (U8_MAX/2+1))
#define ZPL__HAS_ZERO(x) (((x)-ZPL__ONES) & ~(x) & ZPL__HIGHS)


void const *zpl_memchr(void const *data, u8 c, isize n) {
    u8 const *s = cast(u8 const *)data;
    while ((cast(uintptr)s & (sizeof(usize)-1)) &&
            n && *s != c) {
        s++;
        n--;
    }
    if (n && *s != c) {
        isize const *w;
        isize k = ZPL__ONES * c;
        w = cast(isize const *)s;
        while (n >= zpl_size_of(isize) && !ZPL__HAS_ZERO(*w ^ k)) {
            w++;
            n -= zpl_size_of(isize);
        }
        s = cast(u8 const *)w;
        while (n && *s != c) {
            s++;
            n--;
        }
    }

    return n ? cast(void const *)s : NULL;
}


void const *zpl_memrchr(void const *data, u8 c, isize n) {
    u8 const *s = cast(u8 const *)data;
    while (n--) {
        if (s[n] == c)
            return cast(void const *)(s + n);
    }
    return NULL;
}



zpl_inline void *zpl_alloc_align (zpl_allocator a, isize size, isize alignment)                                { return a.proc(a.data, ZPL_ALLOCATION_ALLOC, size, alignment, NULL, 0, ZPL_DEFAULT_ALLOCATOR_FLAGS); }
zpl_inline void *zpl_alloc       (zpl_allocator a, isize size)                                                 { return zpl_alloc_align(a, size, ZPL_DEFAULT_MEMORY_ALIGNMENT); }
zpl_inline void  zpl_free        (zpl_allocator a, void *ptr)                                                  { if (ptr != NULL) a.proc(a.data, ZPL_ALLOCATION_FREE, 0, 0, ptr, 0, ZPL_DEFAULT_ALLOCATOR_FLAGS); }
zpl_inline void  zpl_free_all    (zpl_allocator a)                                                             { a.proc(a.data, ZPL_ALLOCATION_FREE_ALL, 0, 0, NULL, 0, ZPL_DEFAULT_ALLOCATOR_FLAGS); }
zpl_inline void *zpl_resize      (zpl_allocator a, void *ptr, isize old_size, isize new_size)                  { return zpl_resize_align(a, ptr, old_size, new_size, ZPL_DEFAULT_MEMORY_ALIGNMENT); }
zpl_inline void *zpl_resize_align(zpl_allocator a, void *ptr, isize old_size, isize new_size, isize alignment) { return a.proc(a.data, ZPL_ALLOCATION_RESIZE, new_size, alignment, ptr, old_size, ZPL_DEFAULT_ALLOCATOR_FLAGS); }

zpl_inline void *zpl_alloc_copy      (zpl_allocator a, void const *src, isize size)                  { return zpl_memcopy(zpl_alloc(a, size), src, size); }
zpl_inline void *zpl_alloc_copy_align(zpl_allocator a, void const *src, isize size, isize alignment) { return zpl_memcopy(zpl_alloc_align(a, size, alignment), src, size); }

zpl_inline char *zpl_alloc_str(zpl_allocator a, char const *str) {
    return zpl_alloc_str_len(a, str, zpl_strlen(str));
}

zpl_inline char *zpl_alloc_str_len(zpl_allocator a, char const *str, isize len) {
    char *result;
    result = cast(char *)zpl_alloc_copy(a, str, len+1);
    result[len] = '\0';
    return result;
}


zpl_inline void *zpl_default_resize_align(zpl_allocator a, void *old_memory, isize old_size, isize new_size, isize alignment) {
    if (!old_memory) return zpl_alloc_align(a, new_size, alignment);

    if (new_size == 0) {
        zpl_free(a, old_memory);
        return NULL;
    }

    if (new_size < old_size)
        new_size = old_size;

    if (old_size == new_size) {
        return old_memory;
    } else {
        void *new_memory = zpl_alloc_align(a, new_size, alignment);
        if (!new_memory) return NULL;
        zpl_memmove(new_memory, old_memory, zpl_min(new_size, old_size));
        zpl_free(a, old_memory);
        return new_memory;
    }
}



#if ZPL_THREADING

////////////////////////////////////////////////////////////////
//
// Concurrency
//
//
// IMPORTANT TODO: Use compiler intrinsics for the atomics

#if defined(ZPL_COMPILER_MSVC) && !defined(ZPL_COMPILER_CLANG)
zpl_inline i32  zpl_atomic32_load (zpl_atomic32 const volatile *a)      { return a->value;  }
zpl_inline void zpl_atomic32_store(zpl_atomic32 volatile *a, i32 value) { a->value = value; }

zpl_inline i32 zpl_atomic32_compare_exchange(zpl_atomic32 volatile *a, i32 expected, i32 desired) {
    return _InterlockedCompareExchange(cast(long volatile *)a, desired, expected);
}
zpl_inline i32 zpl_atomic32_exchange(zpl_atomic32 volatile *a, i32 desired) {
    return _InterlockedExchange(cast(long volatile *)a, desired);
}
zpl_inline i32 zpl_atomic32_fetch_add(zpl_atomic32 volatile *a, i32 operand) {
    return _InterlockedExchangeAdd(cast(long volatile *)a, operand);
}
zpl_inline i32 zpl_atomic32_fetch_and(zpl_atomic32 volatile *a, i32 operand) {
    return _InterlockedAnd(cast(long volatile *)a, operand);
}
zpl_inline i32 zpl_atomic32_fetch_or(zpl_atomic32 volatile *a, i32 operand) {
    return _InterlockedOr(cast(long volatile *)a, operand);
}

zpl_inline i64 zpl_atomic64_load(zpl_atomic64 const volatile *a) {
#if defined(ZPL_ARCH_64_BIT)
    return a->value;
#elif ZPL_CPU_X86
    // NOTE: The most compatible way to get an atomic 64-bit load on x86 is with cmpxchg8b
    i64 result;
    __asm {
        mov esi, a;
        mov ebx, eax;
        mov ecx, edx;
        lock cmpxchg8b [esi];
        mov dword ptr result, eax;
        mov dword ptr result[4], edx;
    }
    return result;
#else
#error TODO: atomics for this CPU
#endif
}

zpl_inline void zpl_atomic64_store(zpl_atomic64 volatile *a, i64 value) {
#if defined(ZPL_ARCH_64_BIT)
    a->value = value;
#elif ZPL_CPU_X86
    // NOTE: The most compatible way to get an atomic 64-bit store on x86 is with cmpxchg8b
    __asm {
        mov esi, a;
        mov ebx, dword ptr value;
        mov ecx, dword ptr value[4];
    retry:
        cmpxchg8b [esi];
        jne retry;
    }
#else
#error TODO: atomics for this CPU
#endif
}

zpl_inline i64 zpl_atomic64_compare_exchange(zpl_atomic64 volatile *a, i64 expected, i64 desired) {
    return _InterlockedCompareExchange64(cast(i64 volatile *)a, desired, expected);
}

zpl_inline i64 zpl_atomic64_exchange(zpl_atomic64 volatile *a, i64 desired) {
#if defined(ZPL_ARCH_64_BIT)
    return _InterlockedExchange64(cast(i64 volatile *)a, desired);
#elif ZPL_CPU_X86
    i64 expected = a->value;
    for (;;) {
        i64 original = _InterlockedCompareExchange64(cast(i64 volatile *)a, desired, expected);
        if (original == expected)
            return original;
        expected = original;
    }
#else
#error TODO: atomics for this CPU
#endif
}

zpl_inline i64 zpl_atomic64_fetch_add(zpl_atomic64 volatile *a, i64 operand) {
#if defined(ZPL_ARCH_64_BIT)
    return _InterlockedExchangeAdd64(cast(i64 volatile *)a, operand);
#elif ZPL_CPU_X86
    i64 expected = a->value;
    for (;;) {
        i64 original = _InterlockedCompareExchange64(cast(i64 volatile *)a, expected + operand, expected);
        if (original == expected)
            return original;
        expected = original;
    }
#else
#error TODO: atomics for this CPU
#endif
}

zpl_inline i64 zpl_atomic64_fetch_and(zpl_atomic64 volatile *a, i64 operand) {
#if defined(ZPL_ARCH_64_BIT)
    return _InterlockedAnd64(cast(i64 volatile *)a, operand);
#elif ZPL_CPU_X86
    i64 expected = a->value;
    for (;;) {
        i64 original = _InterlockedCompareExchange64(cast(i64 volatile *)a, expected & operand, expected);
        if (original == expected)
            return original;
        expected = original;
    }
#else
#error TODO: atomics for this CPU
#endif
}

zpl_inline i64 zpl_atomic64_fetch_or(zpl_atomic64 volatile *a, i64 operand) {
#if defined(ZPL_ARCH_64_BIT)
    return _InterlockedOr64(cast(i64 volatile *)a, operand);
#elif ZPL_CPU_X86
    i64 expected = a->value;
    for (;;) {
        i64 original = _InterlockedCompareExchange64(cast(i64 volatile *)a, expected | operand, expected);
        if (original == expected)
            return original;
        expected = original;
    }
#else
#error TODO: atomics for this CPU
#endif
}



#elif defined(ZPL_CPU_X86)

zpl_inline i32  zpl_atomic32_load (zpl_atomic32 const volatile *a)      { return a->value;  }
zpl_inline void zpl_atomic32_store(zpl_atomic32 volatile *a, i32 value) { a->value = value; }

zpl_inline i32 zpl_atomic32_compare_exchange(zpl_atomic32 volatile *a, i32 expected, i32 desired) {
    i32 original;
    __asm__ volatile(
                        "lock; cmpxchgl %2, %1"
                        : "=a"(original), "+m"(a->value)
                        : "q"(desired), "0"(expected)
                        );
    return original;
}

zpl_inline i32 zpl_atomic32_exchange(zpl_atomic32 volatile *a, i32 desired) {
    // NOTE: No lock prefix is necessary for xchgl
    i32 original;
    __asm__ volatile(
                        "xchgl %0, %1"
                        : "=r"(original), "+m"(a->value)
                        : "0"(desired)
                        );
    return original;
}

zpl_inline i32 zpl_atomic32_fetch_add(zpl_atomic32 volatile *a, i32 operand) {
    i32 original;
    __asm__ volatile(
                        "lock; xaddl %0, %1"
                        : "=r"(original), "+m"(a->value)
                        : "0"(operand)
                        );
    return original;
}

zpl_inline i32 zpl_atomic32_fetch_and(zpl_atomic32 volatile *a, i32 operand) {
    i32 original;
    i32 tmp;
    __asm__ volatile(
                        "1:     movl    %1, %0\n"
                        "       movl    %0, %2\n"
                        "       andl    %3, %2\n"
                        "       lock; cmpxchgl %2, %1\n"
                        "       jne     1b"
                        : "=&a"(original), "+m"(a->value), "=&r"(tmp)
                        : "r"(operand)
                        );
    return original;
}

zpl_inline i32 zpl_atomic32_fetch_or(zpl_atomic32 volatile *a, i32 operand) {
    i32 original;
    i32 temp;
    __asm__ volatile(
                        "1:     movl    %1, %0\n"
                        "       movl    %0, %2\n"
                        "       orl     %3, %2\n"
                        "       lock; cmpxchgl %2, %1\n"
                        "       jne     1b"
                        : "=&a"(original), "+m"(a->value), "=&r"(temp)
                        : "r"(operand)
                        );
    return original;
}


zpl_inline i64 zpl_atomic64_load(zpl_atomic64 const volatile *a) {
#if defined(ZPL_ARCH_64_BIT)
    return a->value;
#else
    i64 original;
    __asm__ volatile(
                        "movl %%ebx, %%eax\n"
                        "movl %%ecx, %%edx\n"
                        "lock; cmpxchg8b %1"
                        : "=&A"(original)
                        : "m"(a->value)
                        );
    return original;
#endif
}

zpl_inline void zpl_atomic64_store(zpl_atomic64 volatile *a, i64 value) {
#if defined(ZPL_ARCH_64_BIT)
    a->value = value;
#else
    i64 expected = a->value;
    __asm__ volatile(
                        "1:    cmpxchg8b %0\n"
                        "      jne 1b"
                        : "=m"(a->value)
                        : "b"((i32)value), "c"((i32)(value >> 32)), "A"(expected)
                        );
#endif
}

zpl_inline i64 zpl_atomic64_compare_exchange(zpl_atomic64 volatile *a, i64 expected, i64 desired) {
#if defined(ZPL_ARCH_64_BIT)
    i64 original;
    __asm__ volatile(
                        "lock; cmpxchgq %2, %1"
                        : "=a"(original), "+m"(a->value)
                        : "q"(desired), "0"(expected)
                        );
    return original;
#else
    i64 original;
    __asm__ volatile(
                        "lock; cmpxchg8b %1"
                        : "=A"(original), "+m"(a->value)
                        : "b"((i32)desired), "c"((i32)(desired >> 32)), "0"(expected)
                        );
    return original;
#endif
}

zpl_inline i64 zpl_atomic64_exchange(zpl_atomic64 volatile *a, i64 desired) {
#if defined(ZPL_ARCH_64_BIT)
    i64 original;
    __asm__ volatile(
                        "xchgq %0, %1"
                        : "=r"(original), "+m"(a->value)
                        : "0"(desired)
                        );
    return original;
#else
    i64 original = a->value;
    for (;;) {
        i64 previous = zpl_atomic64_compare_exchange(a, original, desired);
        if (original == previous)
            return original;
        original = previous;
    }
#endif
}

zpl_inline i64 zpl_atomic64_fetch_add(zpl_atomic64 volatile *a, i64 operand) {
#if defined(ZPL_ARCH_64_BIT)
    i64 original;
    __asm__ volatile(
                        "lock; xaddq %0, %1"
                        : "=r"(original), "+m"(a->value)
                        : "0"(operand)
                        );
    return original;
#else
    for (;;) {
        i64 original = a->value;
        if (zpl_atomic64_compare_exchange(a, original, original + operand) == original)
            return original;
    }
#endif
}

zpl_inline i64 zpl_atomic64_fetch_and(zpl_atomic64 volatile *a, i64 operand) {
#if defined(ZPL_ARCH_64_BIT)
    i64 original;
    i64 tmp;
    __asm__ volatile(
                        "1:     movq    %1, %0\n"
                        "       movq    %0, %2\n"
                        "       andq    %3, %2\n"
                        "       lock; cmpxchgq %2, %1\n"
                        "       jne     1b"
                        : "=&a"(original), "+m"(a->value), "=&r"(tmp)
                        : "r"(operand)
                        );
    return original;
#else
    for (;;) {
        i64 original = a->value;
        if (zpl_atomic64_compare_exchange(a, original, original & operand) == original)
            return original;
    }
#endif
}

zpl_inline i64 zpl_atomic64_fetch_or(zpl_atomic64 volatile *a, i64 operand) {
#if defined(ZPL_ARCH_64_BIT)
    i64 original;
    i64 temp;
    __asm__ volatile(
                        "1:     movq    %1, %0\n"
                        "       movq    %0, %2\n"
                        "       orq     %3, %2\n"
                        "       lock; cmpxchgq %2, %1\n"
                        "       jne     1b"
                        : "=&a"(original), "+m"(a->value), "=&r"(temp)
                        : "r"(operand)
                        );
    return original;
#else
    for (;;) {
        i64 original = a->value;
        if (zpl_atomic64_compare_exchange(a, original, original | operand) == original)
            return original;
    }
#endif
}

#else
#error TODO: Implement Atomics for this CPU
#endif

zpl_inline b32 zpl_atomic32_spin_lock(zpl_atomic32 volatile *a, isize time_out) {
    i32 old_value = zpl_atomic32_compare_exchange(a, 1, 0);
    i32 counter = 0;
    while (old_value != 0 && (time_out < 0 || counter++ < time_out)) {
        zpl_yield_thread();
        old_value = zpl_atomic32_compare_exchange(a, 1, 0);
        zpl_mfence();
    }
    return old_value == 0;
}
zpl_inline void zpl_atomic32_spin_unlock(zpl_atomic32 volatile *a) {
    zpl_atomic32_store(a, 0);
    zpl_mfence();
}

zpl_inline b32 zpl_atomic64_spin_lock(zpl_atomic64 volatile *a, isize time_out) {
    i64 old_value = zpl_atomic64_compare_exchange(a, 1, 0);
    i64 counter = 0;
    while (old_value != 0 && (time_out < 0 || counter++ < time_out)) {
        zpl_yield_thread();
        old_value = zpl_atomic64_compare_exchange(a, 1, 0);
        zpl_mfence();
    }
    return old_value == 0;
}

zpl_inline void zpl_atomic64_spin_unlock(zpl_atomic64 volatile *a) {
    zpl_atomic64_store(a, 0);
    zpl_mfence();
}

zpl_inline b32 zpl_atomic32_try_acquire_lock(zpl_atomic32 volatile *a) {
    i32 old_value;
    zpl_yield_thread();
    old_value = zpl_atomic32_compare_exchange(a, 1, 0);
    zpl_mfence();
    return old_value == 0;
}

zpl_inline b32 zpl_atomic64_try_acquire_lock(zpl_atomic64 volatile *a) {
    i64 old_value;
    zpl_yield_thread();
    old_value = zpl_atomic64_compare_exchange(a, 1, 0);
    zpl_mfence();
    return old_value == 0;
}



#if defined(ZPL_ARCH_32_BIT)

zpl_inline void *zpl_atomic_ptr_load(zpl_atomic_ptr const volatile *a) {
    return cast(void *)cast(intptr)zpl_atomic32_load(cast(zpl_atomic32 const volatile *)a);
}
zpl_inline void zpl_atomic_ptr_store(zpl_atomic_ptr volatile *a, void *value) {
    zpl_atomic32_store(cast(zpl_atomic32 volatile *)a, cast(i32)cast(intptr)value);
}
zpl_inline void *zpl_atomic_ptr_compare_exchange(zpl_atomic_ptr volatile *a, void *expected, void *desired) {
    return cast(void *)cast(intptr)zpl_atomic32_compare_exchange(cast(zpl_atomic32 volatile *)a, cast(i32)cast(intptr)expected, cast(i32)cast(intptr)desired);
}
zpl_inline void *zpl_atomic_ptr_exchange(zpl_atomic_ptr volatile *a, void *desired) {
    return cast(void *)cast(intptr)zpl_atomic32_exchange(cast(zpl_atomic32 volatile *)a, cast(i32)cast(intptr)desired);
}
zpl_inline void *zpl_atomic_ptr_fetch_add(zpl_atomic_ptr volatile *a, void *operand) {
    return cast(void *)cast(intptr)zpl_atomic32_fetch_add(cast(zpl_atomic32 volatile *)a, cast(i32)cast(intptr)operand);
}
zpl_inline void *zpl_atomic_ptr_fetch_and(zpl_atomic_ptr volatile *a, void *operand) {
    return cast(void *)cast(intptr)zpl_atomic32_fetch_and(cast(zpl_atomic32 volatile *)a, cast(i32)cast(intptr)operand);
}
zpl_inline void *zpl_atomic_ptr_fetch_or(zpl_atomic_ptr volatile *a, void *operand) {
    return cast(void *)cast(intptr)zpl_atomic32_fetch_or(cast(zpl_atomic32 volatile *)a, cast(i32)cast(intptr)operand);
}
zpl_inline b32 zpl_atomic_ptr_spin_lock(zpl_atomic_ptr volatile *a, isize time_out) {
    return zpl_atomic32_spin_lock(cast(zpl_atomic32 volatile *)a, time_out);
}
zpl_inline void zpl_atomic_ptr_spin_unlock(zpl_atomic_ptr volatile *a) {
    zpl_atomic32_spin_unlock(cast(zpl_atomic32 volatile *)a);
}
zpl_inline b32 zpl_atomic_ptr_try_acquire_lock(zpl_atomic_ptr volatile *a) {
    return zpl_atomic32_try_acquire_lock(cast(zpl_atomic32 volatile *)a);
}

#elif defined(ZPL_ARCH_64_BIT)

zpl_inline void *zpl_atomic_ptr_load(zpl_atomic_ptr const volatile *a) {
    return cast(void *)cast(intptr)zpl_atomic64_load(cast(zpl_atomic64 const volatile *)a);
}
zpl_inline void zpl_atomic_ptr_store(zpl_atomic_ptr volatile *a, void *value) {
    zpl_atomic64_store(cast(zpl_atomic64 volatile *)a, cast(i64)cast(intptr)value);
}
zpl_inline void *zpl_atomic_ptr_compare_exchange(zpl_atomic_ptr volatile *a, void *expected, void *desired) {
    return cast(void *)cast(intptr)zpl_atomic64_compare_exchange(cast(zpl_atomic64 volatile *)a, cast(i64)cast(intptr)expected, cast(i64)cast(intptr)desired);
}
zpl_inline void *zpl_atomic_ptr_exchange(zpl_atomic_ptr volatile *a, void *desired) {
    return cast(void *)cast(intptr)zpl_atomic64_exchange(cast(zpl_atomic64 volatile *)a, cast(i64)cast(intptr)desired);
}
zpl_inline void *zpl_atomic_ptr_fetch_add(zpl_atomic_ptr volatile *a, void *operand) {
    return cast(void *)cast(intptr)zpl_atomic64_fetch_add(cast(zpl_atomic64 volatile *)a, cast(i64)cast(intptr)operand);
}
zpl_inline void *zpl_atomic_ptr_fetch_and(zpl_atomic_ptr volatile *a, void *operand) {
    return cast(void *)cast(intptr)zpl_atomic64_fetch_and(cast(zpl_atomic64 volatile *)a, cast(i64)cast(intptr)operand);
}
zpl_inline void *zpl_atomic_ptr_fetch_or(zpl_atomic_ptr volatile *a, void *operand) {
    return cast(void *)cast(intptr)zpl_atomic64_fetch_or(cast(zpl_atomic64 volatile *)a, cast(i64)cast(intptr)operand);
}
zpl_inline b32 zpl_atomic_ptr_spin_lock(zpl_atomic_ptr volatile *a, isize time_out) {
    return zpl_atomic64_spin_lock(cast(zpl_atomic64 volatile *)a, time_out);
}
zpl_inline void zpl_atomic_ptr_spin_unlock(zpl_atomic_ptr volatile *a) {
    zpl_atomic64_spin_unlock(cast(zpl_atomic64 volatile *)a);
}
zpl_inline b32 zpl_atomic_ptr_try_acquire_lock(zpl_atomic_ptr volatile *a) {
    return zpl_atomic64_try_acquire_lock(cast(zpl_atomic64 volatile *)a);
}
#endif


zpl_inline void zpl_yield_thread(void) {
#if defined(ZPL_SYSTEM_WINDOWS)
    _mm_pause();
#elif defined(ZPL_SYSTEM_OSX)
    __asm__ volatile ("" : : : "memory");
#elif defined(ZPL_CPU_X86)
    _mm_pause();
#else
#error Unknown architecture
#endif
}

zpl_inline void zpl_mfence(void) {
#if defined(ZPL_SYSTEM_WINDOWS)
    _ReadWriteBarrier();
#elif defined(ZPL_SYSTEM_OSX)
    __sync_synchronize();
#elif defined(ZPL_CPU_X86)
    _mm_mfence();
#else
#error Unknown architecture
#endif
}

zpl_inline void zpl_sfence(void) {
#if defined(ZPL_SYSTEM_WINDOWS)
    _WriteBarrier();
#elif defined(ZPL_SYSTEM_OSX)
    __asm__ volatile ("" : : : "memory");
#elif defined(ZPL_CPU_X86)
    _mm_sfence();
#else
#error Unknown architecture
#endif
}

zpl_inline void zpl_lfence(void) {
#if defined(ZPL_SYSTEM_WINDOWS)
    _ReadBarrier();
#elif defined(ZPL_SYSTEM_OSX)
    __asm__ volatile ("" : : : "memory");
#elif defined(ZPL_CPU_X86)
    _mm_lfence();
#else
#error Unknown architecture
#endif
}


zpl_inline void zpl_semaphore_release(zpl_semaphore *s) { zpl_semaphore_post(s, 1); }

#if defined(ZPL_SYSTEM_WINDOWS)
zpl_inline void zpl_semaphore_init   (zpl_semaphore *s)            { s->win32_handle = CreateSemaphoreA(NULL, 0, I32_MAX, NULL); }
zpl_inline void zpl_semaphore_destroy(zpl_semaphore *s)            { CloseHandle(s->win32_handle); }
zpl_inline void zpl_semaphore_post   (zpl_semaphore *s, i32 count) { ReleaseSemaphore(s->win32_handle, count, NULL); }
zpl_inline void zpl_semaphore_wait   (zpl_semaphore *s)            { WaitForSingleObject(s->win32_handle, INFINITE); }

#elif defined(ZPL_SYSTEM_OSX)
zpl_inline void zpl_semaphore_init   (zpl_semaphore *s)            { semaphore_create(mach_task_self(), &s->osx_handle, SYNC_POLICY_FIFO, 0); }
zpl_inline void zpl_semaphore_destroy(zpl_semaphore *s)            { semaphore_destroy(mach_task_self(), s->osx_handle); }
zpl_inline void zpl_semaphore_post   (zpl_semaphore *s, i32 count) { while (count --> 0) semaphore_signal(s->osx_handle); }
zpl_inline void zpl_semaphore_wait   (zpl_semaphore *s)            { semaphore_wait(s->osx_handle); }

#elif defined(ZPL_SYSTEM_UNIX)
zpl_inline void zpl_semaphore_init   (zpl_semaphore *s)            { sem_init(&s->unix_handle, 0, 0); }
zpl_inline void zpl_semaphore_destroy(zpl_semaphore *s)            { sem_destroy(&s->unix_handle); }
zpl_inline void zpl_semaphore_post   (zpl_semaphore *s, i32 count) { while (count --> 0) sem_post(&s->unix_handle); }
zpl_inline void zpl_semaphore_wait   (zpl_semaphore *s)            { int i; do { i = sem_wait(&s->unix_handle); } while (i == -1 && errno == EINTR); }

#else
#error
#endif

zpl_inline void zpl_mutex_init(zpl_mutex *m) {
#if defined(ZPL_SYSTEM_WINDOWS)
    InitializeCriticalSection(&m->win32_critical_section);
#else
    pthread_mutex_init(&m->pthread_mutex, NULL);
#endif
}

zpl_inline void zpl_mutex_destroy(zpl_mutex *m) {
#if defined(ZPL_SYSTEM_WINDOWS)
    DeleteCriticalSection(&m->win32_critical_section);
#else
    pthread_mutex_destroy(&m->pthread_mutex);
#endif
}

zpl_inline void zpl_mutex_lock(zpl_mutex *m) {
#if defined(ZPL_SYSTEM_WINDOWS)
    EnterCriticalSection(&m->win32_critical_section);
#else
    pthread_mutex_lock(&m->pthread_mutex);
#endif
}

zpl_inline b32 zpl_mutex_try_lock(zpl_mutex *m) {
#if defined(ZPL_SYSTEM_WINDOWS)
    return TryEnterCriticalSection(&m->win32_critical_section);
#else
    return pthread_mutex_trylock(&m->pthread_mutex);
#endif
}

zpl_inline void zpl_mutex_unlock(zpl_mutex *m) {
#if defined(ZPL_SYSTEM_WINDOWS)
    LeaveCriticalSection(&m->win32_critical_section);
#else
    pthread_mutex_unlock(&m->pthread_mutex);
#endif
}



ZPL_THREAD_PROC(zpl__async_handler) {
    zpl_async_ctl *ctl = cast(zpl_async_ctl *)thread->user_data;

    ctl->work(ctl->data);
    ctl->cb(ctl->data);

    zpl_mfree(ctl);

    return true;
}



void zpl_thread_init(zpl_thread *t) {
    zpl_zero_item(t);
#if defined(ZPL_SYSTEM_WINDOWS)
    t->win32_handle = INVALID_HANDLE_VALUE;
#else
    t->posix_handle = 0;
#endif
    zpl_semaphore_init(&t->semaphore);
}

void zpl_thread_destroy(zpl_thread *t) {
    if (t->is_running) zpl_thread_join(t);
    zpl_semaphore_destroy(&t->semaphore);
}


zpl_inline void zpl__thread_run(zpl_thread *t) {
    zpl_semaphore_release(&t->semaphore);
    t->return_value = t->proc(t);
}

#if defined(ZPL_SYSTEM_WINDOWS)
zpl_inline DWORD __stdcall zpl__thread_proc(void *arg) {
    zpl_thread *t = cast(zpl_thread *)arg;
    zpl__thread_run(t);
    t->is_running = false;
    return 0;
}
#else
zpl_inline void *          zpl__thread_proc(void *arg) {
    zpl_thread *t = cast(zpl_thread *)arg;
    zpl__thread_run(t);
    t->is_running = false;
    return NULL;
}
#endif

zpl_inline void zpl_thread_start(zpl_thread *t, zpl_thread_proc *proc, void *user_data) { zpl_thread_start_with_stack(t, proc, user_data, 0); }

zpl_inline void zpl_thread_start_with_stack(zpl_thread *t, zpl_thread_proc *proc, void *user_data, isize stack_size) {
    ZPL_ASSERT(!t->is_running);
    ZPL_ASSERT(proc != NULL);
    t->proc = proc;
    t->user_data = user_data;
    t->stack_size = stack_size;

#if defined(ZPL_SYSTEM_WINDOWS)
    t->win32_handle = CreateThread(NULL, stack_size, zpl__thread_proc, t, 0, NULL);
    ZPL_ASSERT_MSG(t->win32_handle != NULL, "CreateThread: GetLastError");
#else
    {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        if (stack_size != 0)
            pthread_attr_setstacksize(&attr, stack_size);
        pthread_create(&t->posix_handle, &attr, zpl__thread_proc, t);
        pthread_attr_destroy(&attr);
    }
#endif

    t->is_running = true;
    zpl_semaphore_wait(&t->semaphore);
}

zpl_inline void zpl_thread_join(zpl_thread *t) {
    if (!t->is_running) return;

#if defined(ZPL_SYSTEM_WINDOWS)
    WaitForSingleObject(t->win32_handle, INFINITE);
    CloseHandle(t->win32_handle);
    t->win32_handle = INVALID_HANDLE_VALUE;
#else
    pthread_join(t->posix_handle, NULL);
    t->posix_handle = 0;
#endif
    t->is_running = false;
}

zpl_inline b32 zpl_thread_is_running(zpl_thread const *t) { return t->is_running != 0; }

zpl_inline u32 zpl_thread_current_id(void) {
    u32 thread_id;
#if defined(ZPL_SYSTEM_WINDOWS)
#if defined(ZPL_ARCH_32_BIT) && defined(ZPL_CPU_X86)
    thread_id = (cast(u32 *)__readfsdword(24))[9];
#elif defined(ZPL_ARCH_64_BIT) && defined(ZPL_CPU_X86)
    thread_id = (cast(u32 *)__readgsqword(48))[18];
#else
    thread_id = GetCurrentThreadId();
#endif

#elif defined(ZPL_SYSTEM_OSX) && defined(ZPL_ARCH_64_BIT)
    thread_id = pthread_mach_thread_np(pthread_self());
#elif defined(ZPL_ARCH_32_BIT) && defined(ZPL_CPU_X86)
    __asm__("mov %%gs:0x08,%0" : "=r"(thread_id));
#elif defined(ZPL_ARCH_64_BIT) && defined(ZPL_CPU_X86)
    __asm__("mov %%fs:0x10,%0" : "=r"(thread_id));
#else
#error Unsupported architecture for zpl_thread_current_id()
#endif

    return thread_id;
}



void zpl_thread_set_name(zpl_thread *t, char const *name) {
#if defined(ZPL_COMPILER_MSVC)
#pragma pack(push, 8)
    typedef struct {
        DWORD       type;
        char const *name;
        DWORD       id;
        DWORD       flags;
    } zplprivThreadName;
#pragma pack(pop)
    zplprivThreadName tn;
    tn.type  = 0x1000;
    tn.name  = name;
    tn.id    = GetThreadId(cast(HANDLE)t->win32_handle);
    tn.flags = 0;

    __try {
        RaiseException(0x406d1388, 0, zpl_size_of(tn)/4, cast(ULONG_PTR *)&tn);
    } __except(1 /*EXCEPTION_EXECUTE_HANDLER*/) {
    }

#elif defined(ZPL_SYSTEM_WINDOWS) && !defined(ZPL_COMPILER_MSVC)
    zpl_unused(t);
    zpl_unused(name);
    // IMPORTANT TODO: Set thread name for GCC/Clang on windows
    return;
#elif defined(ZPL_SYSTEM_OSX)
    // TODO: Test if this works
    pthread_setname_np(name);
#else
    zpl_unused(t);
    zpl_unused(name);
    // TODO: Test if this works
    //        pthread_set_name_np(t->posix_handle, name);
#endif
}

void zpl_sync_init(zpl_sync *s) {
    zpl_zero_item(s);
    zpl_mutex_init(&s->mutex);
    zpl_mutex_init(&s->start);
    zpl_semaphore_init(&s->release);
}

void zpl_sync_destroy(zpl_sync *s) {
    if (s->waiting) {
        ZPL_PANIC("Cannot destroy while threads are waiting!");
    }

    zpl_mutex_destroy(&s->mutex);
    zpl_mutex_destroy(&s->start);
    zpl_semaphore_destroy(&s->release);
}

void zpl_sync_set_target(zpl_sync *s, i32 count) {
    zpl_mutex_lock(&s->start);

    zpl_mutex_lock(&s->mutex);
    ZPL_ASSERT(s->target == 0);
    s->target = count;
    s->current = 0;
    s->waiting = 0;
    zpl_mutex_unlock(&s->mutex);
}

void zpl_sync_release(zpl_sync *s) {
    if (s->waiting) {
        zpl_semaphore_release(&s->release);
    } else {
        s->target = 0;
        zpl_mutex_unlock(&s->start);
    }
}

i32 zpl_sync_reach(zpl_sync *s) {
    i32 n;
    zpl_mutex_lock(&s->mutex);
    ZPL_ASSERT(s->current < s->target);
    n = ++s->current; // NOTE: Record this value to avoid possible race if `return s->current` was done
    if (s->current == s->target)
        zpl_sync_release(s);
    zpl_mutex_unlock(&s->mutex);
    return n;
}

void zpl_sync_reach_and_wait(zpl_sync *s) {
    zpl_mutex_lock(&s->mutex);
    ZPL_ASSERT(s->current < s->target);
    s->current++;
    if (s->current == s->target) {
        zpl_sync_release(s);
        zpl_mutex_unlock(&s->mutex);
    } else {
        s->waiting++;                   // NOTE: Waiting, so one more waiter
        zpl_mutex_unlock(&s->mutex);     // NOTE: Release the mutex to other threads

        zpl_semaphore_wait(&s->release); // NOTE: Wait for merge completion

        zpl_mutex_lock(&s->mutex);       // NOTE: On merge completion, lock mutex
        s->waiting--;                   // NOTE: Done waiting
        zpl_sync_release(s);             // NOTE: Restart the next waiter
        zpl_mutex_unlock(&s->mutex);
    }
}






#if defined(ZPL_SYSTEM_WINDOWS)
void zpl_affinity_init(zpl_affinity *a) {
    SYSTEM_LOGICAL_PROCESSOR_INFORMATION *start_processor_info = NULL;
    DWORD length = 0;
    b32 result  = GetLogicalProcessorInformation(NULL, &length);

    zpl_zero_item(a);

    if (!result && GetLastError() == 122l /*ERROR_INSUFFICIENT_BUFFER*/ && length > 0) {
        start_processor_info = cast(SYSTEM_LOGICAL_PROCESSOR_INFORMATION *)zpl_alloc(zpl_heap_allocator(), length);
        result = GetLogicalProcessorInformation(start_processor_info, &length);
        if (result) {
            SYSTEM_LOGICAL_PROCESSOR_INFORMATION *end_processor_info, *processor_info;

            a->is_accurate  = true;
            a->core_count   = 0;
            a->thread_count = 0;
            end_processor_info = cast(SYSTEM_LOGICAL_PROCESSOR_INFORMATION *)zpl_pointer_add(start_processor_info, length);

            for (processor_info = start_processor_info;
                    processor_info < end_processor_info;
                    processor_info++) {
                if (processor_info->Relationship == RelationProcessorCore) {
                    isize thread = zpl_count_set_bits(processor_info->ProcessorMask);
                    if (thread == 0) {
                        a->is_accurate = false;
                    } else if (a->thread_count + thread > zpl_WIN32_MAXHREADS) {
                        a->is_accurate = false;
                    } else {
                        ZPL_ASSERT(a->core_count <= a->thread_count &&
                                    a->thread_count < zpl_WIN32_MAXHREADS);
                        a->core_masks[a->core_count++] = processor_info->ProcessorMask;
                        a->thread_count += thread;
                    }
                }
            }
        }

        zpl_free(zpl_heap_allocator(), start_processor_info);
    }

    ZPL_ASSERT(a->core_count <= a->thread_count);
    if (a->thread_count == 0) {
        a->is_accurate   = false;
        a->core_count    = 1;
        a->thread_count  = 1;
        a->core_masks[0] = 1;
    }

}
void zpl_affinity_destroy(zpl_affinity *a) {
    zpl_unused(a);
}


b32 zpl_affinity_set(zpl_affinity *a, isize core, isize thread) {
    usize available_mask, check_mask = 1;
    ZPL_ASSERT(thread < zpl_affinity_thread_count_for_core(a, core));

    available_mask = a->core_masks[core];
    for (;;) {
        if ((available_mask & check_mask) != 0) {
            if (thread-- == 0) {
                usize result = SetThreadAffinityMask(GetCurrentThread(), check_mask);
                return result != 0;
            }
        }
        check_mask <<= 1; // NOTE: Onto the next bit
    }
}

isize zpl_affinity_thread_count_for_core(zpl_affinity *a, isize core) {
    ZPL_ASSERT(core >= 0 && core < a->core_count);
    return zpl_count_set_bits(a->core_masks[core]);
}

#elif defined(ZPL_SYSTEM_OSX)
void zpl_affinity_init(zpl_affinity *a) {
    usize count, count_size = zpl_size_of(count);

    a->is_accurate      = false;
    a->thread_count     = 1;
    a->core_count       = 1;
    a->threads_per_core = 1;

    if (sysctlbyname("hw.logicalcpu", &count, &count_size, NULL, 0) == 0) {
        if (count > 0) {
            a->thread_count = count;
            // Get # of physical cores
            if (sysctlbyname("hw.physicalcpu", &count, &count_size, NULL, 0) == 0) {
                if (count > 0) {
                    a->core_count = count;
                    a->threads_per_core = a->thread_count / count;
                    if (a->threads_per_core < 1)
                        a->threads_per_core = 1;
                    else
                        a->is_accurate = true;
                }
            }
        }
    }

}

void zpl_affinity_destroy(zpl_affinity *a) {
    zpl_unused(a);
}

b32 zpl_affinity_set(zpl_affinity *a, isize core, isize thread_index) {
    isize index;
    thread_t thread;
    thread_affinity_policy_data_t info;
    kern_return_t result;

    ZPL_ASSERT(core < a->core_count);
    ZPL_ASSERT(thread_index < a->threads_per_core);

    index = core * a->threads_per_core + thread_index;
    thread = mach_thread_self();
    info.affinity_tag = cast(integer_t)index;
    result = thread_policy_set(thread, THREAD_AFFINITY_POLICY, cast(thread_policy_t)&info, THREAD_AFFINITY_POLICY_COUNT);
    return result == KERN_SUCCESS;
}

isize zpl_affinity_thread_count_for_core(zpl_affinity *a, isize core) {
    ZPL_ASSERT(core >= 0 && core < a->core_count);
    return a->threads_per_core;
}

#elif defined(ZPL_SYSTEM_LINUX)
// IMPORTANT TODO: This zpl_affinity stuff for linux needs be improved a lot!
// NOTE(zangent): I have to read /proc/cpuinfo to get the number of threads per core.
#include <stdio.h>

void zpl_affinity_init(zpl_affinity *a) {
    b32   accurate = true;
    isize threads = 0;

    a->thread_count     = 1;
    a->core_count       = sysconf(_SC_NPROCESSORS_ONLN);
    a->threads_per_core = 1;


    if(a->core_count <= 0) {
        a->core_count = 1;
        accurate = false;
    }

    // Parsing /proc/cpuinfo to get the number of threads per core.
    // NOTE(zangent): This calls the CPU's threads "cores", although the wording
    // is kind of weird. This should be right, though.
    FILE *cpu_info = fopen("/proc/cpuinfo", "r");
    if (cpu_info != NULL) {
        for (;;) {
            // The 'temporary char'. Everything goes into this char,
            // so that we can check against EOF at the end of this loop.
            char c;

#define AF__CHECK(letter) ((c = getc(cpu_info)) == letter)
            if (AF__CHECK('c') && AF__CHECK('p') && AF__CHECK('u') && AF__CHECK(' ') &&
                AF__CHECK('c') && AF__CHECK('o') && AF__CHECK('r') && AF__CHECK('e') && AF__CHECK('s')) {
                // We're on a CPU info line.
                while (!AF__CHECK(EOF)) {
                    if (c == '\n') {
                        break;
                    } else if (c < '0' || '9' > c) {
                        continue;
                    }
                    threads = threads * 10 + (c - '0');
                }
                break;
            } else {
                while (!AF__CHECK('\n')) {
                    if (c==EOF) {
                        break;
                    }
                }
            }
            if (c == EOF) {
                break;
            }
#undef AF__CHECK
        }

        fclose(cpu_info);
    }

    if (threads == 0) {
        threads  = 1;
        accurate = false;
    }

    a->threads_per_core = threads;
    a->thread_count = a->threads_per_core * a->core_count;
    a->is_accurate = accurate;

}

void zpl_affinity_destroy(zpl_affinity *a) {
    zpl_unused(a);
}

b32 zpl_affinity_set(zpl_affinity * a, isize core, isize thread_index) {
    zpl_unused(a);
    zpl_unused(core);
    zpl_unused(thread_index);
    return true;
}

isize zpl_affinity_thread_count_for_core(zpl_affinity *a, isize core) {
    ZPL_ASSERT(0 <= core && core < a->core_count);
    return a->threads_per_core;
}
#elif defined(ZPL_SYSTEM_EMSCRIPTEN)
// no code 4 u :(
#else
#error TODO: Unknown system
#endif


#endif // ZPL_THREADING


////////////////////////////////////////////////////////////////
//
// Virtual Memory
//
//

zpl_virtual_memory zpl_vm(void *data, isize size) {
    zpl_virtual_memory vm;
    vm.data = data;
    vm.size = size;
    return vm;
}


#if defined(ZPL_SYSTEM_WINDOWS)
zpl_inline zpl_virtual_memory zpl_vm_alloc(void *addr, isize size) {
    zpl_virtual_memory vm;
    ZPL_ASSERT(size > 0);
    vm.data = VirtualAlloc(addr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    vm.size = size;
    return vm;
}

zpl_inline b32 zpl_vm_free(zpl_virtual_memory vm) {
    MEMORY_BASIC_INFORMATION info;
    while (vm.size > 0) {
        if (VirtualQuery(vm.data, &info, zpl_size_of(info)) == 0)
            return false;
        if (info.BaseAddress != vm.data ||
            info.AllocationBase != vm.data ||
            info.State != MEM_COMMIT || info.RegionSize > cast(usize)vm.size) {
            return false;
        }
        if (VirtualFree(vm.data, 0, MEM_RELEASE) == 0)
            return false;
        vm.data = zpl_pointer_add(vm.data, info.RegionSize);
        vm.size -= info.RegionSize;
    }
    return true;
}

zpl_inline zpl_virtual_memory zpl_vm_trim(zpl_virtual_memory vm, isize lead_size, isize size) {
    zpl_virtual_memory new_vm = {0};
    void *ptr;
    ZPL_ASSERT(vm.size >= lead_size + size);

    ptr = zpl_pointer_add(vm.data, lead_size);

    zpl_vm_free(vm);
    new_vm = zpl_vm_alloc(ptr, size);
    if (new_vm.data == ptr)
        return new_vm;
    if (new_vm.data)
        zpl_vm_free(new_vm);
    return new_vm;
}

zpl_inline b32 zpl_vm_purge(zpl_virtual_memory vm) {
    VirtualAlloc(vm.data, vm.size, MEM_RESET, PAGE_READWRITE);
    // NOTE: Can this really fail?
    return true;
}

isize zpl_virtual_memory_page_size(isize *alignment_out) {
    SYSTEM_INFO info;
    GetSystemInfo(&info);
    if (alignment_out) *alignment_out = info.dwAllocationGranularity;
    return info.dwPageSize;
}

#else

#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS MAP_ANON
#endif

zpl_inline zpl_virtual_memory zpl_vm_alloc(void *addr, isize size) {
    zpl_virtual_memory vm;
    ZPL_ASSERT(size > 0);
    vm.data = mmap(addr, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    vm.size = size;
    return vm;
}

zpl_inline b32 zpl_vm_free(zpl_virtual_memory vm) {
    munmap(vm.data, vm.size);
    return true;
}

zpl_inline zpl_virtual_memory zpl_vm_trim(zpl_virtual_memory vm, isize lead_size, isize size) {
    void *ptr;
    isize trail_size;
    ZPL_ASSERT(vm.size >= lead_size + size);

    ptr = zpl_pointer_add(vm.data, lead_size);
    trail_size = vm.size - lead_size - size;

    if (lead_size != 0)
        zpl_vm_free(zpl_vm(vm.data, lead_size));
    if (trail_size != 0)
        zpl_vm_free(zpl_vm(ptr, trail_size));
    return zpl_vm(ptr, size);

}

zpl_inline b32 zpl_vm_purge(zpl_virtual_memory vm) {
    int err = madvise(vm.data, vm.size, MADV_DONTNEED);
    return err != 0;
}

isize zpl_virtual_memory_page_size(isize *alignment_out) {
    // TODO: Is this always true?
    isize result = cast(isize)sysconf(_SC_PAGE_SIZE);
    if (alignment_out) *alignment_out = result;
    return result;
}

#endif




////////////////////////////////////////////////////////////////
//
// Custom Allocation
//
//

//
// Heap Allocator
//

zpl_inline zpl_allocator zpl_heap_allocator(void) {
    zpl_allocator a;
    a.proc = zpl_heap_allocator_proc;
    a.data = NULL;
    return a;
}

ZPL_ALLOCATOR_PROC(zpl_heap_allocator_proc) {
    void *ptr = NULL;
    zpl_unused(allocator_data);
    zpl_unused(old_size);
    // TODO: Throughly test!
    switch (type) {
#if defined(ZPL_COMPILER_MSVC) || (defined(ZPL_COMPILER_GCC) && defined(ZPL_SYSTEM_WINDOWS))
        case ZPL_ALLOCATION_ALLOC:
            ptr = _aligned_malloc(size, alignment);
            if (flags & ZPL_ALLOCATOR_FLAG_CLEAR_TO_ZERO)
                zpl_zero_size(ptr, size);
            break;
        case ZPL_ALLOCATION_FREE:
            _aligned_free(old_memory);
            break;
        case ZPL_ALLOCATION_RESIZE:
            ptr = _aligned_realloc(old_memory, size, alignment);
            break;

#elif defined(ZPL_SYSTEM_LINUX) && !defined(ZPL_CPU_ARM)
        case ZPL_ALLOCATION_ALLOC: {
                ptr = aligned_alloc(alignment, size);

                if (flags & ZPL_ALLOCATOR_FLAG_CLEAR_TO_ZERO) {
                    zpl_zero_size(ptr, size);
                }
            } break;

            case ZPL_ALLOCATION_FREE: {
                free(old_memory);
            } break;

            case ZPL_ALLOCATION_RESIZE: {
                zpl_allocator a = zpl_heap_allocator();
                ptr = zpl_default_resize_align(a, old_memory, old_size, size, alignment);
            } break;
#else
        case ZPL_ALLOCATION_ALLOC: {
            posix_memalign(&ptr, alignment, size);

            if (flags & ZPL_ALLOCATOR_FLAG_CLEAR_TO_ZERO) {
                zpl_zero_size(ptr, size);
            }
        } break;

        case ZPL_ALLOCATION_FREE: {
            free(old_memory);
        } break;

        case ZPL_ALLOCATION_RESIZE: {
            zpl_allocator a = zpl_heap_allocator();
            ptr = zpl_default_resize_align(a, old_memory, old_size, size, alignment);
        } break;
#endif

        case ZPL_ALLOCATION_FREE_ALL:
            break;
    }

    return ptr;
}


//
// Arena Allocator
//

zpl_inline void zpl_arena_init_from_memory(zpl_arena *arena, void *start, isize size) {
    arena->backing.proc    = NULL;
    arena->backing.data    = NULL;
    arena->physical_start  = start;
    arena->total_size      = size;
    arena->total_allocated = 0;
    arena->temp_count      = 0;
}

zpl_inline void zpl_arena_init_from_allocator(zpl_arena *arena, zpl_allocator backing, isize size) {
    arena->backing         = backing;
    arena->physical_start  = zpl_alloc(backing, size); // NOTE: Uses default alignment
    arena->total_size      = size;
    arena->total_allocated = 0;
    arena->temp_count      = 0;
}

zpl_inline void zpl_arena_init_sub(zpl_arena *arena, zpl_arena *parent_arena, isize size) { zpl_arena_init_from_allocator(arena, zpl_arena_allocator(parent_arena), size); }


zpl_inline void zpl_arena_free(zpl_arena *arena) {
    if (arena->backing.proc) {
        zpl_free(arena->backing, arena->physical_start);
        arena->physical_start = NULL;
    }
}


zpl_inline isize zpl_arena_alignment_of(zpl_arena *arena, isize alignment) {
    isize alignment_offset, result_pointer, mask;
    ZPL_ASSERT(zpl_is_power_of_two(alignment));

    alignment_offset = 0;
    result_pointer = cast(isize)arena->physical_start + arena->total_allocated;
    mask = alignment - 1;
    if (result_pointer & mask)
        alignment_offset = alignment - (result_pointer & mask);

    return alignment_offset;
}

zpl_inline isize zpl_arena_size_remaining(zpl_arena *arena, isize alignment) {
    isize result = arena->total_size - (arena->total_allocated + zpl_arena_alignment_of(arena, alignment));
    return result;
}

zpl_inline void zpl_arena_check(zpl_arena *arena) { ZPL_ASSERT(arena->temp_count == 0); }






zpl_inline zpl_allocator zpl_arena_allocator(zpl_arena *arena) {
    zpl_allocator allocator;
    allocator.proc = zpl_arena_allocator_proc;
    allocator.data = arena;
    return allocator;
}

ZPL_ALLOCATOR_PROC(zpl_arena_allocator_proc) {
    zpl_arena *arena = cast(zpl_arena *)allocator_data;
    void *ptr = NULL;

    zpl_unused(old_size);

    switch (type) {
    case ZPL_ALLOCATION_ALLOC: {
        void *end = zpl_pointer_add(arena->physical_start, arena->total_allocated);
        isize total_size = size + alignment;

        // NOTE: Out of memory
        if (arena->total_allocated + total_size > cast(isize)arena->total_size) {
            zpl_printf_err("Arena out of memory\n");
            return NULL;
        }

        ptr = zpl_align_forward(end, alignment);
        arena->total_allocated += total_size;
        if (flags & ZPL_ALLOCATOR_FLAG_CLEAR_TO_ZERO)
            zpl_zero_size(ptr, size);
    } break;

    case ZPL_ALLOCATION_FREE:
        // NOTE: Free all at once
        // Use Temp_Arena_Memory if you want to free a block
        break;

    case ZPL_ALLOCATION_FREE_ALL:
        arena->total_allocated = 0;
        break;

    case ZPL_ALLOCATION_RESIZE: {
        // TODO: Check if ptr is on top of stack and just extend
        zpl_allocator a = zpl_arena_allocator(arena);
        ptr = zpl_default_resize_align(a, old_memory, old_size, size, alignment);
    } break;
    }
    return ptr;
}


zpl_inline zpl_temp_arena_memory zpl_temp_arena_memory_begin(zpl_arena *arena) {
    zpl_temp_arena_memory tmp;
    tmp.arena = arena;
    tmp.original_count = arena->total_allocated;
    arena->temp_count++;
    return tmp;
}

zpl_inline void zpl_temp_arena_memory_end(zpl_temp_arena_memory tmp) {
    ZPL_ASSERT(tmp.arena->total_allocated >= tmp.original_count);
    ZPL_ASSERT(tmp.arena->temp_count > 0);
    tmp.arena->total_allocated = tmp.original_count;
    tmp.arena->temp_count--;
}




//
// Pool Allocator
//


zpl_inline void zpl_pool_init(zpl_pool *pool, zpl_allocator backing, isize num_blocks, isize block_size) {
    zpl_pool_init_align(pool, backing, num_blocks, block_size, ZPL_DEFAULT_MEMORY_ALIGNMENT);
}

void zpl_pool_init_align(zpl_pool *pool, zpl_allocator backing, isize num_blocks, isize block_size, isize block_align) {
    isize actual_block_size, pool_size, block_index;
    void *data, *curr;
    uintptr *end;

    zpl_zero_item(pool);

    pool->backing = backing;
    pool->block_size = block_size;
    pool->block_align = block_align;

    actual_block_size = block_size + block_align;
    pool_size = num_blocks * actual_block_size;

    data = zpl_alloc_align(backing, pool_size, block_align);

    // NOTE: Init intrusive freelist
    curr = data;
    for (block_index = 0; block_index < num_blocks-1; block_index++) {
        uintptr *next = cast(uintptr *)curr;
        *next = cast(uintptr)curr + actual_block_size;
        curr = zpl_pointer_add(curr, actual_block_size);
    }

    end  = cast(uintptr *)curr;
    *end = cast(uintptr)NULL;

    pool->physical_start = data;
    pool->free_list      = data;
}

zpl_inline void zpl_pool_free(zpl_pool *pool) {
    if (pool->backing.proc) {
        zpl_free(pool->backing, pool->physical_start);
    }
}


zpl_inline zpl_allocator zpl_pool_allocator(zpl_pool *pool) {
    zpl_allocator allocator;
    allocator.proc = zpl_pool_allocator_proc;
    allocator.data = pool;
    return allocator;
}
ZPL_ALLOCATOR_PROC(zpl_pool_allocator_proc) {
    zpl_pool *pool = cast(zpl_pool *)allocator_data;
    void *ptr = NULL;

    zpl_unused(old_size);

    switch (type) {
    case ZPL_ALLOCATION_ALLOC: {
        uintptr next_free;
        ZPL_ASSERT(size      == pool->block_size);
        ZPL_ASSERT(alignment == pool->block_align);
        ZPL_ASSERT(pool->free_list != NULL);

        next_free = *cast(uintptr *)pool->free_list;
        ptr = pool->free_list;
        pool->free_list = cast(void *)next_free;
        pool->total_size += pool->block_size;
        if (flags & ZPL_ALLOCATOR_FLAG_CLEAR_TO_ZERO)
            zpl_zero_size(ptr, size);
    } break;

    case ZPL_ALLOCATION_FREE: {
        uintptr *next;
        if (old_memory == NULL) return NULL;

        next = cast(uintptr *)old_memory;
        *next = cast(uintptr)pool->free_list;
        pool->free_list = old_memory;
        pool->total_size -= pool->block_size;
    } break;

    case ZPL_ALLOCATION_FREE_ALL:
        // TODO:
        break;

    case ZPL_ALLOCATION_RESIZE:
        // NOTE: Cannot resize
        ZPL_PANIC("You cannot resize something allocated by with a pool.");
        break;
    }

    return ptr;
}





zpl_inline zpl_allocation_header_ev *zpl_allocation_header(void *data) {
    isize *p = cast(isize *)data;
    while (p[-1] == cast(isize)(-1))
        p--;
    return cast(zpl_allocation_header_ev *)p - 1;
}

zpl_inline void zpl_allocation_header_fill(zpl_allocation_header_ev *header, void *data, isize size) {
    isize *ptr;
    header->size = size;
    ptr = cast(isize *)(header + 1);
    while (cast(void *)ptr < data)
        *ptr++ = cast(isize)(-1);
}

//
// Scratch Memory Allocator
//

void zpl_scratch_memory_init(zpl_scratch_memory *s, void *start, isize size) {
    s->physical_start = start;
    s->total_size     = size;
    s->alloc_point    = start;
    s->free_point     = start;
}


b32 zpl_scratch_memory_is_in_use(zpl_scratch_memory *s, void *ptr) {
    if (s->free_point == s->alloc_point) return false;
    if (s->alloc_point > s->free_point)
        return ptr >= s->free_point && ptr < s->alloc_point;
    return ptr >= s->free_point || ptr < s->alloc_point;
}


zpl_allocator zpl_scratch_allocator(zpl_scratch_memory *s) {
    zpl_allocator a;
    a.proc = zpl_scratch_allocator_proc;
    a.data = s;
    return a;
}

ZPL_ALLOCATOR_PROC(zpl_scratch_allocator_proc) {
    zpl_scratch_memory *s = cast(zpl_scratch_memory *)allocator_data;
    void *ptr = NULL;
    ZPL_ASSERT_NOT_NULL(s);

    switch (type) {
    case ZPL_ALLOCATION_ALLOC: {
        void *pt = s->alloc_point;
        zpl_allocation_header_ev *header = cast(zpl_allocation_header_ev *)pt;
        void *data = zpl_align_forward(header+1, alignment);
        void *end = zpl_pointer_add(s->physical_start, s->total_size);

        ZPL_ASSERT(alignment % 4 == 0);
        size = ((size + 3)/4)*4;
        pt = zpl_pointer_add(pt, size);

        // NOTE: Wrap around
        if (pt > end) {
            header->size = zpl_pointer_diff(header, end) | ZPL_ISIZE_HIGH_BIT;
            pt = s->physical_start;
            header = cast(zpl_allocation_header_ev *)pt;
            data = zpl_align_forward(header+1, alignment);
            pt = zpl_pointer_add(pt, size);
        }

        if (!zpl_scratch_memory_is_in_use(s, pt)) {
            zpl_allocation_header_fill(header, pt, zpl_pointer_diff(header, pt));
            s->alloc_point = cast(u8 *)pt;
            ptr = data;
        }

        if (flags & ZPL_ALLOCATOR_FLAG_CLEAR_TO_ZERO)
            zpl_zero_size(ptr, size);
    } break;

    case ZPL_ALLOCATION_FREE: {
        if (old_memory) {
            void *end = zpl_pointer_add(s->physical_start, s->total_size);
            if (old_memory < s->physical_start || old_memory >= end) {
                ZPL_ASSERT(false);
            } else {
                // NOTE: Mark as free
                zpl_allocation_header_ev *h = zpl_allocation_header(old_memory);
                ZPL_ASSERT((h->size & ZPL_ISIZE_HIGH_BIT) == 0);
                h->size = h->size | ZPL_ISIZE_HIGH_BIT;

                while (s->free_point != s->alloc_point) {
                    zpl_allocation_header_ev *header = cast(zpl_allocation_header_ev *)s->free_point;
                    if ((header->size & ZPL_ISIZE_HIGH_BIT) == 0)
                        break;

                    s->free_point = zpl_pointer_add(s->free_point, h->size & (~ZPL_ISIZE_HIGH_BIT));
                    if (s->free_point == end)
                        s->free_point = s->physical_start;
                }
            }
        }
    } break;

    case ZPL_ALLOCATION_FREE_ALL:
        s->alloc_point = s->physical_start;
        s->free_point  = s->physical_start;
        break;

    case ZPL_ALLOCATION_RESIZE:
        ptr = zpl_default_resize_align(zpl_scratch_allocator(s), old_memory, old_size, size, alignment);
        break;
    }

    return ptr;
}

//
// Stack Memory Allocator
//

#define ZPL_STACK_ALLOC_OFFSET sizeof(u64)
ZPL_STATIC_ASSERT(ZPL_STACK_ALLOC_OFFSET == 8);

zpl_inline void zpl_stack_memory_init_from_memory(zpl_stack_memory *s, void *start, isize size) {
    s->physical_start = start;
    s->total_size = size;
    s->allocated = 0;
}

zpl_inline void zpl_stack_memory_init(zpl_stack_memory *s, zpl_allocator backing, isize size) {
    s->backing = backing;
    s->physical_start = zpl_alloc(backing, size);
    s->total_size = size;
    s->allocated = 0;
}

zpl_inline b32 zpl_stack_memory_is_in_use(zpl_stack_memory *s, void *ptr) {
    if (s->allocated == 0) return false;

    if (ptr > s->physical_start && ptr < zpl_pointer_add(s->physical_start, s->total_size)) {
        return true;
    }

    return false;
}

zpl_inline void zpl_stack_memory_free(zpl_stack_memory *s) {
    if (s->backing.proc) {
        zpl_free(s->backing, s->physical_start);
        s->physical_start = NULL;
    }
}

zpl_inline zpl_allocator zpl_stack_allocator(zpl_stack_memory *s) {
    zpl_allocator a;
    a.proc = zpl_stack_allocator_proc;
    a.data = s;
    return a;
}

ZPL_ALLOCATOR_PROC(zpl_stack_allocator_proc) {
    zpl_stack_memory *s = cast(zpl_stack_memory *)allocator_data;
    void *ptr = NULL;
    ZPL_ASSERT_NOT_NULL(s);
    zpl_unused(old_size);
    zpl_unused(flags);

    switch(type) {
    case ZPL_ALLOCATION_ALLOC: {
        size += ZPL_STACK_ALLOC_OFFSET;
        u64 alloc_offset = s->allocated;

        void *curr = cast(u64 *)zpl_align_forward(cast(u64 *)zpl_pointer_add(s->physical_start, s->allocated), alignment);

        if (cast(u64 *)zpl_pointer_add(curr, size) > cast(u64 *)zpl_pointer_add(s->physical_start, s->total_size)) {
            if (s->backing.proc) {
                void *old_start=s->physical_start;
                s->physical_start = zpl_resize_align(s->backing, s->physical_start, s->total_size, s->total_size + size, alignment);
                curr = cast(u64 *)zpl_align_forward(cast(u64 *)zpl_pointer_add(s->physical_start, s->allocated), alignment);
                s->total_size = zpl_pointer_diff(old_start, s->physical_start);
            }
            else {
                ZPL_PANIC("Can not resize stack's memory! Allocator not defined!");
            }
        }

        s->allocated = zpl_pointer_diff(s->physical_start, curr) + size;

        *(u64 *)curr = alloc_offset;
        curr = zpl_pointer_add(curr, ZPL_STACK_ALLOC_OFFSET);

        ptr = curr;
    }break;

    case ZPL_ALLOCATION_FREE: {
        if (old_memory) {
            void *curr = old_memory;
            curr = zpl_pointer_sub(curr, ZPL_STACK_ALLOC_OFFSET);

            u64 alloc_offset = *(u64 *)curr;
            s->allocated = (usize)alloc_offset;
        }
    }break;

    case ZPL_ALLOCATION_FREE_ALL: {
        s->allocated = 0;
    }break;

    case ZPL_ALLOCATION_RESIZE: {
        ZPL_PANIC("You cannot resize something allocated by a stack.");
    }break;
    }
    return ptr;
}

////////////////////////////////////////////////////////////////
//
// Sorting
//
//

// TODO: Should I make all the macros local?

#define ZPL__COMPARE_PROC(Type)                                         \
zpl_global isize zpl__##Type##_cmp_offset; ZPL_COMPARE_PROC(zpl__##Type##_cmp) { \
    Type const p = *cast(Type const *)zpl_pointer_add_const(a, zpl__##Type##_cmp_offset); \
    Type const q = *cast(Type const *)zpl_pointer_add_const(b, zpl__##Type##_cmp_offset); \
    return p < q ? -1 : p > q;                                      \
}                                                                   \
ZPL_COMPARE_PROC_PTR(zpl_##Type##_cmp(isize offset)) {              \
    zpl__##Type##_cmp_offset = offset;                              \
    return &zpl__##Type##_cmp;                                      \
}


ZPL__COMPARE_PROC(i16);
ZPL__COMPARE_PROC(i32);
ZPL__COMPARE_PROC(i64);
ZPL__COMPARE_PROC(isize);
ZPL__COMPARE_PROC(f32);
ZPL__COMPARE_PROC(f64);
ZPL__COMPARE_PROC(char);

// NOTE: str_cmp is special as it requires a funny type and funny comparison
zpl_global isize zpl__str_cmp_offset; ZPL_COMPARE_PROC(zpl__str_cmp) {
    char const *p = *cast(char const **)zpl_pointer_add_const(a, zpl__str_cmp_offset);
    char const *q = *cast(char const **)zpl_pointer_add_const(b, zpl__str_cmp_offset);
    return zpl_strcmp(p, q);
}
ZPL_COMPARE_PROC_PTR(zpl_str_cmp(isize offset)) {
    zpl__str_cmp_offset = offset;
    return &zpl__str_cmp;
}

#undef ZPL__COMPARE_PROC




// TODO: Make user definable?
#define ZPL__SORT_STACK_SIZE            64
#define zpl__SORT_INSERT_SORT_TRESHOLD  8

#define ZPL__SORT_PUSH(_base, _limit) do {      \
    stack_ptr[0] = (_base);                 \
    stack_ptr[1] = (_limit);                \
    stack_ptr += 2;                         \
} while (0)


#define ZPL__SORT_POP(_base, _limit) do {       \
    stack_ptr -= 2;                         \
    (_base)  = stack_ptr[0];                \
    (_limit) = stack_ptr[1];                \
} while (0)



void zpl_sort(void *base_, isize count, isize size, zpl_compare_proc cmp) {
    u8 *i, *j;
    u8 *base = cast(u8 *)base_;
    u8 *limit = base + count*size;
    isize threshold = zpl__SORT_INSERT_SORT_TRESHOLD * size;

    // NOTE: Prepare the stack
    u8 *stack[ZPL__SORT_STACK_SIZE] = {0};
    u8 **stack_ptr = stack;

    for (;;) {
        if ((limit-base) > threshold) {
            // NOTE: Quick sort
            i = base + size;
            j = limit - size;

            zpl_memswap(((limit-base)/size/2) * size + base, base, size);
            if (cmp(i, j) > 0)    zpl_memswap(i, j, size);
            if (cmp(base, j) > 0) zpl_memswap(base, j, size);
            if (cmp(i, base) > 0) zpl_memswap(i, base, size);

            for (;;) {
                do i += size; while (cmp(i, base) < 0);
                do j -= size; while (cmp(j, base) > 0);
                if (i > j) break;
                zpl_memswap(i, j, size);
            }

            zpl_memswap(base, j, size);

            if (j - base > limit - i) {
                ZPL__SORT_PUSH(base, j);
                base = i;
            } else {
                ZPL__SORT_PUSH(i, limit);
                limit = j;
            }
        } else {
            // NOTE: Insertion sort
            for (j = base, i = j+size;
                    i < limit;
                    j = i, i += size) {
                for (; cmp(j, j+size) > 0; j -= size) {
                    zpl_memswap(j, j+size, size);
                    if (j == base) break;
                }
            }

            if (stack_ptr == stack) break; // NOTE: Sorting is done!
            ZPL__SORT_POP(base, limit);
        }
    }
}

#undef ZPL__SORT_PUSH
#undef ZPL__SORT_POP


#define ZPL_RADIX_SORT_PROC_GEN(Type) ZPL_RADIX_SORT_PROC(Type) {       \
    Type *source = items;                                           \
    Type *dest   = temp;                                            \
    isize byte_index, i, byte_max = 8*zpl_size_of(Type);            \
    for (byte_index = 0; byte_index < byte_max; byte_index += 8) {  \
        isize offsets[256] = {0};                                   \
        isize total = 0;                                            \
        /* NOTE: First pass - count how many of each key */         \
        for (i = 0; i < count; i++) {                               \
            Type radix_value = source[i];                           \
            Type radix_piece = (radix_value >> byte_index) & 0xff;  \
            offsets[radix_piece]++;                                 \
        }                                                           \
        /* NOTE: Change counts to offsets */                        \
        for (i = 0; i < zpl_count_of(offsets); i++) {               \
            isize skcount = offsets[i];                             \
            offsets[i] = total;                                     \
            total += skcount;                                       \
        }                                                           \
        /* NOTE: Second pass - place elements into the right location */ \
        for (i = 0; i < count; i++) {                               \
            Type radix_value = source[i];                           \
            Type radix_piece = (radix_value >> byte_index) & 0xff;  \
            dest[offsets[radix_piece]++] = source[i];               \
        }                                                           \
        zpl_swap(Type *, source, dest);                             \
    }                                                               \
}

ZPL_RADIX_SORT_PROC_GEN(u8);
ZPL_RADIX_SORT_PROC_GEN(u16);
ZPL_RADIX_SORT_PROC_GEN(u32);
ZPL_RADIX_SORT_PROC_GEN(u64);

zpl_inline isize zpl_binary_search(void const *base, isize count, isize size, void const *key, zpl_compare_proc compare_proc) {
    isize start = 0;
    isize end = count;

    while (start < end) {
        isize mid = start + (end-start)/2;
        isize result = compare_proc(key, cast(u8 *)base + mid*size);
        if (result < 0)
            end = mid;
        else if (result > 0)
            start = mid+1;
        else
            return mid;
    }

    return -1;
}

void zpl_shuffle(void *base, isize count, isize size) {
    u8 *a;
    isize i, j;
    zpl_random random; zpl_random_init(&random);

    a = cast(u8 *)base + (count-1) * size;
    for (i = count; i > 1; i--) {
        j = zpl_random_gen_isize(&random) % i;
        zpl_memswap(a, cast(u8 *)base + j*size, size);
        a -= size;
    }
}

void zpl_reverse(void *base, isize count, isize size) {
    isize i, j = count-1;
    for (i = 0; i < j; i++, j++)
        zpl_memswap(cast(u8 *)base + i*size, cast(u8 *)base + j*size, size);
}



////////////////////////////////////////////////////////////////
//
// Char things
//
//




zpl_inline char zpl_char_to_lower(char c) {
    if (c >= 'A' && c <= 'Z')
        return 'a' + (c - 'A');
    return c;
}

zpl_inline char zpl_char_to_upper(char c) {
    if (c >= 'a' && c <= 'z')
        return 'A' + (c - 'a');        return c;
}

zpl_inline b32 zpl_char_is_space(char c) {
    if (c == ' '  ||
        c == '\t' ||
        c == '\n' ||
        c == '\r' ||
        c == '\f' ||
        c == '\v')
        return true;
    return false;
}

zpl_inline b32 zpl_char_is_digit(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

zpl_inline b32 zpl_char_is_hex_digit(char c) {
    if (zpl_char_is_digit(c) ||
        (c >= 'a' && c <= 'f') ||
        (c >= 'A' && c <= 'F'))
        return true;
    return false;
}

zpl_inline b32 zpl_char_is_alpha(char c) {
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
        return true;
    return false;
}

zpl_inline b32 zpl_char_is_alphanumeric(char c) {
    return zpl_char_is_alpha(c) || zpl_char_is_digit(c);
}

zpl_inline i32 zpl_digit_to_int(char c) {
    return zpl_char_is_digit(c) ? c - '0' : c - 'W';
}

zpl_inline i32 zpl_hex_digit_to_int(char c) {
    if (zpl_char_is_digit(c))
        return zpl_digit_to_int(c);
    else if (zpl_is_between(c, 'a', 'f'))
        return c - 'a' + 10;
    else if (zpl_is_between(c, 'A', 'F'))
        return c - 'A' + 10;
    return -1;
}




zpl_inline void zpl_str_to_lower(char *str) {
    if (!str) return;
    while (*str) {
        *str = zpl_char_to_lower(*str);
        str++;
    }
}

zpl_inline void zpl_str_to_upper(char *str) {
    if (!str) return;
    while (*str) {
        *str = zpl_char_to_upper(*str);
        str++;
    }
}


zpl_inline isize zpl_strlen(char const *str) {
    if (str == NULL) {
        return 0;
    }

    char const *begin = str;
    isize const *w;
    while (cast(uintptr)str % sizeof(usize)) {
        if (!*str)
            return str - begin;
        str++;
    }
    w = cast(isize const *)str;
    while (!ZPL__HAS_ZERO(*w))
        w++;
    str = cast(char const *)w;
    while (*str)
        str++;
    return str - begin;
}

zpl_inline isize zpl_strnlen(char const *str, isize max_len) {
    char const *end = cast(char const *)zpl_memchr(str, 0, max_len);
    if (end)
        return end - str;
    return max_len;
}

zpl_inline isize zpl_utf8_strlen(u8 const *str) {
    isize count = 0;
    for (; *str; count++) {
        u8 c = *str;
        isize inc = 0;
        if (c < 0x80)           inc = 1;
        else if ((c & 0xe0) == 0xc0) inc = 2;
        else if ((c & 0xf0) == 0xe0) inc = 3;
        else if ((c & 0xf8) == 0xf0) inc = 4;
        else return -1;

        str += inc;
    }
    return count;
}

zpl_inline isize zpl_utf8_strnlen(u8 const *str, isize max_len) {
    isize count = 0;
    for (; *str && max_len > 0; count++) {
        u8 c = *str;
        isize inc = 0;
        if (c < 0x80)           inc = 1;
        else if ((c & 0xe0) == 0xc0) inc = 2;
        else if ((c & 0xf0) == 0xe0) inc = 3;
        else if ((c & 0xf8) == 0xf0) inc = 4;
        else return -1;

        str += inc;
        max_len -= inc;
    }
    return count;
}


zpl_inline i32 zpl_strcmp(char const *s1, char const *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++, s2++;
    }
    return *(u8 *)s1 - *(u8 *)s2;
}

zpl_inline char *zpl_strcpy(char *dest, char const *source) {
    ZPL_ASSERT_NOT_NULL(dest);
    if (source) {
        char *str = dest;
        while (*source) *str++ = *source++;
    }
    return dest;
}

zpl_inline char *zpl_strdup(zpl_allocator a, char *src, isize max_len) {
    ZPL_ASSERT_NOT_NULL(src);
    isize len=zpl_strlen(src);
    char *dest = cast(char *)zpl_alloc(a, max_len);
    zpl_memset(dest + len, 0, max_len - len);
    zpl_strncpy(dest, src, max_len);

    return dest;
}


zpl_inline char *zpl_strncpy(char *dest, char const *source, isize len) {
    ZPL_ASSERT_NOT_NULL(dest);
    if (source) {
        char *str = dest;
        while (len > 0 && *source) {
            *str++ = *source++;
            len--;
        }
        while (len > 0) {
            *str++ = '\0';
            len--;
        }
    }
    return dest;
}

zpl_inline isize zpl_strlcpy(char *dest, char const *source, isize len) {
    isize result = 0;
    ZPL_ASSERT_NOT_NULL(dest);
    if (source) {
        char const *source_start = source;
        char *str = dest;
        while (len > 0 && *source) {
            *str++ = *source++;
            len--;
        }
        while (len > 0) {
            *str++ = '\0';
            len--;
        }

        result = source - source_start;
    }
    return result;
}

zpl_inline char *zpl_strrev(char *str) {
    isize len = zpl_strlen(str);
    char *a = str + 0;
    char *b = str + len-1;
    len /= 2;
    while (len--) {
        zpl_swap(char, *a, *b);
        a++, b--;
    }
    return str;
}




zpl_inline i32 zpl_strncmp(char const *s1, char const *s2, isize len) {
    for (; len > 0;
            s1++, s2++, len--) {
        if (*s1 != *s2)
            return ((s1 < s2) ? -1 : +1);
        else if (*s1 == '\0')
            return 0;
    }
    return 0;
}


zpl_inline char const *zpl_strtok(char *output, char const *src, char const *delimit) {
    while (*src && zpl_char_first_occurence(delimit, *src) != NULL)
        *output++ = *src++;

    *output = 0;
    return *src ? src+1 : src;
}

zpl_inline char **zpl_str_split_lines(zpl_allocator alloc, char *source, b32 strip_whitespace)
{
    char **lines=NULL, *p=source, *pd=p;
    zpl_array_init(lines, alloc);

    while (*p) {
        if (*pd == '\n') {
            *pd=0;
            if (*(pd-1) == '\r') *(pd-1)=0;
            if (strip_whitespace && (pd-p)==0) { p=pd+1; continue; }
            zpl_array_append(lines, p);
            p=pd+1;
        }
        ++pd;
    }
    return lines;
}

zpl_inline b32 zpl_str_has_prefix(char const *str, char const *prefix) {
    while (*prefix) {
        if (*str++ != *prefix++)
            return false;
    }
    return true;
}

zpl_inline b32 zpl_str_has_suffix(char const *str, char const *suffix) {
    isize i = zpl_strlen(str);
    isize j = zpl_strlen(suffix);
    if (j <= i)
        return zpl_strcmp(str+i-j, suffix) == 0;
    return false;
}




zpl_inline char const *zpl_char_first_occurence(char const *s, char c) {
    char ch = c;
    for (; *s != ch; s++) {
        if (*s == '\0')
            return NULL;
    }
    return s;
}


zpl_inline char const *zpl_char_last_occurence(char const *s, char c) {
    char const *result = NULL;
    do {
        if (*s == c)
            result = s;
    } while (*s++);

    return result;
}



zpl_inline void zpl_str_concat(char *dest, isize dest_len,
                                char const *src_a, isize src_a_len,
                                char const *src_b, isize src_b_len) {
    ZPL_ASSERT(dest_len >= src_a_len+src_b_len+1);
    if (dest) {
        zpl_memcopy(dest, src_a, src_a_len);
        zpl_memcopy(dest+src_a_len, src_b, src_b_len);
        dest[src_a_len+src_b_len] = '\0';
    }
}


zpl_internal isize zpl__scan_i64(char const *text, i32 base, i64 *value) {
    char const *text_begin = text;
    i64 result = 0;
    b32 negative = false;

    if (*text == '-') {
        negative = true;
        text++;
    }

    if (base == 16 && zpl_strncmp(text, "0x", 2) == 0)
        text += 2;

    for (;;) {
        i64 v;
        if (zpl_char_is_digit(*text))
            v = *text - '0';
        else if (base == 16 && zpl_char_is_hex_digit(*text))
            v = zpl_hex_digit_to_int(*text);
        else
            break;

        result *= base;
        result += v;
        text++;
    }

    if (value) {
        if (negative) result = -result;
        *value = result;
    }

    return (text - text_begin);
}

zpl_internal isize zpl__scan_u64(char const *text, i32 base, u64 *value) {
    char const *text_begin = text;
    u64 result = 0;

    if (base == 16 && zpl_strncmp(text, "0x", 2) == 0)
        text += 2;

    for (;;) {
        u64 v;
        if (zpl_char_is_digit(*text))
            v = *text - '0';
        else if (base == 16 && zpl_char_is_hex_digit(*text))
            v = zpl_hex_digit_to_int(*text);
        else {
            break;
        }

        result *= base;
        result += v;
        text++;
    }

    if (value)
        *value = result;

    return (text - text_begin);
}


// TODO: Make better
u64 zpl_str_to_u64(char const *str, char **end_ptr, i32 base) {
    isize len;
    u64 value = 0;

    if (!base) {
        if ((zpl_strlen(str) > 2) && (zpl_strncmp(str, "0x", 2) == 0))
            base = 16;
        else
            base = 10;
    }

    len = zpl__scan_u64(str, base, &value);
    if (end_ptr)
        *end_ptr = (char *)str + len;
    return value;
}

i64 zpl_str_to_i64(char const *str, char **end_ptr, i32 base) {
    isize len;
    i64 value;

    if (!base) {
        if ((zpl_strlen(str) > 2) && (zpl_strncmp(str, "0x", 2) == 0))
            base = 16;
        else
            base = 10;
    }

    len = zpl__scan_i64(str, base, &value);
    if (end_ptr)
        *end_ptr = (char *)str + len;
    return value;
}

// TODO: Are these good enough for characters?
zpl_global char const zpl__num_to_char_table[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "@$";

zpl_inline void zpl_i64_to_str(i64 value, char *string, i32 base) {
    char *buf = string;
    b32 negative = false;
    u64 v;

    if (value < 0) {
        negative = true;
        value = -value;
    }

    v = cast(u64)value;
    if (v != 0) {
        while (v > 0) {
            *buf++ = zpl__num_to_char_table[v % base];
            v /= base;
        }
    } else {
        *buf++ = '0';
    }
    if (negative)
        *buf++ = '-';
    *buf = '\0';
    zpl_strrev(string);
}



zpl_inline void zpl_u64_to_str(u64 value, char *string, i32 base) {
    char *buf = string;

    if (value) {
        while (value > 0) {
            *buf++ = zpl__num_to_char_table[value % base];
            value /= base;
        }
    } else {
        *buf++ = '0';
    }
    *buf = '\0';

    zpl_strrev(string);
}

zpl_inline f32 zpl_str_to_f32(char const *str, char **end_ptr) {
    f64 f = zpl_str_to_f64(str, end_ptr);
    f32 r = cast(f32)f;
    return r;
}

zpl_inline f64 zpl_str_to_f64(char const *str, char **end_ptr) {
    f64 result, value, sign, scale;
    i32 frac;

    while (zpl_char_is_space(*str)) {
        str++;
    }

    sign = 1.0;
    if (*str == '-') {
        sign = -1.0;
        str++;
    } else if (*str == '+') {
        str++;
    }

    for (value = 0.0; zpl_char_is_digit(*str); str++) {
        value = value * 10.0 + (*str-'0');
    }

    if (*str == '.') {
        f64 pow10 = 10.0;
        str++;
        while (zpl_char_is_digit(*str)) {
            value += (*str-'0') / pow10;
            pow10 *= 10.0;
            str++;
        }
    }

    frac = 0;
    scale = 1.0;
    if ((*str == 'e') || (*str == 'E')) {
        u32 exp;

        str++;
        if (*str == '-') {
            frac = 1;
            str++;
        } else if (*str == '+') {
            str++;
        }

        for (exp = 0; zpl_char_is_digit(*str); str++) {
            exp = exp * 10 + (*str-'0');
        }
        if (exp > 308) exp = 308;

        while (exp >= 50) { scale *= 1e50; exp -= 50; }
        while (exp >=  8) { scale *= 1e8;  exp -=  8; }
        while (exp >   0) { scale *= 10.0; exp -=  1; }
    }

    result = sign * (frac ? (value / scale) : (value * scale));

    if (end_ptr) *end_ptr = cast(char *)str;

    return result;
}







zpl_inline void zpl__set_string_length  (zpl_string str, isize len) { ZPL_STRING_HEADER(str)->length = len; }
zpl_inline void zpl__set_string_capacity(zpl_string str, isize cap) { ZPL_STRING_HEADER(str)->capacity = cap; }

zpl_inline zpl_string zpl_string_make_reserve(zpl_allocator a, isize capacity)
{
    isize header_size = zpl_size_of(zpl_string_header);
    void *ptr = zpl_alloc(a, header_size + capacity + 1);

    zpl_string str;
    zpl_string_header *header;

    if (ptr == NULL) return NULL;
    zpl_zero_size(ptr, header_size + capacity + 1);

    str = cast(char *)ptr + header_size;
    header = ZPL_STRING_HEADER(str);
    header->allocator = a;
    header->length     = 0;
    header->capacity   = capacity;
    str[capacity]      = '\0';

    return str;
}

zpl_inline zpl_string zpl_string_make(zpl_allocator a, char const *str) {
    isize len = str ? zpl_strlen(str) : 0;
    return zpl_string_make_length(a, str, len);
}

zpl_string zpl_string_make_length(zpl_allocator a, void const *init_str, isize num_bytes) {
    isize header_size = zpl_size_of(zpl_string_header);
    void *ptr = zpl_alloc(a, header_size + num_bytes + 1);

    zpl_string str;
    zpl_string_header *header;

    if (ptr == NULL) return NULL;
    if (!init_str) zpl_zero_size(ptr, header_size + num_bytes + 1);

    str = cast(char *)ptr + header_size;
    header = ZPL_STRING_HEADER(str);
    header->allocator = a;
    header->length    = num_bytes;
    header->capacity  = num_bytes;
    if (num_bytes && init_str)
        zpl_memcopy(str, init_str, num_bytes);
    str[num_bytes] = '\0';

    return str;
}

zpl_string zpl_string_sprintf_buf(zpl_allocator a, char const *fmt, ...)
{
    zpl_local_persist char buf[4096] = {0};
    va_list va;
    va_start(va, fmt);
    zpl_snprintf_va(buf, 4096, fmt, va);
    va_end(va);

    return zpl_string_make(a, buf);
}

zpl_string zpl_string_sprintf(zpl_allocator a, char *buf, isize num_bytes, char const *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    zpl_snprintf_va(buf, num_bytes, fmt, va);
    va_end(va);

    return zpl_string_make(a, buf);
}

zpl_inline void zpl_string_free(zpl_string str) {
    if (str) {
        zpl_string_header *header = ZPL_STRING_HEADER(str);
        zpl_free(header->allocator, header);
    }

}

zpl_inline zpl_string zpl_string_duplicate(zpl_allocator a, zpl_string const str) { return zpl_string_make_length(a, str, zpl_string_length(str)); }

zpl_inline isize zpl_string_length  (zpl_string const str) { return ZPL_STRING_HEADER(str)->length; }
zpl_inline isize zpl_string_capacity(zpl_string const str) { return ZPL_STRING_HEADER(str)->capacity; }

zpl_inline isize zpl_string_available_space(zpl_string const str) {
    zpl_string_header *h = ZPL_STRING_HEADER(str);
    if (h->capacity > h->length)
        return h->capacity - h->length;
    return 0;
}


zpl_inline void zpl_string_clear(zpl_string str) { zpl__set_string_length(str, 0); str[0] = '\0'; }

zpl_inline zpl_string zpl_string_append(zpl_string str, zpl_string const other) { return zpl_string_append_length(str, other, zpl_string_length(other)); }

zpl_string zpl_string_append_length(zpl_string str, void const *other, isize other_len) {
    if (other_len > 0) {
        isize curr_len = zpl_string_length(str);

        str = zpl_string_make_space_for(str, other_len);
        if (str == NULL)
            return NULL;

        zpl_memcopy(str + curr_len, other, other_len);
        str[curr_len + other_len] = '\0';
        zpl__set_string_length(str, curr_len + other_len);
    }
    return str;
}

zpl_inline zpl_string zpl_string_appendc(zpl_string str, char const *other) {
    return zpl_string_append_length(str, other, zpl_strlen(other));
}


zpl_string zpl_string_set(zpl_string str, char const *cstr) {
    isize len = zpl_strlen(cstr);
    if (zpl_string_capacity(str) < len) {
        str = zpl_string_make_space_for(str, len - zpl_string_length(str));
        if (str == NULL)
            return NULL;
    }

    zpl_memcopy(str, cstr, len);
    str[len] = '\0';
    zpl__set_string_length(str, len);

    return str;
}



zpl_string zpl_string_make_space_for(zpl_string str, isize add_len) {
    isize available = zpl_string_available_space(str);

    // NOTE: Return if there is enough space left
    if (available >= add_len) {
        return str;
    } else {
        isize new_len, old_size, new_size;
        void *ptr, *new_ptr;
        zpl_allocator a = ZPL_STRING_HEADER(str)->allocator;
        zpl_string_header *header;

        new_len = zpl_string_length(str) + add_len;
        ptr = ZPL_STRING_HEADER(str);
        old_size = zpl_size_of(zpl_string_header) + zpl_string_length(str) + 1;
        new_size = zpl_size_of(zpl_string_header) + new_len + 1;

        new_ptr = zpl_resize(a, ptr, old_size, new_size);
        if (new_ptr == NULL) return NULL;

        header = cast(zpl_string_header *)new_ptr;
        header->allocator = a;

        str = cast(zpl_string)(header+1);
        zpl__set_string_capacity(str, new_len);

        return str;
    }
}

zpl_inline isize zpl_string_allocation_size(zpl_string const str) {
    isize cap = zpl_string_capacity(str);
    return zpl_size_of(zpl_string_header) + cap;
}


zpl_inline b32 zpl_string_are_equal(zpl_string const lhs, zpl_string const rhs) {
    isize lhs_len, rhs_len, i;
    lhs_len = zpl_string_length(lhs);
    rhs_len = zpl_string_length(rhs);
    if (lhs_len != rhs_len)
        return false;

    for (i = 0; i < lhs_len; i++) {
        if (lhs[i] != rhs[i])
            return false;
    }

    return true;
}


zpl_string zpl_string_trim(zpl_string str, char const *cut_set) {
    char *start, *end, *start_pos, *end_pos;
    isize len;

    start_pos = start = str;
    end_pos   = end   = str + zpl_string_length(str) - 1;

    while (start_pos <= end && zpl_char_first_occurence(cut_set, *start_pos))
        start_pos++;
    while (end_pos > start_pos && zpl_char_first_occurence(cut_set, *end_pos))
        end_pos--;

    len = cast(isize)((start_pos > end_pos) ? 0 : ((end_pos - start_pos)+1));

    if (str != start_pos)
        zpl_memmove(str, start_pos, len);
    str[len] = '\0';

    zpl__set_string_length(str, len);

    return str;
}

zpl_inline zpl_string zpl_string_trim_space(zpl_string str) { return zpl_string_trim(str, " \t\r\n\v\f"); }

zpl_string zpl_string_append_rune(zpl_string str, Rune r) {
    if (r >= 0) {
        u8 buf[8] = {0};
        isize len = zpl_utf8_encode_rune(buf, r);
        return zpl_string_append_length(str, buf, len);
    }

    return str;
}

zpl_string zpl_string_append_fmt(zpl_string str, char const *fmt, ...) {
    isize res;
    char buf[4096] = {0};
    va_list va;
    va_start(va, fmt);
    res = zpl_snprintf_va(buf, zpl_count_of(buf)-1, fmt, va)-1;
    va_end(va);
    return zpl_string_append_length(str, buf, res);
}


////////////////////////////////////////////////////////////////
//
// Windows UTF-8 Handling
//
//


u16 *zpl_utf8_to_ucs2(u16 *buffer, isize len, u8 const *str) {
    Rune c;
    isize i = 0;
    len--;
    while (*str) {
        if (i >= len)
            return NULL;
        if (!(*str & 0x80)) {
            buffer[i++] = *str++;
        } else if ((*str & 0xe0) == 0xc0) {
            if (*str < 0xc2)
                return NULL;
            c = (*str++ & 0x1f) << 6;
            if ((*str & 0xc0) != 0x80)
                return NULL;
            buffer[i++] = cast(u16)(c + (*str++ & 0x3f));
        } else if ((*str & 0xf0) == 0xe0) {
            if (*str == 0xe0 &&
                (str[1] < 0xa0 || str[1] > 0xbf))
                return NULL;
            if (*str == 0xed && str[1] > 0x9f) // str[1] < 0x80 is checked below
                return NULL;
            c = (*str++ & 0x0f) << 12;
            if ((*str & 0xc0) != 0x80)
                return NULL;
            c += (*str++ & 0x3f) << 6;
            if ((*str & 0xc0) != 0x80)
                return NULL;
            buffer[i++] = cast(u16)(c + (*str++ & 0x3f));
        } else if ((*str & 0xf8) == 0xf0) {
            if (*str > 0xf4)
                return NULL;
            if (*str == 0xf0 && (str[1] < 0x90 || str[1] > 0xbf))
                return NULL;
            if (*str == 0xf4 && str[1] > 0x8f) // str[1] < 0x80 is checked below
                return NULL;
            c = (*str++ & 0x07) << 18;
            if ((*str & 0xc0) != 0x80)
                return NULL;
            c += (*str++ & 0x3f) << 12;
            if ((*str & 0xc0) != 0x80)
                return NULL;
            c += (*str++ & 0x3f) << 6;
            if ((*str & 0xc0) != 0x80)
                return NULL;
            c += (*str++ & 0x3f);
            // UTF-8 encodings of values used in surrogate pairs are invalid
            if ((c & 0xfffff800) == 0xd800)
                return NULL;
            if (c >= 0x10000) {
                c -= 0x10000;
                if (i+2 > len)
                    return NULL;
                buffer[i++] = 0xd800 | (0x3ff & (c>>10));
                buffer[i++] = 0xdc00 | (0x3ff & (c    ));
            }
        } else {
            return NULL;
        }
    }
    buffer[i] = 0;
    return buffer;
}

u8 *zpl_ucs2_to_utf8(u8 *buffer, isize len, u16 const *str) {
    isize i = 0;
    len--;
    while (*str) {
        if (*str < 0x80) {
            if (i+1 > len)
                return NULL;
            buffer[i++] = (char) *str++;
        } else if (*str < 0x800) {
            if (i+2 > len)
                return NULL;
            buffer[i++] = cast(char)(0xc0 + (*str >> 6));
            buffer[i++] = cast(char)(0x80 + (*str & 0x3f));
            str += 1;
        } else if (*str >= 0xd800 && *str < 0xdc00) {
            Rune c;
            if (i+4 > len)
                return NULL;
            c = ((str[0] - 0xd800) << 10) + ((str[1]) - 0xdc00) + 0x10000;
            buffer[i++] = cast(char)(0xf0 +  (c >> 18));
            buffer[i++] = cast(char)(0x80 + ((c >> 12) & 0x3f));
            buffer[i++] = cast(char)(0x80 + ((c >>  6) & 0x3f));
            buffer[i++] = cast(char)(0x80 + ((c      ) & 0x3f));
            str += 2;
        } else if (*str >= 0xdc00 && *str < 0xe000) {
            return NULL;
        } else {
            if (i+3 > len)
                return NULL;
            buffer[i++] = 0xe0 +  (*str >> 12);
            buffer[i++] = 0x80 + ((*str >>  6) & 0x3f);
            buffer[i++] = 0x80 + ((*str      ) & 0x3f);
            str += 1;
        }
    }
    buffer[i] = 0;
    return buffer;
}

u16 *zpl_utf8_to_ucs2_buf(u8 const *str) { // NOTE: Uses locally persisting buffer
    zpl_local_persist u16 buf[4096];
    return zpl_utf8_to_ucs2(buf, zpl_count_of(buf), str);
}

u8 *zpl_ucs2_to_utf8_buf(u16 const *str) { // NOTE: Uses locally persisting buffer
    zpl_local_persist u8 buf[4096];
    return zpl_ucs2_to_utf8(buf, zpl_count_of(buf), str);
}



zpl_global u8 const zpl__utf8_first[256] = {
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x00-0x0F
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x10-0x1F
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x20-0x2F
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x30-0x3F
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x40-0x4F
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x50-0x5F
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x60-0x6F
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x70-0x7F
    0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0x80-0x8F
    0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0x90-0x9F
    0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0xA0-0xAF
    0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0xB0-0xBF
    0xf1, 0xf1, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, // 0xC0-0xCF
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, // 0xD0-0xDF
    0x13, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x23, 0x03, 0x03, // 0xE0-0xEF
    0x34, 0x04, 0x04, 0x04, 0x44, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0xF0-0xFF
};


#define zpl_utf8_accept_range_t zpl_utf8_accept_range
typedef struct zpl_utf8_accept_range {
    u8 lo, hi;
} zpl_utf8_accept_range;

zpl_global zpl_utf8_accept_range const zpl__utf8_accept_ranges[] = {
    {0x80, 0xbf},
    {0xa0, 0xbf},
    {0x80, 0x9f},
    {0x90, 0xbf},
    {0x80, 0x8f},
};


isize zpl_utf8_decode(u8 const *str, isize str_len, Rune *codepoint_out) {


    isize width = 0;
    Rune codepoint = ZPL_RUNE_INVALID;

    if (str_len > 0) {
        u8 s0 = str[0];
        u8 x = zpl__utf8_first[s0], sz;
        u8 b1, b2, b3;
        zpl_utf8_accept_range accept;
        if (x > 0xf0) {
            Rune mask = (cast(Rune)x >> 31) << 31;
            codepoint = (cast(Rune)s0 & (~mask)) | (ZPL_RUNE_INVALID & mask);
            width = 1;
            goto end;
        }
        if (s0 < 0x80) {
            codepoint = s0;
            width = 1;
            goto end;
        }

        sz = x&7;
        accept = zpl__utf8_accept_ranges[x>>4];
        if (str_len < zpl_size_of(sz))
            goto invalid_codepoint;

        b1 = str[1];
        if (b1 < accept.lo || accept.hi < b1)
            goto invalid_codepoint;

        if (sz == 2) {
            codepoint = (cast(Rune)s0&0x1f)<<6 | (cast(Rune)b1&0x3f);
            width = 2;
            goto end;
        }

        b2 = str[2];
        if (!zpl_is_between(b2, 0x80, 0xbf))
            goto invalid_codepoint;

        if (sz == 3) {
            codepoint = (cast(Rune)s0&0x1f)<<12 | (cast(Rune)b1&0x3f)<<6 | (cast(Rune)b2&0x3f);
            width = 3;
            goto end;
        }

        b3 = str[3];
        if (!zpl_is_between(b3, 0x80, 0xbf))
            goto invalid_codepoint;

        codepoint = (cast(Rune)s0&0x07)<<18 | (cast(Rune)b1&0x3f)<<12 | (cast(Rune)b2&0x3f)<<6 | (cast(Rune)b3&0x3f);
        width = 4;
        goto end;

    invalid_codepoint:
        codepoint = ZPL_RUNE_INVALID;
        width = 1;
    }

end:
    if (codepoint_out) *codepoint_out = codepoint;
    return width;
}

isize zpl_utf8_codepoint_size(u8 const *str, isize str_len) {
    isize i = 0;
    for (; i < str_len && str[i]; i++) {
        if ((str[i] & 0xc0) != 0x80)
            break;
    }
    return i+1;
}

isize zpl_utf8_encode_rune(u8 buf[4], Rune r) {
    u32 i = cast(u32)r;
    u8 mask = 0x3f;
    if (i <= (1<<7)-1) {
        buf[0] = cast(u8)r;
        return 1;
    }
    if (i <= (1<<11)-1) {
        buf[0] = 0xc0 | cast(u8)(r>>6);
        buf[1] = 0x80 | (cast(u8)(r)&mask);
        return 2;
    }

    // Invalid or Surrogate range
    if (i > ZPL_RUNE_MAX ||
        zpl_is_between(i, 0xd800, 0xdfff)) {
        r = ZPL_RUNE_INVALID;

        buf[0] = 0xe0 | cast(u8)(r>>12);
        buf[1] = 0x80 | (cast(u8)(r>>6)&mask);
        buf[2] = 0x80 | (cast(u8)(r)&mask);
        return 3;
    }

    if (i <= (1<<16)-1) {
        buf[0] = 0xe0 | cast(u8)(r>>12);
        buf[1] = 0x80 | (cast(u8)(r>>6)&mask);
        buf[2] = 0x80 | (cast(u8)(r)&mask);
        return 3;
    }

    buf[0] = 0xf0 | cast(u8)(r>>18);
    buf[1] = 0x80 | (cast(u8)(r>>12)&mask);
    buf[2] = 0x80 | (cast(u8)(r>>6)&mask);
    buf[3] = 0x80 | (cast(u8)(r)&mask);
    return 4;
}

////////////////////////////////////////////////////////////////
//
// zpl_ring
//


ZPL_RING_DEFINE(u8);
ZPL_RING_DEFINE(char);
ZPL_RING_DEFINE(u16);
ZPL_RING_DEFINE(i16);
ZPL_RING_DEFINE(u32);
ZPL_RING_DEFINE(i32);
ZPL_RING_DEFINE(u64);
ZPL_RING_DEFINE(i64);
ZPL_RING_DEFINE(f32);
ZPL_RING_DEFINE(f64);
ZPL_RING_DEFINE(usize);
ZPL_RING_DEFINE(isize);
ZPL_RING_DEFINE(uintptr);

////////////////////////////////////////////////////////////////
//
// zpl_list
//


zpl_inline void zpl_list_init(zpl_list *list, void const *ptr) {
    zpl_list list_ = {0};
    *list = list_;
    list->ptr = ptr;
}

zpl_inline zpl_list *zpl_list_add(zpl_list *list, zpl_list *item) {
    item->next = NULL;

    if (list->next) {
        item->next = list->next;
    }

    list->next = item;
    item->prev = list;
    return item;
}

zpl_inline zpl_list *zpl_list_remove(zpl_list *list) {
    if (list->prev) {
        list->prev->next = list->next;
    }

    return list->next;
}



////////////////////////////////////////////////////////////////
//
// zpl_array
//
//


zpl_no_inline void *zpl__array_set_capacity(void *array, isize capacity, isize element_size) {
    zpl_array_header *h = ZPL_ARRAY_HEADER(array);

    ZPL_ASSERT(element_size > 0);

    if (capacity == h->capacity)
        return array;

    if (capacity < h->count) {
        if (h->capacity < capacity) {
            isize new_capacity = ZPL_ARRAY_GROW_FORMULA(h->capacity);
            if (new_capacity < capacity)
                new_capacity = capacity;
            zpl__array_set_capacity(array, new_capacity, element_size);
        }
        h->count = capacity;
    }

    {
        isize size = zpl_size_of(zpl_array_header) + element_size*capacity;
        zpl_array_header *nh = cast(zpl_array_header *)zpl_alloc(h->allocator, size);
        zpl_memmove(nh, h, zpl_size_of(zpl_array_header) + element_size*h->count);
        nh->allocator = h->allocator;
        nh->count     = h->count;
        nh->data = (char *)nh+1;
        nh->capacity  = capacity;
        zpl_free(h->allocator, h);
        return nh+1;
    }
}


////////////////////////////////////////////////////////////////
//
// Hashing functions
//
//

u32 zpl_adler32(void const *data, isize len) {
    u32 const MOD_ALDER = 65521;
    u32 a = 1, b = 0;
    isize i, block_len;
    u8 const *bytes = cast(u8 const *)data;

    block_len = len % 5552;

    while (len) {
        for (i = 0; i+7 < block_len; i += 8) {
            a += bytes[0], b += a;
            a += bytes[1], b += a;
            a += bytes[2], b += a;
            a += bytes[3], b += a;
            a += bytes[4], b += a;
            a += bytes[5], b += a;
            a += bytes[6], b += a;
            a += bytes[7], b += a;

            bytes += 8;
        }
        for (; i < block_len; i++)
            a += *bytes++, b += a;

        a %= MOD_ALDER, b %= MOD_ALDER;
        len -= block_len;
        block_len = 5552;
    }

    return (b << 16) | a;
}


zpl_global u32 const zpl__CRC32_TABLE[256] = {
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
    0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
    0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
    0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
    0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
    0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
    0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
    0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
    0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
    0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
    0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
    0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
    0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
    0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
    0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
    0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
    0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
    0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
    0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
    0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
    0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
    0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
    0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
    0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
    0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
    0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
    0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
    0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
    0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
    0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
    0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
    0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
    0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
    0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
    0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
    0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
    0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
    0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
    0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
    0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
    0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
    0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
    0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
    0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
    0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
    0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
    0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
    0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
    0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
    0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
    0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
    0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
};

zpl_global u64 const zpl__CRC64_TABLE[256] = {
    0x0000000000000000ull, 0x42f0e1eba9ea3693ull, 0x85e1c3d753d46d26ull, 0xc711223cfa3e5bb5ull,
    0x493366450e42ecdfull, 0x0bc387aea7a8da4cull, 0xccd2a5925d9681f9ull, 0x8e224479f47cb76aull,
    0x9266cc8a1c85d9beull, 0xd0962d61b56fef2dull, 0x17870f5d4f51b498ull, 0x5577eeb6e6bb820bull,
    0xdb55aacf12c73561ull, 0x99a54b24bb2d03f2ull, 0x5eb4691841135847ull, 0x1c4488f3e8f96ed4ull,
    0x663d78ff90e185efull, 0x24cd9914390bb37cull, 0xe3dcbb28c335e8c9ull, 0xa12c5ac36adfde5aull,
    0x2f0e1eba9ea36930ull, 0x6dfeff5137495fa3ull, 0xaaefdd6dcd770416ull, 0xe81f3c86649d3285ull,
    0xf45bb4758c645c51ull, 0xb6ab559e258e6ac2ull, 0x71ba77a2dfb03177ull, 0x334a9649765a07e4ull,
    0xbd68d2308226b08eull, 0xff9833db2bcc861dull, 0x388911e7d1f2dda8ull, 0x7a79f00c7818eb3bull,
    0xcc7af1ff21c30bdeull, 0x8e8a101488293d4dull, 0x499b3228721766f8ull, 0x0b6bd3c3dbfd506bull,
    0x854997ba2f81e701ull, 0xc7b97651866bd192ull, 0x00a8546d7c558a27ull, 0x4258b586d5bfbcb4ull,
    0x5e1c3d753d46d260ull, 0x1cecdc9e94ace4f3ull, 0xdbfdfea26e92bf46ull, 0x990d1f49c77889d5ull,
    0x172f5b3033043ebfull, 0x55dfbadb9aee082cull, 0x92ce98e760d05399ull, 0xd03e790cc93a650aull,
    0xaa478900b1228e31ull, 0xe8b768eb18c8b8a2ull, 0x2fa64ad7e2f6e317ull, 0x6d56ab3c4b1cd584ull,
    0xe374ef45bf6062eeull, 0xa1840eae168a547dull, 0x66952c92ecb40fc8ull, 0x2465cd79455e395bull,
    0x3821458aada7578full, 0x7ad1a461044d611cull, 0xbdc0865dfe733aa9ull, 0xff3067b657990c3aull,
    0x711223cfa3e5bb50ull, 0x33e2c2240a0f8dc3ull, 0xf4f3e018f031d676ull, 0xb60301f359dbe0e5ull,
    0xda050215ea6c212full, 0x98f5e3fe438617bcull, 0x5fe4c1c2b9b84c09ull, 0x1d14202910527a9aull,
    0x93366450e42ecdf0ull, 0xd1c685bb4dc4fb63ull, 0x16d7a787b7faa0d6ull, 0x5427466c1e109645ull,
    0x4863ce9ff6e9f891ull, 0x0a932f745f03ce02ull, 0xcd820d48a53d95b7ull, 0x8f72eca30cd7a324ull,
    0x0150a8daf8ab144eull, 0x43a04931514122ddull, 0x84b16b0dab7f7968ull, 0xc6418ae602954ffbull,
    0xbc387aea7a8da4c0ull, 0xfec89b01d3679253ull, 0x39d9b93d2959c9e6ull, 0x7b2958d680b3ff75ull,
    0xf50b1caf74cf481full, 0xb7fbfd44dd257e8cull, 0x70eadf78271b2539ull, 0x321a3e938ef113aaull,
    0x2e5eb66066087d7eull, 0x6cae578bcfe24bedull, 0xabbf75b735dc1058ull, 0xe94f945c9c3626cbull,
    0x676dd025684a91a1ull, 0x259d31cec1a0a732ull, 0xe28c13f23b9efc87ull, 0xa07cf2199274ca14ull,
    0x167ff3eacbaf2af1ull, 0x548f120162451c62ull, 0x939e303d987b47d7ull, 0xd16ed1d631917144ull,
    0x5f4c95afc5edc62eull, 0x1dbc74446c07f0bdull, 0xdaad56789639ab08ull, 0x985db7933fd39d9bull,
    0x84193f60d72af34full, 0xc6e9de8b7ec0c5dcull, 0x01f8fcb784fe9e69ull, 0x43081d5c2d14a8faull,
    0xcd2a5925d9681f90ull, 0x8fdab8ce70822903ull, 0x48cb9af28abc72b6ull, 0x0a3b7b1923564425ull,
    0x70428b155b4eaf1eull, 0x32b26afef2a4998dull, 0xf5a348c2089ac238ull, 0xb753a929a170f4abull,
    0x3971ed50550c43c1ull, 0x7b810cbbfce67552ull, 0xbc902e8706d82ee7ull, 0xfe60cf6caf321874ull,
    0xe224479f47cb76a0ull, 0xa0d4a674ee214033ull, 0x67c58448141f1b86ull, 0x253565a3bdf52d15ull,
    0xab1721da49899a7full, 0xe9e7c031e063acecull, 0x2ef6e20d1a5df759ull, 0x6c0603e6b3b7c1caull,
    0xf6fae5c07d3274cdull, 0xb40a042bd4d8425eull, 0x731b26172ee619ebull, 0x31ebc7fc870c2f78ull,
    0xbfc9838573709812ull, 0xfd39626eda9aae81ull, 0x3a28405220a4f534ull, 0x78d8a1b9894ec3a7ull,
    0x649c294a61b7ad73ull, 0x266cc8a1c85d9be0ull, 0xe17dea9d3263c055ull, 0xa38d0b769b89f6c6ull,
    0x2daf4f0f6ff541acull, 0x6f5faee4c61f773full, 0xa84e8cd83c212c8aull, 0xeabe6d3395cb1a19ull,
    0x90c79d3fedd3f122ull, 0xd2377cd44439c7b1ull, 0x15265ee8be079c04ull, 0x57d6bf0317edaa97ull,
    0xd9f4fb7ae3911dfdull, 0x9b041a914a7b2b6eull, 0x5c1538adb04570dbull, 0x1ee5d94619af4648ull,
    0x02a151b5f156289cull, 0x4051b05e58bc1e0full, 0x87409262a28245baull, 0xc5b073890b687329ull,
    0x4b9237f0ff14c443ull, 0x0962d61b56fef2d0ull, 0xce73f427acc0a965ull, 0x8c8315cc052a9ff6ull,
    0x3a80143f5cf17f13ull, 0x7870f5d4f51b4980ull, 0xbf61d7e80f251235ull, 0xfd913603a6cf24a6ull,
    0x73b3727a52b393ccull, 0x31439391fb59a55full, 0xf652b1ad0167feeaull, 0xb4a25046a88dc879ull,
    0xa8e6d8b54074a6adull, 0xea16395ee99e903eull, 0x2d071b6213a0cb8bull, 0x6ff7fa89ba4afd18ull,
    0xe1d5bef04e364a72ull, 0xa3255f1be7dc7ce1ull, 0x64347d271de22754ull, 0x26c49cccb40811c7ull,
    0x5cbd6cc0cc10fafcull, 0x1e4d8d2b65facc6full, 0xd95caf179fc497daull, 0x9bac4efc362ea149ull,
    0x158e0a85c2521623ull, 0x577eeb6e6bb820b0ull, 0x906fc95291867b05ull, 0xd29f28b9386c4d96ull,
    0xcedba04ad0952342ull, 0x8c2b41a1797f15d1ull, 0x4b3a639d83414e64ull, 0x09ca82762aab78f7ull,
    0x87e8c60fded7cf9dull, 0xc51827e4773df90eull, 0x020905d88d03a2bbull, 0x40f9e43324e99428ull,
    0x2cffe7d5975e55e2ull, 0x6e0f063e3eb46371ull, 0xa91e2402c48a38c4ull, 0xebeec5e96d600e57ull,
    0x65cc8190991cb93dull, 0x273c607b30f68faeull, 0xe02d4247cac8d41bull, 0xa2dda3ac6322e288ull,
    0xbe992b5f8bdb8c5cull, 0xfc69cab42231bacfull, 0x3b78e888d80fe17aull, 0x7988096371e5d7e9ull,
    0xf7aa4d1a85996083ull, 0xb55aacf12c735610ull, 0x724b8ecdd64d0da5ull, 0x30bb6f267fa73b36ull,
    0x4ac29f2a07bfd00dull, 0x08327ec1ae55e69eull, 0xcf235cfd546bbd2bull, 0x8dd3bd16fd818bb8ull,
    0x03f1f96f09fd3cd2ull, 0x41011884a0170a41ull, 0x86103ab85a2951f4ull, 0xc4e0db53f3c36767ull,
    0xd8a453a01b3a09b3ull, 0x9a54b24bb2d03f20ull, 0x5d45907748ee6495ull, 0x1fb5719ce1045206ull,
    0x919735e51578e56cull, 0xd367d40ebc92d3ffull, 0x1476f63246ac884aull, 0x568617d9ef46bed9ull,
    0xe085162ab69d5e3cull, 0xa275f7c11f7768afull, 0x6564d5fde549331aull, 0x279434164ca30589ull,
    0xa9b6706fb8dfb2e3ull, 0xeb46918411358470ull, 0x2c57b3b8eb0bdfc5ull, 0x6ea7525342e1e956ull,
    0x72e3daa0aa188782ull, 0x30133b4b03f2b111ull, 0xf7021977f9cceaa4ull, 0xb5f2f89c5026dc37ull,
    0x3bd0bce5a45a6b5dull, 0x79205d0e0db05dceull, 0xbe317f32f78e067bull, 0xfcc19ed95e6430e8ull,
    0x86b86ed5267cdbd3ull, 0xc4488f3e8f96ed40ull, 0x0359ad0275a8b6f5ull, 0x41a94ce9dc428066ull,
    0xcf8b0890283e370cull, 0x8d7be97b81d4019full, 0x4a6acb477bea5a2aull, 0x089a2aacd2006cb9ull,
    0x14dea25f3af9026dull, 0x562e43b4931334feull, 0x913f6188692d6f4bull, 0xd3cf8063c0c759d8ull,
    0x5dedc41a34bbeeb2ull, 0x1f1d25f19d51d821ull, 0xd80c07cd676f8394ull, 0x9afce626ce85b507ull,
};

u32 zpl_crc32(void const *data, isize len) {
    isize remaining;
    u32 result = ~(cast(u32)0);
    u8 const *c = cast(u8 const *)data;
    for (remaining = len; remaining--; c++)
        result = (result >> 8) ^ (zpl__CRC32_TABLE[(result ^ *c) & 0xff]);
    return ~result;
}

u64 zpl_crc64(void const *data, isize len) {
    isize remaining;
    u64 result = ~(cast(u64)0);
    u8 const *c = cast(u8 const *)data;
    for (remaining = len; remaining--; c++)
        result = (result >> 8) ^ (zpl__CRC64_TABLE[(result ^ *c) & 0xff]);
    return ~result;
}

u32 zpl_fnv32(void const *data, isize len) {
    isize i;
    u32 h = 0x811c9dc5;
    u8 const *c = cast(u8 const *)data;

    for (i = 0; i < len; i++)
        h = (h * 0x01000193) ^ c[i];

    return h;
}

u64 zpl_fnv64(void const *data, isize len) {
    isize i;
    u64 h = 0xcbf29ce484222325ull;
    u8 const *c = cast(u8 const *)data;

    for (i = 0; i < len; i++)
        h = (h * 0x100000001b3ll) ^ c[i];

    return h;
}

u32 zpl_fnv32a(void const *data, isize len) {
    isize i;
    u32 h = 0x811c9dc5;
    u8 const *c = cast(u8 const *)data;

    for (i = 0; i < len; i++)
        h = (h ^ c[i]) * 0x01000193;

    return h;
}

u64 zpl_fnv64a(void const *data, isize len) {
    isize i;
    u64 h = 0xcbf29ce484222325ull;
    u8 const *c = cast(u8 const *)data;

    for (i = 0; i < len; i++)
        h = (h ^ c[i]) * 0x100000001b3ll;

    return h;
}

zpl_inline u32 zpl_murmur32(void const *data, isize len) { return zpl_murmur32_seed(data, len, 0x9747b28c); }
zpl_inline u64 zpl_murmur64(void const *data, isize len) { return zpl_murmur64_seed(data, len, 0x9747b28c); }

u32 zpl_murmur32_seed(void const *data, isize len, u32 seed) {
    u32 const c1 = 0xcc9e2d51;
    u32 const c2 = 0x1b873593;
    u32 const r1 = 15;
    u32 const r2 = 13;
    u32 const m  = 5;
    u32 const n  = 0xe6546b64;

    isize i, nblocks = len / 4;
    u32 hash = seed, k1 = 0;
    u32 const *blocks = cast(u32 const*)data;
    u8 const *tail = cast(u8 const *)(data) + nblocks*4;

    for (i = 0; i < nblocks; i++) {
        u32 k = blocks[i];
        k *= c1;
        k = (k << r1) | (k >> (32 - r1));
        k *= c2;

        hash ^= k;
        hash = ((hash << r2) | (hash >> (32 - r2))) * m + n;
    }

    switch (len & 3) {
    case 3:
        k1 ^= tail[2] << 16;
    case 2:
        k1 ^= tail[1] << 8;
    case 1:
        k1 ^= tail[0];

        k1 *= c1;
        k1 = (k1 << r1) | (k1 >> (32 - r1));
        k1 *= c2;
        hash ^= k1;
    }

    hash ^= len;
    hash ^= (hash >> 16);
    hash *= 0x85ebca6b;
    hash ^= (hash >> 13);
    hash *= 0xc2b2ae35;
    hash ^= (hash >> 16);

    return hash;
}

u64 zpl_murmur64_seed(void const *data_, isize len, u64 seed) {
#if defined(ZPL_ARCH_64_BIT)
    u64 const m = 0xc6a4a7935bd1e995ULL;
    i32 const r = 47;

    u64 h = seed ^ (len * m);

    u64 const *data = cast(u64 const *)data_;
    u8  const *data2 = cast(u8 const *)data_;
    u64 const* end = data + (len / 8);

    while (data != end) {
        u64 k = *data++;

        k *= m;
        k ^= k >> r;
        k *= m;

        h ^= k;
        h *= m;
    }

    switch (len & 7) {
    case 7: h ^= cast(u64)(data2[6]) << 48;
    case 6: h ^= cast(u64)(data2[5]) << 40;
    case 5: h ^= cast(u64)(data2[4]) << 32;
    case 4: h ^= cast(u64)(data2[3]) << 24;
    case 3: h ^= cast(u64)(data2[2]) << 16;
    case 2: h ^= cast(u64)(data2[1]) << 8;
    case 1: h ^= cast(u64)(data2[0]);
        h *= m;
    };

    h ^= h >> r;
    h *= m;
    h ^= h >> r;

    return h;
#else
    u64 h;
    u32 const m = 0x5bd1e995;
    i32 const r = 24;

    u32 h1 = cast(u32)(seed) ^ cast(u32)(len);
    u32 h2 = cast(u32)(seed >> 32);

    u32 const *data = cast(u32 const *)data_;

    while (len >= 8) {
        u32 k1, k2;
        k1 = *data++;
        k1 *= m;
        k1 ^= k1 >> r;
        k1 *= m;
        h1 *= m;
        h1 ^= k1;
        len -= 4;

        k2 = *data++;
        k2 *= m;
        k2 ^= k2 >> r;
        k2 *= m;
        h2 *= m;
        h2 ^= k2;
        len -= 4;
    }

    if (len >= 4) {
        u32 k1 = *data++;
        k1 *= m;
        k1 ^= k1 >> r;
        k1 *= m;
        h1 *= m;
        h1 ^= k1;
        len -= 4;
    }

    switch (len) {
    case 3: h2 ^= (cast(u8 const *)data)[2] << 16;
    case 2: h2 ^= (cast(u8 const *)data)[1] <<  8;
    case 1: h2 ^= (cast(u8 const *)data)[0] <<  0;
        h2 *= m;
    };

    h1 ^= h2 >> 18;
    h1 *= m;
    h2 ^= h1 >> 22;
    h2 *= m;
    h1 ^= h2 >> 17;
    h1 *= m;
    h2 ^= h1 >> 19;
    h2 *= m;

    h = h1;
    h = (h << 32) | h2;

    return h;
#endif
}







////////////////////////////////////////////////////////////////
//
// File Handling
//
//

#if defined(ZPL_SYSTEM_WINDOWS)

zpl_internal wchar_t *zpl__alloc_utf8_to_ucs2(zpl_allocator a, char const *text, isize *w_len_) {
    wchar_t *w_text = NULL;
    isize len = 0, w_len = 0, w_len1 = 0;
    if (text == NULL) {
        if (w_len_) *w_len_ = w_len;
        return NULL;
    }
    len = zpl_strlen(text);
    if (len == 0) {
        if (w_len_) *w_len_ = w_len;
        return NULL;
    }
    w_len = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, text, cast(int)len, NULL, 0);
    if (w_len == 0) {
        if (w_len_) *w_len_ = w_len;
        return NULL;
    }
    w_text = zpl_alloc_array(a, wchar_t, w_len+1);
    w_len1 = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, text, cast(int)len, w_text, cast(int)w_len);
    if (w_len1 == 0) {
        zpl_free(a, w_text);
        if (w_len_) *w_len_ = 0;
        return NULL;
    }
    w_text[w_len] = 0;
    if (w_len_) *w_len_ = w_len;
    return w_text;
}


zpl_internal ZPL_FILE_SEEK_PROC(zpl__win32_file_seek) {
    LARGE_INTEGER li_offset;
    li_offset.QuadPart = offset;
    if (!SetFilePointerEx(fd.p, li_offset, &li_offset, whence)) {
        return false;
    }

    if (new_offset) *new_offset = li_offset.QuadPart;
    return true;
}

zpl_internal ZPL_FILE_READ_AT_PROC(zpl__win32_file_read) {
    zpl_unused(stop_at_newline);
    b32 result = false;
    zpl__win32_file_seek(fd, offset, ZPL_SEEK_WHENCE_BEGIN, NULL);
    DWORD size_ = cast(DWORD)(size > I32_MAX ? I32_MAX : size);
    DWORD bytes_read_;
    if (ReadFile(fd.p, buffer, size_, &bytes_read_, NULL)) {
        if (bytes_read) *bytes_read = bytes_read_;
        result = true;
    }

    return result;
}

zpl_internal ZPL_FILE_WRITE_AT_PROC(zpl__win32_file_write) {
    DWORD size_ = cast(DWORD)(size > I32_MAX ? I32_MAX : size);
    DWORD bytes_written_;
    zpl__win32_file_seek(fd, offset, ZPL_SEEK_WHENCE_BEGIN, NULL);
    if (WriteFile(fd.p, buffer, size_, &bytes_written_, NULL)) {
        if (bytes_written) *bytes_written = bytes_written_;
        return true;
    }
    return false;
}

zpl_internal ZPL_FILE_CLOSE_PROC(zpl__win32_file_close) {
    CloseHandle(fd.p);
}

zpl_file_operations const zpl_default_file_operations = {
    zpl__win32_file_read,
    zpl__win32_file_write,
    zpl__win32_file_seek,
    zpl__win32_file_close
};

zpl_no_inline ZPL_FILE_OPEN_PROC(zpl__win32_file_open) {
    DWORD desired_access;
    DWORD creation_disposition;
    void *handle;
    wchar_t *w_text;

    switch (mode & zpl_file_mode_modes_ev) {
    case ZPL_FILE_MODE_READ:
        desired_access = GENERIC_READ;
        creation_disposition = OPEN_EXISTING;
        break;
    case ZPL_FILE_MODE_WRITE:
        desired_access = GENERIC_WRITE;
        creation_disposition = CREATE_ALWAYS;
        break;
    case ZPL_FILE_MODE_APPEND:
        desired_access = GENERIC_WRITE;
        creation_disposition = OPEN_ALWAYS;
        break;
    case ZPL_FILE_MODE_READ | ZPL_FILE_MODE_RW:
        desired_access = GENERIC_READ | GENERIC_WRITE;
        creation_disposition = OPEN_EXISTING;
        break;
    case ZPL_FILE_MODE_WRITE | ZPL_FILE_MODE_RW:
        desired_access = GENERIC_READ | GENERIC_WRITE;
        creation_disposition = CREATE_ALWAYS;
        break;
    case ZPL_FILE_MODE_APPEND | ZPL_FILE_MODE_RW:
        desired_access = GENERIC_READ | GENERIC_WRITE;
        creation_disposition = OPEN_ALWAYS;
        break;
    default:
        ZPL_PANIC("Invalid file mode");
        return ZPL_FILE_ERROR_INVALID;
    }

    w_text = zpl__alloc_utf8_to_ucs2(zpl_heap_allocator(), filename, NULL);
    handle = CreateFileW(w_text,
                            desired_access,
                            FILE_SHARE_READ|FILE_SHARE_DELETE, NULL,
                            creation_disposition, FILE_ATTRIBUTE_NORMAL, NULL);

    zpl_free(zpl_heap_allocator(), w_text);

    if (handle == INVALID_HANDLE_VALUE) {
        DWORD err = GetLastError();
        switch (err) {
        case ERROR_FILE_NOT_FOUND: return ZPL_FILE_ERROR_NOT_EXISTS;
        case ERROR_FILE_EXISTS:    return ZPL_FILE_ERROR_EXISTS;
        case ERROR_ALREADY_EXISTS: return ZPL_FILE_ERROR_EXISTS;
        case ERROR_ACCESS_DENIED:  return ZPL_FILE_ERROR_PERMISSION;
        }
        return ZPL_FILE_ERROR_INVALID;
    }

    if (mode & ZPL_FILE_MODE_APPEND) {
        LARGE_INTEGER offset = {0};
        if (!SetFilePointerEx(handle, offset, NULL, ZPL_SEEK_WHENCE_END)) {
            CloseHandle(handle);
            return ZPL_FILE_ERROR_INVALID;
        }
    }

    fd->p = handle;
    *ops = zpl_default_file_operations;
    return ZPL_FILE_ERROR_NONE;
}

#else // POSIX
zpl_internal ZPL_FILE_SEEK_PROC(zpl__posix_file_seek) {
#if defined(ZPL_SYSTEM_OSX)
    i64 res = lseek(fd.i, offset, whence);
#else // TODO(ZaKlaus): @fixme lseek64
    i64 res = lseek(fd.i, offset, whence);
#endif
    if (res < 0) return false;
    if (new_offset) *new_offset = res;
    return true;
}

zpl_internal ZPL_FILE_READ_AT_PROC(zpl__posix_file_read) {
    zpl_unused(stop_at_newline);
    isize res = pread(fd.i, buffer, size, offset);
    if (res < 0) return false;
    if (bytes_read) *bytes_read = res;
    return true;
}

zpl_internal ZPL_FILE_WRITE_AT_PROC(zpl__posix_file_write) {
    isize res;
    i64 curr_offset = 0;
    zpl__posix_file_seek(fd, 0, ZPL_SEEK_WHENCE_CURRENT, &curr_offset);
    if (curr_offset == offset) {
        // NOTE: Writing to stdout et al. doesn't like pwrite for numerous reasons
        res = write(cast(int)fd.i, buffer, size);
    } else {
        res = pwrite(cast(int)fd.i, buffer, size, offset);
    }
    if (res < 0) return false;
    if (bytes_written) *bytes_written = res;
    return true;
}


zpl_internal ZPL_FILE_CLOSE_PROC(zpl__posix_file_close) {
    close(fd.i);
}

zpl_file_operations const zpl_default_file_operations = {
    zpl__posix_file_read,
    zpl__posix_file_write,
    zpl__posix_file_seek,
    zpl__posix_file_close
};

zpl_no_inline ZPL_FILE_OPEN_PROC(zpl__posix_file_open) {
    i32 os_mode;
    switch (mode & zpl_file_mode_modes_ev) {
    case ZPL_FILE_MODE_READ:
        os_mode = O_RDONLY;
        break;
    case ZPL_FILE_MODE_WRITE:
        os_mode = O_WRONLY | O_CREAT | O_TRUNC;
        break;
    case ZPL_FILE_MODE_APPEND:
        os_mode = O_WRONLY | O_APPEND | O_CREAT;
        break;
    case ZPL_FILE_MODE_READ | ZPL_FILE_MODE_RW:
        os_mode = O_RDWR;
        break;
    case ZPL_FILE_MODE_WRITE | ZPL_FILE_MODE_RW:
        os_mode = O_RDWR | O_CREAT | O_TRUNC;
        break;
    case ZPL_FILE_MODE_APPEND | ZPL_FILE_MODE_RW:
        os_mode = O_RDWR | O_APPEND | O_CREAT;
        break;
    default:
        ZPL_PANIC("Invalid file mode");
        return ZPL_FILE_ERROR_INVALID;
    }

    fd->i = open(filename, os_mode, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (fd->i < 0) {
        // TODO: More file errors
        return ZPL_FILE_ERROR_INVALID;
    }

    *ops = zpl_default_file_operations;
    return ZPL_FILE_ERROR_NONE;
}

#endif



zplFileError zpl_file_new(zpl_file *f, zpl_file_descriptor fd, zpl_file_operations ops, char const *filename) {
    zplFileError err = ZPL_FILE_ERROR_NONE;
    isize len = zpl_strlen(filename);

    f->ops = ops;
    f->fd = fd;
    f->filename = zpl_alloc_array(zpl_heap_allocator(), char, len+1);
    zpl_memcopy(cast(char *)f->filename, cast(char *)filename, len+1);
    f->last_write_time = zpl_file_last_write_time(f->filename);

    return err;
}



zplFileError zpl_file_open_mode(zpl_file *f, zpl_file_mode mode, char const *filename) {
    zplFileError err;
#if defined(ZPL_SYSTEM_WINDOWS)
    err = zpl__win32_file_open(&f->fd, &f->ops, mode, filename);
#else
    err = zpl__posix_file_open(&f->fd, &f->ops, mode, filename);
#endif
    if (err == ZPL_FILE_ERROR_NONE)
        return zpl_file_new(f, f->fd, f->ops, filename);
    return err;
}

zplFileError zpl_file_close(zpl_file *f) {
    if (!f)
        return ZPL_FILE_ERROR_INVALID;

    if (f->filename) zpl_free(zpl_heap_allocator(), cast(char *)f->filename);

#if defined(ZPL_SYSTEM_WINDOWS)
    if (f->fd.p == INVALID_HANDLE_VALUE)
        return ZPL_FILE_ERROR_INVALID;
#else
    if (f->fd.i < 0)
        return ZPL_FILE_ERROR_INVALID;
#endif

    if (!f->ops.read_at) f->ops = zpl_default_file_operations;
    f->ops.close(f->fd);

    return ZPL_FILE_ERROR_NONE;
}

zpl_inline b32 zpl_file_read_at_check(zpl_file *f, void *buffer, isize size, i64 offset, isize *bytes_read) {
    if (!f->ops.read_at) f->ops = zpl_default_file_operations;
    return f->ops.read_at(f->fd, buffer, size, offset, bytes_read, false);
}

zpl_inline b32 zpl_file_write_at_check(zpl_file *f, void const *buffer, isize size, i64 offset, isize *bytes_written) {
    if (!f->ops.read_at) f->ops = zpl_default_file_operations;
    return f->ops.write_at(f->fd, buffer, size, offset, bytes_written);
}


zpl_inline b32 zpl_file_read_at(zpl_file *f, void *buffer, isize size, i64 offset) {
    return zpl_file_read_at_check(f, buffer, size, offset, NULL);
}

zpl_inline b32 zpl_file_write_at(zpl_file *f, void const *buffer, isize size, i64 offset) {
    return zpl_file_write_at_check(f, buffer, size, offset, NULL);
}

zpl_inline i64 zpl_file_seek(zpl_file *f, i64 offset) {
    i64 new_offset = 0;
    if (!f->ops.read_at) f->ops = zpl_default_file_operations;
    f->ops.seek(f->fd, offset, ZPL_SEEK_WHENCE_BEGIN, &new_offset);
    return new_offset;
}

zpl_inline i64 zpl_file_seek_to_end(zpl_file *f) {
    i64 new_offset = 0;
    if (!f->ops.read_at) f->ops = zpl_default_file_operations;
    f->ops.seek(f->fd, 0, ZPL_SEEK_WHENCE_END, &new_offset);
    return new_offset;
}

// NOTE: Skips a certain amount of bytes
zpl_inline i64 zpl_file_skip(zpl_file *f, i64 bytes) {
    i64 new_offset = 0;
    if (!f->ops.read_at) f->ops = zpl_default_file_operations;
    f->ops.seek(f->fd, bytes, ZPL_SEEK_WHENCE_CURRENT, &new_offset);
    return new_offset;
}

zpl_inline i64 zpl_file_tell(zpl_file *f) {
    i64 new_offset = 0;
    if (!f->ops.read_at) f->ops = zpl_default_file_operations;
    f->ops.seek(f->fd, 0, ZPL_SEEK_WHENCE_CURRENT, &new_offset);
    return new_offset;
}

zpl_inline b32 zpl_file_read(zpl_file *f, void *buffer, isize size) {
    i64 cur_offset = zpl_file_tell(f);
    b32 result = zpl_file_read_at(f, buffer, size, zpl_file_tell(f));
    zpl_file_seek(f, cur_offset + size);
    return result;
}

zpl_inline b32 zpl_file_write(zpl_file *f, void const *buffer, isize size) {
    i64 cur_offset = zpl_file_tell(f);
    b32 result = zpl_file_write_at(f, buffer, size, zpl_file_tell(f));
    zpl_file_seek(f, cur_offset + size);
    return result;
}

zplFileError zpl_file_create(zpl_file *f, char const *filename) {
    return zpl_file_open_mode(f, ZPL_FILE_MODE_WRITE|ZPL_FILE_MODE_RW, filename);
}


zplFileError zpl_file_open(zpl_file *f, char const *filename) {
    return zpl_file_open_mode(f, ZPL_FILE_MODE_READ, filename);
}


char const *zpl_file_name(zpl_file *f) { return f->filename ? f->filename : ""; }

zpl_inline b32 zpl_file_has_changed(zpl_file *f) {
    b32 result = false;
    zpl_file_time last_write_time = zpl_file_last_write_time(f->filename);
    if (f->last_write_time != last_write_time) {
        result = true;
        f->last_write_time = last_write_time;
    }
    return result;
}

#ifdef ZPL_THREADING

typedef struct {
    zpl_async_file *f;
    zpl_async_file_cb *proc;
    void *data;
    isize data_size;
} zpl__async_file_ctl;

ZPL_THREAD_PROC(zpl__async_file_read_proc) {
    zpl__async_file_ctl *afops = cast(zpl__async_file_ctl *)thread->user_data;

    zpl_async_file *f = afops->f;

    i64 file_size = zpl_file_size(&f->handle);
    void *file_contents = zpl_malloc((isize)file_size);
    zpl_file_read(&f->handle, file_contents, (isize)file_size);

    f->size = (isize)file_size;
    f->data = file_contents;

    afops->proc(f);

    zpl_free(zpl_heap_allocator(), afops->f);
    zpl_free(zpl_heap_allocator(), afops);

    return 0;
}

ZPL_THREAD_PROC(zpl__async_file_write_proc) {
    zpl__async_file_ctl *afops = cast(zpl__async_file_ctl *)thread->user_data;

    zpl_async_file *f = afops->f;

    i64 file_size = afops->data_size;
    void *file_contents = afops->data;
    zpl_file_write(&f->handle, file_contents, (isize)file_size);

    f->size = (isize)file_size;
    f->data = file_contents;

    afops->proc(f);

    zpl_free(zpl_heap_allocator(), afops->f);
    zpl_free(zpl_heap_allocator(), afops);

    return 0;
}

void zpl_async_file_read(zpl_file *file, zpl_async_file_cb *proc) {
    ZPL_ASSERT(file && proc);

    zpl_async_file *a = (zpl_async_file *)zpl_malloc(sizeof(zpl_async_file));
    zpl_async_file a_ = {0};
    *a = a_;

    a->handle = *file;

    zpl_thread td = {0};
    zpl_thread_init(&td);

    zpl__async_file_ctl *afops = (zpl__async_file_ctl *)zpl_malloc(sizeof(zpl__async_file_ctl));
    zpl__async_file_ctl afops_ = {0};
    *afops = afops_;

    afops->f = a;
    afops->proc = proc;

    zpl_thread_start(&td, zpl__async_file_read_proc, cast(void *)afops);
}

void zpl_async_file_write(zpl_file *file, void const* buffer, isize size, zpl_async_file_cb *proc) {
    ZPL_ASSERT(file && proc && buffer);

    zpl_async_file *a = (zpl_async_file *)zpl_malloc(sizeof(zpl_async_file));
    zpl_async_file a_ = {0};
    *a = a_;

    a->handle = *file;

    zpl_thread td = {0};
    zpl_thread_init(&td);

    zpl__async_file_ctl *afops = (zpl__async_file_ctl *)zpl_malloc(sizeof(zpl__async_file_ctl));
    zpl__async_file_ctl afops_ = {0};
    *afops = afops_;

    afops->f = a;
    afops->proc = proc;
    afops->data = cast(void *)buffer;
    afops->data_size = size;

    zpl_thread_start(&td, zpl__async_file_write_proc, cast(void *)afops);
}

///////////////////////////////////////////////////////////////
//
// Thread Pool
//

ZPL_THREAD_PROC(zpl__jobs_entry)
{
    zpl_thread_worker *tw = (zpl_thread_worker *)thread->user_data;
    zpl_thread_pool *pool=(zpl_thread_pool *)tw->pool;

    for (;;) {
        u32 status = zpl_atomic32_load(&tw->status);

        switch (status) {
            case ZPL_JOBS_STATUS_READY:
                {
                    zpl_atomic32_store(&tw->status, ZPL_JOBS_STATUS_BUSY);

                    zpl_mutex_lock(&pool->access);
                    zpl_thread_job *job=pool->jobs+tw->jobid;
                    zpl_mutex_unlock(&pool->access);

                    job->proc(job->data);

                    zpl_atomic32_store(&tw->status, ZPL_JOBS_STATUS_WAITING);
                }break;

            case ZPL_JOBS_STATUS_WAITING:
                {
                    zpl_yield();
                }break;

            case ZPL_JOBS_STATUS_TERM:
                {
                    return 0;
                }break;
        }
    }

    return 0;
}

void zpl_jobs_init(zpl_thread_pool *pool, zpl_allocator a, u32 max_threads)
{
    zpl_thread_pool pool_={0};
    *pool=pool_;
    zpl_mutex_init(&pool->access);

    pool->alloc=a;
    pool->max_threads=max_threads;

    // NOTE: Spawn a new job slot when number of available slots is below 25%
    // compared to the total number of slots.
    pool->job_spawn_treshold=0.25;

    zpl_buffer_init(pool->workers, a, max_threads);
    zpl_array_init(pool->jobs, a);
    zpl_array_init(pool->queue, a);
    zpl_array_init(pool->available, a);

    for (usize i=0; i<max_threads; ++i) {
        zpl_thread_worker worker_={0};
        zpl_thread_worker *tw=pool->workers+i;
        *tw=worker_;

        zpl_thread_init(&tw->thread);
        zpl_atomic32_store(&tw->status, ZPL_JOBS_STATUS_WAITING);
        tw->pool=pool;
        tw->jobid=ZPL_INVALID_JOB;
        zpl_thread_start(&tw->thread, zpl__jobs_entry, (void *)tw);
    }
}

void zpl_jobs_free(zpl_thread_pool *pool)
{
    for (usize i=0; i<pool->max_threads; ++i) {
        zpl_thread_worker *tw=pool->workers+i;

        zpl_atomic32_store(&tw->status, ZPL_JOBS_STATUS_TERM);
        zpl_thread_destroy(&tw->thread);
    }

    zpl_buffer_free(pool->workers, pool->alloc);
    zpl_array_free(pool->jobs);
    zpl_array_free(pool->queue);
    zpl_array_free(pool->available);
}

void zpl_jobs_enqueue_with_priority(zpl_thread_pool *pool, zpl_jobs_proc proc, void *data, i32 priority)
{
    ZPL_ASSERT_NOT_NULL(proc);
    f32 treshold=0.0f;

    if (zpl_array_count(pool->queue) > 0) {
        treshold=(zpl_array_count(pool->available)/(f32)zpl_array_count(pool->jobs));
    }

    if (treshold <= pool->job_spawn_treshold) {
        zpl_thread_job job={0};
        job.proc=proc;
        job.data=data;
        job.priority=priority;

        zpl_array_append(pool->jobs, job);
        u32 jobid=(u32)zpl_array_count(pool->jobs)-1;
        zpl_array_append(pool->queue, jobid);
    }
    else {
        u32 jobid=zpl_array_back(pool->available);
        zpl_thread_job *jp=pool->jobs+jobid;
        zpl_array_pop(pool->available);

        jp->proc=proc;
        jp->data=data;
        jp->priority=priority;

        zpl_array_append(pool->queue, jobid);
    }
}
void zpl_jobs_enqueue(zpl_thread_pool *pool, zpl_jobs_proc proc, void *data)
{
    ZPL_ASSERT_NOT_NULL(proc);
    zpl_jobs_enqueue_with_priority(pool, proc, data, 0);
}

zpl_thread_local zpl_thread_pool *zpl__thread_pool; ZPL_COMPARE_PROC(zpl___jobs_cmp) {
    zpl_thread_job *p = (zpl_thread_job *)(zpl__thread_pool->jobs + *(u32 *)a);
    zpl_thread_job *q = (zpl_thread_job *)(zpl__thread_pool->jobs + *(u32 *)b);
    return p->priority < q->priority ? 1 : p->priority > q->priority;
}

ZPL_COMPARE_PROC_PTR(zpl__jobs_cmp(zpl_thread_pool *pool)) {
    zpl__thread_pool=pool;
    return &zpl___jobs_cmp;
}

b32 zpl_jobs_process(zpl_thread_pool *pool)
{
    // NOTE: Sort the queue based on the job priority
    if (zpl_array_count(pool->queue)) {
        zpl_sort_array(pool->queue, zpl_array_count(pool->queue), zpl__jobs_cmp(pool));
    }

    // NOTE: Process the jobs
    for (usize i=0; i<pool->max_threads; ++i) {
        zpl_thread_worker *tw=pool->workers+i;
        if (zpl_array_count(pool->queue) == 0) return false;

        u32 status=zpl_atomic32_load(&tw->status);

        if (status==ZPL_JOBS_STATUS_WAITING) {
            if (tw->jobid != ZPL_INVALID_JOB) {
                zpl_array_append(pool->available, tw->jobid);
            }

            u32 jobid=*pool->queue;
            zpl_array_remove_at(pool->queue, 0);
            tw->jobid=jobid;
            zpl_atomic32_store(&tw->status, ZPL_JOBS_STATUS_READY);
        }
    }

    return true;
}

#endif // ZPL_THREADING

// TODO: Is this a bad idea?
zpl_global b32    zpl__std_file_set = false;
zpl_global zpl_file zpl__std_files[ZPL_FILE_STANDARD_COUNT] = {{0}};


#if defined(ZPL_SYSTEM_WINDOWS)

zpl_inline zpl_file *zpl_file_get_standard(zplFileStandardType std) {
    if (!zpl__std_file_set) {
#define ZPL__SET_STD_FILE(type, v) zpl__std_files[type].fd.p = v; zpl__std_files[type].ops = zpl_default_file_operations
        ZPL__SET_STD_FILE(ZPL_FILE_STANDARD_INPUT,  GetStdHandle(STD_INPUT_HANDLE));
        ZPL__SET_STD_FILE(ZPL_FILE_STANDARD_OUTPUT, GetStdHandle(STD_OUTPUT_HANDLE));
        ZPL__SET_STD_FILE(ZPL_FILE_STANDARD_ERROR,  GetStdHandle(STD_ERROR_HANDLE));
#undef ZPL__SET_STD_FILE
        zpl__std_file_set = true;
    }
    return &zpl__std_files[std];
}

zpl_inline i64 zpl_file_size(zpl_file *f) {
    LARGE_INTEGER size;
    GetFileSizeEx(f->fd.p, &size);
    return size.QuadPart;
}

zplFileError zpl_file_truncate(zpl_file *f, i64 size) {
    zplFileError err = ZPL_FILE_ERROR_NONE;
    i64 prev_offset = zpl_file_tell(f);
    zpl_file_seek(f, size);
    if (!SetEndOfFile(f))
        err = ZPL_FILE_ERROR_TRUNCATION_FAILURE;
    zpl_file_seek(f, prev_offset);
    return err;
}


b32 zpl_file_exists(char const *name) {
    WIN32_FIND_DATAW data;
    wchar_t *w_text;
    void *handle;
    b32 found = false;
    zpl_allocator a = zpl_heap_allocator();

    w_text = zpl__alloc_utf8_to_ucs2(a, name, NULL);
    if (w_text == NULL) {
        return false;
    }
    handle = FindFirstFileW(w_text, &data);
    zpl_free(a, w_text);
    found = handle != INVALID_HANDLE_VALUE;
    if (found) FindClose(handle);
    return found;
}

#else // POSIX

zpl_inline zpl_file *zpl_file_get_standard(zplFileStandardType std) {
    if (!zpl__std_file_set) {
#define ZPL__SET_STD_FILE(type, v) zpl__std_files[type].fd.i = v; zpl__std_files[type].ops = zpl_default_file_operations
        ZPL__SET_STD_FILE(ZPL_FILE_STANDARD_INPUT,  0);
        ZPL__SET_STD_FILE(ZPL_FILE_STANDARD_OUTPUT, 1);
        ZPL__SET_STD_FILE(ZPL_FILE_STANDARD_ERROR,  2);
#undef ZPL__SET_STD_FILE
        zpl__std_file_set = true;
    }
    return &zpl__std_files[std];
}

zpl_inline i64 zpl_file_size(zpl_file *f) {
    i64 size = 0;
    i64 prev_offset = zpl_file_tell(f);
    zpl_file_seek_to_end(f);
    size = zpl_file_tell(f);
    zpl_file_seek(f, prev_offset);
    return size;
}

zpl_inline zplFileError zpl_file_truncate(zpl_file *f, i64 size) {
    zplFileError err = ZPL_FILE_ERROR_NONE;
    int i = ftruncate(f->fd.i, size);
    if (i != 0) err = ZPL_FILE_ERROR_TRUNCATION_FAILURE;
    return err;
}

zpl_inline b32 zpl_file_exists(char const *name) {
    return access(name, F_OK) != -1;
}

#endif

zplFileError zpl_file_temp(zpl_file *file) {
#if defined(ZPL_SYSTEM_EMSCRIPTEN)
    ZPL_PANIC("zpl_file_temp is not supported for emscripten");
#else
    zpl_zero_item(file);
    FILE *fd = tmpfile();

    if (fd == NULL) {
        return ZPL_FILE_ERROR_INVALID;
    }

    file->fd.p = fd;
    file->ops = zpl_default_file_operations;
#endif
    return ZPL_FILE_ERROR_NONE;
}

#if defined(ZPL_SYSTEM_WINDOWS)
zpl_file_time zpl_file_last_write_time(char const *filepath) {
    ULARGE_INTEGER li = {0};
    FILETIME last_write_time = {0};
    WIN32_FILE_ATTRIBUTE_DATA data = {0};
    zpl_allocator a = zpl_heap_allocator();

    wchar_t *w_text = zpl__alloc_utf8_to_ucs2(a, filepath, NULL);
    if (w_text == NULL) {
        return 0;
    }
    if (GetFileAttributesExW(w_text, GetFileExInfoStandard, &data))
        last_write_time = data.ftLastWriteTime;

    zpl_free(a, w_text);

    li.LowPart = last_write_time.dwLowDateTime;
    li.HighPart = last_write_time.dwHighDateTime;
    return cast(zpl_file_time)li.QuadPart;
}


zpl_inline b32 zpl_file_copy(char const *existing_filename, char const *new_filename, b32 fail_if_exists) {
    b32 result = false;
    zpl_allocator a = zpl_heap_allocator();

    wchar_t *w_old = zpl__alloc_utf8_to_ucs2(a, existing_filename, NULL);
    if (w_old == NULL) {
        return false;
    }

    wchar_t *w_new = zpl__alloc_utf8_to_ucs2(a, new_filename, NULL);
    if (w_new != NULL) {
        result = CopyFileW(w_old, w_new, fail_if_exists);
    }

    zpl_free(a, w_old);
    zpl_free(a, w_new);
    return result;
}

zpl_inline b32 zpl_file_move(char const *existing_filename, char const *new_filename) {
    b32 result = false;
    zpl_allocator a = zpl_heap_allocator();

    wchar_t *w_old = zpl__alloc_utf8_to_ucs2(a, existing_filename, NULL);
    if (w_old == NULL) {
        return false;
    }

    wchar_t *w_new = zpl__alloc_utf8_to_ucs2(a, new_filename, NULL);
    if (w_new != NULL) {
        result = MoveFileW(w_old, w_new);
    }

    zpl_free(a, w_old);
    zpl_free(a, w_new);
    return result;
}

zpl_inline b32 zpl_file_remove(char const *filename) {
    b32 result = false;
    zpl_allocator a = zpl_heap_allocator();

    wchar_t *w_filename = zpl__alloc_utf8_to_ucs2(a, filename, NULL);
    if (w_filename == NULL) {
        return false;
    }

    result = DeleteFileW(w_filename);

    zpl_free(a, w_filename);
    return result;
}



#else

zpl_file_time zpl_file_last_write_time(char const *filepath) {
    time_t result = 0;
    struct stat file_stat;

    if (stat(filepath, &file_stat))
        result = file_stat.st_mtime;

    return cast(zpl_file_time)result;
}


zpl_inline b32 zpl_file_copy(char const *existing_filename, char const *new_filename, b32 fail_if_exists) {
    zpl_unused(fail_if_exists);
#if defined(ZPL_SYSTEM_OSX)
    return copyfile(existing_filename, new_filename, NULL, COPYFILE_DATA) == 0;
#else
    isize size;
    int existing_fd = open(existing_filename, O_RDONLY, 0);
    int new_fd      = open(new_filename, O_WRONLY|O_CREAT, 0666);

    struct stat stat_existing;
    fstat(existing_fd, &stat_existing);

    size = sendfile(new_fd, existing_fd, 0, stat_existing.st_size);

    close(new_fd);
    close(existing_fd);

    return size == stat_existing.st_size;
#endif
}

zpl_inline b32 zpl_file_move(char const *existing_filename, char const *new_filename) {
    if (link(existing_filename, new_filename) == 0) {
        return (unlink(existing_filename) != -1);
    }
    return false;
}

zpl_inline b32 zpl_file_remove(char const *filename) {
#if defined(ZPL_SYSTEM_OSX) || defined(ZPL_SYSTEM_EMSCRIPTEN)
    return (unlink(filename) != -1);
#else
    return (remove(filename) == 0);
#endif
}

#endif





zpl_file_contents zpl_file_read_contents(zpl_allocator a, b32 zero_terminate, char const *filepath) {
    zpl_file_contents result = {0};
    zpl_file file = {0};

    result.allocator = a;

    if (zpl_file_open(&file, filepath) == ZPL_FILE_ERROR_NONE) {
        isize file_size = cast(isize)zpl_file_size(&file);
        if (file_size > 0) {
            result.data = zpl_alloc(a, zero_terminate ? file_size+1 : file_size);
            result.size = file_size;
            zpl_file_read_at(&file, result.data, result.size, 0);
            if (zero_terminate) {
                u8 *str = cast(u8 *)result.data;
                str[file_size] = '\0';
            }
        }
        zpl_file_close(&file);
    }

    return result;
}

char *zpl_file_read_lines(zpl_allocator alloc, char ***lines, char const *filename, b32 strip_whitespace)
{
    zpl_file f = {0};
    zpl_file_open(&f, filename);
    isize fsize = (isize)zpl_file_size(&f);

    char *contents = (char *)zpl_alloc(alloc, fsize+1);
    zpl_file_read(&f, contents, fsize);
    contents[fsize]=0;
    *lines=zpl_str_split_lines(alloc, contents, strip_whitespace);
    zpl_file_close(&f);

    return contents;
}

void zpl_file_free_contents(zpl_file_contents *fc) {
    ZPL_ASSERT_NOT_NULL(fc->data);
    zpl_free(fc->allocator, fc->data);
    fc->data = NULL;
    fc->size = 0;
}





zpl_inline b32 zpl_path_is_absolute(char const *path) {
    b32 result = false;
    ZPL_ASSERT_NOT_NULL(path);
#if defined(ZPL_SYSTEM_WINDOWS)
    result = (zpl_strlen(path) > 2) &&
        zpl_char_is_alpha(path[0]) &&
        (path[1] == ':' && path[2] == ZPL_PATH_SEPARATOR);
#else
    result = (zpl_strlen(path) > 0 && path[0] == ZPL_PATH_SEPARATOR);
#endif
    return result;
}

zpl_inline b32 zpl_path_is_relative(char const *path) { return !zpl_path_is_absolute(path); }

zpl_inline b32 zpl_path_is_root(char const *path) {
    b32 result = false;
    ZPL_ASSERT_NOT_NULL(path);
#if defined(ZPL_SYSTEM_WINDOWS)
    result = zpl_path_is_absolute(path) && (zpl_strlen(path) == 3);
#else
    result = zpl_path_is_absolute(path) && (zpl_strlen(path) == 1);
#endif
    return result;
}

zpl_inline char const *zpl_path_base_name(char const *path) {
    char const *ls;
    ZPL_ASSERT_NOT_NULL(path);
    ls = zpl_char_last_occurence(path, '/');
    return (ls == NULL) ? path : ls+1;
}

zpl_inline char const *zpl_path_extension(char const *path) {
    char const *ld;
    ZPL_ASSERT_NOT_NULL(path);
    ld = zpl_char_last_occurence(path, '.');
    return (ld == NULL) ? NULL : ld+1;
}


#if !defined(_WINDOWS_) && defined(ZPL_SYSTEM_WINDOWS)
ZPL_DLL_IMPORT DWORD WINAPI GetFullPathNameA(char const *lpFileName, DWORD nBufferLength, char *lpBuffer, char **lpFilePart);
ZPL_DLL_IMPORT DWORD WINAPI GetFullPathNameW(wchar_t const *lpFileName, DWORD nBufferLength, wchar_t *lpBuffer, wchar_t **lpFilePart);
#endif

char *zpl_path_get_full_name(zpl_allocator a, char const *path) {
#if defined(ZPL_SYSTEM_WINDOWS)
    wchar_t *w_path = NULL;
    wchar_t *w_fullpath = NULL;
    isize w_len = 0;
    isize new_len = 0;
    isize new_len1 = 0;
    char *new_path = 0;
    w_path = zpl__alloc_utf8_to_ucs2(zpl_heap_allocator(), path, NULL);
    if (w_path == NULL) {
        return NULL;
    }
    w_len = GetFullPathNameW(w_path, 0, NULL, NULL);
    if (w_len == 0) {
        return NULL;
    }
    w_fullpath = zpl_alloc_array(zpl_heap_allocator(), wchar_t, w_len+1);
    GetFullPathNameW(w_path, cast(int)w_len, w_fullpath, NULL);
    w_fullpath[w_len] = 0;
    zpl_free(zpl_heap_allocator(), w_path);

    new_len = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, w_fullpath, cast(int)w_len, NULL, 0, NULL, NULL);
    if (new_len == 0) {
        zpl_free(zpl_heap_allocator(), w_fullpath);
        return NULL;
    }
    new_path = zpl_alloc_array(a, char, new_len1);
    new_len1 = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, w_fullpath, cast(int)w_len, new_path, cast(int)new_len, NULL, NULL);
    if (new_len1 == 0) {
        zpl_free(zpl_heap_allocator(), w_fullpath);
        zpl_free(a, new_path);
        return NULL;
    }
    new_path[new_len] = 0;
    return new_path;
#else
    char *p, *result, *fullpath = NULL;
    isize len;
    p = realpath(path, NULL);
    fullpath = p;
    if (p == NULL) {
        // NOTE(bill): File does not exist
        fullpath = cast(char *)path;
    }

    len = zpl_strlen(fullpath);

    result = zpl_alloc_array(a, char, len + 1);
    zpl_memmove(result, fullpath, len);
    result[len] = 0;
    zpl_free(a, p);

    return result;
#endif
}


zplFileError zpl_path_mkdir(char const *path, i32 mode) {
    i32 error = 0;
    #if defined(ZPL_SYSTEM_WINDOWS)
        error = _wmkdir((const wchar_t *)zpl_utf8_to_ucs2_buf((const u8 *)path));
    #else
        error = mkdir(path, (mode_t)mode);
    #endif

    if (error == 0) {
        return ZPL_FILE_ERROR_NONE;
    }

    switch (errno)  {
        case EPERM:
        case EACCES:        return ZPL_FILE_ERROR_PERMISSION;
        case EEXIST:        return ZPL_FILE_ERROR_EXISTS;
        case ENAMETOOLONG:  return ZPL_FILE_ERROR_NAME_TOO_LONG;
    }

    return ZPL_FILE_ERROR_UNKNOWN;
}

zplFileError zpl_path_rmdir(char const *path) {
    i32 error = 0;
    #if defined(ZPL_SYSTEM_WINDOWS)
        error = _wrmdir((const wchar_t *)zpl_utf8_to_ucs2_buf((const u8 *)path));
    #else
        error = rmdir(path);
    #endif

    if (error == 0) {
        return ZPL_FILE_ERROR_NONE;
    }

    switch (errno)  {
        case EPERM:
        case EACCES:        return ZPL_FILE_ERROR_PERMISSION;
        case ENOENT:        return ZPL_FILE_ERROR_NOT_EXISTS;
        case ENOTEMPTY:     return ZPL_FILE_ERROR_NOT_EMPTY;
        case ENAMETOOLONG:  return ZPL_FILE_ERROR_NAME_TOO_LONG;
    }

    return ZPL_FILE_ERROR_UNKNOWN;
}

void zpl__file_direntry(zpl_allocator alloc, char const *dirname, zpl_string *output, b32 recurse) {
#if defined(ZPL_SYSTEM_UNIX) || defined(ZPL_SYSTEM_OSX)
    DIR *d, *cd;
    struct dirent *dir;
    d = opendir(dirname);

    if (d) {
        while ((dir = readdir(d))) {
            if (!zpl_strncmp(dir->d_name, "..", 2)) continue;
            if (dir->d_name[0]=='.' && dir->d_name[1]==0) continue;

            zpl_string dirpath=zpl_string_make(alloc, dirname);
            dirpath=zpl_string_appendc(dirpath, "/");
            dirpath=zpl_string_appendc(dirpath, dir->d_name);

            if ((cd = opendir(dirpath)) == NULL) {
                *output=zpl_string_appendc(*output, dirpath);
                *output=zpl_string_appendc(*output, "\n");
            }

            if (recurse) {
                zpl__file_direntry(alloc, dirpath, output, recurse);
            }
            zpl_string_free(dirpath);
        }
    }
#elif defined(ZPL_SYSTEM_WINDOWS)
    usize length = zpl_strlen(dirname);
    struct _wfinddata_t data;
    intptr_t findhandle;

    char directory[MAX_PATH] = {0};
    zpl_strncpy(directory, dirname, length);

    // keeping it native
    for (usize i = 0; i < length; i++) {
        if (directory[i] == '/') directory[i] = '\\';
    }

    // remove trailing slashses
    if (directory[length - 1] == '\\') {
        directory[length - 1] = '\0';
    }

    // attach search parttern
    zpl_string findpath=zpl_string_make(alloc, directory);
    findpath=zpl_string_appendc(findpath, "\\");
    findpath=zpl_string_appendc(findpath, "*");

    findhandle = _wfindfirst((const wchar_t *)zpl_utf8_to_ucs2_buf((const u8 *)findpath), &data);
    zpl_string_free(findpath);

    if (findhandle != -1) {
        do {
            char *filename = (char *)zpl_ucs2_to_utf8_buf((const u16 *)data.name);
            if (!zpl_strncmp(filename, "..", 2)) continue;
            if (filename[0]=='.' && filename[1]==0) continue;

            zpl_string dirpath=zpl_string_make(alloc, directory);
            dirpath=zpl_string_appendc(dirpath, "\\");
            dirpath=zpl_string_appendc(dirpath, filename);

            if (!(data.attrib & _A_SUBDIR)) {
                *output=zpl_string_appendc(*output, dirpath);
                *output=zpl_string_appendc(*output, "\n");
            }
            else if (recurse) {
                zpl__file_direntry(alloc, dirpath, output, recurse);
            }

            zpl_string_free(dirpath);
        }
        while (_wfindnext(findhandle, &data) != -1);
        _findclose(findhandle);
    }
#else
    // TODO: Implement other OSes
#endif
}

zpl_string zpl_path_dirlist(zpl_allocator alloc, char const *dirname, b32 recurse) {
    zpl_string buf=zpl_string_make_reserve(alloc, 4);
    zpl__file_direntry(alloc, dirname, &buf, recurse);
    return buf;
}



////////////////////////////////////////////////////////////////
//
// Printing
//
//


isize zpl_printf(char const *fmt, ...) {
    isize res;
    va_list va;
    va_start(va, fmt);
    res = zpl_printf_va(fmt, va);
    va_end(va);
    return res;
}


isize zpl_printf_err(char const *fmt, ...) {
    isize res;
    va_list va;
    va_start(va, fmt);
    res = zpl_printf_err_va(fmt, va);
    va_end(va);
    return res;
}

isize zpl_fprintf(struct zpl_file *f, char const *fmt, ...) {
    isize res;
    va_list va;
    va_start(va, fmt);
    res = zpl_fprintf_va(f, fmt, va);
    va_end(va);
    return res;
}

char *zpl_bprintf(char const *fmt, ...) {
    va_list va;
    char *str;
    va_start(va, fmt);
    str = zpl_bprintf_va(fmt, va);
    va_end(va);
    return str;
}

isize zpl_snprintf(char *str, isize n, char const *fmt, ...) {
    isize res;
    va_list va;
    va_start(va, fmt);
    res = zpl_snprintf_va(str, n, fmt, va);
    va_end(va);
    return res;
}



zpl_inline isize zpl_printf_va(char const *fmt, va_list va) {
    return zpl_fprintf_va(zpl_file_get_standard(ZPL_FILE_STANDARD_OUTPUT), fmt, va);
}

zpl_inline isize zpl_printf_err_va(char const *fmt, va_list va) {
    return zpl_fprintf_va(zpl_file_get_standard(ZPL_FILE_STANDARD_ERROR), fmt, va);
}

zpl_inline isize zpl_fprintf_va(struct zpl_file *f, char const *fmt, va_list va) {
    zpl_local_persist char buf[4096];
    isize len = zpl_snprintf_va(buf, zpl_size_of(buf), fmt, va);
    zpl_file_write(f, buf, len-1); // NOTE: prevent extra whitespace
    return len;
}


zpl_inline char *zpl_bprintf_va(char const *fmt, va_list va) {
    zpl_local_persist char buffer[4096];
    zpl_snprintf_va(buffer, zpl_size_of(buffer), fmt, va);
    return buffer;
}


enum {
    ZPL_FMT_MINUS     = ZPL_BIT(0),
    ZPL_FMT_PLUS      = ZPL_BIT(1),
    ZPL_FMT_ALT       = ZPL_BIT(2),
    ZPL_FMT_SPACE     = ZPL_BIT(3),
    ZPL_FMT_ZERO      = ZPL_BIT(4),

    ZPL_FMT_CHAR      = ZPL_BIT(5),
    ZPL_FMT_SHORT     = ZPL_BIT(6),
    ZPL_FMT_INT       = ZPL_BIT(7),
    ZPL_FMT_LONG      = ZPL_BIT(8),
    ZPL_FMT_LLONG     = ZPL_BIT(9),
    ZPL_FMT_SIZE      = ZPL_BIT(10),
    ZPL_FMT_INTPTR    = ZPL_BIT(11),

    ZPL_FMT_UNSIGNED  = ZPL_BIT(12),
    ZPL_FMT_LOWER     = ZPL_BIT(13),
    ZPL_FMT_UPPER     = ZPL_BIT(14),


    ZPL_FMT_DONE      = ZPL_BIT(30),

    ZPL_FMT_INTS = ZPL_FMT_CHAR|ZPL_FMT_SHORT|ZPL_FMT_INT|ZPL_FMT_LONG|ZPL_FMT_LLONG|ZPL_FMT_SIZE|ZPL_FMT_INTPTR
};

typedef struct {
    i32 base;
    i32 flags;
    i32 width;
    i32 precision;
} zplprivFmtInfo;


zpl_internal isize zpl__print_string(char *text, isize max_len, zplprivFmtInfo *info, char const *str) {
    // TODO: Get precision and width to work correctly. How does it actually work?!
    // TODO: This looks very buggy indeed.
    isize res = 0, len;
    isize remaining = max_len;

    if (info && info->precision >= 0)
        len = zpl_strnlen(str, info->precision);
    else
        len = zpl_strlen(str);

    if (info && (info->width == 0 || info->flags & ZPL_FMT_MINUS)) {
        if (info->precision > 0)
            len = info->precision < len ? info->precision : len;

        res += zpl_strlcpy(text, str, len);

        if (info->width > res) {
            isize padding = info->width - len;
            char pad = (info->flags & ZPL_FMT_ZERO) ? '0' : ' ';
            while (padding --> 0 && remaining --> 0)
                *text++ = pad, res++;
        }
    } else {
        if (info && (info->width > res)) {
            isize padding = info->width - len;
            char pad = (info->flags & ZPL_FMT_ZERO) ? '0' : ' ';
            while (padding --> 0 && remaining --> 0)
                *text++ = pad, res++;
        }

        res += zpl_strlcpy(text, str, len);
    }


    if (info) {
        if (info->flags & ZPL_FMT_UPPER)
            zpl_str_to_upper(text);
        else if (info->flags & ZPL_FMT_LOWER)
            zpl_str_to_lower(text);
    }

    return res;
}

zpl_internal isize zpl__print_char(char *text, isize max_len, zplprivFmtInfo *info, char arg) {
    char str[2] = "";
    str[0] = arg;
    return zpl__print_string(text, max_len, info, str);
}


zpl_internal isize zpl__print_i64(char *text, isize max_len, zplprivFmtInfo *info, i64 value) {
    char num[130];
    zpl_i64_to_str(value, num, info ? info->base : 10);
    return zpl__print_string(text, max_len, info, num);
}

zpl_internal isize zpl__print_u64(char *text, isize max_len, zplprivFmtInfo *info, u64 value) {
    char num[130];
    zpl_u64_to_str(value, num, info ? info->base : 10);
    return zpl__print_string(text, max_len, info, num);
}


zpl_internal isize zpl__print_f64(char *text, isize max_len, zplprivFmtInfo *info, f64 arg) {
    // TODO: Handle exponent notation
    isize width, len, remaining = max_len;
    char *text_begin = text;

    if (arg) {
        u64 value;
        if (arg < 0) {
            if (remaining > 1)
                *text = '-', remaining--;
            text++;
            arg = -arg;
        } else if (info->flags & ZPL_FMT_MINUS) {
            if (remaining > 1)
                *text = '+', remaining--;
            text++;
        }

        value = cast(u64)arg;
        len = zpl__print_u64(text, remaining, NULL, value);
        text += len;

        if (len >= remaining)
            remaining = zpl_min(remaining, 1);
        else
            remaining -= len;
        arg -= value;

        if (info->precision < 0)
            info->precision = 6;

        if ((info->flags & ZPL_FMT_ALT) || info->precision > 0) {
            i64 mult = 10;
            if (remaining > 1)
                *text = '.', remaining--;
            text++;
            while (info->precision-- > 0) {
                value = cast(u64)(arg * mult);
                len = zpl__print_u64(text, remaining, NULL, value);
                text += len;
                if (len >= remaining)
                    remaining = zpl_min(remaining, 1);
                else
                    remaining -= len;
                arg -= cast(f64)value / mult;
                mult *= 10;
            }
        }
    } else {
        if (remaining > 1)
            *text = '0', remaining--;
        text++;
        if (info->flags & ZPL_FMT_ALT) {
            if (remaining > 1)
                *text = '.', remaining--;
            text++;
        }
    }

    width = info->width - (text - text_begin);
    if (width > 0) {
        char fill = (info->flags & ZPL_FMT_ZERO) ? '0' : ' ';
        char *end = text+remaining-1;
        len = (text - text_begin);

        for (len = (text - text_begin); len--; ) {
            if ((text_begin+len+width) < end)
                *(text_begin+len+width) = *(text_begin+len);
        }

        len = width;
        text += len;
        if (len >= remaining)
            remaining = zpl_min(remaining, 1);
        else
            remaining -= len;

        while (len--) {
            if (text_begin+len < end)
                text_begin[len] = fill;
        }
    }

    return (text - text_begin);
}



zpl_no_inline isize zpl_snprintf_va(char *text, isize max_len, char const *fmt, va_list va) {
    char const *text_begin = text;
    isize remaining = max_len, res;

    while (*fmt) {
        zplprivFmtInfo info = {0};
        isize len = 0;
        info.precision = -1;

        while (*fmt && *fmt != '%' && remaining)
            *text++ = *fmt++;

        if (*fmt == '%') {
            do {
                switch (*++fmt) {
                case '-': info.flags |= ZPL_FMT_MINUS; break;
                case '+': info.flags |= ZPL_FMT_PLUS;  break;
                case '#': info.flags |= ZPL_FMT_ALT;   break;
                case ' ': info.flags |= ZPL_FMT_SPACE; break;
                case '0': info.flags |= ZPL_FMT_ZERO;  break;
                default:  info.flags |= ZPL_FMT_DONE;  break;
                }
            } while (!(info.flags & ZPL_FMT_DONE));
        }

        // NOTE: Optional Width
        if (*fmt == '*') {
            int width = va_arg(va, int);
            if (width < 0) {
                info.flags |= ZPL_FMT_MINUS;
                info.width = -info.width;
            } else {
                info.width = -info.width;
            }
            fmt++;
        } else {
            info.width = cast(i32)zpl_str_to_i64(fmt, cast(char **)&fmt, 10);
        }

        // NOTE: Optional Precision
        if (*fmt == '.') {
            fmt++;
            if (*fmt == '*') {
                info.precision = va_arg(va, int);
                fmt++;
            } else {
                info.precision = cast(i32)zpl_str_to_i64(fmt, cast(char **)&fmt, 10);
            }
            info.flags &= ~ZPL_FMT_ZERO;
        }


        switch (*fmt++) {
        case 'h':
            if (*fmt == 'h') { // hh => char
                info.flags |= ZPL_FMT_CHAR;
                fmt++;
            } else { // h => short
                info.flags |= ZPL_FMT_SHORT;
            }
            break;

        case 'l':
            if (*fmt == 'l') { // ll => long long
                info.flags |= ZPL_FMT_LLONG;
                fmt++;
            } else { // l => long
                info.flags |= ZPL_FMT_LONG;
            }
            break;

            break;

        case 'z': // NOTE: usize
            info.flags |= ZPL_FMT_UNSIGNED;
            // fallthrough
        case 't': // NOTE: isize
            info.flags |= ZPL_FMT_SIZE;
            break;

        default: fmt--; break;
        }


        switch (*fmt) {
        case 'u':
            info.flags |= ZPL_FMT_UNSIGNED;
            // fallthrough
        case 'd':
        case 'i':
            info.base = 10;
            break;

        case 'o':
            info.base = 8;
            break;

        case 'x':
            info.base = 16;
            info.flags |= (ZPL_FMT_UNSIGNED | ZPL_FMT_LOWER);
            break;

        case 'X':
            info.base = 16;
            info.flags |= (ZPL_FMT_UNSIGNED | ZPL_FMT_UPPER);
            break;

        case 'f':
        case 'F':
        case 'g':
        case 'G':
            len = zpl__print_f64(text, remaining, &info, va_arg(va, f64));
            break;

        case 'a':
        case 'A':
            // TODO:
            break;

        case 'c':
            len = zpl__print_char(text, remaining, &info, cast(char)va_arg(va, int));
            break;

        case 's':
            len = zpl__print_string(text, remaining, &info, va_arg(va, char *));
            break;

        case 'p':
            info.base = 16;
            info.flags |= (ZPL_FMT_LOWER|ZPL_FMT_UNSIGNED|ZPL_FMT_ALT|ZPL_FMT_INTPTR);
            break;

        case '%':
            len = zpl__print_char(text, remaining, &info, '%');
            break;

        default: fmt--; break;
        }

        fmt++;

        if (info.base != 0) {
            if (info.flags & ZPL_FMT_UNSIGNED) {
                u64 value = 0;
                switch (info.flags & ZPL_FMT_INTS) {
                case ZPL_FMT_CHAR:   value = cast(u64)cast(u8) va_arg(va, int);       break;
                case ZPL_FMT_SHORT:  value = cast(u64)cast(u16)va_arg(va, int);       break;
                case ZPL_FMT_LONG:   value = cast(u64)va_arg(va, unsigned long);      break;
                case ZPL_FMT_LLONG:  value = cast(u64)va_arg(va, unsigned long long); break;
                case ZPL_FMT_SIZE:   value = cast(u64)va_arg(va, usize);              break;
                case ZPL_FMT_INTPTR: value = cast(u64)va_arg(va, uintptr);            break;
                default:             value = cast(u64)va_arg(va, unsigned int);       break;
                }

                len = zpl__print_u64(text, remaining, &info, value);

            } else {
                i64 value = 0;
                switch (info.flags & ZPL_FMT_INTS) {
                case ZPL_FMT_CHAR:   value = cast(i64)cast(i8) va_arg(va, int); break;
                case ZPL_FMT_SHORT:  value = cast(i64)cast(i16)va_arg(va, int); break;
                case ZPL_FMT_LONG:   value = cast(i64)va_arg(va, long);         break;
                case ZPL_FMT_LLONG:  value = cast(i64)va_arg(va, long long);    break;
                case ZPL_FMT_SIZE:   value = cast(i64)va_arg(va, usize);        break;
                case ZPL_FMT_INTPTR: value = cast(i64)va_arg(va, uintptr);      break;
                default:             value = cast(i64)va_arg(va, int);          break;
                }

                len = zpl__print_i64(text, remaining, &info, value);
            }
        }


        text += len;
        if (len >= remaining)
            remaining = zpl_min(remaining, 1);
        else
            remaining -= len;
    }

    *text++ = '\0';
    res = (text - text_begin);
    return (res >= max_len || res < 0) ? -1 : res;
}


////////////////////////////////////////////////////////////////
//
// DLL Handling
//
//

#if defined(ZPL_SYSTEM_WINDOWS)

zpl_dll_handle zpl_dll_load(char const *filepath) {
    return cast(zpl_dll_handle)LoadLibraryA(filepath);
}
zpl_inline void      zpl_dll_unload      (zpl_dll_handle dll)                        { FreeLibrary(cast(HMODULE)dll); }
zpl_inline zpl_dll_proc zpl_dll_proc_address(zpl_dll_handle dll, char const *proc_name) { return cast(zpl_dll_proc)GetProcAddress(cast(HMODULE)dll, proc_name); }

#else // POSIX

zpl_dll_handle zpl_dll_load(char const *filepath) {
    return cast(zpl_dll_handle)dlopen(filepath, RTLD_LAZY|RTLD_GLOBAL);
}

zpl_inline void      zpl_dll_unload      (zpl_dll_handle dll)                        { dlclose(dll); }
zpl_inline zpl_dll_proc zpl_dll_proc_address(zpl_dll_handle dll, char const *proc_name) { return cast(zpl_dll_proc)dlsym(dll, proc_name); }

#endif


////////////////////////////////////////////////////////////////
//
// Time
//
//

#if defined(ZPL_COMPILER_MSVC) && !defined(__clang__)
zpl_inline u64 zpl_rdtsc(void) { return __rdtsc(); }
#elif defined(__i386__)
zpl_inline u64 zpl_rdtsc(void) {
    u64 x;
    __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
    return x;
}
#elif defined(__x86_64__)
zpl_inline u64 zpl_rdtsc(void) {
    u32 hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return (cast(u64)lo) | ((cast(u64)hi)<<32);
}
#elif defined(__powerpc__)
zpl_inline u64 zpl_rdtsc(void) {
    u64 result = 0;
    u32 upper, lower,tmp;
    __asm__ volatile(
                        "0:                   \n"
                        "\tmftbu   %0         \n"
                        "\tmftb    %1         \n"
                        "\tmftbu   %2         \n"
                        "\tcmpw    %2,%0      \n"
                        "\tbne     0b         \n"
                        : "=r"(upper),"=r"(lower),"=r"(tmp)
                        );
    result = upper;
    result = result<<32;
    result = result|lower;

    return result;
}
#elif defined(ZPL_CPU_ARM)
zpl_inline u64 zpl_rdtsc(void) {
#if defined(__aarch64__)
    int64_t r = 0;
    asm volatile("mrs %0, cntvct_el0" : "=r"(r) );
#elif defined(__ARM_ARCH_7A__)
    uint32_t r = 0;
    asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(r) );
#elif (__ARM_ARCH >= 6)
    uint32_t pmccntr;
    uint32_t pmuseren;
    uint32_t pmcntenset;

    // Read the user mode perf monitor counter access permissions.
    asm volatile("mrc p15, 0, %0, c9, c14, 0" : "=r"(pmuseren));
    if (pmuseren & 1) {  // Allows reading perfmon counters for user mode code.
        asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r"(pmcntenset));
        if (pmcntenset & 0x80000000ul) {  // Is it counting?
            asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(pmccntr));
            // The counter is set up to count every 64th cycle
            return ((int64_t)pmccntr) * 64;  // Should optimize to << 6
        }
    }
#else
#error "No suitable method for zpl_rdtsc for this cpu type"
#endif
    return r;
}
#endif

#if defined(ZPL_SYSTEM_WINDOWS)

zpl_inline f64 zpl_time_now(void) {
    zpl_local_persist LARGE_INTEGER win32_perf_count_freq = {0};
    f64 result;
    LARGE_INTEGER counter;
    zpl_local_persist LARGE_INTEGER win32_perf_counter = {0};
    if (!win32_perf_count_freq.QuadPart) {
        QueryPerformanceFrequency(&win32_perf_count_freq);
        ZPL_ASSERT(win32_perf_count_freq.QuadPart != 0);
        QueryPerformanceCounter(&win32_perf_counter);
    }

    QueryPerformanceCounter(&counter);

    result = (counter.QuadPart - win32_perf_counter.QuadPart)  / cast(f64)(win32_perf_count_freq.QuadPart);
    return result;
}

zpl_inline f64 zpl_utc_time_now(void) {
    FILETIME ft;
    ULARGE_INTEGER li;

    GetSystemTimeAsFileTime(&ft);
    li.LowPart = ft.dwLowDateTime;
    li.HighPart = ft.dwHighDateTime;

    return li.QuadPart/10 / 10e5;
}

zpl_inline void zpl_sleep_ms(u32 ms) { Sleep(ms); }

#else

#if defined(ZPL_SYSTEM_LINUX)
f64 zpl__unix_getime(void) {
    struct timespec t;
    f64 result;

    clock_gettime(1 /*CLOCK_MONOTONIC*/, &t);
    result = t.tv_sec + 1.0e-9 * t.tv_nsec;
    return result;
}
#endif

zpl_inline f64 zpl_time_now(void) {
#if defined(ZPL_SYSTEM_OSX)
    f64 result;

    zpl_local_persist f64 timebase  = 0.0;
    zpl_local_persist u64 timestart = 0;

    if (!timestart) {
        mach_timebase_info_data_t tb = {0};
        mach_timebase_info(&tb);
        timebase = tb.numer;
        timebase /= tb.denom;
        timestart = mach_absolute_time();
    }

    // NOTE: mach_absolute_time() returns things in nanoseconds
    result = 1.0e-9 * (mach_absolute_time() - timestart) * timebase;
    return result;
#else
    zpl_local_persist f64 unix_timestart = 0.0;

    if (!unix_timestart) {
        unix_timestart = zpl__unix_getime();
    }

    f64 now = zpl__unix_getime();

    return (now - unix_timestart);
#endif
}

zpl_inline f64 zpl_utc_time_now(void) {
    struct timespec t;
#if defined(ZPL_SYSTEM_OSX)
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    t.tv_sec = mts.tv_sec;
    t.tv_nsec = mts.tv_nsec;
#else
    clock_gettime(0 /*CLOCK_REALTIME*/, &t);
#endif
    return (cast(u64)t.tv_sec * 1000000ull + t.tv_nsec/1000 + 11644473600000000ull) / 10e5;
}

zpl_inline void zpl_sleep_ms(u32 ms) {
    struct timespec req = {cast(time_t)ms/1000, cast(long)((ms%1000)*1000000)};
    struct timespec rem = {0, 0};
    nanosleep(&req, &rem);
}

#endif


////////////////////////////////////////////////////////////////
//
// Timer
//
//

zpl_inline zpl_timer *zpl_timer_add(zpl_timer_pool pool) {
    ZPL_ASSERT(pool);

    zpl_timer t = {0};
    zpl_array_append(pool, t);
    return pool + (zpl_array_count(pool) - 1);
}

zpl_inline void zpl_timer_set(zpl_timer *t, f64 duration, i32 count, zpl_timer_cb *cb) {
    ZPL_ASSERT(t);

    t->duration        = duration;
    t->remaining_calls = t->initial_calls = count;
    t->callback        = cb;
    t->enabled         = false;
}

zpl_inline void zpl_timer_start(zpl_timer *t, f64 delay_start) {
    ZPL_ASSERT(t && !t->enabled);

    t->enabled = true;
    t->remaining_calls = t->initial_calls;
    t->next_call_ts = zpl_time_now() + delay_start;
}

zpl_inline void zpl_timer_stop(zpl_timer *t) {
    ZPL_ASSERT(t && t->enabled);

    t->enabled = false;
}

zpl_inline void zpl_timer_update(zpl_timer_pool pool) {
    ZPL_ASSERT(pool);

    f64 now = zpl_time_now();

    for (isize i = 0; i < zpl_array_count(pool); ++i) {
        zpl_timer *t = pool + i;

        if (t->enabled) {
            if (t->remaining_calls > 0 || t->initial_calls == -1) {
                if (t->next_call_ts <= now) {
                    if (t->initial_calls != -1) {
                        --t->remaining_calls;
                    }

                    if (t->remaining_calls == 0) {
                        t->enabled = false;
                    }
                    else {
                        t->next_call_ts = now + t->duration;
                    }

                    t->callback(t->user_data);
                }
            }
        }
    }
}


////////////////////////////////////////////////////////////////
//
// Event Handler
//
//


ZPL_TABLE_DEFINE(zpl_event_pool, zpl_event_pool_, zpl_event_block);

zpl_inline void zpl_event_init   (zpl_event_pool *pool, zpl_allocator alloc) {
    zpl_event_pool_init(pool, alloc);
}

zpl_inline void zpl_event_destroy(zpl_event_pool *pool) {
    for (isize i = 0; i < zpl_array_count(pool->entries); ++i) {
        zpl_event_block *block = &pool->entries[i].value;

        if (block) {
            zpl_array_free(*block);
        }
    }

    zpl_event_pool_destroy(pool);
}

u64 zpl_event_add(zpl_event_pool *pool, u64 slot, zpl_event_cb cb) {
    zpl_event_block *block = zpl_event_pool_get(pool, slot);

    if (!block) {
        zpl_event_block arr;
        zpl_array_init(arr, zpl_heap_allocator());
        zpl_event_pool_set(pool, slot, arr);
        block = zpl_event_pool_get(pool, slot);
    }

    u64 offset = zpl_array_count(block);
    zpl_array_append(*block, cb);
    return offset;
}

void zpl_event_remove(zpl_event_pool *pool, u64 slot, u64 index) {
    zpl_event_block *block = zpl_event_pool_get(pool, slot);

    if (block) {
        zpl_array_remove_at(*block, (isize)index);
    }
}

void zpl_event_trigger(zpl_event_pool *pool, u64 slot, zpl_event_data evt) {
    zpl_event_block *block = zpl_event_pool_get(pool, slot);

    if (block) {
        for (isize i = 0; i < zpl_array_count(*block); ++i) {
            (*block)[i](evt);
        }
    }
}

////////////////////////////////////////////////////////////////
//
// Miscellany
//
//

#if ZPL_THREADING
zpl_global zpl_atomic32 zpl__random_shared_counter = {0};
#else
zpl_global i32 zpl__random_shared_counter = 0;
#endif

zpl_internal u32 zpl__get_noise_from_time(void) {
    u32 accum = 0;
    f64 start, remaining, end, curr = 0;
    u64 interval = 100000ll;

    start     = zpl_time_now();
    remaining = (interval - cast(u64)(interval*start)%interval) / cast(f64)interval;
    end       = start + remaining;

    do {
        curr = zpl_time_now();
        accum += cast(u32)curr;
    } while (curr >= end);
    return accum;
}

// NOTE: Partly from http://preshing.com/20121224/how-to-generate-a-sequence-of-unique-random-integers/
// But the generation is even more random-er-est

zpl_internal zpl_inline u32 zpl__permute_qpr(u32 x) {
    zpl_local_persist u32 const prime = 4294967291; // 2^32 - 5
    if (x >= prime) {
        return x;
    } else {
        u32 residue = cast(u32)(cast(u64) x * x) % prime;
        if (x <= prime / 2)
            return residue;
        else
            return prime - residue;
    }
}

zpl_internal zpl_inline u32 zpl__permute_with_offset(u32 x, u32 offset) {
    return (zpl__permute_qpr(x) + offset) ^ 0x5bf03635;
}


void zpl_random_init(zpl_random *r) {
    u64 time, tick;
    isize i, j;
    u32 x = 0;
    r->value = 0;

    r->offsets[0] = zpl__get_noise_from_time();
#ifdef ZPL_THREADING
    r->offsets[1] = zpl_atomic32_fetch_add(&zpl__random_shared_counter, 1);
    r->offsets[2] = zpl_thread_current_id();
    r->offsets[3] = zpl_thread_current_id() * 3 + 1;
#else
    r->offsets[1] = zpl__random_shared_counter++;
    r->offsets[2] = 0;
    r->offsets[3] = 1;
#endif
    time = cast(u64)zpl_utc_time_now();
    r->offsets[4] = cast(u32)(time >> 32);
    r->offsets[5] = cast(u32)time;
    r->offsets[6] = zpl__get_noise_from_time();
    tick = zpl_rdtsc();
    r->offsets[7] = cast(u32)(tick ^ (tick >> 32));

    for (j = 0; j < 4; j++) {
        for (i = 0; i < zpl_count_of(r->offsets); i++) {
            r->offsets[i] = x = zpl__permute_with_offset(x, r->offsets[i]);
        }
    }
}

u32 zpl_random_gen_u32(zpl_random *r) {
    u32 x = r->value;
    u32 carry = 1;
    isize i;
    for (i = 0; i < zpl_count_of(r->offsets); i++) {
        x = zpl__permute_with_offset(x, r->offsets[i]);
        if (carry > 0) {
            carry = ++r->offsets[i] ? 0 : 1;
        }
    }

    r->value = x;
    return x;
}

u32 zpl_random_gen_u32_unique(zpl_random *r) {
    u32 x = r->value;
    isize i;
    r->value++;
    for (i = 0; i < zpl_count_of(r->offsets); i++) {
        x = zpl__permute_with_offset(x, r->offsets[i]);
    }

    return x;
}

u64 zpl_random_gen_u64(zpl_random *r) {
    return ((cast(u64)zpl_random_gen_u32(r)) << 32) | zpl_random_gen_u32(r);
}


isize zpl_random_gen_isize(zpl_random *r) {
    u64 u = zpl_random_gen_u64(r);
    return *cast(isize *)&u;
}




i64 zpl_random_range_i64(zpl_random *r, i64 lower_inc, i64 higher_inc) {
    u64 u = zpl_random_gen_u64(r);
    i64 i = *cast(i64 *)&u;
    i64 diff = higher_inc-lower_inc+1;
    i %= diff;
    i += lower_inc;
    return i;
}

isize zpl_random_range_isize(zpl_random *r, isize lower_inc, isize higher_inc) {
    u64 u = zpl_random_gen_u64(r);
    isize i = *cast(isize *)&u;
    isize diff = higher_inc-lower_inc+1;
    i %= diff;
    i += lower_inc;
    return i;
}

f64 zpl_random_range_f64(zpl_random *r, f64 lower_inc, f64 higher_inc) {
    u64 u = zpl_random_gen_u64(r);
    f64 f = *cast(f64 *)&u;
    f64 diff = higher_inc-lower_inc+1.0;
    f = zpl_mod64(f, diff);
    f += lower_inc;
    return f;
}



#if defined(ZPL_SYSTEM_WINDOWS)
zpl_inline void zpl_exit(u32 code) { ExitProcess(code); }
#else
zpl_inline void zpl_exit(u32 code) { exit(code); }
#endif

zpl_inline void zpl_yield(void) {
#if defined(ZPL_SYSTEM_WINDOWS)
    Sleep(0);
#else
    sched_yield();
#endif
}

#include <stdlib.h>

zpl_inline char const *zpl_get_env(char const *name) {
    return getenv(name);

    // TODO: Use GetEnvironmentVariable on Windows?
}

zpl_inline void zpl_set_env(char const *name, char const *value) {
#if defined(ZPL_SYSTEM_WINDOWS)
    // TODO: Should this be a Wide version?
    SetEnvironmentVariableA(name, value);
#else
    setenv(name, value, 1);
#endif
}

zpl_inline void zpl_unset_env(char const *name) {
#if defined(ZPL_SYSTEM_WINDOWS)
    // TODO: Should this be a Wide version?
    SetEnvironmentVariableA(name, NULL);
#else
    unsetenv(name);
#endif
}


zpl_inline u16 zpl_endian_swap16(u16 i) {
    return (i>>8) | (i<<8);
}

zpl_inline u32 zpl_endian_swap32(u32 i) {
    return (i>>24) |(i<<24) |
        ((i&0x00ff0000u)>>8)  | ((i&0x0000ff00u)<<8);
}

zpl_inline u64 zpl_endian_swap64(u64 i) {
    return (i>>56) | (i<<56) |
        ((i&0x00ff000000000000ull)>>40) | ((i&0x000000000000ff00ull)<<40) |
        ((i&0x0000ff0000000000ull)>>24) | ((i&0x0000000000ff0000ull)<<24) |
        ((i&0x000000ff00000000ull)>>8)  | ((i&0x00000000ff000000ull)<<8);
}


zpl_inline isize zpl_count_set_bits(u64 mask) {
    isize count = 0;
    while (mask) {
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

#if !defined(ZPL_SYSTEM_WINDOWS)
extern char **environ;
#endif

zpl_inline u32 zpl_system_command(char const *command, usize buffer_len, char *buffer) {
#if defined(ZPL_SYSTEM_EMSCRIPTEN)
    ZPL_PANIC("zpl_system_command not supported");
#else

#if defined(ZPL_SYSTEM_WINDOWS)
    FILE *handle = _popen(command, "r");
#else
    FILE *handle =  popen(command, "r");
#endif

    if(!handle) return 0;

    char c;
    usize i=0;
    while ((c = getc(handle)) != EOF && i++ < buffer_len) {
        *buffer++ = c;
    }
#if defined(ZPL_SYSTEM_WINDOWS)
    _pclose(handle);
#else
    pclose(handle);
#endif

#endif
    return 1;
}

zpl_inline u32 zpl_system_command_str(char const *command, zpl_array(u8) *str) {
#if defined(ZPL_SYSTEM_EMSCRIPTEN)
    ZPL_PANIC("zpl_system_command not supported");
#else

#if defined(ZPL_SYSTEM_WINDOWS)
    FILE *handle = _popen(command, "r");
#else
    FILE *handle =  popen(command, "r");
#endif

    if(!handle) return 0;

    char c;
    while ((c = getc(handle)) != EOF) {
        if (str) {
            zpl_array_append(*str, c);
        }
    }
#if defined(ZPL_SYSTEM_WINDOWS)
    _pclose(handle);
#else
    pclose(handle);
#endif

#endif
    return 1;
}

////////////////////////////////////////////////////////////////
//
// JSON5 Parser
//
//


b32 zpl__json_is_control_char(char c);
char *zpl__json_trim(char *str);

void zpl_json_parse(zpl_json_object *root, usize len, char *const source, zpl_allocator_t a, b32 strip_comments, u8 *err_code) {
    ZPL_ASSERT(root && source);
    zpl_unused(len);

    char *dest = source;

    if (strip_comments) {
        b32 is_lit = false;
        char lit_c = '\0';
        char *p = dest;
        char *b = dest;
        isize l = 0;

        while (*p) {
            if (!is_lit) {
                if ((*p == '"' || *p == '\'')) {
                    lit_c = *p;
                    is_lit = true;
                    ++p;
                    continue;
                }
            }
            else {
                /**/ if (*p == '\\' && *(p+1) && *(p+1) == lit_c) {
                    p+=2;
                    continue;
                }
                else if (*p == lit_c) {
                    is_lit = false;
                    ++p;
                    continue;
                }
            }

            if (!is_lit) {
                // NOTE(ZaKlaus): block comment
                if (p[0] == '/' && p[1] == '*') {
                    b = p;
                    l=2;
                    p+=2;

                    while (p[0] != '*' && p[1] != '/') {
                        ++p; ++l;
                    }
                    p+=2;
                    l+=2;
                    zpl_memset(b, ' ', l);
                }

                // NOTE(ZaKlaus): inline comment
                if (p[0] == '/' && p[1] == '/') {
                    b = p;
                    l=2;
                    p+=2;

                    while (p[0] != '\n') {
                        ++p; ++l;
                    }
                    ++l;
                    zpl_memset(b, ' ', l);
                }
            }

            ++p;
        }
    }

    if (err_code) *err_code = ZPL_JSON_ERROR_NONE;
    zpl_json_object root_ = {0};

    dest=zpl__json_trim(dest);

    if (*dest != '{' || *dest != '[') {
        root_.cfg_mode=true;
    }

    zpl__json_parse_object(&root_, dest, a, err_code);

    *root = root_;
}

#define zpl___ind(x) for (int i = 0; i < x; ++i) zpl_fprintf(f, " ");

void zpl__json_write_value(zpl_file *f, zpl_json_object_t *o, isize indent, b32 is_inline, b32 is_last);

void zpl_json_write(zpl_file *f, zpl_json_object *o, isize indent) {
    zpl___ind(indent-4);
    if (!o->cfg_mode) zpl_fprintf(f, "{\n");
    else {
        indent-=4;
    }
    isize cnt = zpl_array_count(o->nodes);

    for (int i = 0; i < cnt; ++i) {
        if (i < cnt-1) {
            zpl__json_write_value(f, o->nodes + i, indent, false, false);
        }
        else {
            zpl__json_write_value(f, o->nodes + i, indent, false, true);
        }
    }

    zpl___ind(indent);

    if (indent > 0) {
        zpl_fprintf(f, "}");
    }
    else {
        if (!o->cfg_mode) zpl_fprintf(f, "}\n");
    }
}

void zpl__json_write_value(zpl_file *f, zpl_json_object_t *o, isize indent, b32 is_inline, b32 is_last) {
    zpl_json_object_t *node = o;
    indent+=4;

    if (!is_inline) {
        zpl___ind(indent);
        switch(node->name_style) {
            case ZPL_JSON_NAME_STYLE_DOUBLE_QUOTE: {
                zpl_fprintf(f, "\"%s\": ", node->name);
            }break;

            case ZPL_JSON_NAME_STYLE_SINGLE_QUOTE: {
                zpl_fprintf(f, "\'%s\': ", node->name);
            }break;

            case ZPL_JSON_NAME_STYLE_NO_QUOTES: {
                zpl_fprintf(f, "%s: ", node->name);
            }break;
        }

    }

    switch (node->type) {
        case ZPL_JSON_TYPE_STRING: {
            zpl_fprintf(f, "\"%s\"", node->string);
        }break;

        case ZPL_JSON_TYPE_MULTISTRING: {
            zpl_fprintf(f, "`%s`", node->string);
        }break;

        case ZPL_JSON_TYPE_ARRAY: {
            zpl_fprintf(f, "[");
            isize elemn = zpl_array_count(node->elements);
            for (int j = 0; j < elemn; ++j) {
                zpl__json_write_value(f, node->elements + j, -4, true, true);

                if (j < elemn-1) {
                    zpl_fprintf(f, ", ");
                }
            }
            zpl_fprintf(f, "]");
        }break;

        case ZPL_JSON_TYPE_INTEGER: {
            /**/ if (node->props == ZPL_JSON_PROPS_IS_HEX) {
                zpl_fprintf(f, "0x%llx", (long long)node->integer);
            }
            else {
                zpl_fprintf(f, "%lld", (long long)node->integer);
            }
        }break;

        case ZPL_JSON_TYPE_REAL: {
            /**/ if (node->props == ZPL_JSON_PROPS_NAN) {
                zpl_fprintf(f, "NaN");
            }
            else if (node->props == ZPL_JSON_PROPS_NAN_NEG) {
                zpl_fprintf(f, "-NaN");
            }
            else if (node->props == ZPL_JSON_PROPS_INFINITY) {
                zpl_fprintf(f, "Infinity");
            }
            else if (node->props == ZPL_JSON_PROPS_INFINITY_NEG) {
                zpl_fprintf(f, "-Infinity");
            }
            else if (node->props == ZPL_JSON_PROPS_IS_EXP) {
                zpl_fprintf(f, "%lld.%llde%c%lld", (long long)node->base, (long long)node->base2, node->exp_neg ? '-' : '+', (long long)node->exp);
            }
            else {
                if (!node->lead_digit) zpl_fprintf(f, ".%lld", (long long)node->base2);
                else zpl_fprintf(f, "%lld.%lld", (long long)node->base, (long long)node->base2);
            }
        }break;

        case ZPL_JSON_TYPE_OBJECT: {
            zpl_json_write(f, node, indent);
        }break;

        case ZPL_JSON_TYPE_CONSTANT: {
            /**/ if (node->constant == ZPL_JSON_CONST_TRUE) {
                zpl_fprintf(f, "true");
            }
            else if (node->constant == ZPL_JSON_CONST_FALSE) {
                zpl_fprintf(f, "false");
            }
            else if (node->constant == ZPL_JSON_CONST_NULL) {
                zpl_fprintf(f, "null");
            }
        }break;
    }

    if (!is_inline) {

        if (!is_last) {
            zpl_fprintf(f, ",\n");
        }
        else {
            zpl_fprintf(f, "\n");
        }
    }
}
#undef zpl___ind

void zpl_json_free(zpl_json_object *obj) {
    /**/ if (obj->type == ZPL_JSON_TYPE_ARRAY && obj->elements) {
        for (isize i = 0; i < zpl_array_count(obj->elements); ++i) {
            zpl_json_free(obj->elements+i);
        }

        zpl_array_free(obj->elements);
    }
    else if (obj->type == ZPL_JSON_TYPE_OBJECT && obj->nodes) {
        for (isize i = 0; i < zpl_array_count(obj->nodes); ++i) {
            zpl_json_free(obj->nodes+i);
        }

        zpl_array_free(obj->nodes);
    }
}

char *zpl__json_parse_array(zpl_json_object *obj, char *base, zpl_allocator_t a, u8 *err_code) {
    ZPL_ASSERT(obj && base);
    char *p = base;

    obj->type = ZPL_JSON_TYPE_ARRAY;
    zpl_array_init(obj->elements, a);
    obj->backing = a;

    while(*p) {
        p = zpl__json_trim(p);

        zpl_json_object elem = {0};
        p = zpl__json_parse_value(&elem, p, a, err_code);

        if (err_code && *err_code != ZPL_JSON_ERROR_NONE) {
            return NULL;
        }

        zpl_array_append(obj->elements, elem);

        p = zpl__json_trim(p);

        if (*p == ',') {
            ++p;
            continue;
        }
        else {
            return p;
        }
    }
    return p;
}

char *zpl__json_parse_value(zpl_json_object *obj, char *base, zpl_allocator_t a, u8 *err_code) {
    ZPL_ASSERT(obj && base);
    char *p = base;
    char *b = base;
    char *e = base;

    /**/ if (*p == '"' || *p == '\'') {
        char c = *p;
        obj->type = ZPL_JSON_TYPE_STRING;
        b = p+1;
        e = b;
        obj->string = b;

        while(*e) {
            /**/ if (*e == '\\' && *(e+1) == c) {
                e += 2;
                continue;
            }
            else if (*e == '\\' && (*(e+1) == '\r' || *(e+1) == '\n')) {
                *e = ' ';
                e++;
                continue;
            }
            else if (*e == c) {
                break;
            }
            ++e;
        }

        *e = '\0';
        p = e+1;
    }
    else if (*p == '`') {
        obj->type = ZPL_JSON_TYPE_MULTISTRING;
        b = p+1;
        e = b;
        obj->string = b;


        while(*e) {
            /**/ if (*e == '\\' && *(e+1) == '`') {
                e += 2;
                continue;
            }
            else if (*e == '`') {
                break;
            }
            ++e;
        }

        *e = '\0';
        p = e+1;
    }
    else if (zpl_char_is_alpha(*p) || (*p == '-' && !zpl_char_is_digit(*(p+1)))) {
        obj->type = ZPL_JSON_TYPE_CONSTANT;

        /**/ if (!zpl_strncmp(p, "true", 4)) {
            obj->constant = ZPL_JSON_CONST_TRUE;
            p += 4;
        }
        else if (!zpl_strncmp(p, "false", 5)) {
            obj->constant = ZPL_JSON_CONST_FALSE;
            p += 5;
        }
        else if (!zpl_strncmp(p, "null", 4)) {
            obj->constant = ZPL_JSON_CONST_NULL;
            p += 4;
        }
        else if (!zpl_strncmp(p, "Infinity", 8)) {
            obj->type = ZPL_JSON_TYPE_REAL;
            obj->real = INFINITY;
            obj->props= ZPL_JSON_PROPS_INFINITY;
            p += 8;
        }
        else if (!zpl_strncmp(p, "-Infinity", 9)) {
            obj->type = ZPL_JSON_TYPE_REAL;
            obj->real = -INFINITY;
            obj->props= ZPL_JSON_PROPS_INFINITY_NEG;
            p += 9;
        }
        else if (!zpl_strncmp(p, "NaN", 3)) {
            obj->type = ZPL_JSON_TYPE_REAL;
            obj->real = NAN;
            obj->props= ZPL_JSON_PROPS_NAN;
            p += 3;
        }
        else if (!zpl_strncmp(p, "-NaN", 4)) {
            obj->type = ZPL_JSON_TYPE_REAL;
            obj->real = -NAN;
            obj->props= ZPL_JSON_PROPS_NAN_NEG;
            p += 4;
        }
        else {
            ZPL_JSON_ASSERT; if (err_code) *err_code = ZPL_JSON_ERROR_INVALID_VALUE;
            return NULL;
        }
    }
    else if (zpl_char_is_digit(*p) ||
                *p == '+' || *p == '-' ||
                *p == '.') {
        obj->type = ZPL_JSON_TYPE_INTEGER;

        b = p;
        e = b;

        isize ib = 0;
        u8 frac=0;
        char buf[16] = {0};

        /**/ if (*e == '+') ++e;
        else if (*e == '-') {
            buf[ib++] = *e++;
        }

        if (*e == '.') {
            obj->type = ZPL_JSON_TYPE_REAL;
            buf[ib++] = '0';
            obj->lead_digit = false;

            do {
                buf[ib++] = *e;
                ++frac;
            }
            while(zpl_char_is_digit(*++e));
        }
        else {
            if (*e == '0' && (*(e+1) == 'x' || *(e+1) == 'X')) {
                obj->props = ZPL_JSON_PROPS_IS_HEX;
            }
            while(zpl_char_is_hex_digit(*e) || *e == 'x' || *e == 'X') {
                buf[ib++] = *e++;
            }

            if (*e == '.') {
                obj->type = ZPL_JSON_TYPE_REAL;
                obj->lead_digit = true;
                u32 step = 0;

                do {
                    buf[ib++] = *e;
                    ++step;
                    ++frac;
                }
                while(zpl_char_is_digit(*++e));

                if (step < 2) {
                    buf[ib++] = '0';
                }
            }
        }

        i64 exp = 0; f32 eb = 10;
        char expbuf[6] = {0};
        isize expi = 0;

        if (*e == 'e' || *e == 'E') {
            ++e;
            if (*e == '+' || *e == '-' || zpl_char_is_digit(*e)) {
                if (*e == '-') {
                    eb = 0.1f;
                }

                if (!zpl_char_is_digit(*e)) {
                    ++e;
                }

                while(zpl_char_is_digit(*e)) {
                    expbuf[expi++] = *e++;
                }

            }

            exp = zpl_str_to_i64(expbuf, NULL, 10);
        }

        if (*e == '\0') {
            ZPL_JSON_ASSERT; if (err_code) *err_code = ZPL_JSON_ERROR_INVALID_VALUE;
        }

        if (obj->type == ZPL_JSON_TYPE_INTEGER) {
            obj->integer = zpl_str_to_i64(buf, 0, 0);

            while(--exp > 0) {
                obj->integer *= (i64)eb;
            }
        }
        else {
            obj->real = zpl_str_to_f64(buf, 0);
            obj->frac = frac-1;

            isize qs=zpl_strlen(buf)+1;
            char *q=(char *)zpl_malloc(qs), *qp=q, *qp2=q;
            zpl_memcopy(q,buf,qs);
            while (*qp != '.') ++qp;
            *qp='\0';
            qp2=qp+1;

            obj->base    = zpl_str_to_i64(q, 0, 0);
            obj->base2   = zpl_str_to_i64(qp2, 0, 0);

            if (exp) {
                obj->exp     = exp;
                obj->exp_neg = !(eb == 10.f);
                obj->props   = ZPL_JSON_PROPS_IS_EXP;
            }

            while(--exp > 0) {
                obj->real *= eb;
            }
        }
        p = e;
    }
    else if (*p == '[') {
        p = zpl__json_trim(p+1);
        if (*p == ']') return p;
        p = zpl__json_parse_array(obj, p, a, err_code);

        if (err_code && *err_code != ZPL_JSON_ERROR_NONE) {
            return NULL;
        }

        ++p;
    }
    else if (*p == '{') {
        p = zpl__json_trim(p+1);
        p = zpl__json_parse_object(obj, p, a, err_code);

        if (err_code && *err_code != ZPL_JSON_ERROR_NONE) {
            return NULL;
        }

        ++p;
    }

    return p;
}

char *zpl__json_parse_object(zpl_json_object *obj, char *base, zpl_allocator_t a, u8 *err_code) {
    ZPL_ASSERT(obj && base);
    char *p = base;
    char *b = base;
    char *e = base;

    zpl_array_init(obj->nodes, a);
    obj->backing = a;

    p = zpl__json_trim(p);
    if (*p == '{') {
        ++p;
    }

    while(*p) {
        zpl_json_object node = {0};
        p = zpl__json_trim(p);
        if (*p == '}') return p;

        if (*p == '"' || *p == '\'') {
            if (*p == '"') {
                node.name_style = ZPL_JSON_NAME_STYLE_DOUBLE_QUOTE;
            }
            else {
                node.name_style = ZPL_JSON_NAME_STYLE_SINGLE_QUOTE;
            }

            char c = *p;
            b = ++p;
            e = zpl__json_skip(b, c);
            node.name = b;
            *e = '\0';

            p = ++e;
            p = zpl__json_trim(p);

            if (*p && *p != ':') {
                ZPL_JSON_ASSERT; if (err_code) *err_code = ZPL_JSON_ERROR_INVALID_NAME;
                return NULL;
            }
        }
        else {
            /**/ if (*p == '[') {
                if (node.name) *node.name = '\0';
                p = zpl__json_parse_value(&node, p, a, err_code);
                goto l_parsed;
            }
            else if (zpl_char_is_alpha(*p) || *p == '_' || *p == '$') {
                b = p;
                e = b;

                do {
                    ++e;
                }
                while(*e && (zpl_char_is_alphanumeric(*e) || *e == '_')
                        && !zpl_char_is_space(*e) && *e != ':');

                if (*e == ':') {
                    p = e;
                }
                else {
                    while(*e) {
                        if (*e && (!zpl_char_is_space(*e) || *e == ':')) {
                            break;
                        }
                        ++e;
                    }
                    e = zpl__json_trim(e);
                    p = e;

                    if (*p && *p != ':') {
                        ZPL_JSON_ASSERT; if (err_code) *err_code = ZPL_JSON_ERROR_INVALID_NAME;
                        return NULL;
                    }
                }

                *e = '\0';
                node.name = b;
                node.name_style = ZPL_JSON_NAME_STYLE_NO_QUOTES;
            }
        }

        char errc;
        if (!zpl__json_validate_name(node.name, &errc)) {
            ZPL_JSON_ASSERT; if (err_code) *err_code = ZPL_JSON_ERROR_INVALID_NAME;
            return NULL;
        }

        p = zpl__json_trim(p+1);
        p = zpl__json_parse_value(&node, p, a, err_code);

        if (err_code && *err_code != ZPL_JSON_ERROR_NONE) {
            return NULL;
        }

        l_parsed:

        zpl_array_append(obj->nodes, node);

        p = zpl__json_trim(p);

        /**/ if (*p == ',') {
            p=zpl__json_trim(p+1);
            /**/ if (*p == '\0' || *p == '}') return p;
            else continue;
        }
        else if (*p == '\0' || *p == '}') {
            return p;
        }
        else {
            ZPL_JSON_ASSERT; if (err_code) *err_code = ZPL_JSON_ERROR_INVALID_VALUE;
            return NULL;
        }
    }
    return p;
}

zpl_inline char *zpl__json_trim(char *str) {
    while (*str && zpl_char_is_space(*str)) {
        ++str;
    }

    return str;
}

zpl_inline b32 zpl__json_is_control_char(char c) {
    return (c == '"' || c == '\\' || c == '/' || c == 'b' ||
            c == 'f' || c == 'n'  || c == 'r' || c == 't');
}

zpl_inline b32 zpl__json_is_special_char(char c) {
    return (c == '<' || c == '>' || c == ':' || c == '/');
}

#define jx(x) !zpl_char_is_hex_digit(str[x])
zpl_inline b32 zpl__json_validate_name(char *str, char *err) {
    while(*str) {
        if ((str[0] == '\\' && !zpl__json_is_control_char(str[1])) &&
            (str[0] == '\\' && jx(1) && jx(2) && jx(3) && jx(4))) {
            *err = *str;
            return false;
        }

        ++str;
    }

    return true;
}
#undef jx

zpl_inline char *zpl__json_skip(char *str, char c) {
    while ((*str && *str != c) || (*(str-1) == '\\' && *str == c && zpl__json_is_control_char(c))) {
        ++str;
    }

    return str;
}


////////////////////////////////////////////////////////////////
//
// CLI Options
//
//

void zpl_opts_init(zpl_opts *opts, zpl_allocator a, char const *app)
{
    zpl_opts opts_={0};
    *opts=opts_;
    opts->alloc=a;
    opts->appname=app;

    zpl_array_init(opts->entries, a);
    zpl_array_init(opts->positioned, a);
    zpl_array_init(opts->errors, a);
}

void zpl_opts_free(zpl_opts *opts)
{
    zpl_array_free(opts->entries);
    zpl_array_free(opts->positioned);
    zpl_array_free(opts->errors);
}

void zpl_opts_add(zpl_opts *opts, char const *name, char const *lname, const char *desc, u8 type)
{
    zpl_opts_entry e={0};

    e.name =name;
    e.lname=lname;
    e.desc =desc;
    e.type =type;
    e.met  =false;
    e.pos  =false;

    zpl_array_append(opts->entries, e);
}

zpl_opts_entry *zpl__opts_find(zpl_opts *opts, char const *name, usize len, b32 longname)
{
    zpl_opts_entry *e=0;

    for (int i=0; i<zpl_array_count(opts->entries); ++i) {
        e=opts->entries+i;
        char const *n=(longname ? e->lname : e->name);

        if (zpl_strnlen(name, len) == zpl_strlen(n) && !zpl_strncmp(n, name, len)) {
                return e;
        }
    }

    return NULL;
}

void zpl_opts_positional_add(zpl_opts *opts, char const *name)
{
    zpl_opts_entry *e=zpl__opts_find(opts, name, zpl_strlen(name), true);

    if (e) {
        e->pos=true;
        zpl_array_append(opts->positioned, e);
    }
}

b32 zpl_opts_positionals_filled(zpl_opts *opts)
{
    return zpl_array_count(opts->positioned)==0;
}

zpl_string zpl_opts_string(zpl_opts *opts, char const *name, char const *fallback)
{
    zpl_opts_entry *e=zpl__opts_find(opts, name, zpl_strlen(name), true);

    return (char *)((e && e->met) ? e->text : fallback);
}

f64 zpl_opts_real(zpl_opts *opts, char const *name, f64 fallback)
{
    zpl_opts_entry *e=zpl__opts_find(opts, name, zpl_strlen(name), true);

    return (e && e->met) ? e->real : fallback;
}

i64 zpl_opts_integer(zpl_opts *opts, char const *name, i64 fallback)
{
    zpl_opts_entry *e=zpl__opts_find(opts, name, zpl_strlen(name), true);

    return (e && e->met) ? e->integer : fallback;
}

void zpl__opts_set_value(zpl_opts *opts, zpl_opts_entry *t, char *b)
{
    t->met=true;
    switch (t->type) {
        case ZPL_OPTS_STRING:
            {
                t->text=zpl_string_make(opts->alloc, b);
            }break;

        case ZPL_OPTS_FLOAT:
            {
                t->real=zpl_str_to_f64(b, NULL);
            }break;

        case ZPL_OPTS_INT:
            {
                t->integer=zpl_str_to_i64(b, NULL, 10);
            }break;
    }
}

b32 zpl_opts_has_arg(zpl_opts *opts, char const *name)
{
    zpl_opts_entry *e=zpl__opts_find(opts, name, zpl_strlen(name), true);

    if (e) {
        return e->met;
    }

    return false;
}

void zpl_opts_print_help(zpl_opts *opts)
{
    zpl_printf("USAGE: %s", opts->appname);

    for (int i=0; i<zpl_array_count(opts->entries); ++i) {
        zpl_opts_entry *e=opts->entries+i;

        if (e->pos==(b32)true) {
            zpl_printf(" [%s]", e->lname);
        }
    }

    zpl_printf("\nOPTIONS:\n");

    for (int i=0; i<zpl_array_count(opts->entries); ++i) {
        zpl_opts_entry *e=opts->entries+i;

        zpl_printf("\t-%s, --%s: %s\n", e->name, e->lname, e->desc);
    }
}

void zpl_opts_print_errors(zpl_opts *opts)
{
    for (int i=0; i<zpl_array_count(opts->errors); ++i) {
        zpl_opts_err *err=(opts->errors+i);

        zpl_printf("ERROR: ");

        switch (err->type) {
            case ZPL_OPTS_ERR_OPTION:
                zpl_printf("Invalid option \"%s\"", err->val);
                break;

            case ZPL_OPTS_ERR_VALUE:
                zpl_printf("Invalid value \"%s\"", err->val);
                break;

            case ZPL_OPTS_ERR_MISSING_VALUE:
                zpl_printf("Missing value for option \"%s\"", err->val);
                break;

            case ZPL_OPTS_ERR_EXTRA_VALUE:
                zpl_printf("Extra value for option \"%s\"", err->val);
                break;
        }

        zpl_printf("\n");
    }
}

void zpl__opts_push_error(zpl_opts *opts, char *b, u8 errtype)
{
    zpl_opts_err err={0};
    err.val=b;
    err.type=errtype;
    zpl_array_append(opts->errors, err);
}

b32 zpl_opts_compile(zpl_opts *opts, int argc, char **argv)
{
    b32 had_errors=false;
    for (int i=1; i<argc; ++i) {
        char *p=argv[i];

        if (*p) {
            p=zpl__trim(p);
            if (*p=='-') {
                zpl_opts_entry *t=0;
                b32 checkln=false;
                if (*(p+1)=='-') {
                    checkln=true;
                    ++p;
                }

                char *b=p+1, *e=b;

                while (zpl_char_is_alphanumeric(*e)) {
                    ++e;
                }

                t=zpl__opts_find(opts, b, (e-b), checkln);

                if (t) {
                    char *ob=b;
                    b=e;

                    /**/ if (*e=='=') {
                        if (t->type == ZPL_OPTS_FLAG) {
                            *e='\0';
                            zpl__opts_push_error(opts, ob, ZPL_OPTS_ERR_EXTRA_VALUE);
                            had_errors=true;
                            continue;
                        }

                        b=e=e+1;
                    }
                    else if (*e == '\0') {
                        char *sp=argv[++i];

                        if (sp && *sp!='-') {
                            if (t->type == ZPL_OPTS_FLAG) {
                                zpl__opts_push_error(opts, b, ZPL_OPTS_ERR_EXTRA_VALUE);
                                had_errors=true;
                                continue;
                            }

                            p=sp;
                            b=e=sp;
                        }
                        else {
                            if (t->type != ZPL_OPTS_FLAG) {
                                zpl__opts_push_error(opts, ob, ZPL_OPTS_ERR_MISSING_VALUE);
                                had_errors=true;
                                continue;
                            }
                            t->met=true;
                            continue;
                        }
                    }

                    e=zpl__skip(e, '\0');
                    zpl__opts_set_value(opts, t, b);
                }
                else {
                    zpl__opts_push_error(opts, b, ZPL_OPTS_ERR_OPTION);
                    had_errors=true;
                }
            }
            else if (zpl_array_count(opts->positioned)) {
                zpl_opts_entry *l=zpl_array_back(opts->positioned);
                zpl_array_pop(opts->positioned);
                zpl__opts_set_value(opts, l, p);
            }
            else {
                zpl__opts_push_error(opts, p, ZPL_OPTS_ERR_VALUE);
                had_errors=true;
            }
        }
    }
    return !had_errors;
}

////////////////////////////////////////////////////////////////
//
// Math
//

#if defined(__cplusplus)
}
#endif

#if defined(__cplusplus)

inline bool operator==(zpl_vec2 a, zpl_vec2 b) { return (a.x == b.x) && (a.y == b.y); }
inline bool operator!=(zpl_vec2 a, zpl_vec2 b) { return !operator==(a, b); }

inline zpl_vec2 operator+(zpl_vec2 a) { return a; }
inline zpl_vec2 operator-(zpl_vec2 a) {
    zpl_vec2 r = { -a.x, -a.y };
    return r;
}

inline zpl_vec2 operator+(zpl_vec2 a, zpl_vec2 b) {
    zpl_vec2 r;
    zpl_vec2_add(&r, a, b);
    return r;
}
inline zpl_vec2 operator-(zpl_vec2 a, zpl_vec2 b) {
    zpl_vec2 r;
    zpl_vec2_sub(&r, a, b);
    return r;
}

inline zpl_vec2 operator*(zpl_vec2 a, f32 scalar) {
    zpl_vec2 r;
    zpl_vec2_mul(&r, a, scalar);
    return r;
}
inline zpl_vec2 operator*(f32 scalar, zpl_vec2 a) { return operator*(a, scalar); }

inline zpl_vec2 operator/(zpl_vec2 a, f32 scalar) { return operator*(a, 1.0f / scalar); }

/* Hadamard Product */
inline zpl_vec2 operator*(zpl_vec2 a, zpl_vec2 b) {
    zpl_vec2 r = { a.x * b.x, a.y * b.y };
    return r;
}
inline zpl_vec2 operator/(zpl_vec2 a, zpl_vec2 b) {
    zpl_vec2 r = { a.x / b.x, a.y / b.y };
    return r;
}

inline zpl_vec2 &operator+=(zpl_vec2 &a, zpl_vec2 b) { return (a = a + b); }
inline zpl_vec2 &operator-=(zpl_vec2 &a, zpl_vec2 b) { return (a = a - b); }
inline zpl_vec2 &operator*=(zpl_vec2 &a, f32 scalar) { return (a = a * scalar); }
inline zpl_vec2 &operator/=(zpl_vec2 &a, f32 scalar) { return (a = a / scalar); }

inline bool operator==(zpl_vec3 a, zpl_vec3 b) { return (a.x == b.x) && (a.y == b.y) && (a.z == b.z); }
inline bool operator!=(zpl_vec3 a, zpl_vec3 b) { return !operator==(a, b); }

inline zpl_vec3 operator+(zpl_vec3 a) { return a; }
inline zpl_vec3 operator-(zpl_vec3 a) {
    zpl_vec3 r = { -a.x, -a.y, -a.z };
    return r;
}

inline zpl_vec3 operator+(zpl_vec3 a, zpl_vec3 b) {
    zpl_vec3 r;
    zpl_vec3_add(&r, a, b);
    return r;
}
inline zpl_vec3 operator-(zpl_vec3 a, zpl_vec3 b) {
    zpl_vec3 r;
    zpl_vec3_sub(&r, a, b);
    return r;
}

inline zpl_vec3 operator*(zpl_vec3 a, f32 scalar) {
    zpl_vec3 r;
    zpl_vec3_mul(&r, a, scalar);
    return r;
}
inline zpl_vec3 operator*(f32 scalar, zpl_vec3 a) { return operator*(a, scalar); }

inline zpl_vec3 operator/(zpl_vec3 a, f32 scalar) { return operator*(a, 1.0f / scalar); }

/* Hadamard Product */
inline zpl_vec3 operator*(zpl_vec3 a, zpl_vec3 b) {
    zpl_vec3 r = { a.x * b.x, a.y * b.y, a.z * b.z };
    return r;
}
inline zpl_vec3 operator/(zpl_vec3 a, zpl_vec3 b) {
    zpl_vec3 r = { a.x / b.x, a.y / b.y, a.z / b.z };
    return r;
}

inline zpl_vec3 &operator+=(zpl_vec3 &a, zpl_vec3 b) { return (a = a + b); }
inline zpl_vec3 &operator-=(zpl_vec3 &a, zpl_vec3 b) { return (a = a - b); }
inline zpl_vec3 &operator*=(zpl_vec3 &a, f32 scalar) { return (a = a * scalar); }
inline zpl_vec3 &operator/=(zpl_vec3 &a, f32 scalar) { return (a = a / scalar); }

inline bool operator==(zpl_vec4 a, zpl_vec4 b) { return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w); }
inline bool operator!=(zpl_vec4 a, zpl_vec4 b) { return !operator==(a, b); }

inline zpl_vec4 operator+(zpl_vec4 a) { return a; }
inline zpl_vec4 operator-(zpl_vec4 a) {
    zpl_vec4 r = { -a.x, -a.y, -a.z, -a.w };
    return r;
}

inline zpl_vec4 operator+(zpl_vec4 a, zpl_vec4 b) {
    zpl_vec4 r;
    zpl_vec4_add(&r, a, b);
    return r;
}
inline zpl_vec4 operator-(zpl_vec4 a, zpl_vec4 b) {
    zpl_vec4 r;
    zpl_vec4_sub(&r, a, b);
    return r;
}

inline zpl_vec4 operator*(zpl_vec4 a, f32 scalar) {
    zpl_vec4 r;
    zpl_vec4_mul(&r, a, scalar);
    return r;
}
inline zpl_vec4 operator*(f32 scalar, zpl_vec4 a) { return operator*(a, scalar); }

inline zpl_vec4 operator/(zpl_vec4 a, f32 scalar) { return operator*(a, 1.0f / scalar); }

/* Hadamard Product */
inline zpl_vec4 operator*(zpl_vec4 a, zpl_vec4 b) {
    zpl_vec4 r = { a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
    return r;
}
inline zpl_vec4 operator/(zpl_vec4 a, zpl_vec4 b) {
    zpl_vec4 r = { a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
    return r;
}

inline zpl_vec4 &operator+=(zpl_vec4 &a, zpl_vec4 b) { return (a = a + b); }
inline zpl_vec4 &operator-=(zpl_vec4 &a, zpl_vec4 b) { return (a = a - b); }
inline zpl_vec4 &operator*=(zpl_vec4 &a, f32 scalar) { return (a = a * scalar); }
inline zpl_vec4 &operator/=(zpl_vec4 &a, f32 scalar) { return (a = a / scalar); }

inline zpl_mat2 operator+(zpl_mat2 const &a, zpl_mat2 const &b) {
    int i, j;
    zpl_mat2 r = { 0 };
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) r.e[2 * j + i] = a.e[2 * j + i] + b.e[2 * j + i];
    }
    return r;
}

inline zpl_mat2 operator-(zpl_mat2 const &a, zpl_mat2 const &b) {
    int i, j;
    zpl_mat2 r = { 0 };
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) r.e[2 * j + i] = a.e[2 * j + i] - b.e[2 * j + i];
    }
    return r;
}

inline zpl_mat2 operator*(zpl_mat2 const &a, zpl_mat2 const &b) {
    zpl_mat2 r;
    zpl_mat2_mul(&r, (zpl_mat2 *)&a, (zpl_mat2 *)&b);
    return r;
}
inline zpl_vec2 operator*(zpl_mat2 const &a, zpl_vec2 v) {
    zpl_vec2 r;
    zpl_mat2_mul_vec2(&r, (zpl_mat2 *)&a, v);
    return r;
}
inline zpl_mat2 operator*(zpl_mat2 const &a, f32 scalar) {
    zpl_mat2 r = { 0 };
    int i;
    for (i = 0; i < 2 * 2; i++) r.e[i] = a.e[i] * scalar;
    return r;
}
inline zpl_mat2 operator*(f32 scalar, zpl_mat2 const &a) { return operator*(a, scalar); }
inline zpl_mat2 operator/(zpl_mat2 const &a, f32 scalar) { return operator*(a, 1.0f / scalar); }

inline zpl_mat2 &operator+=(zpl_mat2 &a, zpl_mat2 const &b) { return (a = a + b); }
inline zpl_mat2 &operator-=(zpl_mat2 &a, zpl_mat2 const &b) { return (a = a - b); }
inline zpl_mat2 &operator*=(zpl_mat2 &a, zpl_mat2 const &b) { return (a = a * b); }

inline zpl_mat3 operator+(zpl_mat3 const &a, zpl_mat3 const &b) {
    int i, j;
    zpl_mat3 r = { 0 };
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) r.e[3 * j + i] = a.e[3 * j + i] + b.e[3 * j + i];
    }
    return r;
}

inline zpl_mat3 operator-(zpl_mat3 const &a, zpl_mat3 const &b) {
    int i, j;
    zpl_mat3 r = { 0 };
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) r.e[3 * j + i] = a.e[3 * j + i] - b.e[3 * j + i];
    }
    return r;
}

inline zpl_mat3 operator*(zpl_mat3 const &a, zpl_mat3 const &b) {
    zpl_mat3 r;
    zpl_mat3_mul(&r, (zpl_mat3 *)&a, (zpl_mat3 *)&b);
    return r;
}
inline zpl_vec3 operator*(zpl_mat3 const &a, zpl_vec3 v) {
    zpl_vec3 r;
    zpl_mat3_mul_vec3(&r, (zpl_mat3 *)&a, v);
    return r;
}
inline zpl_mat3 operator*(zpl_mat3 const &a, f32 scalar) {
    zpl_mat3 r = { 0 };
    int i;
    for (i = 0; i < 3 * 3; i++) r.e[i] = a.e[i] * scalar;
    return r;
}
inline zpl_mat3 operator*(f32 scalar, zpl_mat3 const &a) { return operator*(a, scalar); }
inline zpl_mat3 operator/(zpl_mat3 const &a, f32 scalar) { return operator*(a, 1.0f / scalar); }

inline zpl_mat3 &operator+=(zpl_mat3 &a, zpl_mat3 const &b) { return (a = a + b); }
inline zpl_mat3 &operator-=(zpl_mat3 &a, zpl_mat3 const &b) { return (a = a - b); }
inline zpl_mat3 &operator*=(zpl_mat3 &a, zpl_mat3 const &b) { return (a = a * b); }

inline zpl_mat4 operator+(zpl_mat4 const &a, zpl_mat4 const &b) {
    int i, j;
    zpl_mat4 r = { 0 };
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) r.e[4 * j + i] = a.e[4 * j + i] + b.e[4 * j + i];
    }
    return r;
}

inline zpl_mat4 operator-(zpl_mat4 const &a, zpl_mat4 const &b) {
    int i, j;
    zpl_mat4 r = { 0 };
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) r.e[4 * j + i] = a.e[4 * j + i] - b.e[4 * j + i];
    }
    return r;
}

inline zpl_mat4 operator*(zpl_mat4 const &a, zpl_mat4 const &b) {
    zpl_mat4 r;
    zpl_mat4_mul(&r, (zpl_mat4 *)&a, (zpl_mat4 *)&b);
    return r;
}
inline zpl_vec4 operator*(zpl_mat4 const &a, zpl_vec4 v) {
    zpl_vec4 r;
    zpl_mat4_mul_vec4(&r, (zpl_mat4 *)&a, v);
    return r;
}
inline zpl_mat4 operator*(zpl_mat4 const &a, f32 scalar) {
    zpl_mat4 r = { 0 };
    int i;
    for (i = 0; i < 4 * 4; i++) r.e[i] = a.e[i] * scalar;
    return r;
}
inline zpl_mat4 operator*(f32 scalar, zpl_mat4 const &a) { return operator*(a, scalar); }
inline zpl_mat4 operator/(zpl_mat4 const &a, f32 scalar) { return operator*(a, 1.0f / scalar); }

inline zpl_mat4 &operator+=(zpl_mat4 &a, zpl_mat4 const &b) { return (a = a + b); }
inline zpl_mat4 &operator-=(zpl_mat4 &a, zpl_mat4 const &b) { return (a = a - b); }
inline zpl_mat4 &operator*=(zpl_mat4 &a, zpl_mat4 const &b) { return (a = a * b); }

inline bool operator==(zpl_quat a, zpl_quat b) { return a.xyzw == b.xyzw; }
inline bool operator!=(zpl_quat a, zpl_quat b) { return !operator==(a, b); }

inline zpl_quat operator+(zpl_quat q) { return q; }
inline zpl_quat operator-(zpl_quat q) { return zpl_quatf(-q.x, -q.y, -q.z, -q.w); }

inline zpl_quat operator+(zpl_quat a, zpl_quat b) {
    zpl_quat r;
    zpl_quat_add(&r, a, b);
    return r;
}
inline zpl_quat operator-(zpl_quat a, zpl_quat b) {
    zpl_quat r;
    zpl_quat_sub(&r, a, b);
    return r;
}

inline zpl_quat operator*(zpl_quat a, zpl_quat b) {
    zpl_quat r;
    zpl_quat_mul(&r, a, b);
    return r;
}
inline zpl_quat operator*(zpl_quat q, f32 s) {
    zpl_quat r;
    zpl_quat_mulf(&r, q, s);
    return r;
}
inline zpl_quat operator*(f32 s, zpl_quat q) { return operator*(q, s); }
inline zpl_quat operator/(zpl_quat q, f32 s) {
    zpl_quat r;
    zpl_quat_divf(&r, q, s);
    return r;
}

inline zpl_quat &operator+=(zpl_quat &a, zpl_quat b) {
    zpl_quat_addeq(&a, b);
    return a;
}
inline zpl_quat &operator-=(zpl_quat &a, zpl_quat b) {
    zpl_quat_subeq(&a, b);
    return a;
}
inline zpl_quat &operator*=(zpl_quat &a, zpl_quat b) {
    zpl_quat_muleq(&a, b);
    return a;
}
inline zpl_quat &operator/=(zpl_quat &a, zpl_quat b) {
    zpl_quat_diveq(&a, b);
    return a;
}

inline zpl_quat &operator*=(zpl_quat &a, f32 b) {
    zpl_quat_muleqf(&a, b);
    return a;
}
inline zpl_quat &operator/=(zpl_quat &a, f32 b) {
    zpl_quat_diveqf(&a, b);
    return a;
}

/* Rotate v by a */
inline zpl_vec3 operator*(zpl_quat q, zpl_vec3 v) {
    zpl_vec3 r;
    zpl_quat_rotate_vec3(&r, q, v);
    return r;
}

#endif


#if defined(__cplusplus)
extern "C" {
#endif

#if (defined(__GCC__) || defined(__GNUC__)) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
#pragma GCC diagnostic ignored "-Wmissing-braces"
#elif __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wattributes"
#pragma clang diagnostic ignored "-Wmissing-braces"
#endif

/* NOTE: To remove the need for memcpy */
static void zpl__memcpy_4byte(void *dest, void const *src, size_t size) {
    size_t i;
    unsigned int *d, *s;
    d = (unsigned int *)dest;
    s = (unsigned int *)src;
    for (i = 0; i < size / 4; i++) { *d++ = *s++; }
}

f32 zpl_to_radians(f32 degrees) { return degrees * ZPL_TAU / 360.0f; }
f32 zpl_to_degrees(f32 radians) { return radians * 360.0f / ZPL_TAU; }

f32 zpl_angle_diff(f32 radians_a, f32 radians_b) {
    f32 delta = zpl_mod(radians_b - radians_a, ZPL_TAU);
    delta = zpl_mod(delta + 1.5f * ZPL_TAU, ZPL_TAU);
    delta -= 0.5f * ZPL_TAU;
    return delta;
}

f32 zpl_copy_sign(f32 x, f32 y) {
    int ix, iy;
    ix = *(int *)&x;
    iy = *(int *)&y;

    ix &= 0x7fffffff;
    ix |= iy & 0x80000000;
    return *(f32 *)&ix;
}

f32 zpl_remainder(f32 x, f32 y) { return x - (zpl_round(x / y) * y); }

f32 zpl_mod(f32 x, f32 y) {
    f32 result;
    y = zpl_abs(y);
    result = zpl_remainder(zpl_abs(x), y);
    if (zpl_sign(result)) result += y;
    return zpl_copy_sign(result, x);
}

f64 zpl_copy_sign64(f64 x, f64 y) {
    i64 ix, iy;
    ix = *(i64 *)&x;
    iy = *(i64 *)&y;

    ix &= 0x7fffffffffffffff;
    ix |= iy & 0x8000000000000000;
    return *cast(f64 *)&ix;
}

f64 zpl_floor64    (f64 x)        { return cast(f64)((x >= 0.0) ? cast(i64)x : cast(i64)(x-0.9999999999999999)); }
f64 zpl_ceil64     (f64 x)        { return cast(f64)((x < 0) ? cast(i64)x : (cast(i64)x)+1); }
f64 zpl_round64    (f64 x)        { return cast(f64)((x >= 0.0) ? zpl_floor64(x + 0.5) : zpl_ceil64(x - 0.5)); }
f64 zpl_remainder64(f64 x, f64 y) { return x - (zpl_round64(x/y)*y); }
f64 zpl_abs64      (f64 x)        { return x < 0 ? -x : x; }
f64 zpl_sign64     (f64 x)        { return x < 0 ? -1.0 : +1.0; }

f64 zpl_mod64(f64 x, f64 y) {
    f64 result;
    y = zpl_abs64(y);
    result = zpl_remainder64(zpl_abs64(x), y);
    if (zpl_sign64(result)) result += y;
    return zpl_copy_sign64(result, x);
}


f32 zpl_quake_rsqrt(f32 a) {
    union {
        int i;
        f32 f;
    } t;
    f32 x2;
    f32 const three_halfs = 1.5f;

    x2 = a * 0.5f;
    t.f = a;
    t.i = 0x5f375a86 - (t.i >> 1);                /* What the fuck? */
    t.f = t.f * (three_halfs - (x2 * t.f * t.f)); /* 1st iteration */
    t.f = t.f * (three_halfs - (x2 * t.f * t.f)); /* 2nd iteration, this can be removed */

    return t.f;
}

#if defined(ZPL_NO_MATH_H)
#if defined(_MSC_VER)

f32 zpl_rsqrt(f32 a) { return _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(a))); }
f32 zpl_sqrt(f32 a) { return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(a))); };
f32 zpl_sin(f32 a) {
    static f32 const a0 = +1.91059300966915117e-31f;
    static f32 const a1 = +1.00086760103908896f;
    static f32 const a2 = -1.21276126894734565e-2f;
    static f32 const a3 = -1.38078780785773762e-1f;
    static f32 const a4 = -2.67353392911981221e-2f;
    static f32 const a5 = +2.08026600266304389e-2f;
    static f32 const a6 = -3.03996055049204407e-3f;
    static f32 const a7 = +1.38235642404333740e-4f;
    return a0 + a * (a1 + a * (a2 + a * (a3 + a * (a4 + a * (a5 + a * (a6 + a * a7))))));
}
f32 zpl_cos(f32 a) {
    static f32 const a0 = +1.00238601909309722f;
    static f32 const a1 = -3.81919947353040024e-2f;
    static f32 const a2 = -3.94382342128062756e-1f;
    static f32 const a3 = -1.18134036025221444e-1f;
    static f32 const a4 = +1.07123798512170878e-1f;
    static f32 const a5 = -1.86637164165180873e-2f;
    static f32 const a6 = +9.90140908664079833e-4f;
    static f32 const a7 = -5.23022132118824778e-14f;
    return a0 + a * (a1 + a * (a2 + a * (a3 + a * (a4 + a * (a5 + a * (a6 + a * a7))))));
}

f32 zpl_tan(f32 radians) {
    f32 rr = radians * radians;
    f32 a = 9.5168091e-03f;
    a *= rr;
    a += 2.900525e-03f;
    a *= rr;
    a += 2.45650893e-02f;
    a *= rr;
    a += 5.33740603e-02f;
    a *= rr;
    a += 1.333923995e-01f;
    a *= rr;
    a += 3.333314036e-01f;
    a *= rr;
    a += 1.0f;
    a *= radians;
    return a;
}

f32 zpl_arcsin(f32 a) { return zpl_arctan2(a, zpl_sqrt((1.0f + a) * (1.0f - a))); }
f32 zpl_arccos(f32 a) { return zpl_arctan2(zpl_sqrt((1.0f + a) * (1.0 - a)), a); }

f32 zpl_arctan(f32 a) {
    f32 u = a * a;
    f32 u2 = u * u;
    f32 u3 = u2 * u;
    f32 u4 = u3 * u;
    f32 f = 1.0f + 0.33288950512027f * u - 0.08467922817644f * u2 + 0.03252232640125f * u3 - 0.00749305860992f * u4;
    return a / f;
}

f32 zpl_arctan2(f32 y, f32 x) {
    if (zpl_abs(x) > zpl_abs(y)) {
        f32 a = zpl_arctan(y / x);
        if (x > 0.0f)
            return a;
        else
            return y > 0.0f ? a + ZPL_TAU_OVER_2 : a - ZPL_TAU_OVER_2;
    } else {
        f32 a = zpl_arctan(x / y);
        if (x > 0.0f)
            return y > 0.0f ? ZPL_TAU_OVER_4 - a : -ZPL_TAU_OVER_4 - a;
        else
            return y > 0.0f ? ZPL_TAU_OVER_4 + a : -ZPL_TAU_OVER_4 + a;
    }
}

f32 zpl_exp(f32 a) {
    union {
        f32 f;
        int i;
    } u, v;
    u.i = (int)(6051102 * a + 1056478197);
    v.i = (int)(1056478197 - 6051102 * a);
    return u.f / v.f;
}

f32 zpl_log(f32 a) {
    union {
        f32 f;
        int i;
    } u = { a };
    return (u.i - 1064866805) * 8.262958405176314e-8f; /* 1 / 12102203.0; */
}

f32 zpl_pow(f32 a, f32 b) {
    int flipped = 0, e;
    f32 f, r = 1.0f;
    if (b < 0) {
        flipped = 1;
        b = -b;
    }

    e = (int)b;
    f = zpl_exp(b - e);

    while (e) {
        if (e & 1) r *= a;
        a *= a;
        e >>= 1;
    }

    r *= f;
    return flipped ? 1.0f / r : r;
}

#else

f32 zpl_rsqrt(f32 a) { return 1.0f / __builtin_sqrt(a); }
f32 zpl_sqrt(f32 a) { return __builtin_sqrt(a); }
f32 zpl_sin(f32 radians) { return __builtin_sinf(radians); }
f32 zpl_cos(f32 radians) { return __builtin_cosf(radians); }
f32 zpl_tan(f32 radians) { return __builtin_tanf(radians); }
f32 zpl_arcsin(f32 a) { return __builtin_asinf(a); }
f32 zpl_arccos(f32 a) { return __builtin_acosf(a); }
f32 zpl_arctan(f32 a) { return __builtin_atanf(a); }
f32 zpl_arctan2(f32 y, f32 x) { return __builtin_atan2f(y, x); }

f32 zpl_exp(f32 x) { return __builtin_expf(x); }
f32 zpl_log(f32 x) { return __builtin_logf(x); }

// TODO: Should this be zpl_exp(y * zpl_log(x)) ???
f32 zpl_pow(f32 x, f32 y) { return __builtin_powf(x, y); }

#endif

#else
f32 zpl_rsqrt(f32 a) { return 1.0f / sqrtf(a); }
f32 zpl_sqrt(f32 a) { return sqrtf(a); };
f32 zpl_sin(f32 radians) { return sinf(radians); };
f32 zpl_cos(f32 radians) { return cosf(radians); };
f32 zpl_tan(f32 radians) { return tanf(radians); };
f32 zpl_arcsin(f32 a) { return asinf(a); };
f32 zpl_arccos(f32 a) { return acosf(a); };
f32 zpl_arctan(f32 a) { return atanf(a); };
f32 zpl_arctan2(f32 y, f32 x) { return atan2f(y, x); };

f32 zpl_exp(f32 x) { return expf(x); }
f32 zpl_log(f32 x) { return logf(x); }
f32 zpl_pow(f32 x, f32 y) { return powf(x, y); }
#endif

f32 zpl_exp2(f32 x) { return zpl_exp(ZPL_LOG_TWO * x); }
f32 zpl_log2(f32 x) { return zpl_log(x) / ZPL_LOG_TWO; }

f32 zpl_fast_exp(f32 x) {
    /* NOTE: Only works in the range -1 <= x <= +1 */
    f32 e = 1.0f + x * (1.0f + x * 0.5f * (1.0f + x * 0.3333333333f * (1.0f + x * 0.25f * (1.0f + x * 0.2f))));
    return e;
}

f32 zpl_fast_exp2(f32 x) { return zpl_fast_exp(ZPL_LOG_TWO * x); }

f32 zpl_round(f32 x) { return (float)((x >= 0.0f) ? zpl_floor(x + 0.5f) : zpl_ceil(x - 0.5f)); }
f32 zpl_floor(f32 x) { return (float)((x >= 0.0f) ? (int)x : (int)(x - 0.9999999999999999f)); }
f32 zpl_ceil(f32 x) { return (float)((x < 0) ? (int)x : ((int)x) + 1); }

f32 zpl_half_to_float(zpl_half value) {
    union {
        unsigned int i;
        f32 f;
    } result;
    int s = (value >> 15) & 0x001;
    int e = (value >> 10) & 0x01f;
    int m = value & 0x3ff;

    if (e == 0) {
        if (m == 0) {
            /* Plus or minus zero */
            result.i = (unsigned int)(s << 31);
            return result.f;
        } else {
            /* Denormalized number */
            while (!(m & 0x00000400)) {
                m <<= 1;
                e -= 1;
            }

            e += 1;
            m &= ~0x00000400;
        }
    } else if (e == 31) {
        if (m == 0) {
            /* Positive or negative infinity */
            result.i = (unsigned int)((s << 31) | 0x7f800000);
            return result.f;
        } else {
            /* Nan */
            result.i = (unsigned int)((s << 31) | 0x7f800000 | (m << 13));
            return result.f;
        }
    }

    e = e + (127 - 15);
    m = m << 13;

    result.i = (unsigned int)((s << 31) | (e << 23) | m);
    return result.f;
}

zpl_half zpl_float_to_half(f32 value) {
    union {
        unsigned int i;
        f32 f;
    } v;
    int i, s, e, m;

    v.f = value;
    i = (int)v.i;

    s = (i >> 16) & 0x00008000;
    e = ((i >> 23) & 0x000000ff) - (127 - 15);
    m = i & 0x007fffff;

    if (e <= 0) {
        if (e < -10) return (zpl_half)s;
        m = (m | 0x00800000) >> (1 - e);

        if (m & 0x00001000) m += 0x00002000;

        return (zpl_half)(s | (m >> 13));
    } else if (e == 0xff - (127 - 15)) {
        if (m == 0) {
            return (zpl_half)(s | 0x7c00); /* NOTE: infinity */
        } else {
            /* NOTE: NAN */
            m >>= 13;
            return (zpl_half)(s | 0x7c00 | m | (m == 0));
        }
    } else {
        if (m & 0x00001000) {
            m += 0x00002000;
            if (m & 0x00800000) {
                m = 0;
                e += 1;
            }
        }

        if (e > 30) {
            f32 volatile f = 1e12f;
            int j;
            for (j = 0; j < 10; j++) f *= f; /* NOTE: Cause overflow */

            return (zpl_half)(s | 0x7c00);
        }

        return (zpl_half)(s | (e << 10) | (m >> 13));
    }
}

#define ZPL_VEC2_2OP(a, c, post)                                                                                      \
    \
a->x = c.x post;                                                                                                       \
    \
a->y = c.y post;

#define ZPL_VEC2_3OP(a, b, op, c, post)                                                                               \
    \
a->x = b.x op c.x post;                                                                                                \
    \
a->y = b.y op c.y post;

#define ZPL_VEC3_2OP(a, c, post)                                                                                      \
    \
a->x = c.x post;                                                                                                       \
    \
a->y = c.y post;                                                                                                       \
    \
a->z = c.z post;

#define ZPL_VEC3_3OP(a, b, op, c, post)                                                                               \
    \
a->x = b.x op c.x post;                                                                                                \
    \
a->y = b.y op c.y post;                                                                                                \
    \
a->z = b.z op c.z post;

#define ZPL_VEC4_2OP(a, c, post)                                                                                      \
    \
a->x = c.x post;                                                                                                       \
    \
a->y = c.y post;                                                                                                       \
    \
a->z = c.z post;                                                                                                       \
    \
a->w = c.w post;

#define ZPL_VEC4_3OP(a, b, op, c, post)                                                                               \
    \
a->x = b.x op c.x post;                                                                                                \
    \
a->y = b.y op c.y post;                                                                                                \
    \
a->z = b.z op c.z post;                                                                                                \
    \
a->w = b.w op c.w post;

zpl_vec2 zpl_vec2f_zero(void) {
    zpl_vec2 v = { 0, 0 };
    return v;
}
zpl_vec2 zpl_vec2f(f32 x, f32 y) {
    zpl_vec2 v;
    v.x = x;
    v.y = y;
    return v;
}
zpl_vec2 zpl_vec2fv(f32 x[2]) {
    zpl_vec2 v;
    v.x = x[0];
    v.y = x[1];
    return v;
}

zpl_vec3 zpl_vec3f_zero(void) {
    zpl_vec3 v = { 0, 0, 0 };
    return v;
}
zpl_vec3 zpl_vec3f(f32 x, f32 y, f32 z) {
    zpl_vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}
zpl_vec3 zpl_vec3fv(f32 x[3]) {
    zpl_vec3 v;
    v.x = x[0];
    v.y = x[1];
    v.z = x[2];
    return v;
}

zpl_vec4 zpl_vec4f_zero(void) {
    zpl_vec4 v = { 0, 0, 0, 0 };
    return v;
}
zpl_vec4 zpl_vec4f(f32 x, f32 y, f32 z, f32 w) {
    zpl_vec4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}
zpl_vec4 zpl_vec4fv(f32 x[4]) {
    zpl_vec4 v;
    v.x = x[0];
    v.y = x[1];
    v.z = x[2];
    v.w = x[3];
    return v;
}

void zpl_vec2_add(zpl_vec2 *d, zpl_vec2 v0, zpl_vec2 v1) { ZPL_VEC2_3OP(d, v0, +, v1, +0); }
void zpl_vec2_sub(zpl_vec2 *d, zpl_vec2 v0, zpl_vec2 v1) { ZPL_VEC2_3OP(d, v0, -, v1, +0); }
void zpl_vec2_mul(zpl_vec2 *d, zpl_vec2 v, f32 s) { ZPL_VEC2_2OP(d, v, *s); }
void zpl_vec2_div(zpl_vec2 *d, zpl_vec2 v, f32 s) { ZPL_VEC2_2OP(d, v, / s); }

void zpl_vec3_add(zpl_vec3 *d, zpl_vec3 v0, zpl_vec3 v1) { ZPL_VEC3_3OP(d, v0, +, v1, +0); }
void zpl_vec3_sub(zpl_vec3 *d, zpl_vec3 v0, zpl_vec3 v1) { ZPL_VEC3_3OP(d, v0, -, v1, +0); }
void zpl_vec3_mul(zpl_vec3 *d, zpl_vec3 v, f32 s) { ZPL_VEC3_2OP(d, v, *s); }
void zpl_vec3_div(zpl_vec3 *d, zpl_vec3 v, f32 s) { ZPL_VEC3_2OP(d, v, / s); }

void zpl_vec4_add(zpl_vec4 *d, zpl_vec4 v0, zpl_vec4 v1) { ZPL_VEC4_3OP(d, v0, +, v1, +0); }
void zpl_vec4_sub(zpl_vec4 *d, zpl_vec4 v0, zpl_vec4 v1) { ZPL_VEC4_3OP(d, v0, -, v1, +0); }
void zpl_vec4_mul(zpl_vec4 *d, zpl_vec4 v, f32 s) { ZPL_VEC4_2OP(d, v, *s); }
void zpl_vec4_div(zpl_vec4 *d, zpl_vec4 v, f32 s) { ZPL_VEC4_2OP(d, v, / s); }

void zpl_vec2_addeq(zpl_vec2 *d, zpl_vec2 v) { ZPL_VEC2_3OP(d, (*d), +, v, +0); }
void zpl_vec2_subeq(zpl_vec2 *d, zpl_vec2 v) { ZPL_VEC2_3OP(d, (*d), -, v, +0); }
void zpl_vec2_muleq(zpl_vec2 *d, f32 s) { ZPL_VEC2_2OP(d, (*d), *s); }
void zpl_vec2_diveq(zpl_vec2 *d, f32 s) { ZPL_VEC2_2OP(d, (*d), / s); }

void zpl_vec3_addeq(zpl_vec3 *d, zpl_vec3 v) { ZPL_VEC3_3OP(d, (*d), +, v, +0); }
void zpl_vec3_subeq(zpl_vec3 *d, zpl_vec3 v) { ZPL_VEC3_3OP(d, (*d), -, v, +0); }
void zpl_vec3_muleq(zpl_vec3 *d, f32 s) { ZPL_VEC3_2OP(d, (*d), *s); }
void zpl_vec3_diveq(zpl_vec3 *d, f32 s) { ZPL_VEC3_2OP(d, (*d), / s); }

void zpl_vec4_addeq(zpl_vec4 *d, zpl_vec4 v) { ZPL_VEC4_3OP(d, (*d), +, v, +0); }
void zpl_vec4_subeq(zpl_vec4 *d, zpl_vec4 v) { ZPL_VEC4_3OP(d, (*d), -, v, +0); }
void zpl_vec4_muleq(zpl_vec4 *d, f32 s) { ZPL_VEC4_2OP(d, (*d), *s); }
void zpl_vec4_diveq(zpl_vec4 *d, f32 s) { ZPL_VEC4_2OP(d, (*d), / s); }

#undef ZPL_VEC2_2OP
#undef ZPL_VEC2_3OP
#undef ZPL_VEC3_3OP
#undef ZPL_VEC3_2OP
#undef ZPL_VEC4_2OP
#undef ZPL_VEC4_3OP

f32 zpl_vec2_dot(zpl_vec2 v0, zpl_vec2 v1) { return v0.x * v1.x + v0.y * v1.y; }
f32 zpl_vec3_dot(zpl_vec3 v0, zpl_vec3 v1) { return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z; }
f32 zpl_vec4_dot(zpl_vec4 v0, zpl_vec4 v1) { return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w; }

void zpl_vec2_cross(f32 *d, zpl_vec2 v0, zpl_vec2 v1) { *d = v0.x * v1.y - v1.x * v0.y; }
void zpl_vec3_cross(zpl_vec3 *d, zpl_vec3 v0, zpl_vec3 v1) {
    d->x = v0.y * v1.z - v0.z * v1.y;
    d->y = v0.z * v1.x - v0.x * v1.z;
    d->z = v0.x * v1.y - v0.y * v1.x;
}

f32 zpl_vec2_mag2(zpl_vec2 v) { return zpl_vec2_dot(v, v); }
f32 zpl_vec3_mag2(zpl_vec3 v) { return zpl_vec3_dot(v, v); }
f32 zpl_vec4_mag2(zpl_vec4 v) { return zpl_vec4_dot(v, v); }

/* TODO: Create custom sqrt function */
f32 zpl_vec2_mag(zpl_vec2 v) { return zpl_sqrt(zpl_vec2_dot(v, v)); }
f32 zpl_vec3_mag(zpl_vec3 v) { return zpl_sqrt(zpl_vec3_dot(v, v)); }
f32 zpl_vec4_mag(zpl_vec4 v) { return zpl_sqrt(zpl_vec4_dot(v, v)); }

void zpl_vec2_norm(zpl_vec2 *d, zpl_vec2 v) {
    f32 inv_mag = zpl_rsqrt(zpl_vec2_dot(v, v));
    zpl_vec2_mul(d, v, inv_mag);
}
void zpl_vec3_norm(zpl_vec3 *d, zpl_vec3 v) {
    f32 mag = zpl_vec3_mag(v);
    zpl_vec3_div(d, v, mag);
}
void zpl_vec4_norm(zpl_vec4 *d, zpl_vec4 v) {
    f32 mag = zpl_vec4_mag(v);
    zpl_vec4_div(d, v, mag);
}

void zpl_vec2_norm0(zpl_vec2 *d, zpl_vec2 v) {
    f32 mag = zpl_vec2_mag(v);
    if (mag > 0)
        zpl_vec2_div(d, v, mag);
    else
        *d = zpl_vec2f_zero( );
}
void zpl_vec3_norm0(zpl_vec3 *d, zpl_vec3 v) {
    f32 mag = zpl_vec3_mag(v);
    if (mag > 0)
        zpl_vec3_div(d, v, mag);
    else
        *d = zpl_vec3f_zero( );
}
void zpl_vec4_norm0(zpl_vec4 *d, zpl_vec4 v) {
    f32 mag = zpl_vec4_mag(v);
    if (mag > 0)
        zpl_vec4_div(d, v, mag);
    else
        *d = zpl_vec4f_zero( );
}

void zpl_vec2_reflect(zpl_vec2 *d, zpl_vec2 i, zpl_vec2 n) {
    zpl_vec2 b = n;
    zpl_vec2_muleq(&b, 2.0f * zpl_vec2_dot(n, i));
    zpl_vec2_sub(d, i, b);
}

void zpl_vec3_reflect(zpl_vec3 *d, zpl_vec3 i, zpl_vec3 n) {
    zpl_vec3 b = n;
    zpl_vec3_muleq(&b, 2.0f * zpl_vec3_dot(n, i));
    zpl_vec3_sub(d, i, b);
}

void zpl_vec2_refract(zpl_vec2 *d, zpl_vec2 i, zpl_vec2 n, f32 eta) {
    zpl_vec2 a, b;
    f32 dv, k;

    dv = zpl_vec2_dot(n, i);
    k = 1.0f - eta * eta * (1.0f - dv * dv);
    zpl_vec2_mul(&a, i, eta);
    zpl_vec2_mul(&b, n, eta * dv * zpl_sqrt(k));
    zpl_vec2_sub(d, a, b);
    zpl_vec2_muleq(d, (float)(k >= 0.0f));
}

void zpl_vec3_refract(zpl_vec3 *d, zpl_vec3 i, zpl_vec3 n, f32 eta) {
    zpl_vec3 a, b;
    f32 dv, k;

    dv = zpl_vec3_dot(n, i);
    k = 1.0f - eta * eta * (1.0f - dv * dv);
    zpl_vec3_mul(&a, i, eta);
    zpl_vec3_mul(&b, n, eta * dv * zpl_sqrt(k));
    zpl_vec3_sub(d, a, b);
    zpl_vec3_muleq(d, (float)(k >= 0.0f));
}

f32 zpl_vec2_aspect_ratio(zpl_vec2 v) { return (v.y < 0.0001f) ? 0.0f : v.x / v.y; }

void zpl_mat2_transpose(zpl_mat2 *m) { zpl_float22_transpose(zpl_float22_m(m)); }
void zpl_mat2_identity(zpl_mat2 *m) { zpl_float22_identity(zpl_float22_m(m)); }
void zpl_mat2_mul(zpl_mat2 *out, zpl_mat2 *m1, zpl_mat2 *m2) {
    zpl_float22_mul(zpl_float22_m(out), zpl_float22_m(m1), zpl_float22_m(m2));
}

void zpl_float22_identity(f32 m[2][2]) {
    m[0][0] = 1;
    m[0][1] = 0;
    m[1][0] = 0;
    m[1][1] = 1;
}

void zpl_mat2_mul_vec2(zpl_vec2 *out, zpl_mat2 *m, zpl_vec2 in) { zpl_float22_mul_vec2(out, zpl_float22_m(m), in); }

zpl_mat2 *zpl_mat2_v(zpl_vec2 m[2]) { return (zpl_mat2 *)m; }
zpl_mat2 *zpl_mat2_f(f32 m[2][2]) { return (zpl_mat2 *)m; }

zpl_float2 *zpl_float22_m(zpl_mat2 *m) { return (zpl_float2 *)m; }
zpl_float2 *zpl_float22_v(zpl_vec2 m[2]) { return (zpl_float2 *)m; }
zpl_float2 *zpl_float22_4(f32 m[4]) { return (zpl_float2 *)m; }

void zpl_float22_transpose(f32 (*vec)[2]) {
    int i, j;
    for (j = 0; j < 2; j++) {
        for (i = j + 1; i < 2; i++) {
            f32 t = vec[i][j];
            vec[i][j] = vec[j][i];
            vec[j][i] = t;
        }
    }
}

void zpl_float22_mul(f32 (*out)[2], f32 (*mat1)[2], f32 (*mat2)[2]) {
    int i, j;
    f32 temp1[2][2], temp2[2][2];
    if (mat1 == out) {
        zpl__memcpy_4byte(temp1, mat1, sizeof(temp1));
        mat1 = temp1;
    }
    if (mat2 == out) {
        zpl__memcpy_4byte(temp2, mat2, sizeof(temp2));
        mat2 = temp2;
    }
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) { out[j][i] = mat1[0][i] * mat2[j][0] + mat1[1][i] * mat2[j][1]; }
    }
}

void zpl_float22_mul_vec2(zpl_vec2 *out, f32 m[2][2], zpl_vec2 v) {
    out->x = m[0][0] * v.x + m[0][1] * v.y;
    out->y = m[1][0] * v.x + m[1][1] * v.y;
}

f32 zpl_mat2_determinate(zpl_mat2 *m) {
    zpl_float2 *e = zpl_float22_m(m);
    return e[0][0] * e[1][1] - e[1][0] * e[0][1];
}

void zpl_mat2_inverse(zpl_mat2 *out, zpl_mat2 *in) {
    zpl_float2 *o = zpl_float22_m(out);
    zpl_float2 *i = zpl_float22_m(in);

    f32 ood = 1.0f / zpl_mat2_determinate(in);

    o[0][0] = +i[1][1] * ood;
    o[0][1] = -i[0][1] * ood;
    o[1][0] = -i[1][0] * ood;
    o[1][1] = +i[0][0] * ood;
}

void zpl_mat3_transpose(zpl_mat3 *m) { zpl_float33_transpose(zpl_float33_m(m)); }
void zpl_mat3_identity(zpl_mat3 *m) { zpl_float33_identity(zpl_float33_m(m)); }
void zpl_mat3_mul(zpl_mat3 *out, zpl_mat3 *m1, zpl_mat3 *m2) {
    zpl_float33_mul(zpl_float33_m(out), zpl_float33_m(m1), zpl_float33_m(m2));
}

void zpl_float33_identity(f32 m[3][3]) {
    m[0][0] = 1;
    m[0][1] = 0;
    m[0][2] = 0;
    m[1][0] = 0;
    m[1][1] = 1;
    m[1][2] = 0;
    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1;
}

void zpl_mat3_mul_vec3(zpl_vec3 *out, zpl_mat3 *m, zpl_vec3 in) { zpl_float33_mul_vec3(out, zpl_float33_m(m), in); }

zpl_mat3 *zpl_mat3_v(zpl_vec3 m[3]) { return (zpl_mat3 *)m; }
zpl_mat3 *zpl_mat3_f(f32 m[3][3]) { return (zpl_mat3 *)m; }

zpl_float3 *zpl_float33_m(zpl_mat3 *m) { return (zpl_float3 *)m; }
zpl_float3 *zpl_float33_v(zpl_vec3 m[3]) { return (zpl_float3 *)m; }
zpl_float3 *zpl_float33_16(f32 m[9]) { return (zpl_float3 *)m; }

void zpl_float33_transpose(f32 (*vec)[3]) {
    int i, j;
    for (j = 0; j < 3; j++) {
        for (i = j + 1; i < 3; i++) {
            f32 t = vec[i][j];
            vec[i][j] = vec[j][i];
            vec[j][i] = t;
        }
    }
}

void zpl_float33_mul(f32 (*out)[3], f32 (*mat1)[3], f32 (*mat2)[3]) {
    int i, j;
    f32 temp1[3][3], temp2[3][3];
    if (mat1 == out) {
        zpl__memcpy_4byte(temp1, mat1, sizeof(temp1));
        mat1 = temp1;
    }
    if (mat2 == out) {
        zpl__memcpy_4byte(temp2, mat2, sizeof(temp2));
        mat2 = temp2;
    }
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            out[j][i] = mat1[0][i] * mat2[j][0] + mat1[1][i] * mat2[j][1] + mat1[2][i] * mat2[j][2];
        }
    }
}

void zpl_float33_mul_vec3(zpl_vec3 *out, f32 m[3][3], zpl_vec3 v) {
    out->x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
    out->y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
    out->z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;
}

f32 zpl_mat3_determinate(zpl_mat3 *m) {
    zpl_float3 *e = zpl_float33_m(m);
    f32 d = +e[0][0] * (e[1][1] * e[2][2] - e[1][2] * e[2][1]) - e[0][1] * (e[1][0] * e[2][2] - e[1][2] * e[2][0]) +
              e[0][2] * (e[1][0] * e[2][1] - e[1][1] * e[2][0]);
    return d;
}

void zpl_mat3_inverse(zpl_mat3 *out, zpl_mat3 *in) {
    zpl_float3 *o = zpl_float33_m(out);
    zpl_float3 *i = zpl_float33_m(in);

    f32 ood = 1.0f / zpl_mat3_determinate(in);

    o[0][0] = +(i[1][1] * i[2][2] - i[2][1] * i[1][2]) * ood;
    o[0][1] = -(i[1][0] * i[2][2] - i[2][0] * i[1][2]) * ood;
    o[0][2] = +(i[1][0] * i[2][1] - i[2][0] * i[1][1]) * ood;
    o[1][0] = -(i[0][1] * i[2][2] - i[2][1] * i[0][2]) * ood;
    o[1][1] = +(i[0][0] * i[2][2] - i[2][0] * i[0][2]) * ood;
    o[1][2] = -(i[0][0] * i[2][1] - i[2][0] * i[0][1]) * ood;
    o[2][0] = +(i[0][1] * i[1][2] - i[1][1] * i[0][2]) * ood;
    o[2][1] = -(i[0][0] * i[1][2] - i[1][0] * i[0][2]) * ood;
    o[2][2] = +(i[0][0] * i[1][1] - i[1][0] * i[0][1]) * ood;
}

void zpl_mat4_transpose(zpl_mat4 *m) { zpl_float44_transpose(zpl_float44_m(m)); }
void zpl_mat4_identity(zpl_mat4 *m) { zpl_float44_identity(zpl_float44_m(m)); }
void zpl_mat4_mul(zpl_mat4 *out, zpl_mat4 *m1, zpl_mat4 *m2) {
    zpl_float44_mul(zpl_float44_m(out), zpl_float44_m(m1), zpl_float44_m(m2));
}

void zpl_float44_identity(f32 m[4][4]) {
    m[0][0] = 1;
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;
    m[1][0] = 0;
    m[1][1] = 1;
    m[1][2] = 0;
    m[1][3] = 0;
    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1;
    m[2][3] = 0;
    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1;
}

void zpl_mat4_mul_vec4(zpl_vec4 *out, zpl_mat4 *m, zpl_vec4 in) { zpl_float44_mul_vec4(out, zpl_float44_m(m), in); }

zpl_mat4 *zpl_mat4_v(zpl_vec4 m[4]) { return (zpl_mat4 *)m; }
zpl_mat4 *zpl_mat4_f(f32 m[4][4]) { return (zpl_mat4 *)m; }

zpl_float4 *zpl_float44_m(zpl_mat4 *m) { return (zpl_float4 *)m; }
zpl_float4 *zpl_float44_v(zpl_vec4 m[4]) { return (zpl_float4 *)m; }
zpl_float4 *zpl_float44_16(f32 m[16]) { return (zpl_float4 *)m; }

void zpl_float44_transpose(f32 (*vec)[4]) {
    f32 tmp;
    tmp = vec[1][0];
    vec[1][0] = vec[0][1];
    vec[0][1] = tmp;
    tmp = vec[2][0];
    vec[2][0] = vec[0][2];
    vec[0][2] = tmp;
    tmp = vec[3][0];
    vec[3][0] = vec[0][3];
    vec[0][3] = tmp;
    tmp = vec[2][1];
    vec[2][1] = vec[1][2];
    vec[1][2] = tmp;
    tmp = vec[3][1];
    vec[3][1] = vec[1][3];
    vec[1][3] = tmp;
    tmp = vec[3][2];
    vec[3][2] = vec[2][3];
    vec[2][3] = tmp;
}

void zpl_float44_mul(f32 (*out)[4], f32 (*mat1)[4], f32 (*mat2)[4]) {
    int i, j;
    f32 temp1[4][4], temp2[4][4];
    if (mat1 == out) {
        zpl__memcpy_4byte(temp1, mat1, sizeof(temp1));
        mat1 = temp1;
    }
    if (mat2 == out) {
        zpl__memcpy_4byte(temp2, mat2, sizeof(temp2));
        mat2 = temp2;
    }
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            out[j][i] =
                mat1[0][i] * mat2[j][0] + mat1[1][i] * mat2[j][1] + mat1[2][i] * mat2[j][2] + mat1[3][i] * mat2[j][3];
        }
    }
}

void zpl_float44_mul_vec4(zpl_vec4 *out, f32 m[4][4], zpl_vec4 v) {
    out->x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w;
    out->y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1] * v.w;
    out->z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2] * v.w;
    out->w = m[0][3] * v.x + m[1][3] * v.y + m[2][3] * v.z + m[3][3] * v.w;
}

void zpl_mat4_inverse(zpl_mat4 *out, zpl_mat4 *in) {
    zpl_float4 *o = zpl_float44_m(out);
    zpl_float4 *m = zpl_float44_m(in);

    f32 ood;
    // f32 tmp;

    f32 sf00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    f32 sf01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    f32 sf02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    f32 sf03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    f32 sf04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    f32 sf05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    f32 sf06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
    f32 sf07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    f32 sf08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
    f32 sf09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
    f32 sf10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
    f32 sf11 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    f32 sf12 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
    f32 sf13 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
    f32 sf14 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
    f32 sf15 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
    f32 sf16 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
    f32 sf17 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
    f32 sf18 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

    o[0][0] = +(m[1][1] * sf00 - m[1][2] * sf01 + m[1][3] * sf02);
    o[1][0] = -(m[1][0] * sf00 - m[1][2] * sf03 + m[1][3] * sf04);
    o[2][0] = +(m[1][0] * sf01 - m[1][1] * sf03 + m[1][3] * sf05);
    o[3][0] = -(m[1][0] * sf02 - m[1][1] * sf04 + m[1][2] * sf05);

    o[0][1] = -(m[0][1] * sf00 - m[0][2] * sf01 + m[0][3] * sf02);
    o[1][1] = +(m[0][0] * sf00 - m[0][2] * sf03 + m[0][3] * sf04);
    o[2][1] = -(m[0][0] * sf01 - m[0][1] * sf03 + m[0][3] * sf05);
    o[3][1] = +(m[0][0] * sf02 - m[0][1] * sf04 + m[0][2] * sf05);

    o[0][2] = +(m[0][1] * sf06 - m[0][2] * sf07 + m[0][3] * sf08);
    o[1][2] = -(m[0][0] * sf06 - m[0][2] * sf09 + m[0][3] * sf10);
    o[2][2] = +(m[0][0] * sf11 - m[0][1] * sf09 + m[0][3] * sf12);
    o[3][2] = -(m[0][0] * sf08 - m[0][1] * sf10 + m[0][2] * sf12);

    o[0][3] = -(m[0][1] * sf13 - m[0][2] * sf14 + m[0][3] * sf15);
    o[1][3] = +(m[0][0] * sf13 - m[0][2] * sf16 + m[0][3] * sf17);
    o[2][3] = -(m[0][0] * sf14 - m[0][1] * sf16 + m[0][3] * sf18);
    o[3][3] = +(m[0][0] * sf15 - m[0][1] * sf17 + m[0][2] * sf18);

    ood = 1.0f / (m[0][0] * o[0][0] + m[0][1] * o[1][0] + m[0][2] * o[2][0] + m[0][3] * o[3][0]);

    o[0][0] *= ood;
    o[0][1] *= ood;
    o[0][2] *= ood;
    o[0][3] *= ood;
    o[1][0] *= ood;
    o[1][1] *= ood;
    o[1][2] *= ood;
    o[1][3] *= ood;
    o[2][0] *= ood;
    o[2][1] *= ood;
    o[2][2] *= ood;
    o[2][3] *= ood;
    o[3][0] *= ood;
    o[3][1] *= ood;
    o[3][2] *= ood;
    o[3][3] *= ood;
}

void zpl_mat4_translate(zpl_mat4 *out, zpl_vec3 v) {
    zpl_mat4_identity(out);
    out->col[3].xyz = v;
    out->col[3].w = 1;
}

void zpl_mat4_rotate(zpl_mat4 *out, zpl_vec3 v, f32 angle_radians) {
    f32 c, s;
    zpl_vec3 axis, t;
    zpl_float4 *rot;

    c = zpl_cos(angle_radians);
    s = zpl_sin(angle_radians);

    zpl_vec3_norm(&axis, v);
    zpl_vec3_mul(&t, axis, 1.0f - c);

    zpl_mat4_identity(out);
    rot = zpl_float44_m(out);

    rot[0][0] = c + t.x * axis.x;
    rot[0][1] = 0 + t.x * axis.y + s * axis.z;
    rot[0][2] = 0 + t.x * axis.z - s * axis.y;
    rot[0][3] = 0;

    rot[1][0] = 0 + t.y * axis.x - s * axis.z;
    rot[1][1] = c + t.y * axis.y;
    rot[1][2] = 0 + t.y * axis.z + s * axis.x;
    rot[1][3] = 0;

    rot[2][0] = 0 + t.z * axis.x + s * axis.y;
    rot[2][1] = 0 + t.z * axis.y - s * axis.x;
    rot[2][2] = c + t.z * axis.z;
    rot[2][3] = 0;
}

void zpl_mat4_scale(zpl_mat4 *out, zpl_vec3 v) {
    zpl_mat4_identity(out);
    out->e[0] = v.x;
    out->e[5] = v.y;
    out->e[10] = v.z;
}

void zpl_mat4_scalef(zpl_mat4 *out, f32 s) {
    zpl_mat4_identity(out);
    out->e[0] = s;
    out->e[5] = s;
    out->e[10] = s;
}

void zpl_mat4_ortho2d(zpl_mat4 *out, f32 left, f32 right, f32 bottom, f32 top) {
    zpl_float4 *m;
    zpl_mat4_identity(out);
    m = zpl_float44_m(out);

    m[0][0] = 2.0f / (right - left);
    m[1][1] = 2.0f / (top - bottom);
    m[2][2] = -1.0f;
    m[3][0] = -(right + left) / (right - left);
    m[3][1] = -(top + bottom) / (top - bottom);
}

void zpl_mat4_ortho3d(zpl_mat4 *out, f32 left, f32 right, f32 bottom, f32 top, f32 z_near, f32 z_far) {
    zpl_float4 *m;
    zpl_mat4_identity(out);
    m = zpl_float44_m(out);

    m[0][0] = +2.0f / (right - left);
    m[1][1] = +2.0f / (top - bottom);
    m[2][2] = -2.0f / (z_far - z_near);
    m[3][0] = -(right + left) / (right - left);
    m[3][1] = -(top + bottom) / (top - bottom);
    m[3][2] = -(z_far + z_near) / (z_far - z_near);
}

void zpl_mat4_perspective(zpl_mat4 *out, f32 fovy, f32 aspect, f32 z_near, f32 z_far) {
    f32 tan_half_fovy = zpl_tan(0.5f * fovy);
    zpl_mat4 zero_mat = { 0 };
    zpl_float4 *m = zpl_float44_m(out);
    *out = zero_mat;

    m[0][0] = 1.0f / (aspect * tan_half_fovy);
    m[1][1] = 1.0f / (tan_half_fovy);
    m[2][2] = -(z_far + z_near) / (z_far - z_near);
    m[2][3] = -1.0f;
    m[3][2] = -2.0f * z_far * z_near / (z_far - z_near);
}

void zpl_mat4_infinite_perspective(zpl_mat4 *out, f32 fovy, f32 aspect, f32 z_near) {
    f32 range = zpl_tan(0.5f * fovy) * z_near;
    f32 left = -range * aspect;
    f32 right = range * aspect;
    f32 bottom = -range;
    f32 top = range;
    zpl_mat4 zero_mat = { 0 };
    zpl_float4 *m = zpl_float44_m(out);
    *out = zero_mat;

    m[0][0] = (2.0f * z_near) / (right - left);
    m[1][1] = (2.0f * z_near) / (top - bottom);
    m[2][2] = -1.0f;
    m[2][3] = -1.0f;
    m[3][2] = -2.0f * z_near;
}

void zpl_mat4_look_at(zpl_mat4 *out, zpl_vec3 eye, zpl_vec3 centre, zpl_vec3 up) {
    zpl_vec3 f, s, u;
    zpl_float4 *m;

    zpl_vec3_sub(&f, centre, eye);
    zpl_vec3_norm(&f, f);

    zpl_vec3_cross(&s, f, up);
    zpl_vec3_norm(&s, s);

    zpl_vec3_cross(&u, s, f);

    zpl_mat4_identity(out);
    m = zpl_float44_m(out);

    m[0][0] = +s.x;
    m[1][0] = +s.y;
    m[2][0] = +s.z;

    m[0][1] = +u.x;
    m[1][1] = +u.y;
    m[2][1] = +u.z;

    m[0][2] = -f.x;
    m[1][2] = -f.y;
    m[2][2] = -f.z;

    m[3][0] = zpl_vec3_dot(s, eye);
    m[3][1] = zpl_vec3_dot(u, eye);
    m[3][2] = zpl_vec3_dot(f, eye);
}

zpl_quat zpl_quatf(f32 x, f32 y, f32 z, f32 w) {
    zpl_quat q;
    q.x = x;
    q.y = y;
    q.z = z;
    q.w = w;
    return q;
}
zpl_quat zpl_quatfv(f32 e[4]) {
    zpl_quat q;
    q.x = e[0];
    q.y = e[1];
    q.z = e[2];
    q.w = e[3];
    return q;
}

zpl_quat zpl_quat_axis_angle(zpl_vec3 axis, f32 angle_radians) {
    zpl_quat q;
    zpl_vec3_norm(&q.xyz, axis);
    zpl_vec3_muleq(&q.xyz, zpl_sin(0.5f * angle_radians));
    q.w = zpl_cos(0.5f * angle_radians);
    return q;
}

zpl_quat zpl_quat_euler_angles(f32 pitch, f32 yaw, f32 roll) {
    /* TODO: Do without multiplication, i.e. make it faster */
    zpl_quat q, p, y, r;
    p = zpl_quat_axis_angle(zpl_vec3f(1, 0, 0), pitch);
    y = zpl_quat_axis_angle(zpl_vec3f(0, 1, 0), yaw);
    r = zpl_quat_axis_angle(zpl_vec3f(0, 0, 1), roll);

    zpl_quat_mul(&q, y, p);
    zpl_quat_muleq(&q, r);

    return q;
}

zpl_quat zpl_quat_identity(void) {
    zpl_quat q = { 0, 0, 0, 1 };
    return q;
}

void zpl_quat_add(zpl_quat *d, zpl_quat q0, zpl_quat q1) { zpl_vec4_add(&d->xyzw, q0.xyzw, q1.xyzw); }
void zpl_quat_sub(zpl_quat *d, zpl_quat q0, zpl_quat q1) { zpl_vec4_sub(&d->xyzw, q0.xyzw, q1.xyzw); }

void zpl_quat_mul(zpl_quat *d, zpl_quat q0, zpl_quat q1) {
    d->x = q0.w * q1.x + q0.x * q1.w + q0.y * q1.z - q0.z * q1.y;
    d->y = q0.w * q1.y - q0.x * q1.z + q0.y * q1.w + q0.z * q1.x;
    d->z = q0.w * q1.z + q0.x * q1.y - q0.y * q1.x + q0.z * q1.w;
    d->w = q0.w * q1.w - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z;
}

void zpl_quat_div(zpl_quat *d, zpl_quat q0, zpl_quat q1) {
    zpl_quat iq1;
    zpl_quat_inverse(&iq1, q1);
    zpl_quat_mul(d, q0, iq1);
}

void zpl_quat_mulf(zpl_quat *d, zpl_quat q0, f32 s) { zpl_vec4_mul(&d->xyzw, q0.xyzw, s); }
void zpl_quat_divf(zpl_quat *d, zpl_quat q0, f32 s) { zpl_vec4_div(&d->xyzw, q0.xyzw, s); }

void zpl_quat_addeq(zpl_quat *d, zpl_quat q) { zpl_vec4_addeq(&d->xyzw, q.xyzw); }
void zpl_quat_subeq(zpl_quat *d, zpl_quat q) { zpl_vec4_subeq(&d->xyzw, q.xyzw); }
void zpl_quat_muleq(zpl_quat *d, zpl_quat q) { zpl_quat_mul(d, *d, q); }
void zpl_quat_diveq(zpl_quat *d, zpl_quat q) { zpl_quat_div(d, *d, q); }

void zpl_quat_muleqf(zpl_quat *d, f32 s) { zpl_vec4_muleq(&d->xyzw, s); }
void zpl_quat_diveqf(zpl_quat *d, f32 s) { zpl_vec4_diveq(&d->xyzw, s); }

f32 zpl_quat_dot(zpl_quat q0, zpl_quat q1) {
    f32 r = zpl_vec3_dot(q0.xyz, q1.xyz) + q0.w * q1.w;
    return r;
}
f32 zpl_quat_mag(zpl_quat q) {
    f32 r = zpl_sqrt(zpl_quat_dot(q, q));
    return r;
}

void zpl_quat_norm(zpl_quat *d, zpl_quat q) { zpl_quat_divf(d, q, zpl_quat_mag(q)); }
void zpl_quat_conj(zpl_quat *d, zpl_quat q) {
    d->xyz = zpl_vec3f(-q.x, -q.y, -q.z);
    d->w = q.w;
}
void zpl_quat_inverse(zpl_quat *d, zpl_quat q) {
    zpl_quat_conj(d, q);
    zpl_quat_diveqf(d, zpl_quat_dot(q, q));
}

void zpl_quat_axis(zpl_vec3 *axis, zpl_quat q) {
    zpl_quat n;
    zpl_quat_norm(&n, q);
    zpl_vec3_div(axis, n.xyz, zpl_sin(zpl_arccos(q.w)));
}

f32 zpl_quat_angle(zpl_quat q) {
    f32 mag = zpl_quat_mag(q);
    f32 c = q.w * (1.0f / mag);
    f32 angle = 2.0f * zpl_arccos(c);
    return angle;
}

f32 zpl_quat_roll(zpl_quat q) {
    return zpl_arctan2(2.0f * q.x * q.y + q.z * q.w, q.x * q.x + q.w * q.w - q.y * q.y - q.z * q.z);
}
f32 zpl_quat_pitch(zpl_quat q) {
    return zpl_arctan2(2.0f * q.y * q.z + q.w * q.x, q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z);
}
f32 zpl_quat_yaw(zpl_quat q) { return zpl_arcsin(-2.0f * (q.x * q.z - q.w * q.y)); }

void zpl_quat_rotate_vec3(zpl_vec3 *d, zpl_quat q, zpl_vec3 v) {
    /* zpl_vec3 t = 2.0f * cross(q.xyz, v);
     * *d = q.w*t + v + cross(q.xyz, t);
     */
    zpl_vec3 t, p;
    zpl_vec3_cross(&t, q.xyz, v);
    zpl_vec3_muleq(&t, 2.0f);

    zpl_vec3_cross(&p, q.xyz, t);

    zpl_vec3_mul(d, t, q.w);
    zpl_vec3_addeq(d, v);
    zpl_vec3_addeq(d, p);
}

void zpl_mat4_from_quat(zpl_mat4 *out, zpl_quat q) {
    zpl_float4 *m;
    zpl_quat a;
    f32 xx, yy, zz, xy, xz, yz, wx, wy, wz;

    zpl_quat_norm(&a, q);
    xx = a.x * a.x;
    yy = a.y * a.y;
    zz = a.z * a.z;
    xy = a.x * a.y;
    xz = a.x * a.z;
    yz = a.y * a.z;
    wx = a.w * a.x;
    wy = a.w * a.y;
    wz = a.w * a.z;

    zpl_mat4_identity(out);
    m = zpl_float44_m(out);

    m[0][0] = 1.0f - 2.0f * (yy + zz);
    m[0][1] = 2.0f * (xy + wz);
    m[0][2] = 2.0f * (xz - wy);

    m[1][0] = 2.0f * (xy - wz);
    m[1][1] = 1.0f - 2.0f * (xx + zz);
    m[1][2] = 2.0f * (yz + wx);

    m[2][0] = 2.0f * (xz + wy);
    m[2][1] = 2.0f * (yz - wx);
    m[2][2] = 1.0f - 2.0f * (xx + yy);
}

void zpl_quat_from_mat4(zpl_quat *out, zpl_mat4 *mat) {
    zpl_float4 *m;
    f32 four_x_squared_minus_1, four_y_squared_minus_1, four_z_squared_minus_1, four_w_squared_minus_1,
        four_biggest_squared_minus_1;
    int biggest_index = 0;
    f32 biggest_value, mult;

    m = zpl_float44_m(mat);

    four_x_squared_minus_1 = m[0][0] - m[1][1] - m[2][2];
    four_y_squared_minus_1 = m[1][1] - m[0][0] - m[2][2];
    four_z_squared_minus_1 = m[2][2] - m[0][0] - m[1][1];
    four_w_squared_minus_1 = m[0][0] + m[1][1] + m[2][2];

    four_biggest_squared_minus_1 = four_w_squared_minus_1;
    if (four_x_squared_minus_1 > four_biggest_squared_minus_1) {
        four_biggest_squared_minus_1 = four_x_squared_minus_1;
        biggest_index = 1;
    }
    if (four_y_squared_minus_1 > four_biggest_squared_minus_1) {
        four_biggest_squared_minus_1 = four_y_squared_minus_1;
        biggest_index = 2;
    }
    if (four_z_squared_minus_1 > four_biggest_squared_minus_1) {
        four_biggest_squared_minus_1 = four_z_squared_minus_1;
        biggest_index = 3;
    }

    biggest_value = zpl_sqrt(four_biggest_squared_minus_1 + 1.0f) * 0.5f;
    mult = 0.25f / biggest_value;

    switch (biggest_index) {
    case 0:
        out->w = biggest_value;
        out->x = (m[1][2] - m[2][1]) * mult;
        out->y = (m[2][0] - m[0][2]) * mult;
        out->z = (m[0][1] - m[1][0]) * mult;
        break;
    case 1:
        out->w = (m[1][2] - m[2][1]) * mult;
        out->x = biggest_value;
        out->y = (m[0][1] + m[1][0]) * mult;
        out->z = (m[2][0] + m[0][2]) * mult;
        break;
    case 2:
        out->w = (m[2][0] - m[0][2]) * mult;
        out->x = (m[0][1] + m[1][0]) * mult;
        out->y = biggest_value;
        out->z = (m[1][2] + m[2][1]) * mult;
        break;
    case 3:
        out->w = (m[0][1] - m[1][0]) * mult;
        out->x = (m[2][0] + m[0][2]) * mult;
        out->y = (m[1][2] + m[2][1]) * mult;
        out->z = biggest_value;
        break;
    default:
        /* NOTE: This shouldn't fucking happen!!! */
        break;
    }
}

f32 zpl_lerp(f32 a, f32 b, f32 t) { return a * (1.0f - t) + b * t; }
f32 zpl_unlerp(f32 t, f32 a, f32 b) { return (t - a) / (b - a); }
f32 zpl_smooth_step(f32 a, f32 b, f32 t) {
    f32 x = (t - a) / (b - a);
    return x * x * (3.0f - 2.0f * x);
}
f32 zpl_smoother_step(f32 a, f32 b, f32 t) {
    f32 x = (t - a) / (b - a);
    return x * x * x * (x * (6.0f * x - 15.0f) + 10.0f);
}

#define ZPL_VEC_LERPN(N, d, a, b, t)                                                                                  \
    \
zpl_vec##N##_t db;                                                                                                     \
    \
zpl_vec##N##_sub(&db, b, a);                                                                                           \
    \
zpl_vec##N##_muleq(&db, t);                                                                                            \
    \
zpl_vec##N##_add(d, a, db)
void zpl_vec2_lerp(zpl_vec2 *d, zpl_vec2 a, zpl_vec2 b, f32 t) { ZPL_VEC_LERPN(2, d, a, b, t); }
void zpl_vec3_lerp(zpl_vec3 *d, zpl_vec3 a, zpl_vec3 b, f32 t) { ZPL_VEC_LERPN(3, d, a, b, t); }
void zpl_vec4_lerp(zpl_vec4 *d, zpl_vec4 a, zpl_vec4 b, f32 t) { ZPL_VEC_LERPN(4, d, a, b, t); }

#undef ZPL_VEC_LERPN

void zpl_vec2_cslerp(zpl_vec2 *d, zpl_vec2 a, zpl_vec2 v0, zpl_vec2 b, zpl_vec2 v1, f32 t) {
    f32 t2 = t * t;
    f32 ti = (t - 1);
    f32 ti2 = ti * ti;

    f32 h00 = (1 + 2 * t) * ti2;
    f32 h10 = t * ti2;
    f32 h01 = t2 * (3 - 2 * t);
    f32 h11 = t2 * ti;

    d->x = h00 * a.x + h10 * v0.x + h01 * b.x + h11 * v1.x;
    d->y = h00 * a.y + h10 * v0.y + h01 * b.y + h11 * v1.y;
}

void zpl_vec3_cslerp(zpl_vec3 *d, zpl_vec3 a, zpl_vec3 v0, zpl_vec3 b, zpl_vec3 v1, f32 t) {
    f32 t2 = t * t;
    f32 ti = (t - 1);
    f32 ti2 = ti * ti;

    f32 h00 = (1 + 2 * t) * ti2;
    f32 h10 = t * ti2;
    f32 h01 = t2 * (3 - 2 * t);
    f32 h11 = t2 * ti;

    d->x = h00 * a.x + h10 * v0.x + h01 * b.x + h11 * v1.x;
    d->y = h00 * a.y + h10 * v0.y + h01 * b.y + h11 * v1.y;
    d->z = h00 * a.z + h10 * v0.z + h01 * b.z + h11 * v1.z;
}

void zpl_vec2_dcslerp(zpl_vec2 *d, zpl_vec2 a, zpl_vec2 v0, zpl_vec2 b, zpl_vec2 v1, f32 t) {
    f32 t2 = t * t;

    f32 dh00 = 6 * t2 - 6 * t;
    f32 dh10 = 3 * t2 - 4 * t + 1;
    f32 dh01 = -6 * t2 + 6 * t;
    f32 dh11 = 3 * t2 - 2 * t;

    d->x = dh00 * a.x + dh10 * v0.x + dh01 * b.x + dh11 * v1.x;
    d->y = dh00 * a.y + dh10 * v0.y + dh01 * b.y + dh11 * v1.y;
}

void zpl_vec3_dcslerp(zpl_vec3 *d, zpl_vec3 a, zpl_vec3 v0, zpl_vec3 b, zpl_vec3 v1, f32 t) {
    f32 t2 = t * t;

    f32 dh00 = 6 * t2 - 6 * t;
    f32 dh10 = 3 * t2 - 4 * t + 1;
    f32 dh01 = -6 * t2 + 6 * t;
    f32 dh11 = 3 * t2 - 2 * t;

    d->x = dh00 * a.x + dh10 * v0.x + dh01 * b.x + dh11 * v1.x;
    d->y = dh00 * a.y + dh10 * v0.y + dh01 * b.y + dh11 * v1.y;
    d->z = dh00 * a.z + dh10 * v0.z + dh01 * b.z + dh11 * v1.z;
}

void zpl_quat_lerp(zpl_quat *d, zpl_quat a, zpl_quat b, f32 t) { zpl_vec4_lerp(&d->xyzw, a.xyzw, b.xyzw, t); }
void zpl_quat_nlerp(zpl_quat *d, zpl_quat a, zpl_quat b, f32 t) {
    zpl_quat_lerp(d, a, b, t);
    zpl_quat_norm(d, *d);
}

void zpl_quat_slerp(zpl_quat *d, zpl_quat a, zpl_quat b, f32 t) {
    zpl_quat x, y, z;
    f32 cos_theta, angle;
    f32 s1, s0, is;

    z = b;
    cos_theta = zpl_quat_dot(a, b);

    if (cos_theta < 0.0f) {
        z = zpl_quatf(-b.x, -b.y, -b.z, -b.w);
        cos_theta = -cos_theta;
    }

    if (cos_theta > 1.0f) {
        /* NOTE: Use lerp not nlerp as it's not a real angle or they are not normalized */
        zpl_quat_lerp(d, a, b, t);
    }

    angle = zpl_arccos(cos_theta);

    s1 = zpl_sin(1.0f - t * angle);
    s0 = zpl_sin(t * angle);
    is = 1.0f / zpl_sin(angle);
    zpl_quat_mulf(&x, z, s1);
    zpl_quat_mulf(&y, z, s0);
    zpl_quat_add(d, x, y);
    zpl_quat_muleqf(d, is);
}

void zpl_quat_slerp_approx(zpl_quat *d, zpl_quat a, zpl_quat b, f32 t) {
    /* NOTE: Derived by taylor expanding the geometric interpolation equation
     *             Even works okay for nearly anti-parallel versors!!!
     */
    /* NOTE: Extra interations cannot be used as they require angle^4 which is not worth it to approximate */
    f32 tp = t + (1.0f - zpl_quat_dot(a, b)) / 3.0f * t * (-2.0f * t * t + 3.0f * t - 1.0f);
    zpl_quat_nlerp(d, a, b, tp);
}

void zpl_quat_nquad(zpl_quat *d, zpl_quat p, zpl_quat a, zpl_quat b, zpl_quat q, f32 t) {
    zpl_quat x, y;
    zpl_quat_nlerp(&x, p, q, t);
    zpl_quat_nlerp(&y, a, b, t);
    zpl_quat_nlerp(d, x, y, 2.0f * t * (1.0f - t));
}

void zpl_quat_squad(zpl_quat *d, zpl_quat p, zpl_quat a, zpl_quat b, zpl_quat q, f32 t) {
    zpl_quat x, y;
    zpl_quat_slerp(&x, p, q, t);
    zpl_quat_slerp(&y, a, b, t);
    zpl_quat_slerp(d, x, y, 2.0f * t * (1.0f - t));
}

void zpl_quat_squad_approx(zpl_quat *d, zpl_quat p, zpl_quat a, zpl_quat b, zpl_quat q, f32 t) {
    zpl_quat x, y;
    zpl_quat_slerp_approx(&x, p, q, t);
    zpl_quat_slerp_approx(&y, a, b, t);
    zpl_quat_slerp_approx(d, x, y, 2.0f * t * (1.0f - t));
}

zpl_rect2 zpl_rect2f(zpl_vec2 pos, zpl_vec2 dim) {
    zpl_rect2 r;
    r.pos = pos;
    r.dim = dim;
    return r;
}

zpl_rect3 zpl_rect3f(zpl_vec3 pos, zpl_vec3 dim) {
    zpl_rect3 r;
    r.pos = pos;
    r.dim = dim;
    return r;
}

int zpl_rect2_contains(zpl_rect2 a, f32 x, f32 y) {
    f32 min_x = zpl_min(a.pos.x, a.pos.x + a.dim.x);
    f32 max_x = zpl_max(a.pos.x, a.pos.x + a.dim.x);
    f32 min_y = zpl_min(a.pos.y, a.pos.y + a.dim.y);
    f32 max_y = zpl_max(a.pos.y, a.pos.y + a.dim.y);
    int result = (x >= min_x) & (x < max_x) & (y >= min_y) & (y < max_y);
    return result;
}

int zpl_rect2_contains_vec2(zpl_rect2 a, zpl_vec2 p) { return zpl_rect2_contains(a, p.x, p.y); }

int zpl_rect2_intersects(zpl_rect2 a, zpl_rect2 b) {
    zpl_rect2 r = { 0 };
    return zpl_rect2_intersection_result(a, b, &r);
}

int zpl_rect2_intersection_result(zpl_rect2 a, zpl_rect2 b, zpl_rect2 *intersection) {
    f32 a_min_x = zpl_min(a.pos.x, a.pos.x + a.dim.x);
    f32 a_max_x = zpl_max(a.pos.x, a.pos.x + a.dim.x);
    f32 a_min_y = zpl_min(a.pos.y, a.pos.y + a.dim.y);
    f32 a_max_y = zpl_max(a.pos.y, a.pos.y + a.dim.y);

    f32 b_min_x = zpl_min(b.pos.x, b.pos.x + b.dim.x);
    f32 b_max_x = zpl_max(b.pos.x, b.pos.x + b.dim.x);
    f32 b_min_y = zpl_min(b.pos.y, b.pos.y + b.dim.y);
    f32 b_max_y = zpl_max(b.pos.y, b.pos.y + b.dim.y);

    f32 x0 = zpl_max(a_min_x, b_min_x);
    f32 y0 = zpl_max(a_min_y, b_min_y);
    f32 x1 = zpl_min(a_max_x, b_max_x);
    f32 y1 = zpl_min(a_max_y, b_max_y);

    if ((x0 < x1) && (y0 < y1)) {
        zpl_rect2 r = zpl_rect2f(zpl_vec2f(x0, y0), zpl_vec2f(x1 - x0, y1 - y0));
        *intersection = r;
        return 1;
    } else {
        zpl_rect2 r = { 0 };
        *intersection = r;
        return 0;
    }
}

////////////////////////////////////////////////////////////////
//
// Platform
//
//

#if defined(ZPL_PLATFORM)

zpl_inline void zpl_key_state_update(zplKeyState *s, b32 is_down) {
    b32 was_down = (*s & ZPL_KEY_STATE_DOWN) != 0;
    is_down = is_down != 0; // NOTE(bill): Make sure it's a boolean
    ZPL_MASK_SET(*s, is_down, ZPL_KEY_STATE_DOWN);
    ZPL_MASK_SET(*s, !was_down && is_down, ZPL_KEY_STATE_PRESSED);
    ZPL_MASK_SET(*s, was_down && !is_down, ZPL_KEY_STATE_RELEASED);
}

#if defined(ZPL_SYSTEM_WINDOWS)

#ifndef ERROR_DEVICE_NOT_CONNECTED
#define ERROR_DEVICE_NOT_CONNECTED 1167
#endif

ZPL_XINPUT_GET_STATE(zplXInputGetState_Stub) {
    zpl_unused(dwUserIndex);
    zpl_unused(pState);
    return ERROR_DEVICE_NOT_CONNECTED;
}
ZPL_XINPUT_SET_STATE(zplXInputSetState_Stub) {
    zpl_unused(dwUserIndex);
    zpl_unused(pVibration);
    return ERROR_DEVICE_NOT_CONNECTED;
}

zpl_internal zpl_inline f32 zpl__process_xinput_stick_value(i16 value, i16 dead_zone_threshold) {
    f32 result = 0;

    if (value < -dead_zone_threshold) {
        result = cast(f32)(value + dead_zone_threshold) / (32768.0f - dead_zone_threshold);
    } else if (value > dead_zone_threshold) {
        result = cast(f32)(value - dead_zone_threshold) / (32767.0f - dead_zone_threshold);
    }

    return result;
}

zpl_internal void zpl__platform_resize_dib_section(zpl_platform *p, i32 width, i32 height) {
    if ((p->renderer_type == ZPL_RENDERER_SOFTWARE) && !(p->window_width == width && p->window_height == height)) {
        BITMAPINFO bmi = { 0 };

        if (width == 0 || height == 0) { return; }

        p->window_width = width;
        p->window_height = height;

        // TODO(bill): Is this slow to get the desktop mode everytime?
        p->sw_framebuffer.bits_per_pixel = zpl_video_mode_get_desktop( ).bits_per_pixel;
        p->sw_framebuffer.pitch = (p->sw_framebuffer.bits_per_pixel * width / 8);

        bmi.bmiHeader.biSize = zpl_size_of(bmi.bmiHeader);
        bmi.bmiHeader.biWidth = width;
        bmi.bmiHeader.biHeight = height; // NOTE(bill): -ve is top-down, +ve is bottom-up
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = cast(u16) p->sw_framebuffer.bits_per_pixel;
        bmi.bmiHeader.biCompression = 0 /*BI_RGB*/;

        p->sw_framebuffer.win32_bmi = bmi;

        if (p->sw_framebuffer.memory) {
            zpl_vm_free(zpl_vm(p->sw_framebuffer.memory, p->sw_framebuffer.memory_size));
        }

        {
            isize memory_size = p->sw_framebuffer.pitch * height;
            zpl_virtual_memory vm = zpl_vm_alloc(0, memory_size);
            p->sw_framebuffer.memory = vm.data;
            p->sw_framebuffer.memory_size = vm.size;
        }
    }
}

zpl_internal zplKeyType zpl__win32_from_vk(unsigned int key) {
    // NOTE(bill): Letters and numbers are defined the same for VK_* and ZPL_*
    if (key >= 'A' && key < 'Z') return cast(zplKeyType) key;
    if (key >= '0' && key < '9') return cast(zplKeyType) key;
    switch (key) {
    case VK_ESCAPE: return ZPL_KEY_ESCAPE;

    case VK_LCONTROL: return ZPL_KEY_LCONTROL;
    case VK_LSHIFT: return ZPL_KEY_LSHIFT;
    case VK_LMENU: return ZPL_KEY_LALT;
    case VK_LWIN: return ZPL_KEY_LSYSTEM;
    case VK_RCONTROL: return ZPL_KEY_RCONTROL;
    case VK_RSHIFT: return ZPL_KEY_RSHIFT;
    case VK_RMENU: return ZPL_KEY_RALT;
    case VK_RWIN: return ZPL_KEY_RSYSTEM;
    case VK_MENU: return ZPL_KEY_MENU;

    case VK_OEM_4: return ZPL_KEY_LBRACKET;
    case VK_OEM_6: return ZPL_KEY_RBRACKET;
    case VK_OEM_1: return ZPL_KEY_SEMICOLON;
    case VK_OEM_COMMA: return ZPL_KEY_COMMA;
    case VK_OEM_PERIOD: return ZPL_KEY_PERIOD;
    case VK_OEM_7: return ZPL_KEY_QUOTE;
    case VK_OEM_2: return ZPL_KEY_SLASH;
    case VK_OEM_5: return ZPL_KEY_BACKSLASH;
    case VK_OEM_3: return ZPL_KEY_GRAVE;
    case VK_OEM_PLUS: return ZPL_KEY_EQUALS;
    case VK_OEM_MINUS: return ZPL_KEY_MINUS;

    case VK_SPACE: return ZPL_KEY_SPACE;
    case VK_RETURN: return ZPL_KEY_RETURN;
    case VK_BACK: return ZPL_KEY_BACKSPACE;
    case VK_TAB: return ZPL_KEY_TAB;

    case VK_PRIOR: return ZPL_KEY_PAGEUP;
    case VK_NEXT: return ZPL_KEY_PAGEDOWN;
    case VK_END: return ZPL_KEY_END;
    case VK_HOME: return ZPL_KEY_HOME;
    case VK_INSERT: return ZPL_KEY_INSERT;
    case VK_DELETE: return ZPL_KEY_DELETE;

    case VK_ADD: return ZPL_KEY_PLUS;
    case VK_SUBTRACT: return ZPL_KEY_SUBTRACT;
    case VK_MULTIPLY: return ZPL_KEY_MULTIPLY;
    case VK_DIVIDE: return ZPL_KEY_DIVIDE;

    case VK_LEFT: return ZPL_KEY_LEFT;
    case VK_RIGHT: return ZPL_KEY_RIGHT;
    case VK_UP: return ZPL_KEY_UP;
    case VK_DOWN: return ZPL_KEY_DOWN;

    case VK_NUMPAD0: return ZPL_KEY_NUMPAD0;
    case VK_NUMPAD1: return ZPL_KEY_NUMPAD1;
    case VK_NUMPAD2: return ZPL_KEY_NUMPAD2;
    case VK_NUMPAD3: return ZPL_KEY_NUMPAD3;
    case VK_NUMPAD4: return ZPL_KEY_NUMPAD4;
    case VK_NUMPAD5: return ZPL_KEY_NUMPAD5;
    case VK_NUMPAD6: return ZPL_KEY_NUMPAD6;
    case VK_NUMPAD7: return ZPL_KEY_NUMPAD7;
    case VK_NUMPAD8: return ZPL_KEY_NUMPAD8;
    case VK_NUMPAD9: return ZPL_KEY_NUMPAD9;
    case VK_SEPARATOR: return ZPL_KEY_NUMPADENTER;
    case VK_DECIMAL: return ZPL_KEY_NUMPADDOT;

    case VK_F1: return ZPL_KEY_F1;
    case VK_F2: return ZPL_KEY_F2;
    case VK_F3: return ZPL_KEY_F3;
    case VK_F4: return ZPL_KEY_F4;
    case VK_F5: return ZPL_KEY_F5;
    case VK_F6: return ZPL_KEY_F6;
    case VK_F7: return ZPL_KEY_F7;
    case VK_F8: return ZPL_KEY_F8;
    case VK_F9: return ZPL_KEY_F9;
    case VK_F10: return ZPL_KEY_F10;
    case VK_F11: return ZPL_KEY_F11;
    case VK_F12: return ZPL_KEY_F12;
    case VK_F13: return ZPL_KEY_F13;
    case VK_F14: return ZPL_KEY_F14;
    case VK_F15: return ZPL_KEY_F15;

    case VK_PAUSE: return ZPL_KEY_PAUSE;
    }
    return ZPL_KEY_UNKNOWN;
}
LRESULT CALLBACK zpl__win32_window_callback(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    // NOTE(bill): Silly callbacks
    zpl_platform *platform = cast(zpl_platform *) GetWindowLongPtrW(hWnd, GWLP_USERDATA);
    b32 window_has_focus = (platform != NULL) && platform->window_has_focus;

    if (msg == WM_CREATE) { // NOTE(bill): Doesn't need the platform
        // NOTE(bill): https://msdn.microsoft.com/en-us/library/windows/desktop/ms645536(v=vs.85).aspx
        RAWINPUTDEVICE rid[2] = { 0 };

        // NOTE(bill): Keyboard
        rid[0].usUsagePage = 0x01;
        rid[0].usUsage = 0x06;
        rid[0].dwFlags =
            0x00002000; /*RIDEV_DEVNOTIFY*/
            //0x00000030 /*RIDEV_NOLEGACY*/; // NOTE(bill): Do not generate legacy messages such as WM_KEYDOWN
        rid[0].hwndTarget = hWnd;

        // NOTE(bill): Mouse
        rid[1].usUsagePage = 0x01;
        rid[1].usUsage = 0x02;
        rid[1].dwFlags =
            0; // NOTE(bill): adds HID mouse and also allows legacy mouse messages to allow for window movement etc.
        rid[1].hwndTarget = hWnd;

        if (RegisterRawInputDevices(rid, zpl_count_of(rid), zpl_size_of(rid[0])) == false) {
            DWORD err = GetLastError( );
            ZPL_PANIC("Failed to initialize raw input device for win32."
                     "Err: %u",
                     err);
        }
    }

    if (!platform) { return DefWindowProcW(hWnd, msg, wParam, lParam); }

    switch (msg) {
    case WM_CLOSE:
    case WM_DESTROY: platform->window_is_closed = true; return 0;

    case WM_QUIT: {
        platform->quit_requested = true;
    } break;

    // TODO Improve to handle different keyboard layouts
    case WM_CHAR:
    case WM_UNICHAR: {
        if (window_has_focus) {
            if (wParam == '\r') { wParam = '\n'; }
            
            platform->char_buffer[platform->char_buffer_count++] = cast(Rune) wParam;
        }
    } break;


    case WM_INPUT: {
        RAWINPUT raw = { 0 };
        unsigned int size = zpl_size_of(RAWINPUT);

        if (!GetRawInputData(cast(HRAWINPUT) lParam, RID_INPUT, &raw, &size, zpl_size_of(RAWINPUTHEADER))) { return 0; }
        switch (raw.header.dwType) {
        case RIM_TYPEKEYBOARD: {
            // NOTE(bill): Many thanks to
            // https://blog.molecular-matters.com/2011/09/05/properly-handling-keyboard-input/ for the
            RAWKEYBOARD *raw_kb = &raw.data.keyboard;
            unsigned int vk = raw_kb->VKey;
            unsigned int scan_code = raw_kb->MakeCode;
            unsigned int flags = raw_kb->Flags;
            // NOTE(bill): e0 and e1 are escape sequences used for certain special keys, such as PRINT and PAUSE/BREAK.
            // NOTE(bill): http://www.win.tue.nl/~aeb/linux/kbd/scancodes-1.html
            b32 is_e0 = (flags & RI_KEY_E0) != 0;
            b32 is_e1 = (flags & RI_KEY_E1) != 0;
            b32 is_up = (flags & RI_KEY_BREAK) != 0;
            b32 is_down = !is_up;

            // TODO(bill): Should I handle scan codes?

            if (vk == 255) {
                // NOTE(bill): Discard "fake keys"
                return 0;
            } else if (vk == VK_SHIFT) {
                // NOTE(bill): Correct left/right shift
                vk = MapVirtualKeyW(scan_code, MAPVK_VSC_TO_VK_EX);
            } else if (vk == VK_NUMLOCK) {
                // NOTE(bill): Correct PAUSE/BREAK and NUM LOCK and set the extended bit
                scan_code = MapVirtualKeyW(vk, MAPVK_VK_TO_VSC) | 0x100;
            }

            if (is_e1) {
                // NOTE(bill): Escaped sequences, turn vk into the correct scan code
                // except for VK_PAUSE (it's a bug)
                if (vk == VK_PAUSE) {
                    scan_code = 0x45;
                } else {
                    scan_code = MapVirtualKeyW(vk, MAPVK_VK_TO_VSC);
                }
            }

            switch (vk) {
            case VK_CONTROL: vk = (is_e0) ? VK_RCONTROL : VK_LCONTROL; break;
            case VK_MENU: vk = (is_e0) ? VK_RMENU : VK_LMENU; break;

            case VK_RETURN:
                if (is_e0) vk = VK_SEPARATOR;
                break; // NOTE(bill): Numpad return
            case VK_DELETE:
                if (!is_e0) vk = VK_DECIMAL;
                break; // NOTE(bill): Numpad dot
            case VK_INSERT:
                if (!is_e0) vk = VK_NUMPAD0;
                break;
            case VK_HOME:
                if (!is_e0) vk = VK_NUMPAD7;
                break;
            case VK_END:
                if (!is_e0) vk = VK_NUMPAD1;
                break;
            case VK_PRIOR:
                if (!is_e0) vk = VK_NUMPAD9;
                break;
            case VK_NEXT:
                if (!is_e0) vk = VK_NUMPAD3;
                break;

            // NOTE(bill): The standard arrow keys will always have their e0 bit set, but the
            // corresponding keys on the NUMPAD will not.
            case VK_LEFT:
                if (!is_e0) vk = VK_NUMPAD4;
                break;
            case VK_RIGHT:
                if (!is_e0) vk = VK_NUMPAD6;
                break;
            case VK_UP:
                if (!is_e0) vk = VK_NUMPAD8;
                break;
            case VK_DOWN:
                if (!is_e0) vk = VK_NUMPAD2;
                break;

            // NUMPAD 5 doesn't have its e0 bit set
            case VK_CLEAR:
                if (!is_e0) vk = VK_NUMPAD5;
                break;
            }

            // NOTE(bill): Set appropriate key state flags
            zpl_key_state_update(&platform->keys[zpl__win32_from_vk(vk)], is_down);

        } break;
        case RIM_TYPEMOUSE: {
            RAWMOUSE *raw_mouse = &raw.data.mouse;
            u16 flags = raw_mouse->usButtonFlags;
            long dx = +raw_mouse->lLastX;
            long dy = -raw_mouse->lLastY;

            if (flags & RI_MOUSE_WHEEL) { platform->mouse_wheel_delta = cast(i16) raw_mouse->usButtonData; }

            platform->mouse_raw_dx = dx;
            platform->mouse_raw_dy = dy;
        } break;
        }
    } break;

    default: break;
    }

    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

typedef void *wglCreateContextAttribsARB_Proc(void *hDC, void *hshareContext, int const *attribList);

b32 zpl__platform_init(zpl_platform *p, char const *window_title, zpl_video_mode mode, zplRendererType type,
                      u32 window_flags) {
    WNDCLASSEXW wc = { zpl_size_of(WNDCLASSEXW) };
    DWORD ex_style = 0, style = 0;
    RECT wr;
    u16 title_buffer[256] = { 0 }; // TODO(bill): zpl_local_persist this?

    wc.style = CS_HREDRAW | CS_VREDRAW; // | CS_OWNDC
    wc.lpfnWndProc = zpl__win32_window_callback;
    wc.hbrBackground = cast(HBRUSH) GetStockObject(0 /*WHITE_BRUSH*/);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = L"zpl-win32-wndclass"; // TODO(bill): Is this enough?
    wc.hInstance = GetModuleHandleW(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    p->window_cursor = (void*)wc.hCursor;

    if (RegisterClassExW(&wc) == 0) {
        MessageBoxW(NULL, L"Failed to register the window class", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
        return false;
    }

    if ((window_flags & ZPL_WINDOW_FULLSCREEN) && !(window_flags & ZPL_WINDOW_BORDERLESS)) {
        DEVMODEW screen_settings = { zpl_size_of(DEVMODEW) };
        screen_settings.dmPelsWidth = mode.width;
        screen_settings.dmPelsHeight = mode.height;
        screen_settings.dmBitsPerPel = mode.bits_per_pixel;
        screen_settings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

        if (ChangeDisplaySettingsW(&screen_settings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) {
            if (MessageBoxW(NULL,
                            L"The requested fullscreen mode is not supported by\n"
                            L"your video card. Use windowed mode instead?",
                            L"", MB_YESNO | MB_ICONEXCLAMATION) == IDYES) {
                window_flags &= ~ZPL_WINDOW_FULLSCREEN;
            } else {
                mode = zpl_video_mode_get_desktop( );
                screen_settings.dmPelsWidth = mode.width;
                screen_settings.dmPelsHeight = mode.height;
                screen_settings.dmBitsPerPel = mode.bits_per_pixel;
                ChangeDisplaySettingsW(&screen_settings, CDS_FULLSCREEN);
            }
        }
    }

    // ex_style = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
    // style = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_THICKFRAME | WS_SYSMENU | WS_MAXIMIZEBOX |
    // WS_MINIMIZEBOX;

    style |= WS_VISIBLE;

    if (window_flags & ZPL_WINDOW_HIDDEN) style &= ~WS_VISIBLE;
    if (window_flags & ZPL_WINDOW_RESIZABLE) style |= WS_THICKFRAME | WS_MAXIMIZEBOX;
    if (window_flags & ZPL_WINDOW_MAXIMIZED) style |= WS_MAXIMIZE;
    if (window_flags & ZPL_WINDOW_MINIMIZED) style |= WS_MINIMIZE;

    // NOTE(bill): Completely ignore the given mode and just change it
    if (window_flags & ZPL_WINDOW_FULLSCREENDESKTOP) { mode = zpl_video_mode_get_desktop( ); }

    if ((window_flags & ZPL_WINDOW_FULLSCREEN) || (window_flags & ZPL_WINDOW_BORDERLESS)) {
        style |= WS_POPUP;
    } else {
        style |= WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
    }

    wr.left = 0;
    wr.top = 0;
    wr.right = mode.width;
    wr.bottom = mode.height;
    AdjustWindowRect(&wr, style, false);

    p->window_flags = window_flags;
    p->window_handle = CreateWindowExW(
        ex_style, wc.lpszClassName,
        cast(wchar_t const *) zpl_utf8_to_ucs2(title_buffer, zpl_size_of(title_buffer), (u8 *)window_title), style,
        CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top, 0, 0, GetModuleHandleW(NULL), NULL);

    if (!p->window_handle) {
        MessageBoxW(NULL, L"Window creation failed", L"Error", MB_OK | MB_ICONEXCLAMATION);
        return false;
    }

    p->win32_dc = GetDC(cast(HWND) p->window_handle);

    p->renderer_type = type;
    switch (p->renderer_type) {
    case ZPL_RENDERER_OPENGL: {
        wglCreateContextAttribsARB_Proc *wglCreateContextAttribsARB;
        i32 attribs[8] = { 0 };
        isize c = 0;

        PIXELFORMATDESCRIPTOR pfd = { zpl_size_of(PIXELFORMATDESCRIPTOR) };
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cAlphaBits = 8;
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;
        pfd.iLayerType = PFD_MAIN_PLANE;

        SetPixelFormat(cast(HDC) p->win32_dc, ChoosePixelFormat(cast(HDC) p->win32_dc, &pfd), NULL);
        p->opengl.context = cast(void *) wglCreateContext(cast(HDC) p->win32_dc);
        wglMakeCurrent(cast(HDC) p->win32_dc, cast(HGLRC) p->opengl.context);

        if (p->opengl.major > 0) {
            attribs[c++] = 0x2091; // WGL_CONTEXT_MAJOR_VERSION_ARB
            attribs[c++] = zpl_max(p->opengl.major, 1);
        }
        if (p->opengl.major > 0 && p->opengl.minor >= 0) {
            attribs[c++] = 0x2092; // WGL_CONTEXT_MINOR_VERSION_ARB
            attribs[c++] = zpl_max(p->opengl.minor, 0);
        }

        if (p->opengl.core) {
            attribs[c++] = 0x9126; // WGL_CONTEXT_PROFILE_MASK_ARB
            attribs[c++] = 0x0001; // WGL_CONTEXT_CORE_PROFILE_BIT_ARB
        } else if (p->opengl.compatible) {
            attribs[c++] = 0x9126; // WGL_CONTEXT_PROFILE_MASK_ARB
            attribs[c++] = 0x0002; // WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
        }
        attribs[c++] = 0; // NOTE(bill): tells the proc that this is the end of attribs

        wglCreateContextAttribsARB =
            cast(wglCreateContextAttribsARB_Proc *) wglGetProcAddress("wglCreateContextAttribsARB");
        if (wglCreateContextAttribsARB) {
            HGLRC rc = cast(HGLRC) wglCreateContextAttribsARB(p->win32_dc, 0, attribs);
            if (rc && wglMakeCurrent(cast(HDC) p->win32_dc, rc)) {
                p->opengl.context = rc;
            } else {
                // TODO(bill): Handle errors from GetLastError
                // ERROR_INVALID_VERSION_ARB 0x2095
                // ERROR_INVALID_PROFILE_ARB 0x2096
            }
        }

    } break;

    case ZPL_RENDERER_SOFTWARE: zpl__platform_resize_dib_section(p, mode.width, mode.height); break;

    default: ZPL_PANIC("Unknown window type"); break;
    }

    SetForegroundWindow(cast(HWND) p->window_handle);
    SetFocus(cast(HWND) p->window_handle);
    SetWindowLongPtrW(cast(HWND) p->window_handle, GWLP_USERDATA, cast(LONG_PTR) p);

    p->window_width = mode.width;
    p->window_height = mode.height;

    if (p->renderer_type == ZPL_RENDERER_OPENGL) { p->opengl.dll_handle = zpl_dll_load("opengl32.dll"); }

    { // Load XInput
        // TODO(bill): What other dlls should I look for?
        zpl_dll_handle xinput_library = zpl_dll_load("xinput1_4.dll");
        p->xinput.get_state = zplXInputGetState_Stub;
        p->xinput.set_state = zplXInputSetState_Stub;

        if (!xinput_library) xinput_library = zpl_dll_load("xinput9_1_0.dll");
        if (!xinput_library) xinput_library = zpl_dll_load("xinput1_3.dll");
        if (!xinput_library) {
            // TODO(bill): Proper Diagnostic
            zpl_printf_err("XInput could not be loaded. Controllers will not work!\n");
        } else {
            p->xinput.get_state = cast(zpl_xinput_get_state_proc *) zpl_dll_proc_address(xinput_library, "XInputGetState");
            p->xinput.set_state = cast(zpl_xinput_set_state_proc *) zpl_dll_proc_address(xinput_library, "XInputSetState");
        }
    }

    // Init keys
    zpl_zero_array(p->keys, zpl_count_of(p->keys));

    p->is_initialized = true;
    return true;
}

zpl_inline b32 zpl_platform_init_with_software(zpl_platform *p, char const *window_title, i32 width, i32 height,
                                             u32 window_flags) {
    zpl_video_mode mode;
    mode.width = width;
    mode.height = height;
    mode.bits_per_pixel = 32;
    return zpl__platform_init(p, window_title, mode, ZPL_RENDERER_SOFTWARE, window_flags);
}

zpl_inline b32 zpl_platform_init_with_opengl(zpl_platform *p, char const *window_title, i32 width, i32 height,
                                           u32 window_flags, i32 major, i32 minor, b32 core, b32 compatible) {
    zpl_video_mode mode;
    mode.width = width;
    mode.height = height;
    mode.bits_per_pixel = 32;
    p->opengl.major = major;
    p->opengl.minor = minor;
    p->opengl.core = cast(b16) core;
    p->opengl.compatible = cast(b16) compatible;
    return zpl__platform_init(p, window_title, mode, ZPL_RENDERER_OPENGL, window_flags);
}

#ifndef _XINPUT_H_
typedef struct _XINPUT_GAMEPAD {
    u16 wButtons;
    u8 bLeftTrigger;
    u8 bRightTrigger;
    u16 sThumbLX;
    u16 sThumbLY;
    u16 sThumbRX;
    u16 sThumbRY;
} XINPUT_GAMEPAD;

typedef struct _XINPUT_STATE {
    DWORD dwPacketNumber;
    XINPUT_GAMEPAD Gamepad;
} XINPUT_STATE;

typedef struct _XINPUT_VIBRATION {
    u16 wLeftMotorSpeed;
    u16 wRightMotorSpeed;
} XINPUT_VIBRATION;

#define XINPUT_GAMEPAD_DPAD_UP 0x00000001
#define XINPUT_GAMEPAD_DPAD_DOWN 0x00000002
#define XINPUT_GAMEPAD_DPAD_LEFT 0x00000004
#define XINPUT_GAMEPAD_DPAD_RIGHT 0x00000008
#define XINPUT_GAMEPAD_START 0x00000010
#define XINPUT_GAMEPAD_BACK 0x00000020
#define XINPUT_GAMEPAD_LEFT_THUMB 0x00000040
#define XINPUT_GAMEPAD_RIGHT_THUMB 0x00000080
#define XINPUT_GAMEPAD_LEFT_SHOULDER 0x0100
#define XINPUT_GAMEPAD_RIGHT_SHOULDER 0x0200
#define XINPUT_GAMEPAD_A 0x1000
#define XINPUT_GAMEPAD_B 0x2000
#define XINPUT_GAMEPAD_X 0x4000
#define XINPUT_GAMEPAD_Y 0x8000
#define XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE 7849
#define XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE 8689
#define XINPUT_GAMEPAD_TRIGGER_THRESHOLD 30
#endif

#ifndef XUSER_MAX_COUNT
#define XUSER_MAX_COUNT 4
#endif

void zpl_platform_update(zpl_platform *p) {
    isize i;

    { // NOTE(bill): Set window state
        // TODO(bill): Should this be moved to zpl__win32_window_callback ?
        RECT window_rect;
        i32 x, y, w, h;

        GetClientRect(cast(HWND) p->window_handle, &window_rect);
        x = window_rect.left;
        y = window_rect.top;
        w = window_rect.right - window_rect.left;
        h = window_rect.bottom - window_rect.top;

        if ((p->window_width != w) || (p->window_height != h)) {
            if (p->renderer_type == ZPL_RENDERER_SOFTWARE) { zpl__platform_resize_dib_section(p, w, h); }
        }

        p->window_x = x;
        p->window_y = y;
        p->window_width = w;
        p->window_height = h;
        ZPL_MASK_SET(p->window_flags, IsIconic(cast(HWND) p->window_handle) != 0, ZPL_WINDOW_MINIMIZED);

        p->window_has_focus = GetFocus( ) == cast(HWND) p->window_handle;

        RECT outline_rect;
        GetWindowRect(cast(HWND) p->window_handle, &outline_rect);
        x = window_rect.left;
        y = window_rect.top;
        w = window_rect.right - window_rect.left;
        h = window_rect.bottom - window_rect.top;

        p->outline_x = x;
        p->outline_y = y;
        p->outline_width = w;
        p->outline_height = h;
    }

    { // NOTE(bill): Set mouse position
        POINT mouse_pos;
        DWORD win_button_id[ZPL_MOUSEBUTTON_COUNT] = {
            VK_LBUTTON, VK_MBUTTON, VK_RBUTTON, VK_XBUTTON1, VK_XBUTTON2,
        };

        // NOTE(bill): This needs to be GetAsyncKeyState as RAWMOUSE doesn't aways work for some odd reason
        // TODO(bill): Try and get RAWMOUSE to work for key presses
        for (i = 0; i < ZPL_MOUSEBUTTON_COUNT; i++) {
            zpl_key_state_update(p->mouse_buttons + i, GetAsyncKeyState(win_button_id[i]) < 0);
        }

        GetCursorPos(&mouse_pos);
        ScreenToClient(cast(HWND) p->window_handle, &mouse_pos);
        {
            i32 x = mouse_pos.x;
            i32 y = p->window_height - 1 - mouse_pos.y;
            p->mouse_dx = x - p->mouse_x;
            p->mouse_dy = y - p->mouse_y;
            p->mouse_x = x;
            p->mouse_y = y;
        }

        if (p->mouse_clip) {
            b32 update = false;
            i32 x = p->mouse_x;
            i32 y = p->mouse_y;
            if (p->mouse_x < 0) {
                x = 0;
                update = true;
            } else if (p->mouse_y > p->window_height - 1) {
                y = p->window_height - 1;
                update = true;
            }

            if (p->mouse_y < 0) {
                y = 0;
                update = true;
            } else if (p->mouse_x > p->window_width - 1) {
                x = p->window_width - 1;
                update = true;
            }

            if (update) { zpl_platform_set_mouse_position(p, x, y); }
        }
    }

    // NOTE(bill): Set Key/Button states
    if (p->window_has_focus) {
        p->char_buffer[0] = '\0';
        p->char_buffer_count = 0; // TODO(bill): Reset buffer count here or else where?
        p->mouse_wheel_delta = 0.0f;

        // NOTE(bill): Need to update as the keys only get updates on events
        for (i = 0; i < ZPL_KEY_COUNT; i++) {
            b32 is_down = (p->keys[i] & ZPL_KEY_STATE_DOWN) != 0;
            zpl_key_state_update(&p->keys[i], is_down);
        }

        p->key_modifiers.control = p->keys[ZPL_KEY_LCONTROL] | p->keys[ZPL_KEY_RCONTROL];
        p->key_modifiers.alt = p->keys[ZPL_KEY_LALT] | p->keys[ZPL_KEY_RALT];
        p->key_modifiers.shift = p->keys[ZPL_KEY_LSHIFT] | p->keys[ZPL_KEY_RSHIFT];
    }

    { // NOTE(bill): Set Controller states
        isize max_controller_count = XUSER_MAX_COUNT;
        if (max_controller_count > zpl_count_of(p->game_controllers)) {
            max_controller_count = zpl_count_of(p->game_controllers);
        }

        for (i = 0; i < max_controller_count; i++) {
            zpl_game_controller *controller = &p->game_controllers[i];
            XINPUT_STATE controller_state = { 0 };
            if (p->xinput.get_state(cast(DWORD) i, &controller_state) != 0) {
                // NOTE(bill): The controller is not available
                controller->is_connected = false;
            } else {
                // NOTE(bill): This controller is plugged in
                // TODO(bill): See if ControllerState.dwPacketNumber increments too rapidly
                XINPUT_GAMEPAD *pad = &controller_state.Gamepad;

                controller->is_connected = true;

                // TODO(bill): This is a square deadzone, check XInput to verify that the deadzone is "round" and do
                // round deadzone processing.
                controller->axes[ZPL_CONTROLLER_AXIS_LEFTX] =
                    zpl__process_xinput_stick_value(pad->sThumbLX, XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
                controller->axes[ZPL_CONTROLLER_AXIS_LEFTY] =
                    zpl__process_xinput_stick_value(pad->sThumbLY, XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
                controller->axes[ZPL_CONTROLLER_AXIS_RIGHTX] =
                    zpl__process_xinput_stick_value(pad->sThumbRX, XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
                controller->axes[ZPL_CONTROLLER_AXIS_RIGHTY] =
                    zpl__process_xinput_stick_value(pad->sThumbRY, XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);

                controller->axes[ZPL_CONTROLLER_AXIS_LEFTTRIGGER] = cast(f32) pad->bLeftTrigger / 255.0f;
                controller->axes[ZPL_CONTROLLER_AXIS_RIGHTTRIGGER] = cast(f32) pad->bRightTrigger / 255.0f;

                if ((controller->axes[ZPL_CONTROLLER_AXIS_LEFTX] != 0.0f) ||
                    (controller->axes[ZPL_CONTROLLER_AXIS_LEFTY] != 0.0f)) {
                    controller->is_analog = true;
                }

#define ZPL__PROCESS_DIGITAL_BUTTON(button_type, xinput_button)                                                         \
    zpl_key_state_update(&controller->buttons[button_type], (pad->wButtons & xinput_button) == xinput_button)

                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_A, XINPUT_GAMEPAD_A);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_B, XINPUT_GAMEPAD_B);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_X, XINPUT_GAMEPAD_X);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_Y, XINPUT_GAMEPAD_Y);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_LEFTSHOULDER, XINPUT_GAMEPAD_LEFT_SHOULDER);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_RIGHTSHOULDER, XINPUT_GAMEPAD_RIGHT_SHOULDER);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_START, XINPUT_GAMEPAD_START);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_BACK, XINPUT_GAMEPAD_BACK);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_LEFT, XINPUT_GAMEPAD_DPAD_LEFT);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_RIGHT, XINPUT_GAMEPAD_DPAD_RIGHT);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_DOWN, XINPUT_GAMEPAD_DPAD_DOWN);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_UP, XINPUT_GAMEPAD_DPAD_UP);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_LEFTTHUMB, XINPUT_GAMEPAD_LEFT_THUMB);
                ZPL__PROCESS_DIGITAL_BUTTON(ZPL_CONTROLLER_BUTTON_RIGHTTHUMB, XINPUT_GAMEPAD_RIGHT_THUMB);
#undef ZPL__PROCESS_DIGITAL_BUTTON
            }
        }
    }

    { // NOTE(bill): Process pending messages
        MSG message;
        for (;;) {
            BOOL is_okay = PeekMessageW(&message, 0, 0, 0, PM_REMOVE);
            if (!is_okay) break;

            switch (message.message) {
            case WM_QUIT: p->quit_requested = true; break;

            case WM_SETCURSOR: {
                SetCursor((HCURSOR)p->window_cursor);
            } break;

            default:
                TranslateMessage(&message);
                DispatchMessageW(&message);
                break;
            }
        }
    }
}

void zpl_platform_display(zpl_platform *p) {
    if (p->renderer_type == ZPL_RENDERER_OPENGL) {
        SwapBuffers(cast(HDC) p->win32_dc);
    } else if (p->renderer_type == ZPL_RENDERER_SOFTWARE) {
        StretchDIBits(cast(HDC) p->win32_dc, 0, 0, p->window_width, p->window_height, 0, 0, p->window_width,
                      p->window_height, p->sw_framebuffer.memory, &p->sw_framebuffer.win32_bmi, DIB_RGB_COLORS,
                      SRCCOPY);
    } else {
        ZPL_PANIC("Invalid window rendering type");
    }

    {
        f64 prev_time = p->curr_time;
        f64 curr_time = zpl_time_now( );
        p->dt_for_frame = curr_time - prev_time;
        p->curr_time = curr_time;
    }
}

void zpl_platform_destroy(zpl_platform *p) {
    if (p->renderer_type == ZPL_RENDERER_OPENGL) {
        wglDeleteContext(cast(HGLRC) p->opengl.context);
    } else if (p->renderer_type == ZPL_RENDERER_SOFTWARE) {
        zpl_vm_free(zpl_vm(p->sw_framebuffer.memory, p->sw_framebuffer.memory_size));
    }

    DestroyWindow(cast(HWND) p->window_handle);
}

void zpl_platform_show_cursor(zpl_platform *p, b32 show) {
    zpl_unused(p);
    ShowCursor(show);
}

void zpl_platform_set_cursor(zpl_platform *p, void *handle) {
    ZPL_ASSERT_NOT_NULL(p);
    p->window_cursor = handle;
    SetCursor((HCURSOR)handle);
}

void zpl_platform_set_mouse_position(zpl_platform *p, i32 x, i32 y) {
    POINT point;
    point.x = cast(LONG) x;
    point.y = cast(LONG)(p->window_height - 1 - y);
    ClientToScreen(cast(HWND) p->window_handle, &point);
    SetCursorPos(point.x, point.y);

    p->mouse_x = point.x;
    p->mouse_y = p->window_height - 1 - point.y;
}

void zpl_platform_set_controller_vibration(zpl_platform *p, isize index, f32 left_motor, f32 right_motor) {
    if (zpl_is_between(index, 0, ZPL_MAX_GAME_CONTROLLER_COUNT - 1)) {
        XINPUT_VIBRATION vibration = { 0 };
        left_motor = zpl_clamp01(left_motor);
        right_motor = zpl_clamp01(right_motor);
        vibration.wLeftMotorSpeed = cast(WORD)(65535 * left_motor);
        vibration.wRightMotorSpeed = cast(WORD)(65535 * right_motor);

        p->xinput.set_state(cast(DWORD) index, &vibration);
    }
}

void zpl_platform_set_window_position(zpl_platform *p, i32 x, i32 y) {
    RECT rect;
    i32 width, height;

    GetClientRect(cast(HWND) p->window_handle, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
    MoveWindow(cast(HWND) p->window_handle, x, y, width, height, false);
}

void zpl_platform_set_window_title(zpl_platform *p, char const *title, ...) {
    u16 buffer[256] = { 0 };
    char str[512] = { 0 };
    va_list va;
    va_start(va, title);
    zpl_snprintf_va(str, zpl_size_of(str), title, va);
    va_end(va);

    if (str[0] != '\0') {
        SetWindowTextW(cast(HWND) p->window_handle,
                       cast(wchar_t const *) zpl_utf8_to_ucs2(buffer, zpl_size_of(buffer), (u8 *)str));
    }
}

void zpl_platform_toggle_fullscreen(zpl_platform *p, b32 fullscreen_desktop) {
    // NOTE(bill): From the man himself, Raymond Chen! (Modified for my need.)
    HWND handle = cast(HWND) p->window_handle;
    DWORD style = cast(DWORD) GetWindowLongW(handle, GWL_STYLE);
    WINDOWPLACEMENT placement;

    if (style & WS_OVERLAPPEDWINDOW) {
        MONITORINFO monitor_info = { zpl_size_of(monitor_info) };
        if (GetWindowPlacement(handle, &placement) && GetMonitorInfoW(MonitorFromWindow(handle, 1), &monitor_info)) {
            style &= ~WS_OVERLAPPEDWINDOW;
            if (fullscreen_desktop) {
                style &= ~WS_CAPTION;
                style |= WS_POPUP;
            }
            SetWindowLongW(handle, GWL_STYLE, style);
            SetWindowPos(handle, HWND_TOP, monitor_info.rcMonitor.left, monitor_info.rcMonitor.top,
                         monitor_info.rcMonitor.right - monitor_info.rcMonitor.left,
                         monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top,
                         SWP_NOOWNERZORDER | SWP_FRAMECHANGED);

            if (fullscreen_desktop) {
                p->window_flags |= ZPL_WINDOW_FULLSCREENDESKTOP;
            } else {
                p->window_flags |= ZPL_WINDOW_FULLSCREEN;
            }
        }
    } else {
        style &= ~WS_POPUP;
        style |= WS_OVERLAPPEDWINDOW | WS_CAPTION;
        SetWindowLongW(handle, GWL_STYLE, style);
        SetWindowPlacement(handle, &placement);
        SetWindowPos(handle, 0, 0, 0, 0, 0,
                     SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_FRAMECHANGED);

        p->window_flags &= ~ZPL_WINDOW_FULLSCREEN;
    }
}

void zpl_platform_toggle_borderless(zpl_platform *p) {
    HWND handle = cast(HWND) p->window_handle;
    DWORD style = GetWindowLongW(handle, GWL_STYLE);
    b32 is_borderless = (style & WS_POPUP) != 0;

    ZPL_MASK_SET(style, is_borderless, WS_OVERLAPPEDWINDOW | WS_CAPTION);
    ZPL_MASK_SET(style, !is_borderless, WS_POPUP);

    SetWindowLongW(handle, GWL_STYLE, style);

    ZPL_MASK_SET(p->window_flags, !is_borderless, ZPL_WINDOW_BORDERLESS);
}

zpl_inline void zpl_platform_make_opengl_context_current(zpl_platform *p) {
    if (p->renderer_type == ZPL_RENDERER_OPENGL) { wglMakeCurrent(cast(HDC) p->win32_dc, cast(HGLRC) p->opengl.context); }
}

zpl_inline void zpl_platform_show_window(zpl_platform *p) {
    ShowWindow(cast(HWND) p->window_handle, SW_SHOW);
    p->window_flags &= ~ZPL_WINDOW_HIDDEN;
}

zpl_inline void zpl_platform_hide_window(zpl_platform *p) {
    ShowWindow(cast(HWND) p->window_handle, SW_HIDE);
    p->window_flags |= ZPL_WINDOW_HIDDEN;
}

zpl_inline zpl_video_mode zpl_video_mode_get_desktop(void) {
    DEVMODEW win32_mode = { zpl_size_of(win32_mode) };
    EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, &win32_mode);
    return zpl_set_video_mode(win32_mode.dmPelsWidth, win32_mode.dmPelsHeight, win32_mode.dmBitsPerPel);
}

isize zpl_video_mode_get_fullscreen_modes(zpl_video_mode *modes, isize max_mode_count) {
    DEVMODEW win32_mode = { zpl_size_of(win32_mode) };
    i32 count;
    for (count = 0; count < max_mode_count && EnumDisplaySettingsW(NULL, count, &win32_mode); count++) {
        modes[count] = zpl_set_video_mode(win32_mode.dmPelsWidth, win32_mode.dmPelsHeight, win32_mode.dmBitsPerPel);
    }

    zpl_sort_array(modes, count, zpl_video_mode_dsc_cmp);
    return count;
}

b32 zpl_platform_has_clipboard_text(zpl_platform *p) {
    b32 result = false;

    if (IsClipboardFormatAvailable(1 /*CF_TEXT*/) && OpenClipboard(cast(HWND) p->window_handle)) {
        HANDLE mem = GetClipboardData(1 /*CF_TEXT*/);
        if (mem) {
            char *str = cast(char *) GlobalLock(mem);
            if (str && str[0] != '\0') { result = true; }
            GlobalUnlock(mem);
        } else {
            return false;
        }

        CloseClipboard( );
    }

    return result;
}

// TODO(bill): Handle UTF-8
void zpl_platform_set_clipboard_text(zpl_platform *p, char const *str) {
    if (OpenClipboard(cast(HWND) p->window_handle)) {
        isize i, len = zpl_strlen(str) + 1;

        HANDLE mem = cast(HANDLE) GlobalAlloc(0x0002 /*GMEM_MOVEABLE*/, len);
        if (mem) {
            char *dst = cast(char *) GlobalLock(mem);
            if (dst) {
                for (i = 0; str[i]; i++) {
                    // TODO(bill): Does this cause a buffer overflow?
                    // NOTE(bill): Change \n to \r\n 'cause windows
                    if (str[i] == '\n' && (i == 0 || str[i - 1] != '\r')) { *dst++ = '\r'; }
                    *dst++ = str[i];
                }
                *dst = 0;
            }
            GlobalUnlock(mem);
        }

        EmptyClipboard( );
        if (!SetClipboardData(1 /*CF_TEXT*/, mem)) { return; }
        CloseClipboard( );
    }
}

// TODO(bill): Handle UTF-8
char *zpl_platform_get_clipboard_text(zpl_platform *p, zpl_allocator a) {
    char *text = NULL;

    if (IsClipboardFormatAvailable(1 /*CF_TEXT*/) && OpenClipboard(cast(HWND) p->window_handle)) {
        HANDLE mem = GetClipboardData(1 /*CF_TEXT*/);
        if (mem) {
            char *str = cast(char *) GlobalLock(mem);
            text = zpl_alloc_str(a, str);
            GlobalUnlock(mem);
        } else {
            return NULL;
        }

        CloseClipboard( );
    }

    return text;
}

u32  zpl_platform_get_scancode(zpl_platform *p, zplKeyType key) {
    u32 vk = p->keys[key];

    u32 scancode = MapVirtualKey(vk, MAPVK_VK_TO_CHAR);
    return scancode;
}

// TODO: Refactor OS X part
#if 0
#elif defined(ZPL_SYSTEM_OSX)

#include <CoreGraphics/CoreGraphics.h>
#include <objc/NSObjCRuntime.h>
#include <objc/message.h>
#include <objc/objc.h>

#if __LP64__ || (TARGET_OS_EMBEDDED && !TARGET_OS_IPHONE) || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
#define NSIntegerEncoding "q"
#define NSUIntegerEncoding "L"
#else
#define NSIntegerEncoding "i"
#define NSUIntegerEncoding "I"
#endif

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#else
typedef CGPoint NSPoint;
typedef CGSize NSSize;
typedef CGRect NSRect;

extern id NSApp;
extern id const NSDefaultRunLoopMode;
#endif

#if defined(__OBJC__) && __has_feature(objc_arc)
#error TODO(bill): Cannot compile as objective-c code just yet!
#endif

// ABI is a bit different between platforms
#ifdef __arm64__
#define abi_objc_msgSend_stret objc_msgSend
#else
#define abi_objc_msgSend_stret objc_msgSend_stret
#endif
#ifdef __i386__
#define abi_objc_msgSend_fpret objc_msgSend_fpret
#else
#define abi_objc_msgSend_fpret objc_msgSend
#endif

#define objc_msgSend_id ((id(*)(id, SEL))objc_msgSend)
#define objc_msgSend_void ((void (*)(id, SEL))objc_msgSend)
#define objc_msgSend_void_id ((void (*)(id, SEL, id))objc_msgSend)
#define objc_msgSend_void_bool ((void (*)(id, SEL, BOOL))objc_msgSend)
#define objc_msgSend_id_char_const ((id(*)(id, SEL, char const *))objc_msgSend)

zpl_internal NSUInteger zpl__osx_application_should_terminate(id self, SEL _sel, id sender) {
    // NOTE(bill): Do nothing
    return 0;
}

zpl_internal void zpl__osx_window_will_close(id self, SEL _sel, id notification) {
    NSUInteger value = true;
    object_setInstanceVariable(self, "closed", cast(void *) value);
}

zpl_internal void zpl__osx_window_did_become_key(id self, SEL _sel, id notification) {
    zpl_platform *p = NULL;
    object_getInstanceVariable(self, "zpl_platform", cast(void **) & p);
    if (p) {
        // TODO(bill):
    }
}

b32 zpl__platform_init(zpl_platform *p, char const *window_title, zpl_video_mode mode, zplRendererType type,
                      u32 window_flags) {
    if (p->is_initialized) { return true; }
    // Init Platform
    { // Initial OSX State
        Class appDelegateClass;
        b32 resultAddProtoc, resultAddMethod;
        id dgAlloc, dg, menubarAlloc, menubar;
        id appMenuItemAlloc, appMenuItem;
        id appMenuAlloc, appMenu;

#if defined(ARC_AVAILABLE)
#error TODO(bill): This code should be compiled as C for now
#else
        id poolAlloc = objc_msgSend_id(cast(id) objc_getClass("NSAutoreleasePool"), sel_registerName("alloc"));
        p->osx_autorelease_pool = objc_msgSend_id(poolAlloc, sel_registerName("init"));
#endif

        objc_msgSend_id(cast(id) objc_getClass("NSApplication"), sel_registerName("sharedApplication"));
        ((void (*)(id, SEL, NSInteger))objc_msgSend)(NSApp, sel_registerName("setActivationPolicy:"), 0);

        appDelegateClass = objc_allocateClassPair((Class)objc_getClass("NSObject"), "AppDelegate", 0);
        resultAddProtoc = class_addProtocol(appDelegateClass, objc_getProtocol("NSApplicationDelegate"));
        assert(resultAddProtoc);
        resultAddMethod = class_addMethod(appDelegateClass, sel_registerName("applicationShouldTerminate:"),
                                          cast(IMP) zpl__osx_application_should_terminate, NSUIntegerEncoding "@:@");
        assert(resultAddMethod);
        dgAlloc = objc_msgSend_id(cast(id) appDelegateClass, sel_registerName("alloc"));
        dg = objc_msgSend_id(dgAlloc, sel_registerName("init"));
#ifndef ARC_AVAILABLE
        objc_msgSend_void(dg, sel_registerName("autorelease"));
#endif

        objc_msgSend_void_id(NSApp, sel_registerName("setDelegate:"), dg);
        objc_msgSend_void(NSApp, sel_registerName("finishLaunching"));

        menubarAlloc = objc_msgSend_id(cast(id) objc_getClass("NSMenu"), sel_registerName("alloc"));
        menubar = objc_msgSend_id(menubarAlloc, sel_registerName("init"));
#ifndef ARC_AVAILABLE
        objc_msgSend_void(menubar, sel_registerName("autorelease"));
#endif

        appMenuItemAlloc = objc_msgSend_id(cast(id) objc_getClass("NSMenuItem"), sel_registerName("alloc"));
        appMenuItem = objc_msgSend_id(appMenuItemAlloc, sel_registerName("init"));
#ifndef ARC_AVAILABLE
        objc_msgSend_void(appMenuItem, sel_registerName("autorelease"));
#endif

        objc_msgSend_void_id(menubar, sel_registerName("addItem:"), appMenuItem);
        ((id(*)(id, SEL, id))objc_msgSend)(NSApp, sel_registerName("setMainMenu:"), menubar);

        appMenuAlloc = objc_msgSend_id(cast(id) objc_getClass("NSMenu"), sel_registerName("alloc"));
        appMenu = objc_msgSend_id(appMenuAlloc, sel_registerName("init"));
#ifndef ARC_AVAILABLE
        objc_msgSend_void(appMenu, sel_registerName("autorelease"));
#endif

        {
            id processInfo = objc_msgSend_id(cast(id) objc_getClass("NSProcessInfo"), sel_registerName("processInfo"));
            id appName = objc_msgSend_id(processInfo, sel_registerName("processName"));

            id quitTitlePrefixString = objc_msgSend_id_char_const(cast(id) objc_getClass("NSString"),
                                                                  sel_registerName("stringWithUTF8String:"), "Quit ");
            id quitTitle = ((id(*)(id, SEL, id))objc_msgSend)(quitTitlePrefixString,
                                                              sel_registerName("stringByAppendingString:"), appName);

            id quitMenuItemKey = objc_msgSend_id_char_const(cast(id) objc_getClass("NSString"),
                                                            sel_registerName("stringWithUTF8String:"), "q");
            id quitMenuItemAlloc = objc_msgSend_id(cast(id) objc_getClass("NSMenuItem"), sel_registerName("alloc"));
            id quitMenuItem = ((id(*)(id, SEL, id, SEL, id))objc_msgSend)(
                quitMenuItemAlloc, sel_registerName("initWithTitle:action:keyEquivalent:"), quitTitle,
                sel_registerName("terminate:"), quitMenuItemKey);
#ifndef ARC_AVAILABLE
            objc_msgSend_void(quitMenuItem, sel_registerName("autorelease"));
#endif

            objc_msgSend_void_id(appMenu, sel_registerName("addItem:"), quitMenuItem);
            objc_msgSend_void_id(appMenuItem, sel_registerName("setSubmenu:"), appMenu);
        }
    }

    { // Init Window
        NSRect rect = { { 0, 0 }, { cast(CGFloat) mode.width, cast(CGFloat) mode.height } };
        id windowAlloc, window, wdgAlloc, wdg, contentView, titleString;
        Class WindowDelegateClass;
        b32 resultAddProtoc, resultAddIvar, resultAddMethod;

        windowAlloc = objc_msgSend_id(cast(id) objc_getClass("NSWindow"), sel_registerName("alloc"));
        window = ((id(*)(id, SEL, NSRect, NSUInteger, NSUInteger, BOOL))objc_msgSend)(
            windowAlloc, sel_registerName("initWithContentRect:styleMask:backing:defer:"), rect, 15, 2, NO);
#ifndef ARC_AVAILABLE
        objc_msgSend_void(window, sel_registerName("autorelease"));
#endif

        // when we are not using ARC, than window will be added to autorelease pool
        // so if we close it by hand (pressing red button), we don't want it to be released for us
        // so it will be released by autorelease pool later
        objc_msgSend_void_bool(window, sel_registerName("setReleasedWhenClosed:"), NO);

        WindowDelegateClass = objc_allocateClassPair((Class)objc_getClass("NSObject"), "WindowDelegate", 0);
        resultAddProtoc = class_addProtocol(WindowDelegateClass, objc_getProtocol("NSWindowDelegate"));
        ZPL_ASSERT(resultAddProtoc);
        resultAddIvar = class_addIvar(WindowDelegateClass, "closed", zpl_size_of(NSUInteger),
                                      rint(log2(zpl_size_of(NSUInteger))), NSUIntegerEncoding);
        ZPL_ASSERT(resultAddIvar);
        resultAddIvar =
            class_addIvar(WindowDelegateClass, "zpl_platform", zpl_size_of(void *), rint(log2(zpl_size_of(void *))), "ˆv");
        ZPL_ASSERT(resultAddIvar);
        resultAddMethod = class_addMethod(WindowDelegateClass, sel_registerName("windowWillClose:"),
                                          cast(IMP) zpl__osx_window_will_close, "v@:@");
        ZPL_ASSERT(resultAddMethod);
        resultAddMethod = class_addMethod(WindowDelegateClass, sel_registerName("windowDidBecomeKey:"),
                                          cast(IMP) zpl__osx_window_did_become_key, "v@:@");
        ZPL_ASSERT(resultAddMethod);
        wdgAlloc = objc_msgSend_id(cast(id) WindowDelegateClass, sel_registerName("alloc"));
        wdg = objc_msgSend_id(wdgAlloc, sel_registerName("init"));
#ifndef ARC_AVAILABLE
        objc_msgSend_void(wdg, sel_registerName("autorelease"));
#endif

        objc_msgSend_void_id(window, sel_registerName("setDelegate:"), wdg);

        contentView = objc_msgSend_id(window, sel_registerName("contentView"));

        {
            NSPoint point = { 20, 20 };
            ((void (*)(id, SEL, NSPoint))objc_msgSend)(window, sel_registerName("cascadeTopLeftFromPoint:"), point);
        }

        titleString = objc_msgSend_id_char_const(cast(id) objc_getClass("NSString"),
                                                 sel_registerName("stringWithUTF8String:"), window_title);
        objc_msgSend_void_id(window, sel_registerName("setTitle:"), titleString);

        if (type == ZPL_RENDERER_OPENGL) {
            // TODO(bill): Make sure this works correctly
            u32 opengl_hex_version = (p->opengl.major << 12) | (p->opengl.minor << 8);
            u32 gl_attribs[] = { 8, 24, // NSOpenGLPFAColorSize, 24,
                                 11, 8, // NSOpenGLPFAAlphaSize, 8,
                                 5,     // NSOpenGLPFADoubleBuffer,
                                 73,    // NSOpenGLPFAAccelerated,
                                 // 72,                   // NSOpenGLPFANoRecovery,
                                 // 55, 1,                // NSOpenGLPFASampleBuffers, 1,
                                 // 56, 4,                // NSOpenGLPFASamples, 4,
                                 99, opengl_hex_version, // NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
                                 0 };

            id pixel_format_alloc, pixel_format;
            id opengl_context_alloc, opengl_context;

            pixel_format_alloc =
                objc_msgSend_id(cast(id) objc_getClass("NSOpenGLPixelFormat"), sel_registerName("alloc"));
            pixel_format = ((id(*)(id, SEL, const uint32_t *))objc_msgSend)(
                pixel_format_alloc, sel_registerName("initWithAttributes:"), gl_attribs);
#ifndef ARC_AVAILABLE
            objc_msgSend_void(pixel_format, sel_registerName("autorelease"));
#endif

            opengl_context_alloc =
                objc_msgSend_id(cast(id) objc_getClass("NSOpenGLContext"), sel_registerName("alloc"));
            opengl_context = ((id(*)(id, SEL, id, id))objc_msgSend)(
                opengl_context_alloc, sel_registerName("initWithFormat:shareContext:"), pixel_format, nil);
#ifndef ARC_AVAILABLE
            objc_msgSend_void(opengl_context, sel_registerName("autorelease"));
#endif

            objc_msgSend_void_id(opengl_context, sel_registerName("setView:"), contentView);
            objc_msgSend_void_id(window, sel_registerName("makeKeyAndOrderFront:"), window);
            objc_msgSend_void_bool(window, sel_registerName("setAcceptsMouseMovedEvents:"), YES);

            p->window_handle = cast(void *) window;
            p->opengl.context = cast(void *) opengl_context;
        } else {
            ZPL_PANIC("TODO(bill): Software rendering");
        }

        {
            id blackColor = objc_msgSend_id(cast(id) objc_getClass("NSColor"), sel_registerName("blackColor"));
            objc_msgSend_void_id(window, sel_registerName("setBackgroundColor:"), blackColor);
            objc_msgSend_void_bool(NSApp, sel_registerName("activateIgnoringOtherApps:"), YES);
        }
        object_setInstanceVariable(wdg, "zpl_platform", cast(void *) p);

        p->is_initialized = true;
    }

    return true;
}

// NOTE(bill): Software rendering
b32 zpl_platform_init_with_software(zpl_platform *p, char const *window_title, i32 width, i32 height, u32 window_flags) {
    ZPL_PANIC("TODO(bill): Software rendering in not yet implemented on OS X\n");
    return zpl__platform_init(p, window_title, zpl_set_video_mode(width, height, 32), ZPL_RENDERER_SOFTWARE, window_flags);
}
// NOTE(bill): OpenGL Rendering
b32 zpl_platform_init_with_opengl(zpl_platform *p, char const *window_title, i32 width, i32 height, u32 window_flags,
                                 i32 major, i32 minor, b32 core, b32 compatible) {

    p->opengl.major = major;
    p->opengl.minor = minor;
    p->opengl.core = core;
    p->opengl.compatible = compatible;
    return zpl__platform_init(p, window_title, zpl_set_video_mode(width, height, 32), ZPL_RENDERER_OPENGL, window_flags);
}

// NOTE(bill): Reverse engineering can be fun!!!
zpl_internal zplKeyType zpl__osx_from_key_code(u16 key_code) {
    switch (key_code) {
    default:
        return zplKey_Unknown;
    // NOTE(bill): WHO THE FUCK DESIGNED THIS VIRTUAL KEY CODE SYSTEM?!
    // THEY ARE FUCKING IDIOTS!
    case 0x1d: return zplKey_0;
    case 0x12: return zplKey_1;
    case 0x13: return zplKey_2;
    case 0x14: return zplKey_3;
    case 0x15: return zplKey_4;
    case 0x17: return zplKey_5;
    case 0x16: return zplKey_6;
    case 0x1a: return zplKey_7;
    case 0x1c: return zplKey_8;
    case 0x19: return zplKey_9;

    case 0x00: return zplKey_A;
    case 0x0b: return zplKey_B;
    case 0x08: return zplKey_C;
    case 0x02: return zplKey_D;
    case 0x0e: return zplKey_E;
    case 0x03: return zplKey_F;
    case 0x05: return zplKey_G;
    case 0x04: return zplKey_H;
    case 0x22: return zplKey_I;
    case 0x26: return zplKey_J;
    case 0x28: return zplKey_K;
    case 0x25: return zplKey_L;
    case 0x2e: return zplKey_M;
    case 0x2d: return zplKey_N;
    case 0x1f: return zplKey_O;
    case 0x23: return zplKey_P;
    case 0x0c: return zplKey_Q;
    case 0x0f: return zplKey_R;
    case 0x01: return zplKey_S;
    case 0x11: return zplKey_T;
    case 0x20: return zplKey_U;
    case 0x09: return zplKey_V;
    case 0x0d: return zplKey_W;
    case 0x07: return zplKey_X;
    case 0x10: return zplKey_Y;
    case 0x06: return zplKey_Z;

    case 0x21: return zplKey_Lbracket;
    case 0x1e: return zplKey_Rbracket;
    case 0x29: return zplKey_Semicolon;
    case 0x2b: return zplKey_Comma;
    case 0x2f: return zplKey_Period;
    case 0x27: return zplKey_Quote;
    case 0x2c: return zplKey_Slash;
    case 0x2a: return zplKey_Backslash;
    case 0x32: return zplKey_Grave;
    case 0x18: return zplKey_Equals;
    case 0x1b: return zplKey_Minus;
    case 0x31: return zplKey_Space;

    case 0x35:
        return zplKey_Escape; // Escape
    case 0x3b:
        return ZPL_KEY_LCONTROL; // Left Control
    case 0x38:
        return ZPL_KEY_LSHIFT; // Left Shift
    case 0x3a:
        return ZPL_KEY_LALT; // Left Alt
    case 0x37:
        return zplKey_Lsystem; // Left OS specific: window (Windows and Linux), apple/cmd (MacOS X), ...
    case 0x3e:
        return ZPL_KEY_RCONTROL; // Right Control
    case 0x3c:
        return ZPL_KEY_RSHIFT; // Right Shift
    case 0x3d:
        return ZPL_KEY_RALT; // Right Alt
    // case 0x37: return zplKey_Rsystem;      // Right OS specific: window (Windows and Linux), apple/cmd (MacOS X), ...
    case 0x6e:
        return zplKey_Menu; // Menu
    case 0x24:
        return zplKey_Return; // Return
    case 0x33:
        return zplKey_Backspace; // Backspace
    case 0x30:
        return zplKey_Tab; // Tabulation
    case 0x74:
        return zplKey_Pageup; // Page up
    case 0x79:
        return zplKey_Pagedown; // Page down
    case 0x77:
        return zplKey_End; // End
    case 0x73:
        return zplKey_Home; // Home
    case 0x72:
        return zplKey_Insert; // Insert
    case 0x75:
        return zplKey_Delete; // Delete
    case 0x45:
        return zplKey_Plus; // +
    case 0x4e:
        return zplKey_Subtract; // -
    case 0x43:
        return zplKey_Multiply; // *
    case 0x4b:
        return zplKey_Divide; // /
    case 0x7b:
        return zplKey_Left; // Left arrow
    case 0x7c:
        return zplKey_Right; // Right arrow
    case 0x7e:
        return zplKey_Up; // Up arrow
    case 0x7d:
        return zplKey_Down; // Down arrow
    case 0x52:
        return zplKey_Numpad0; // Numpad 0
    case 0x53:
        return zplKey_Numpad1; // Numpad 1
    case 0x54:
        return zplKey_Numpad2; // Numpad 2
    case 0x55:
        return zplKey_Numpad3; // Numpad 3
    case 0x56:
        return zplKey_Numpad4; // Numpad 4
    case 0x57:
        return zplKey_Numpad5; // Numpad 5
    case 0x58:
        return zplKey_Numpad6; // Numpad 6
    case 0x59:
        return zplKey_Numpad7; // Numpad 7
    case 0x5b:
        return zplKey_Numpad8; // Numpad 8
    case 0x5c:
        return zplKey_Numpad9; // Numpad 9
    case 0x41:
        return zplKey_NumpadDot; // Numpad .
    case 0x4c:
        return zplKey_NumpadEnter; // Numpad Enter
    case 0x7a:
        return zplKey_F1; // F1
    case 0x78:
        return zplKey_F2; // F2
    case 0x63:
        return zplKey_F3; // F3
    case 0x76:
        return zplKey_F4; // F4
    case 0x60:
        return zplKey_F5; // F5
    case 0x61:
        return zplKey_F6; // F6
    case 0x62:
        return zplKey_F7; // F7
    case 0x64:
        return zplKey_F8; // F8
    case 0x65:
        return zplKey_F9; // F8
    case 0x6d:
        return zplKey_F10; // F10
    case 0x67:
        return zplKey_F11; // F11
    case 0x6f:
        return zplKey_F12; // F12
    case 0x69:
        return zplKey_F13; // F13
    case 0x6b:
        return zplKey_F14; // F14
    case 0x71:
        return zplKey_F15; // F15
        // case : return zplKey_Pause;        // Pause // NOTE(bill): Not possible on OS X
    }
}

zpl_internal void zpl__osx_on_cocoa_event(zpl_platform *p, id event, id window) {
    if (!event) {
        return;
    } else if (objc_msgSend_id(window, sel_registerName("delegate"))) {
        NSUInteger event_type = ((NSUInteger(*)(id, SEL))objc_msgSend)(event, sel_registerName("type"));
        switch (event_type) {
        case 1:
            zpl_key_state_update(&p->mouse_buttons[zplMouseButton_Left], true);
            break; // NSLeftMouseDown
        case 2:
            zpl_key_state_update(&p->mouse_buttons[zplMouseButton_Left], false);
            break; // NSLeftMouseUp
        case 3:
            zpl_key_state_update(&p->mouse_buttons[zplMouseButton_Right], true);
            break; // NSRightMouseDown
        case 4:
            zpl_key_state_update(&p->mouse_buttons[zplMouseButton_Right], false);
            break; // NSRightMouseUp
        case 25: { // NSOtherMouseDown
            // TODO(bill): Test thoroughly
            NSInteger number = ((NSInteger(*)(id, SEL))objc_msgSend)(event, sel_registerName("buttonNumber"));
            if (number == 2) zpl_key_state_update(&p->mouse_buttons[zplMouseButton_Middle], true);
            if (number == 3) zpl_key_state_update(&p->mouse_buttons[zplMouseButton_X1], true);
            if (number == 4) zpl_key_state_update(&p->mouse_buttons[zplMouseButton_X2], true);
        } break;
        case 26: { // NSOtherMouseUp
            NSInteger number = ((NSInteger(*)(id, SEL))objc_msgSend)(event, sel_registerName("buttonNumber"));
            if (number == 2) zpl_key_state_update(&p->mouse_buttons[zplMouseButton_Middle], false);
            if (number == 3) zpl_key_state_update(&p->mouse_buttons[zplMouseButton_X1], false);
            if (number == 4) zpl_key_state_update(&p->mouse_buttons[zplMouseButton_X2], false);

        } break;

        // TODO(bill): Scroll wheel
        case 22: { // NSScrollWheel
            CGFloat dx = ((CGFloat(*)(id, SEL))abi_objc_msgSend_fpret)(event, sel_registerName("scrollingDeltaX"));
            CGFloat dy = ((CGFloat(*)(id, SEL))abi_objc_msgSend_fpret)(event, sel_registerName("scrollingDeltaY"));
            BOOL precision_scrolling =
                ((BOOL(*)(id, SEL))objc_msgSend)(event, sel_registerName("hasPreciseScrollingDeltas"));
            if (precision_scrolling) {
                dx *= 0.1f;
                dy *= 0.1f;
            }
            // TODO(bill): Handle sideways
            p->mouse_wheel_delta = dy;
            // p->mouse_wheel_dy = dy;
            // zpl_printf("%f %f\n", dx, dy);
        } break;

        case 12: { // NSFlagsChanged
#if 0
			// TODO(bill): Reverse engineer this properly
			NSUInteger modifiers = ((NSUInteger (*)(id, SEL))objc_msgSend)(event, sel_registerName("modifierFlags"));
			u32 upper_mask = (modifiers & 0xffff0000ul) >> 16;
			b32 shift   = (upper_mask & 0x02) != 0;
			b32 control = (upper_mask & 0x04) != 0;
			b32 alt     = (upper_mask & 0x08) != 0;
			b32 command = (upper_mask & 0x10) != 0;
#endif

            // zpl_printf("%u\n", keys.mask);
            // zpl_printf("%x\n", cast(u32)modifiers);
        } break;

        case 10: { // NSKeyDown
            u16 key_code;

            id input_text = objc_msgSend_id(event, sel_registerName("characters"));
            char const *input_text_utf8 =
                ((char const *(*)(id, SEL))objc_msgSend)(input_text, sel_registerName("UTF8String"));
            p->char_buffer_count = zpl_strnlen(input_text_utf8, zpl_size_of(p->char_buffer));
            zpl_memcopy(p->char_buffer, input_text_utf8, p->char_buffer_count);

            key_code = ((unsigned short (*)(id, SEL))objc_msgSend)(event, sel_registerName("keyCode"));
            zpl_key_state_update(&p->keys[zpl__osx_from_key_code(key_code)], true);
        } break;

        case 11: { // NSKeyUp
            u16 key_code = ((unsigned short (*)(id, SEL))objc_msgSend)(event, sel_registerName("keyCode"));
            zpl_key_state_update(&p->keys[zpl__osx_from_key_code(key_code)], false);
        } break;

        default: break;
        }

        objc_msgSend_void_id(NSApp, sel_registerName("sendEvent:"), event);
    }
}

void zpl_platform_update(zpl_platform *p) {
    id window, key_window, content_view;
    NSRect original_frame;

    window = cast(id) p->window_handle;
    key_window = objc_msgSend_id(NSApp, sel_registerName("keyWindow"));
    p->window_has_focus = key_window == window; // TODO(bill): Is this right

    if (p->window_has_focus) {
        isize i;
        p->char_buffer_count = 0; // TODO(bill): Reset buffer count here or else where?

        // NOTE(bill): Need to update as the keys only get updates on events
        for (i = 0; i < ZPL_KEY_COUNT; i++) {
            b32 is_down = (p->keys[i] & ZPL_KEY_STATE_DOWN) != 0;
            zpl_key_state_update(&p->keys[i], is_down);
        }

        for (i = 0; i < ZPL_MOUSEBUTTON_COUNT; i++) {
            b32 is_down = (p->mouse_buttons[i] & ZPL_KEY_STATE_DOWN) != 0;
            zpl_key_state_update(&p->mouse_buttons[i], is_down);
        }
    }

    { // Handle Events
        id distant_past = objc_msgSend_id(cast(id) objc_getClass("NSDate"), sel_registerName("distantPast"));
        id event = ((id(*)(id, SEL, NSUInteger, id, id, BOOL))objc_msgSend)(
            NSApp, sel_registerName("nextEventMatchingMask:untilDate:inMode:dequeue:"), NSUIntegerMax, distant_past,
            NSDefaultRunLoopMode, YES);
        zpl__osx_on_cocoa_event(p, event, window);
    }

    if (p->window_has_focus) {
        p->key_modifiers.control = p->keys[ZPL_KEY_LCONTROL] | p->keys[ZPL_KEY_RCONTROL];
        p->key_modifiers.alt = p->keys[ZPL_KEY_LALT] | p->keys[ZPL_KEY_RALT];
        p->key_modifiers.shift = p->keys[ZPL_KEY_LSHIFT] | p->keys[ZPL_KEY_RSHIFT];
    }

    { // Check if window is closed
        id wdg = objc_msgSend_id(window, sel_registerName("delegate"));
        if (!wdg) {
            p->window_is_closed = false;
        } else {
            NSUInteger value = 0;
            object_getInstanceVariable(wdg, "closed", cast(void **) & value);
            p->window_is_closed = (value != 0);
        }
    }

    content_view = objc_msgSend_id(window, sel_registerName("contentView"));
    original_frame = ((NSRect(*)(id, SEL))abi_objc_msgSend_stret)(content_view, sel_registerName("frame"));

    { // Window
        NSRect frame = original_frame;
        frame = ((NSRect(*)(id, SEL, NSRect))abi_objc_msgSend_stret)(content_view,
                                                                     sel_registerName("convertRectToBacking:"), frame);
        p->window_width = frame.size.width;
        p->window_height = frame.size.height;
        frame = ((NSRect(*)(id, SEL, NSRect))abi_objc_msgSend_stret)(window, sel_registerName("convertRectToScreen:"),
                                                                     frame);
        p->window_x = frame.origin.x;
        p->window_y = frame.origin.y;
    }

    { // Mouse
        NSRect frame = original_frame;
        NSPoint mouse_pos =
            ((NSPoint(*)(id, SEL))objc_msgSend)(window, sel_registerName("mouseLocationOutsideOfEventStream"));
        mouse_pos.x = zpl_clamp(mouse_pos.x, 0, frame.size.width - 1);
        mouse_pos.y = zpl_clamp(mouse_pos.y, 0, frame.size.height - 1);

        {
            i32 x = mouse_pos.x;
            i32 y = mouse_pos.y;
            p->mouse_dx = x - p->mouse_x;
            p->mouse_dy = y - p->mouse_y;
            p->mouse_x = x;
            p->mouse_y = y;
        }

        if (p->mouse_clip) {
            b32 update = false;
            i32 x = p->mouse_x;
            i32 y = p->mouse_y;
            if (p->mouse_x < 0) {
                x = 0;
                update = true;
            } else if (p->mouse_y > p->window_height - 1) {
                y = p->window_height - 1;
                update = true;
            }

            if (p->mouse_y < 0) {
                y = 0;
                update = true;
            } else if (p->mouse_x > p->window_width - 1) {
                x = p->window_width - 1;
                update = true;
            }

            if (update) { zpl_platform_set_mouse_position(p, x, y); }
        }
    }

    { // TODO(bill): Controllers
    }

    // TODO(bill): Is this in the correct place?
    objc_msgSend_void(NSApp, sel_registerName("updateWindows"));
    if (p->renderer_type == ZPL_RENDERER_OPENGL) {
        objc_msgSend_void(cast(id) p->opengl.context, sel_registerName("update"));
        zpl_platform_make_opengl_context_current(p);
    }
}

void zpl_platform_display(zpl_platform *p) {
    // TODO(bill): Do more
    if (p->renderer_type == ZPL_RENDERER_OPENGL) {
        zpl_platform_make_opengl_context_current(p);
        objc_msgSend_void(cast(id) p->opengl.context, sel_registerName("flushBuffer"));
    } else if (p->renderer_type == ZPL_RENDERER_SOFTWARE) {
        // TODO(bill):
    } else {
        ZPL_PANIC("Invalid window rendering type");
    }

    {
        f64 prev_time = p->curr_time;
        f64 curr_time = zpl_time_now( );
        p->dt_for_frame = curr_time - prev_time;
        p->curr_time = curr_time;
    }
}

void zpl_platform_destroy(zpl_platform *p) {
    zpl_platform_make_opengl_context_current(p);

    objc_msgSend_void(cast(id) p->window_handle, sel_registerName("close"));

#if defined(ARC_AVAILABLE)
// TODO(bill): autorelease pool
#else
    objc_msgSend_void(cast(id) p->osx_autorelease_pool, sel_registerName("drain"));
#endif
}

void zpl_platform_show_cursor(zpl_platform *p, b32 show) {
    if (show) {
        // objc_msgSend_void(class_registerName("NSCursor"), sel_registerName("unhide"));
    } else {
        // objc_msgSend_void(class_registerName("NSCursor"), sel_registerName("hide"));
    }
}

void zpl_platform_set_mouse_position(zpl_platform *p, i32 x, i32 y) {
    // TODO(bill):
    CGPoint pos = { cast(CGFloat) x, cast(CGFloat) y };
    pos.x += p->window_x;
    pos.y += p->window_y;
    CGWarpMouseCursorPosition(pos);
}

void zpl_platform_set_controller_vibration(zpl_platform *p, isize index, f32 left_motor, f32 right_motor) {
    // TODO(bill):
}

b32 zpl_platform_has_clipboard_text(zpl_platform *p) {
    // TODO(bill):
    return false;
}

void zpl_platform_set_clipboard_text(zpl_platform *p, char const *str) {
    // TODO(bill):
}

char *zpl_platform_get_clipboard_text(zpl_platform *p, zplAllocator a) {
    // TODO(bill):
    return NULL;
}

void zpl_platform_set_window_position(zpl_platform *p, i32 x, i32 y) {
    // TODO(bill):
}

void zpl_platform_set_window_title(zpl_platform *p, char const *title, ...) {
    id title_string;
    char buf[256] = { 0 };
    va_list va;
    va_start(va, title);
    zpl_snprintf_va(buf, zpl_count_of(buf), title, va);
    va_end(va);

    title_string =
        objc_msgSend_id_char_const(cast(id) objc_getClass("NSString"), sel_registerName("stringWithUTF8String:"), buf);
    objc_msgSend_void_id(cast(id) p->window_handle, sel_registerName("setTitle:"), title_string);
}

void zpl_platform_toggle_fullscreen(zpl_platform *p, b32 fullscreen_desktop) {
    // TODO(bill):
}

void zpl_platform_toggle_borderless(zpl_platform *p) {
    // TODO(bill):
}

void zpl_platform_make_opengl_context_current(zpl_platform *p) {
    objc_msgSend_void(cast(id) p->opengl.context, sel_registerName("makeCurrentContext"));
}

void zpl_platform_show_window(zpl_platform *p) {
    // TODO(bill):
}

void zpl_platform_hide_window(zpl_platform *p) {
    // TODO(bill):
}

i32 zpl__osx_mode_bits_per_pixel(CGDisplayModeRef mode) {
    i32 bits_per_pixel = 0;
    CFStringRef pixel_encoding = CGDisplayModeCopyPixelEncoding(mode);
    if (CFStringCompare(pixel_encoding, CFSTR(IO32BitDirectPixels), kCFCompareCaseInsensitive) == kCFCompareEqualTo) {
        bits_per_pixel = 32;
    } else if (CFStringCompare(pixel_encoding, CFSTR(IO16BitDirectPixels), kCFCompareCaseInsensitive) ==
               kCFCompareEqualTo) {
        bits_per_pixel = 16;
    } else if (CFStringCompare(pixel_encoding, CFSTR(IO8BitIndexedPixels), kCFCompareCaseInsensitive) ==
               kCFCompareEqualTo) {
        bits_per_pixel = 8;
    }
    CFRelease(pixel_encoding);

    return bits_per_pixel;
}

i32 zpl__osx_display_bits_per_pixel(CGDirectDisplayID display) {
    CGDisplayModeRef mode = CGDisplayCopyDisplayMode(display);
    i32 bits_per_pixel = zpl__osx_mode_bits_per_pixel(mode);
    CGDisplayModeRelease(mode);
    return bits_per_pixel;
}

zpl_video_mode zpl_video_mode_get_desktop(void) {
    CGDirectDisplayID display = CGMainDisplayID( );
    return zpl_set_video_mode(CGDisplayPixelsWide(display), CGDisplayPixelsHigh(display),
                         zpl__osx_display_bits_per_pixel(display));
}

isize zpl_video_mode_get_fullscreen_modes(zpl_video_mode *modes, isize max_mode_count) {
    CFArrayRef cg_modes = CGDisplayCopyAllDisplayModes(CGMainDisplayID( ), NULL);
    CFIndex i, count;
    if (cg_modes == NULL) { return 0; }

    count = zpl_min(CFArrayGetCount(cg_modes), max_mode_count);
    for (i = 0; i < count; i++) {
        CGDisplayModeRef cg_mode = cast(CGDisplayModeRef) CFArrayGetValueAtIndex(cg_modes, i);
        modes[i] = zpl_set_video_mode(CGDisplayModeGetWidth(cg_mode), CGDisplayModeGetHeight(cg_mode),
                                 zpl__osx_mode_bits_per_pixel(cg_mode));
    }

    CFRelease(cg_modes);

    zpl_sort_array(modes, count, zpl_video_mode_dsc_cmp);
    return cast(isize) count;
}

#endif
#endif // #if 0

// TODO(bill): OSX Platform Layer
// NOTE(bill): Use this as a guide so there is no need for Obj-C https://github.com/jimon/osx_app_in_plain_c

zpl_inline zpl_video_mode zpl_set_video_mode(i32 width, i32 height, i32 bits_per_pixel) {
    zpl_video_mode m;
    m.width = width;
    m.height = height;
    m.bits_per_pixel = bits_per_pixel;
    return m;
}

zpl_inline b32 zpl_video_mode_is_valid(zpl_video_mode mode) {
    zpl_local_persist zpl_video_mode modes[256] = { 0 };
    zpl_local_persist isize mode_count = 0;
    zpl_local_persist b32 is_set = false;
    isize i;

    if (!is_set) {
        mode_count = zpl_video_mode_get_fullscreen_modes(modes, zpl_count_of(modes));
        is_set = true;
    }

    for (i = 0; i < mode_count; i++) { zpl_printf("%d %d\n", modes[i].width, modes[i].height); }

    return zpl_binary_search_array(modes, mode_count, &mode, zpl_video_mode_cmp) >= 0;
}

ZPL_COMPARE_PROC(zpl_video_mode_cmp) {
    zpl_video_mode const *x = cast(zpl_video_mode const *) a;
    zpl_video_mode const *y = cast(zpl_video_mode const *) b;

    if (x->bits_per_pixel == y->bits_per_pixel) {
        if (x->width == y->width) { return x->height < y->height ? -1 : x->height > y->height; }
        return x->width < y->width ? -1 : x->width > y->width;
    }
    return x->bits_per_pixel < y->bits_per_pixel ? -1 : +1;
}

ZPL_COMPARE_PROC(zpl_video_mode_dsc_cmp) { return zpl_video_mode_cmp(b, a); }

#endif // defined(ZPL_PLATFORM)

//
// BOTTOM
//


#if defined(ZPL_COMPILER_MSVC)
#pragma warning(pop)
#endif

#if defined(__GCC__) || defined(__GNUC__)
#pragma GCC diagnostic pop
#endif


#if defined(__cplusplus)
}
#endif

#endif // ZPL_IMPLEMENTATION

///////////////////////////////////////////////////////////////
//
// Code Snippets
//

/*


#ifndef FOO_H
#define FOO_H

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#if defined(FOO_IMPLEMENTATION) && !defined(FOO_IMPLEMENTATION_DONE)
#define FOO_IMPLEMENTATION_DONE

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#endif // FOO_IMPLEMENTATION
#endif // FOO_H


 */
