# vim: et ts=4 sw=4
cmake_minimum_required(VERSION 3.12.4)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic)

###
### Binary Targets
###
add_library( tpf STATIC
    src/tpf/__module.cpp
    src/tpf/tpf.cpp
    test/tpf/test_tpf.cpp
)

add_executable( panos
    src/panos.cpp
)
target_link_libraries( panos
    tpf
)

add_library( test STATIC
    test/test.cpp
)
target_include_directories( test
    PUBLIC test
)


###
### Build specification and Usage Requirements
###
target_compile_definitions(tpf
    PRIVATE	_TPF__BUILDING
    INTERFACE _TPF__USING
)
include_directories( AFTER
    src
)


##  set(CMAKE_INCLUDE_CURRENT_DIR ON)
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
