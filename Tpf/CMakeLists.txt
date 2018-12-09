# vim: et ts=4 sw=4
#
# Hello, user.
#
# Welcome to Aperture IT.
#

cmake_minimum_required(VERSION 3.12)

add_library(Tpf STATIC
    src/Tpf/Append.cpp
    src/Tpf.cpp
    src/Tpf/def.cpp
    src/Tpf/Id.cpp
    src/Tpf/Id.cpp
    src/Tpf/Prepend.cpp
    src/Tpf/return_.cpp
    src/Tpf/tpf.cpp
    src/Tpf/Tuplify.cpp
)
target_include_directories(Tpf
    PUBLIC
        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        # $<INSTALL_INTERFACE:include>
        src
    )
target_link_libraries(Tpf
    PRIVATE
        _compile_options
    )

add_library(Tpf_Test STATIC
    test/test.cpp
    test/test_def.cpp
    test/fixture/tpfs.cpp
)
target_link_libraries(Tpf_Test
    PUBLIC
        Tpf
    PRIVATE
        _compile_options
    )

#install(
#    TARGETS
#        Tpf
#    EXPORT TpfTargets
#    LIBRARY DESTINATION lib
#    ARCHIVE DESTINATION lib
#    RUNTIME DESTINATION bin
#    INCLUDES DESTINATION include
#    )
#install(
#    EXPORT TpfTargets
#    FILE TpfConfig.cmake
#    NAMESPACE Tpf::
#    DESTINATION lib/cmake/Tpf
#    )
#export(EXPORT TpfTargets NAMESPACE Tpf::)
