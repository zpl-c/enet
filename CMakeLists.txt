cmake_minimum_required(VERSION 2.6)
project(enet)

if(MSVC)
	add_definitions(-W3)
else()
	add_definitions(-Wno-error)
endif()

if (NOT DEFINED ENET_ONLY_CONFIG)
    include_directories(${PROJECT_SOURCE_DIR}/include)
    set(INCLUDE_FILES include/enet.h)
    source_group(include FILES ${INCLUDE_FILES})

    add_library(enet STATIC
        ${INCLUDE_FILES}
        ${SOURCE_FILES}
    )

    if (MINGW)
        target_link_libraries(enet winmm ws2_32)
    endif()
endif()
