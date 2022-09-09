#pragma once

#include <tree_node/tree_node.h>

namespace renderer {
void render_tree_node(TreeNode* node,
                      const char* out_filename = "tree_node.png");

void render_to_window(TreeNode* node);
}  // namespace renderer
