# vim: et ts=4 sw=4
#
# Hello, user.
#
# Welcome to Aperture IT.
#

cmake_minimum_required(VERSION 3.12)

add_library(Tpf STATIC
    src/Tpf/def.cpp
)
target_include_directories(Tpf
    PUBLIC
        src/
    )

add_library(Tpf_Test STATIC
    test/test.cpp
    test/test_def.cpp
    test/fixture/tpfs.cpp
)
target_link_libraries(Tpf_Test
    PUBLIC
        Tpf
        _compile_options
    )
