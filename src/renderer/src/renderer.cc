#include <cairo.h>
#include <math.h>
#include <renderer/renderer.h>
#include <tree_node/helpers.h>
#include <sstream>
#include "render_context.h"
#include "tree_renderer.h"

namespace renderer {

void render_tree_node(TreeNode* node, const char* out_filename) {
  TreeRenderer renderer(node);
  renderer.draw();
  renderer.to_png(out_filename);
}

void render_to_window(TreeNode* node) {
  TreeRenderer renderer(node);
  renderer.draw();
  renderer.to_window();
}

}  // namespace renderer
