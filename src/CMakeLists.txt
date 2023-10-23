
add_library(libmymod mymod.hpp)
set_target_properties(libmymod PROPERTIES LINKER_LANGUAGE CXX)

add_executable(mymod main.cpp)  
set_target_properties(mymod PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(mymod PUBLIC libmymod)



if(SKBUILD)
  # Scikit-Build does not add your site-packages to the search path
  # automatically, so we need to add it _or_ the pybind11 specific directory
  # here.
  
  if(NOT PYTHON_EXECUTABLE)
    set(PYTHON_EXECUTABLE python)   # default to python in the environment
  endif()

  execute_process(
    COMMAND "${PYTHON_EXECUTABLE}" -c
            "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE _tmp_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
  list(APPEND CMAKE_PREFIX_PATH "${_tmp_dir}")

  # Now we can find pybind11
  find_package(pybind11 CONFIG REQUIRED)

  # TODO: FIXME: rename "_mymod" to "_your_module_name"
  pybind11_add_module(_mymod MODULE src/pybind.cpp)
  # here, "mymod" (the last arg) is the name of the C++ library target; TODO: rename this as well
  target_link_libraries(_mymod PUBLIC libmymod)   
  install(TARGETS _mymod DESTINATION .)
endif(SKBUILD)
