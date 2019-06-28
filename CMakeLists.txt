cmake_minimum_required(VERSION 2.6)
project(enet C)

if(MSVC)
	add_definitions(-W3)
else()
	add_definitions(-Wno-error)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

if (ENET_STATIC)
    add_library(enet_static STATIC test/library.c)

    if (WIN32)
        target_link_libraries(enet_static winmm ws2_32)
    endif()
endif()

if (ENET_SHARED)
    add_definitions(-DENET_DLL)
    add_library(enet SHARED test/library.c)

    if (WIN32)
        target_link_libraries(enet winmm ws2_32)
    endif()
endif()

if (ENET_TEST)
    add_executable(enet_test test/build.c)

    if (WIN32)
        target_link_libraries(enet_test winmm ws2_32)
    endif()
endif()
