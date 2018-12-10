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


set(mods Tpf)
set(TpfComponents def tpf Id Prepend Append Tuplify)


add_executable(test
    src/foo_main.cpp
    src/sacl.cpp
#    test/Tpf.cpp
#    test/Tpf/test_def.cpp
#    test/Tpf/fixture/tpfs.cpp
    )
target_link_libraries(test PRIVATE _compile_options)
target_include_directories(test PRIVATE src)

foreach(mod IN LISTS mods)
    target_sources(test PRIVATE src/${mod}.cpp)

    set(comps ${${mod}Components})
    string(REPLACE ";" ", " sacls "${comps}")
    string(TOUPPER mod mod_upper)
    target_compile_definitions(test PRIVATE ${mod_upper}__SACLS=${sacls})

    foreach(comp IN LISTS comps)
        target_sources(test PRIVATE
            src/${mod}/${comp}.cpp
            test/${mod}/test_${comp}.cpp
            )
    endforeach()
endforeach()


### TMP
target_compile_definitions(test
    PRIVATE
        TPF__SACLS=Tpf::sacl::def
    )
