#include <window/window.h>
#include "gl_app.h"

namespace window {

class WindowPrivate : public GLApp {
 public:
  WindowPrivate(Window* in_window) { window = in_window; }
  virtual void render_texture() override { window->texture_provider->draw(); }
  virtual uint8_t* get_texture_data() override {
    return window->texture_provider->get_data();
  }

 private:
  Window* window;
};

void Window::init(int32_t width, int32_t height) {
  window_private->set_dimensions(width, height);
  window_private->init();
}

void Window::show() {
  window_private->run();
}

Window::Window(std::shared_ptr<TextureProvider> in_texture_provider) {
  texture_provider = in_texture_provider;
  window_private = new WindowPrivate(this);
}

Window::~Window() {
  delete window_private;
}
}  // namespace window
