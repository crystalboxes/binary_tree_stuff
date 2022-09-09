#include "gl_app.h"

namespace window {
void GLApp::init() {
  glfw_instance.init_window(get_width(), get_height());
  glfw_instance.setup();

  glfw_instance.get_viewport_dimensions(viewport_x, viewport_y);
}

void GLApp::render_loop() {
  time.update();

  glViewport(0, 0, viewport_x, viewport_y);
  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(glfw_instance.get_program());
  glActiveTexture(GL_TEXTURE0);

  render_texture();
  glfw_instance.set_frame_texture(get_texture_data(), get_width(),
                                  get_height());

  glDrawArrays(GL_TRIANGLES, 0, 6);
}

void GLApp::run() {
  while (glfw_instance.loop()) {
    render_loop();
  }
}
}  // namespace window
