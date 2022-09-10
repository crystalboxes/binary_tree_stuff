cmake_minimum_required(VERSION 3.12)

project(leetcode)

add_subdirectory(external)

if(EMSCRIPTEN)
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    message("debug mode")
    add_link_options(-g -gsource-map --source-map-base http://localhost:3000/embuild/src/app/)
  endif(CMAKE_BUILD_TYPE MATCHES "Debug")

  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3")
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

add_subdirectory(src)
