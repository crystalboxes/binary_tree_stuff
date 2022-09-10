cmake_minimum_required(VERSION 3.12)

project(binary_tree_stuff)

add_subdirectory(external)

if(EMSCRIPTEN)
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    message("debug mode")
    
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s ASSERTIONS=2 -s SAFE_HEAP=1 -s STACK_OVERFLOW_CHECK=1")
    add_link_options(-g)
  else()
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O2")
  endif(CMAKE_BUILD_TYPE MATCHES "Debug")

  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s EMULATE_FUNCTION_POINTER_CASTS=1")
  set(CMAKE_EXECUTABLE_SUFFIX ".html")

endif()

add_subdirectory(src)
