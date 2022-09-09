#include <tree_node/helpers.h>
#include <algorithm>
namespace tree_node {
int compute_height_recurse(TreeNode* node, int height) {
  if (!node) {
    return height;
  }

  return std::max(compute_height_recurse(node->left, height + 1),
                  compute_height_recurse(node->right, height + 1));
}
int compute_height(TreeNode* node) {
  return compute_height_recurse(node, 0);
}
}  // namespace tree_node
