cmake_minimum_required(VERSION 3.0)
project(enet C)

# defaults
option(ENET_STATIC ON)
option(ENET_SHARED OFF)
option(ENET_TEST OFF)

# configure projects
if (ENET_STATIC)
    add_library(enet STATIC test/library.c)

    if (WIN32)
        target_link_libraries(enet PUBLIC winmm ws2_32)
    endif()
endif()

if (ENET_SHARED)
    target_compile_definitions(enet PUBLIC -DENET_DLL)
    add_library(enet SHARED test/library.c)

    if (WIN32)
        target_link_libraries(enet PUBLIC winmm ws2_32)
    endif()
endif()

if (ENET_TEST)
    add_subdirectory(test)
endif()

if(MSVC)
    target_compile_options(enet PRIVATE -W3)
else()
    target_compile_options(enet PRIVATE -Wno-error)
endif()

target_include_directories(enet PUBLIC ${PROJECT_SOURCE_DIR}/include)