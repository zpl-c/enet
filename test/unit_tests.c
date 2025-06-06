#include <stdio.h>

#define ENET_UNIT_IMPLEMENTATION
#define ENET_IMPLEMENTATION

#include "enet.h"
#include "units/enet_unit.h"

int main() {
    if (enet_initialize() != 0) {
        printf("An error occurred while initializing ENet.\n");
        return 1;
    }

    int failed = run_all_tests();

    enet_deinitialize();

    return failed;
}
