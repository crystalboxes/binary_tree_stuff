#include <tree_node/codec.h>
#include <tree_node/loader.h>

TreeNode* TreeNodeLoader::from_string(const char* in_string) {
  Codec x;
  return x.deserialize(in_string);
}
