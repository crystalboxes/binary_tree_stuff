#pragma once
#include <math.h>
#include <memory>

namespace window {

class TextureProvider {
 public:
  virtual void draw() = 0;
  virtual uint8_t* get_data() = 0;
};

class Window {
 public:
  Window(std::shared_ptr<TextureProvider> in_texture_provider);
  ~Window();
  void init(int32_t width, int32_t height);
  void show();

  std::shared_ptr<TextureProvider> texture_provider;

 private:
  class WindowPrivate* window_private;
};

}  // namespace window
