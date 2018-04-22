#define ZPL_IMPLEMENTATION
#include <zpl.h>

typedef struct {
    u64 a,b,c;
} test_e1;

enum {
    TEST_E1,
};

ZPL_EVENT(test_e1_v1) {
    ZPL_EVENT_CAST(test_e1, data);

    zpl_printf("a: %lu b: %lu c: %lu\n", data->a, data->b, data->c);
};

ZPL_EVENT(test_e1_v2) {
    ZPL_EVENT_CAST(test_e1, data);

    zpl_printf("a -- %lu b -- %lu c -- %lu\n", data->a, data->b, data->c);
};
ZPL_EVENT(test_e1_v3) {
    ZPL_EVENT_CAST(test_e1, data);

    zpl_printf("a> %lu b> %lu c> %lu\n", data->a, data->b, data->c);
};

int
main(void) {

    zpl_event_pool events;
    zpl_event_init(&events, zpl_heap_allocator());

    zpl_event_add(&events, TEST_E1, test_e1_v1); // 0
    zpl_event_add(&events, TEST_E1, test_e1_v2); // 1
    zpl_event_add(&events, TEST_E1, test_e1_v3); // 2


    test_e1 cb_data = {1, 2, 3};
    zpl_event_trigger(&events, TEST_E1, &cb_data);

    zpl_event_remove(&events, TEST_E1, 1);
    zpl_printf("After deletion of ID 1\n");

    // NOTE(ZaKlaus): Prints 0,2
    zpl_event_trigger(&events, TEST_E1, &cb_data);

    zpl_event_destroy(&events);

    return 0;
}
