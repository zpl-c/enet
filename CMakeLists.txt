cmake_minimum_required(VERSION 3.0)
project(enet C)

# configure projects
if (ENET_STATIC)
    add_library(enet_static STATIC test/library.c)

    if (WIN32)
        target_link_libraries(enet_static PUBLIC winmm ws2_32)

        if(MSVC)
            target_compile_options(enet_static PRIVATE -W3)
        endif()
    else()
        target_compile_options(enet_static PRIVATE -Wno-error)
    endif()

    target_include_directories(enet_static PUBLIC ${PROJECT_SOURCE_DIR}/include)
endif()

if (ENET_SHARED)
    add_library(enet_shared SHARED test/library.c)
    target_compile_definitions(enet_shared PUBLIC -DENET_DLL)

    if (WIN32)
        target_link_libraries(enet_shared PUBLIC winmm ws2_32)

        if(MSVC)
            target_compile_options(enet_shared PRIVATE -W3)
        endif()
    else()
        target_compile_options(enet_shared PRIVATE -Wno-error)
    endif()

    target_include_directories(enet_shared PUBLIC ${PROJECT_SOURCE_DIR}/include)
endif()

if (ENET_TEST)
    add_executable(enet_test test/build.c)
    target_include_directories(enet_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

    if (WIN32)
        target_link_libraries(enet_test PUBLIC winmm ws2_32)
    endif()
endif()

