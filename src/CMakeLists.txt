

add_library(libmymod STATIC mymod.hpp)
set_target_properties(libmymod PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(libmymod PUBLIC ${CMAKE_PREFIX_PATH} )

add_executable(mymod main.cpp)  
set_target_properties(mymod PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(mymod PUBLIC libmymod)

