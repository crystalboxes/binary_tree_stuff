add_library(
  renderer
  STATIC
  include/renderer/renderer.h
  src/style.h
  src/render_context.h
  src/render_context.cc
  src/renderer.cc
  src/tree_renderer.h
  src/tree_renderer.cc
)

target_include_directories(renderer
  PUBLIC include
  PRIVATE src)

target_link_libraries(renderer PRIVATE cairo pixman png zlib tree_node window)
