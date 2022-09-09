#pragma once
#include <glad/glad.h>
//
#include <GLFW/glfw3.h>

namespace window {

class GlfwInstance {
 public:
  GlfwInstance();
  ~GlfwInstance();
  inline GLuint get_program() { return program; }
  inline int get_width() { return width; }
  inline int get_height() { return height; }

  void get_viewport_dimensions(int32_t& width, int32_t& height);

  unsigned int get_frame_texture() { return frame_texture; }

  void init_window(int width, int height, const char* window_name = "Canvas");

  void setup();
  bool loop();
  void set_frame_texture(unsigned char* data,
                         int texture_width,
                         int texture_height);

 private:
  void create_vertex_buffer();
  void compile_shaders();

  GLFWwindow* window = NULL;
  GLuint program;
  int width, height;
  unsigned int frame_texture;
  bool texture_created = false;
};
}  // namespace window
