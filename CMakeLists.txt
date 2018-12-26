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
target_compile_options(_compile_options INTERFACE -Wall -Wextra -pedantic -O0 -g)
target_include_directories(_compile_options INTERFACE src)

#add_library(Tpf)
#target_link_libraries(Tpf PRIVATE _compile_options)
#target_compile_definitions(Tpf PRIVATE Tpf__sacls=Tpf::_Append::sacl,Tpf::_Id::sacl,Tpf::_Prepend::sacl,Tpf::_return_::sacl,Tpf::_tpf::sacl,Tpf::_Tuplify::sacl)
#target_sources(Tpf PRIVATE src/Tpf.cpp)
#target_sources(Tpf PRIVATE src/Tpf/Append.cpp)
#target_sources(Tpf PRIVATE src/Tpf/Id.cpp)
#target_sources(Tpf PRIVATE src/Tpf/Prepend.cpp)
#target_sources(Tpf PRIVATE src/Tpf/return_.cpp)
#target_sources(Tpf PRIVATE src/Tpf/tpf.cpp)
#target_sources(Tpf PRIVATE src/Tpf/Tuplify.cpp)

add_library(typelite)
target_link_libraries(typelite PRIVATE _compile_options)
target_compile_definitions(typelite PRIVATE typelite__sacls=typelite::tag::sacl,typelite::_Ghost::sacl)
target_sources(typelite PRIVATE src/typelite/tag.cpp)
target_sources(typelite PRIVATE src/typelite/Ghost.cpp)
target_sources(typelite PRIVATE src/typelite.cpp)

add_library(lr1)
target_link_libraries(lr1 PRIVATE _compile_options)
target_compile_definitions(lr1 PRIVATE lr1__sacls=)
target_sources(lr1 PRIVATE src/lr1.cpp)

add_library(smaragd)
target_link_libraries(smaragd PRIVATE _compile_options)
target_compile_definitions(smaragd PRIVATE smaragd__sacls=)
target_link_libraries(smaragd PRIVATE lr1)
target_sources(smaragd PRIVATE src/smaragd.cpp)

add_executable(main)
target_link_libraries(main PRIVATE _compile_options)
#target_link_libraries(main PRIVATE Tpf)
target_link_libraries(main PRIVATE typelite)
target_link_libraries(main PRIVATE lr1)
target_link_libraries(main PRIVATE smaragd)
target_sources(main PRIVATE src/main.cpp)
