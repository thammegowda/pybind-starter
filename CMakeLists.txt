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

#############

# Any other libs
#include_directories("${CMAKE_SOURCE_DIR}/libs/<name/include")

add_subdirectory(src)


############ pybind11 stuff
# Find Python
#find_package(Python REQUIRED COMPONENTS Development)
# add pybind11 to CMAKE_PREFIX_PATH
if(NOT PYTHON_EXECUTABLE)
  set(PYTHON_EXECUTABLE python)   # default to python in the environment
endif()

execute_process(
  COMMAND "${PYTHON_EXECUTABLE}" -c "import pybind11; print(pybind11.get_cmake_dir())"
  OUTPUT_VARIABLE PYBIND11_CMAKE_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
list(APPEND CMAKE_PREFIX_PATH "${PYBIND11_CMAKE_DIR}")


# Now we can find pybind11
find_package(pybind11 CONFIG REQUIRED)
################


# TODO: FIXME: rename "_mymod" to "_your_module_name"
pybind11_add_module(_mymod MODULE python/binding.cpp)
# here, "mymod" (the last arg) is the name of the C++ library target; TODO: rename this as well
target_link_libraries(_mymod PUBLIC libmymod)   
install(TARGETS _mymod DESTINATION .)
#############


