cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(LIBMONADIC_TEST CXX)

# Set include directories
include_directories( ${MFW_SOURCE_DIR}/libmonadic/include )
include_directories( ${MFW_SOURCE_DIR}/extdeps/Catch/single_include )
include_directories( ${MFW_SOURCE_DIR}/extdeps/cereal/include )

set( DEPS "${DEPS};monadic" )

add_executable( core_test core_test.cc )
add_executable( cereal_test cereal_test.cc obj.cc dobj.cc )
add_executable( binaryserialization_test binaryserialization_test.cc )

# Link libraries
target_link_libraries( core_test ${DEPS} )
target_link_libraries( cereal_test ${DEPS} )
target_link_libraries( binaryserialization_test ${DEPS} )
