cmake_minimum_required( VERSION 2.8 )

project( voltageClamp )

# -Wall specifies the warning level -g enables debugging and -pg profiling.
set(CMAKE_CXX_FLAGS "-Wall -g -pg")

add_subdirectory( libraries )
add_subdirectory( test )
