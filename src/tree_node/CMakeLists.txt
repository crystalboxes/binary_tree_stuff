add_library(
  tree_node
  STATIC
  include/tree_node/tree_node.h
  include/tree_node/loader.h
  include/tree_node/etc.h
  include/tree_node/helpers.h
  include/tree_node/codec.h
  src/helpers.cc
  src/tree_node.cc
  src/loader.cc
  src/etc.cc
  src/codec.cc
)

target_include_directories(tree_node
  PUBLIC include
  PRIVATE src)

target_compile_features(tree_node PUBLIC cxx_std_17)
