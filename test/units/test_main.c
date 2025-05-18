#include <stdio.h>

#include "enet.h"
#include "enet_unit.h"
#include "test_times.c"

int main() {
    if (enet_initialize() != 0) {
        printf("An error occurred while initializing ENet.\n");
        return 1;
    }

    int failed = run_all_tests();

    enet_deinitialize();

    return failed;
}
