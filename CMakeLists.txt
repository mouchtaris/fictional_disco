# vim: et ts=4 sw=4
#
# Hello, user.
#
# Welcome to Aperture IT.
#

set(CMAKE_CXX_COMPILER /usr/bin/clang++)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(_compile_options INTERFACE)
target_compile_features(_compile_options INTERFACE cxx_std_20)
target_compile_options(_compile_options INTERFACE -Wall -Wextra -pedantic)
target_include_directories(_compile_options INTERFACE src)

add_library(lib)
target_link_libraries(lib PRIVATE _compile_options)
target_sources(lib PRIVATE src/lib.cpp)
add_executable(main)
target_link_libraries(main PRIVATE _compile_options)
target_sources(main PRIVATE src/main.cpp)
target_link_libraries(main PRIVATE lib)
add_executable(test)
target_link_libraries(test PRIVATE _compile_options)
target_sources(test PRIVATE test/main.cpp)
target_link_libraries(test PRIVATE lib)
target_sources(main PRIVATE src/Tpf.cpp)
target_sources(test PRIVATE test/test_Tpf.cpp)
target_compile_definitions(main PRIVATE TPF__SACLS="Append, Id, Prepend, return_, tpf, Tuplify")
target_sources(main PRIVATE src/Tpf/Append.cpp)
target_sources(test PRIVATE test/Tpf/test_Append.cpp)
target_sources(main PRIVATE src/Tpf/Id.cpp)
target_sources(test PRIVATE test/Tpf/test_Id.cpp)
target_sources(main PRIVATE src/Tpf/Prepend.cpp)
target_sources(test PRIVATE test/Tpf/test_Prepend.cpp)
target_sources(main PRIVATE src/Tpf/return_.cpp)
target_sources(test PRIVATE test/Tpf/test_return_.cpp)
target_sources(main PRIVATE src/Tpf/tpf.cpp)
target_sources(test PRIVATE test/Tpf/test_tpf.cpp)
target_sources(main PRIVATE src/Tpf/Tuplify.cpp)
target_sources(test PRIVATE test/Tpf/test_Tuplify.cpp)
