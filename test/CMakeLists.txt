cmake_minimum_required(VERSION 3.0)
project(enet_test C)

add_executable(enet_test build.c)

target_link_libraries(enet_test PRIVATE enet)
target_include_directories(enet_test PRIVATE enet)

if(MSVC)
    target_compile_options(enet_test PRIVATE -W3)
else()
    target_compile_options(enet_test PRIVATE -Wno-error)
endif()