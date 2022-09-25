#include <tree_node/tree_node.h>
#include <vector>

namespace tree_node {
std::vector<int> inorder(TreeNode* node);
TreeNode* predecessor(TreeNode* node);
TreeNode* successor(TreeNode* node);
}  // namespace tree_node
