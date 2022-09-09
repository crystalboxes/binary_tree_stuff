#include "render_context.h"
#include <cairo.h>
#include <stdlib.h>

namespace renderer {

struct RenderContextPrivate {
  cairo_surface_t* surface = nullptr;
  cairo_t* cr = nullptr;
  uint8_t* data = nullptr;
  uint64_t size = 0;
  int32_t stride = 0;

  void allocate_for_wh(int32_t width, int32_t height) {
    stride = cairo_format_stride_for_width(CAIRO_FORMAT_ARGB32, width);
    size = stride * height;
    data = (unsigned char*)malloc(size);

    surface = cairo_image_surface_create_for_data(data, CAIRO_FORMAT_ARGB32,
                                                  width, height, stride);
    cr = cairo_create(surface);
  }

  ~RenderContextPrivate() {
    if (cr) {
      cairo_destroy(cr);
    }

    if (surface) {
      cairo_surface_destroy(surface);
    }

    if (data) {
      free(data);
    }
  }
};

uint8_t* RenderContext::data_ptr() {
  return ctx->data;
}

uint64_t RenderContext::data_size() {
  return ctx->size;
}

RenderContext::RenderContext(int32_t in_width, int32_t in_height) {
  ctx = new RenderContextPrivate();
  width = in_width;
  height = in_height;
  ctx->allocate_for_wh(width, height);
}

RenderContext::~RenderContext() {
  delete ctx;
}

void RenderContext::write(const char* filename) {
  cairo_surface_write_to_png(ctx->surface, filename);
}

void RenderContext::clear(float_t r, float_t g, float_t b) {
  cairo_set_source_rgb(ctx->cr, r, g, b);
  cairo_paint(ctx->cr);
}

void RenderContext::circle(const Style& style,
                           float_t x,
                           float_t y,
                           float_t r) {
  if (style.fill) {
    cairo_arc(ctx->cr, x, y, r, 0, 2 * M_PI);
    fill(style);
  }

  if (style.stroke) {
    cairo_arc(ctx->cr, x, y, r, 0, 2 * M_PI);
    stroke(style);
  }
}

void RenderContext::fill(const Style& style) {
  cairo_set_source_rgb(ctx->cr, style.fill_color.r, style.fill_color.g,
                       style.fill_color.b);
  cairo_fill(ctx->cr);
}

void RenderContext::stroke(const Style& style) {
  cairo_set_line_width(ctx->cr, style.line_width);
  cairo_set_source_rgb(ctx->cr, style.stroke_color.r, style.stroke_color.g,
                       style.stroke_color.b);
  cairo_stroke(ctx->cr);
}

void RenderContext::line(const Style& style,
                         float_t x0,
                         float_t y0,
                         float_t x1,
                         float_t y1) {
  cairo_move_to(ctx->cr, x0, y0);
  cairo_line_to(ctx->cr, x1, y1);
  stroke(style);
}

void RenderContext::text(const Font& font, const char* text) {
  auto cr = ctx->cr;
  cairo_select_font_face(cr, "Serif", CAIRO_FONT_SLANT_NORMAL,
                         CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size(cr, font.size);

  cairo_set_source_rgb(cr, font.color.r, font.color.g, font.color.b);

  cairo_text_extents_t extents;
  cairo_text_extents(cr, text, &extents);

  float_t x = font.x - (extents.width / 2 + extents.x_bearing);
  float_t y = font.y - (extents.height / 2 + extents.y_bearing);

  cairo_move_to(cr, x, y);
  cairo_show_text(cr, text);
}
}  // namespace renderer
