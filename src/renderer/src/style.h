#pragma once
#include <math.h>

namespace renderer {

struct RGB {
  float_t r = 0;
  float_t g = 0;
  float_t b = 0;
};

struct Font {
  float_t size = 20.f;
  float_t x = 0;
  float_t y = 0;

  RGB color;
};

struct Style {
  RGB fill_color;
  RGB stroke_color;

  bool fill = false;
  bool stroke = false;

  float_t line_width = 1.0;
};
}  // namespace renderer
