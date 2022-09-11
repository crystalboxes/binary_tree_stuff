#include <renderer/renderer.h>
#include <tree_node/helpers.h>
#include <tree_node/loader.h>
#include <iostream>

int main() {
  auto a = new TreeNode(2);
  a->left = new TreeNode(1);
  a->right = new TreeNode(33);
  a->right->left = new TreeNode(25);
  a->right->right = new TreeNode(40);
  a->right->right->left = new TreeNode(34);
  a->right->right->left->right = new TreeNode(36);
  a->right->left->left = new TreeNode(11);
  a->right->left->left->left = new TreeNode(7);
  a->right->left->left->right = new TreeNode(12);
  a->right->left->left->right->right = new TreeNode(13);

  std::string serialized = TreeNodeLoader::to_string(a);
  std::cout << serialized << "\n";

  auto node = TreeNodeLoader::from_string(serialized.c_str());

  std::cout << tree_node::compute_height(node) << "\n";

  renderer::render_tree_node(node, "test.png");
  renderer::render_to_window(node);

  return 0;
}
