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

add_library(Tpf)
target_link_libraries(Tpf PRIVATE _compile_options)
target_compile_definitions(Tpf PRIVATE TPF__SACLS=Tpf::sacl::Append,Tpf::sacl::Id,Tpf::sacl::Prepend,Tpf::sacl::return_,Tpf::sacl::tpf,Tpf::sacl::Tuplify)
target_sources(Tpf PRIVATE src/Tpf.cpp)
target_sources(Tpf PRIVATE src/Tpf/Append.cpp)
target_sources(Tpf PRIVATE src/Tpf/Id.cpp)
target_sources(Tpf PRIVATE src/Tpf/Prepend.cpp)
target_sources(Tpf PRIVATE src/Tpf/return_.cpp)
target_sources(Tpf PRIVATE src/Tpf/tpf.cpp)
target_sources(Tpf PRIVATE src/Tpf/Tuplify.cpp)

add_library(typelite)
target_link_libraries(typelite PRIVATE _compile_options)
target_sources(typelite PRIVATE src/typelite/tag.cpp)

add_executable(main)
target_link_libraries(main PRIVATE _compile_options)
target_link_libraries(main PRIVATE Tpf)
target_link_libraries(main PRIVATE typelite)
target_sources(main PRIVATE src/main.cpp)
