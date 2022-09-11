#pragma once
#include <sstream>
#include "tree_node.h"

class Codec {
 public:
  std::string serialize(TreeNode* root);
  TreeNode* deserialize(std::string data);
};
