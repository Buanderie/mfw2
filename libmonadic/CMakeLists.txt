cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(LIBMONADIC CXX)

# Set custom cmake scripts directory
set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${LIBMONADIC_SOURCE_DIR}/cmake")

# Add Dynamic Library Loader dependency, pthread, uuid (if UNIX-based)
if( ${MFW_CURRENT_SYSTEM} STREQUAL "LINUX" )
    set( DEPS "${DEPS};dl" )
    set( DEPS "${DEPS};pthread" )
    set( DEPS "${DEPS};uuid" )
endif()

# Set include directories
include_directories( ${LIBMONADIC_SOURCE_DIR}/include )

file ( GLOB_RECURSE CORE_CPP ./src/*.cc )
set( LIBMONADIC_CPP ${CORE_CPP} )
message( ${LIBMONADIC_CPP} )
if( ${MFW_CURRENT_SYSTEM} STREQUAL "WINDOWS" )
  add_library( monadic ${LIBMONADIC_CPP} )
else()
  add_library( monadic SHARED ${LIBMONADIC_CPP} )
endif()

# Link libraries
target_link_libraries( monadic ${DEPS} )
