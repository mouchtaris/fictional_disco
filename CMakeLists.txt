cmake_minimum_required(VERSION 3.12)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
# set(CMAKE_CXX_COMPILER /usr/bin/clang++)


# set_property(TARGET tgt PROPERTY CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

###
# TPF
add_library(libtpf STATIC
    src/tpf/libtpf.cpp
#    tpf/select.cpp
#    tpf/find.cpp
#    tpf/bind.cpp
#    tpf/templ.cpp
#    tpf/cons.cpp
#    tpf/tupletools.cpp
#    tpf/comp.cpp
#    tpf/get.cpp
)

###
# LibPanos
add_library(libpanos STATIC
    src/libpanos.cpp
)

###
# Main
add_executable(panos 
    src/panos.cpp
)
# libs
target_link_libraries(panos libpanos)
target_link_libraries(panos libtpf)

# includes
target_include_directories(libpanos
    PRIVATE /tmp/lalala
)
target_compile_definitions( libpanos
	PRIVATE	HELLO_WHO="PRIVATE"
	INTERFACE HELLO_WHO="INTER"
)
#target_compile_options(libhi -Wall -Wextra -pedantic -std=c++1z)
#target_compile_options(hi -Wall -Wextra -pedantic -std=c++1z)
