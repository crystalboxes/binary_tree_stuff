#include <renderer/renderer.h>
#include <tree_node/helpers.h>
#include <tree_node/loader.h>
#include <iostream>

int main() {
  const char* tree = "[5,4,7,3,null,2,null,-1,null,9,2,3,5,2,3,2,14,4,5]";
  auto node = TreeNodeLoader::from_string(tree);

  std::cout << tree_node::compute_height(node);
  
  renderer::render_tree_node(node, "test.png");
  renderer::render_to_window(node);

  return 0;
}
