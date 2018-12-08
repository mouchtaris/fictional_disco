# vim: et ts=4 sw=4
#
# Hello, user.
#
# Welcome to Aperture IT.
#

cmake_minimum_required(VERSION 3.12)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(tpf)

add_executable(test
    test/main.cpp
    )
target_link_libraries(test PRIVATE Tpf_Test)
