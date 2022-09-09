#pragma once
#include <glad/glad.h>
#include <window/window.h>
#include "glfw_instance.h"

namespace window {

class TimeManager {
 public:
  void update() { frame_count++; }
  unsigned int get_frame_count() { return frame_count; }
  float get_seconds() { return frame_count / (float)frames_per_second; }

 private:
  const int frames_per_second = 120;
  unsigned int frame_count = 0;
};

class App {
 public:
  virtual void init() = 0;
  virtual void render_loop() = 0;
  virtual void run() = 0;
};

class GLApp : public App {
 public:
  int get_width() { return width; }
  int get_height() { return height; }
  virtual void render_texture() = 0;
  virtual uint8_t* get_texture_data() = 0;

  void set_dimensions(int new_width, int new_height) {
    width = new_width;
    height = new_height;
  }

  virtual void init() override;

  virtual void render_loop() override;

  virtual void run() override;

  GlfwInstance glfw_instance;
  TimeManager time;

 private:
  int width;
  int height;

  int32_t viewport_x = 0;
  int32_t viewport_y = 0;
};
}  // namespace window
