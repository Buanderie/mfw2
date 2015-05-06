cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(LIBMONADIC_TEST CXX)

# Set include directories
include_directories( ${MFW_SOURCE_DIR}/libmonadic/include )
include_directories( ${MFW_SOURCE_DIR}/extdeps/picotest )

set( DEPS "${DEPS};monadic" )

add_executable( monadic_test test.cc )

# Link libraries
target_link_libraries( monadic_test ${DEPS} )
