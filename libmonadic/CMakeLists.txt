cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(LIBMONADIC CXX)

# Set custom cmake scripts directory
set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${LIBMONADIC_SOURCE_DIR}/cmake")

# Add Dynamic Library Loader dependency, pthread, uuid (if UNIX-based)
if( ${MFW_CURRENT_SYSTEM} STREQUAL "LINUX" )
    set( DEPS "${DEPS};dl" )
    set( DEPS "${DEPS};pthread" )
    set( DEPS "${DEPS};uuid" )
endif()

# Lua
find_package( LuaJIT )
if( LUAJIT_FOUND )
message("Found LuaJIT")
include_directories( ${LUAJIT_INCLUDE_DIR} )
# TODO: Replace hardcoded lua lib linkage with automated one
set( DEPS "${DEPS};${LUAJIT_LIBRARIES}" )
endif()

# ZMQ
find_package( ZMQ )
if( ZMQ_FOUND )
message("Found ZeroMQ")
include_directories( ${ZMQ_INCLUDE_DIR} )
include_directories( ${MFW_SOURCE_DIR}/extdeps/cppzmq )
set( DEPS "${DEPS};${ZMQ_LIBRARY}" )
endif()

# Set include directories
include_directories( ${LIBMONADIC_SOURCE_DIR}/include )

file ( GLOB_RECURSE CORE_CPP ./src/*.cc )
set( LIBMONADIC_CPP ${CORE_CPP} )
if( ${MFW_CURRENT_SYSTEM} STREQUAL "WINDOWS" )
  add_library( monadic ${LIBMONADIC_CPP} )
else()
  add_library( monadic SHARED ${LIBMONADIC_CPP} )
endif()

# Link libraries
target_link_libraries( monadic ${DEPS} )
