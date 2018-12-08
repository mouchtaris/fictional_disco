# vim: et ts=4 sw=4
#
# Hello, user.
#
# Welcome to Aperture IT.
#

###
### TMP
###
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.12)
add_compile_definitions(
    __MODULE__=tpf
)
###
### // TMP
###




set( src
    "src/def.cpp"
)

add_library( lib STATIC ${src} )


set( test_src
    "test/test.cpp"
    "test/test_def.cpp"
    "test/main.cpp"
)

add_executable(test ${test_src})
target_link_libraries(test lib)
target_include_directories(test PRIVATE src)

