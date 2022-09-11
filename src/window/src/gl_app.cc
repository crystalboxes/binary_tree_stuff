#include "gl_app.h"
#include <functional>
#include "gl.h"

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
  glClearColor(0, 0, 0, 1);

  glUseProgram(glfw_instance.get_program());
  glActiveTexture(GL_TEXTURE0);

  render_texture();
  glfw_instance.set_frame_texture(get_texture_data(), get_width(),
                                  get_height());

  glDrawArrays(GL_TRIANGLES, 0, 6);
}

std::function<void()> loop;
void main_loop() {
  loop();
}

void GLApp::run() {
  loop = [&] {
    render_loop();
    glfw_instance.loop();
  };

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(main_loop, 0, true);
#else
  while (!glfw_instance.should_close()) {
    main_loop();
  }
#endif

  glfw_instance.terminate();
}
}  // namespace window
