add_library(window STATIC
  src/gl_app.cc
  src/gl_app.h
  src/window.cc
  src/glfw_instance.cc
  src/glfw_instance.h
  include/window/window.h)
target_include_directories(window PUBLIC include PRIVATE src)
target_link_libraries(window PRIVATE glad glfw)
