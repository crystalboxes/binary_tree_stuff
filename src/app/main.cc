#include <renderer/renderer.h>
#include <tree_node/etc.h>
#include <tree_node/helpers.h>
#include <tree_node/loader.h>
#include <iostream>

int main() {
  auto node = TreeNodeLoader::from_string("[5,4,6,2,null,null,7]");

  std::cout << tree_node::compute_height(node) << "\n";

  renderer::render_tree_node(node, "test.png");
  renderer::render_to_window(node);

  return 0;
}
