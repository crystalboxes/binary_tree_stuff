#include <tree_node/etc.h>
#include <functional>

namespace tree_node {
std::vector<int> inorder(TreeNode* node) {
  std::function<void(TreeNode*, std::vector<int>&)> h =
      [&](TreeNode* node, std::vector<int>& arr) {
        if (!node) {
          return;
        }
        h(node->left, arr);
        arr.push_back(node->val);
        h(node->right, arr);
      };

  std::vector<int> arr;
  h(node, arr);
  return arr;
}

TreeNode* predecessor(TreeNode* node) {
  node = node->left;
  while (node->right != nullptr) {
    node = node->right;
  }
  return node;
}

TreeNode* successor(TreeNode* node) {
  node = node->right;
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}
}  // namespace tree_node
