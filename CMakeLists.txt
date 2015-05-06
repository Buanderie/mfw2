cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(MFW)

option(BUILD_UNIT_TESTS "Build Unit tests" ON)
option(BUILD_TEST_APPS "Build Test Applications" ON)

# Handle platform specifics
if ( "${CMAKE_SYSTEM_NAME}" MATCHES "Windows" )
	SET( MFW_CURRENT_SYSTEM "WINDOWS" )
    ADD_DEFINITIONS( -D__WINDOWS__ )
elseif( "${CMAKE_SYSTEM_NAME}" MATCHES "Linux" )
	SET( MFW_CURRENT_SYSTEM "LINUX" )
    ADD_DEFINITIONS( -D__LINUX__ )
elseif( "${CMAKE_SYSTEM_NAME}" MATCHES "Darwin" )
	SET( MFW_CURRENT_SYSTEM "MACOSX" )
    ADD_DEFINITIONS( -D__MACOSX__ )
endif()

## CHECK FOR COMPILER CAPABILITIES
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
message( STATUS ${COMPILER_SUPPORTS_CXX0X} )
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
##

add_subdirectory(libmonadic)
add_subdirectory(test)
#add_subdirectory(kernels)
#add_subdirectory(mfwedit)

#if( BUILD_TEST_APPS )
#    add_subdirectory( test )
#endif( BUILD_TEST_APPS )
