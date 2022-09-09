add_library(
  tree_node
  STATIC
  include/tree_node/tree_node.h
  include/tree_node/loader.h
  include/tree_node/helpers.h
  src/helpers.cc
  src/linked_list.h
  src/linked_list.cc
  src/tree_deserializer.cc
  src/tree_deserializer.h
  src/tree_node.cc
  src/loader.cc
)

target_include_directories(tree_node
  PUBLIC include
  PRIVATE src)

target_compile_features(tree_node PUBLIC cxx_std_17)
