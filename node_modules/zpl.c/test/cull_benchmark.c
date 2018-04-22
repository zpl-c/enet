#define ZPL_IMPLEMENTATION
#include "zpl.h"

#define ZPLM_IMPLEMENTATION
#include "zpl_math.h"

#define ZPLC_IMPLEMENTATION
#include "zpl_cull.h"

int
main(void) {
    zplc_bounds b = {0};

    b.centre = zplm_vec3f(0, 0, 0);
    b.half_size = zplm_vec3f(5000, 5000, 5000);

    zplc root = {0};
    zplc_init(&root, zpl_heap_allocator(), ZPLC_DIM_3D, b, zplm_vec3f(0,0,0), 32);
    zplc_bounds search_bounds = {
        .centre = {0,0,0},
        .half_size = {250,250,250},
    };

    isize start = zpl_utc_time_now();
    srand(0xDEADBEEF);
    for (isize i = 0; i < 4000000; ++i) {

        zplc_node e = {0};
        e.position.x =  (float)(2000 - rand() % 4000);
        e.position.y =  (float)(2000 - rand() % 4000);
        zplc_insert(&root, e);
    }
    isize insertion = zpl_utc_time_now() - start;


    zpl_array(zplc_node) search_result2;
    zpl_array_init(search_result2, zpl_heap_allocator());

    start = zpl_utc_time_now();
    zplc_query(&root, search_bounds, &search_result2);
    isize query = zpl_utc_time_now() - start;
    isize c = zpl_array_count(search_result2);
    printf("Insertion: %f ms.\n Query: %f ms. %ld", insertion/1000.0f, query/1000.0f, c);


    return 0;
}
