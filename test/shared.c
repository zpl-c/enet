/* Links against the enet shared library instead of compiling enet in, the way
 * an application using the prebuilt release binaries would. This checks that
 * the library exports its API and, on Windows, that its import library links. */
#include "enet.h"
#include <stdio.h>

int main(void) {
    ENetVersion version;

    if (enet_initialize() != 0) {
        printf("An error occurred while initializing ENet.\n");
        return 1;
    }

    version = enet_linked_version();
    enet_deinitialize();

    if (version != (ENetVersion) ENET_VERSION) {
        printf("Linked ENet version does not match the header.\n");
        return 1;
    }

    printf("Linked against shared ENet %u.%u.%u.\n",
        ENET_VERSION_GET_MAJOR(version),
        ENET_VERSION_GET_MINOR(version),
        ENET_VERSION_GET_PATCH(version));

    return 0;
}
