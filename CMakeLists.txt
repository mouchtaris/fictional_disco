# vim: et ts=4 sw=4
cmake_minimum_required(VERSION 3.12.4)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic)

###
### Tpf
###
set( tpf_src
    "[
add_library( libtpf STATIC
    src/tpf.cpp
)
target_compile_definitions( libtpf
    INTERFACE
    _TPF__USING
    PRIVATE
        _TPF__BUILDING
        _MOD_BEGIN='namespace test {'
        _MOD_END='}'
)

###
### Binary Targets
###

#add_executable( panos
#    src/panos.cpp
#)
#target_link_libraries( panos
#    tpf
#)


##  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
##  set(CMAKE_CXX_COMPILER /usr/bin/g++)
##  # set(CMAKE_CXX_COMPILER /usr/bin/clang++)
##  
##  
##  # set_property(TARGET tgt PROPERTY CXX_STANDARD 11)
##  set(CMAKE_CXX_STANDARD 20)
##  
##  ###
##  # TPF
##  ###
##  # LibPanos
##  # add_library(libpanos STATIC
##  #     src/libpanos.cpp
##  #     src/ser.cpp
##  #     src/test_ser.cpp
##  # )
##  
##  ###
##  # Main
##  add_executable(panos 
##      src/panos.cpp
##      src/scafold_tokens.cpp
##      src/incubate.cpp
##  
##      src/smaragd/tpf.cpp
##      src/smaragd/tpf/bind.cpp
##  )
##  # libs
##  #target_link_libraries(panos libpanos)
##  
##  # includes
##  target_include_directories(panos
##      PRIVATE src/
##  )
##  #target_compile_definitions( libpanos
##  #	PRIVATE	HELLO_WHO="PRIVATE"
##  #	INTERFACE HELLO_WHO="INTER"
##  #)
##  target_compile_options(panos PRIVATE -Wall -Wextra -pedantic -std=c++1z)
##  #target_compile_options(hi -Wall -Wextra -pedantic -std=c++1z)
