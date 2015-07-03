cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(LIBMONADIC_TEST CXX)

# Set include directories
include_directories( ${MFW_SOURCE_DIR}/libmonadic/include )
include_directories( ${MFW_SOURCE_DIR}/extdeps/Catch/single_include )

set( DEPS "${DEPS};monadic" )

add_executable( core_test core_test.cc )

# Link libraries
target_link_libraries( core_test ${DEPS} )
