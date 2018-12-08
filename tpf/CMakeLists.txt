# vim: et ts=4 sw=4
#
# Hello, user.
#
# Welcome to Aperture IT.
#

cmake_minimum_required(VERSION 3.12)

set(Module Tpf)

add_library(${Module}_Lib STATIC
    src/def.cpp
)
target_include_directories(${Module}_Lib
    PUBLIC
        /tmp/shala
    )

add_library(${Module}_Test STATIC
    test/test.cpp
    test/test_def.cpp
)
target_link_libraries(${Module}_Test
    PUBLIC
        ${Module}_Lib
    )

###
### TMP
###
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_definitions(
    __MODULE__=tpf
)
###
### // TMP
###
