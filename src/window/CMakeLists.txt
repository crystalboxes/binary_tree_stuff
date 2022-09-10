add_library(window STATIC
  src/gl_app.cc
  src/gl_app.h
  src/gl.h
  src/window.cc
  src/glfw_instance.cc
  src/glfw_instance.h
  include/window/window.h)
target_include_directories(window PUBLIC include PRIVATE src)

if(EMSCRIPTEN)
  target_compile_options(window PUBLIC -s USE_GLFW=3)
else()
  target_link_libraries(window PRIVATE glad glfw)
endif()

target_compile_features(window PUBLIC cxx_std_17)
