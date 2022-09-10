#pragma once
#include <stdlib.h>
#include <stdint.h>

struct GLFWwindow;

namespace window {

class GlfwInstance {
 public:
  GlfwInstance();
  ~GlfwInstance();
  inline uint32_t get_program() { return program; }
  inline int get_width() { return width; }
  inline int get_height() { return height; }

  void get_viewport_dimensions(int32_t& width, int32_t& height);

  uint32_t get_frame_texture() { return frame_texture; }

  void init_window(int32_t width,
                   int32_t height,
                   const char* window_name = "Canvas");

  void setup();

  void loop();
  
  void set_frame_texture(unsigned char* data,
                         int32_t texture_width,
                         int32_t texture_height);

  bool should_close();
  void terminate();

 private:
  void create_vertex_buffer();
  void compile_shaders();

  GLFWwindow* window = NULL;
  uint32_t program;
  int32_t width, height;
  uint32_t frame_texture;
  bool texture_created = false;
};
}  // namespace window
