#include <renderer/renderer.h>
#include <tree_node/helpers.h>
#include <tree_node/loader.h>
#include <iostream>

int main() {
  const char* tree = "[2,1,33,null,null,25,40,11]";
  auto node = TreeNodeLoader::from_string(tree);

  std::cout << tree_node::compute_height(node);

  renderer::render_tree_node(node, "test.png");
  renderer::render_to_window(node);

  return 0;
}
