cmake_minimum_required(VERSION 2.6)
project(enet)

if(MSVC)
	add_definitions(-W3)
else()
	add_definitions(-Wno-error)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

if (DEFINED ENET_STATIC)
    add_definitions(-DENET_IMPLEMENTATION)
    add_library(enet_static STATIC include/enet.h)

    if (WIN32)
        target_link_libraries(enet_static winmm ws2_32)
    endif()
endif()

if (DEFINED ENET_SHARED)
    add_definitions(-DENET_IMPLEMENTATION -DENET_DLL)
    add_library(enet STATIC include/enet.h)

    if (WIN32)
        target_link_libraries(enet winmm ws2_32)
    endif()
endif()

if (DEFINED ENET_TEST)
    add_definitions(-DENET_IMPLEMENTATION)
    add_executable(enet_test tes/build.c)

    if (WIN32)
        target_link_libraries(enet_test winmm ws2_32)
    endif()
endif()
