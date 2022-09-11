#include "tree_renderer.h"
#include <tree_node/helpers.h>
#include <window/window.h>
#include <sstream>

namespace renderer {

void TreeRenderer::render_node_circle(RenderContext& ctx,
                                      float_t x,
                                      float_t y,
                                      int32_t num) {
  std::stringstream ss;
  ss << num;

  ctx.circle({{1, 1, 1}, {0, 0, 0}, true, true, 1}, x, y, 14);
  ctx.text({14, x, y, {0, 0, 0}}, ss.str().c_str());
}

void TreeRenderer::draw() {
  ctx->clear(1, 1, 1);
  if (!node) {
    return;
  }
  draw_tree(*ctx, node, 0, false, 0, ctx->get_width(), -1.f, true);
  draw_tree(*ctx, node, 0, false, 0, ctx->get_width(), -1.f, false);
}

void TreeRenderer::to_png(const char* filename) {
  ctx->write(filename);
}

void TreeRenderer::setup() {
  int32_t tree_height = tree_node::compute_height(node);

  int32_t image_height = tree_height * 50 * 2;
  int32_t image_width = tree_height * 2 * 30 * 2;

  ctx = std::make_shared<RenderContext>(image_width, image_height);
}

void TreeRenderer::draw_tree(RenderContext& context,
                             TreeNode* node,
                             int32_t depth,
                             bool is_left,
                             float_t parent_x,
                             float_t offset_x,
                             float_t previous_y,
                             bool is_line_pass) {
  auto new_offset = offset_x / 2.f;
  auto current_x = is_left ? parent_x - new_offset : parent_x + new_offset;
  auto current_y = 35 + 100 * depth;

  if (is_line_pass) {
    if (previous_y > 0) {
      context.line({{0, 0, 0}, {0, 0, 0}, false, true, 1}, parent_x, previous_y,
                   current_x, current_y);
    }
  } else {
    render_node_circle(context, current_x, current_y, node->val);
  }

  if (node->left) {
    draw_tree(context, node->left, depth + 1, true, current_x, new_offset,
              current_y, is_line_pass);
  }

  if (node->right) {
    draw_tree(context, node->right, depth + 1, false, current_x, new_offset,
              current_y, is_line_pass);
  }
}

class CtxTextureProvider : public window::TextureProvider {
 public:
  CtxTextureProvider(std::shared_ptr<RenderContext> in_ctx) { ctx = in_ctx; }
  virtual void draw() override {}
  virtual uint8_t* get_data() override { return ctx->data_ptr(); }

 private:
  std::shared_ptr<RenderContext> ctx;
};

void TreeRenderer::to_window() {
  auto wnd = new window::Window(std::make_shared<CtxTextureProvider>(ctx));
  wnd->init(ctx->get_width(), ctx->get_height());
  wnd->show();
}

}  // namespace renderer
