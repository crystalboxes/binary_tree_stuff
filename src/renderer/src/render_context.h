#pragma once
#include <math.h>
#include "style.h"

namespace renderer {

/**
 * @brief Wraps cairo interface to render vector graphics
 *
 */
class RenderContext {
 public:
  RenderContext(int32_t in_width, int32_t in_height);
  ~RenderContext();

  uint8_t* data_ptr();
  uint64_t data_size();

  void write(const char* filename);
  void clear(float_t r, float_t g, float_t b);
  void circle(const Style& style, float_t x, float_t y, float_t r);
  void line(const Style& style, float_t x0, float_t y0, float_t x1, float_t y1);
  void text(const Font& font, const char* text);

  int32_t get_width() { return width; }
  int32_t get_height() { return height; }

 private:
  void fill(const Style& style);
  void stroke(const Style& style);

  struct RenderContextPrivate* ctx;

  int32_t width = 0;
  int32_t height = 0;
};
}  // namespace renderer
