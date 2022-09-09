#include <math.h>
#include <tree_node/tree_node.h>
#include <memory>
#include "render_context.h"

namespace renderer {

/**
 * @brief Recursively renders binary tree structure to canvas in 2 passes
 *
 */
class TreeRenderer {
 public:
  TreeRenderer(TreeNode* in_node) {
    this->node = in_node;
    setup();
  }

  void draw();

  /**
   * @brief Renders to a window
   */
  void to_window();
  void to_png(const char* filename);

 private:
  void render_node_circle(RenderContext& ctx,
                          float_t x,
                          float_t y,
                          int32_t num);

  void draw_tree(RenderContext& context,
                 TreeNode* node,
                 int32_t depth,
                 bool is_left,
                 float_t parent_x,
                 float_t offset_x,
                 float_t previous_y,
                 bool is_line_pass);

  void setup();

  TreeNode* node;
  std::shared_ptr<RenderContext> ctx;
};
}  // namespace renderer
