cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(rtgp CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXT_LIBS "")

option(USE_CCACHE "Use ccache compiler cache (https://ccache.dev)" ON)

find_package(Git QUIET)

set(CMAKE_BUILD_TYPE Debug)

if(USE_CCACHE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -C")
endif()


#include_directories(
#    "${CMAKE_SOURCE_DIR}/libs/sentencepiece/src"
#)


add_subdirectory(src)
