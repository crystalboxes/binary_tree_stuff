#include <string>
#include "tree_node.h"
class TreeNodeLoader {
 public:
  static TreeNode* from_string(const char*);
  static std::string to_string(TreeNode*);
};
