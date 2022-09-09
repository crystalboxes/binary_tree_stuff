#include <tree_node/loader.h>
#include "tree_deserializer.h"

TreeNode* TreeNodeLoader::from_string(const char* in_string) {
  TreeSerializer x(in_string);
  return x.deserialize();
}
