#pragma once

#include <glad/glad.h>
// Include glad before any other GL operations

#include <GLFW/glfw3.h>

#include <functional>
#include <memory>

namespace particles {
class window {
 public:
  window();
  ~window();
  window(const window&) = delete;
  window& operator=(const window&) = delete;
  window(window&&) = delete;
  window& operator=(window&&) = delete;

  void loop() const;

 private:
  using deleter_type = std::function<void(GLFWwindow*)>;

  void initialize();

  std::unique_ptr<GLFWwindow, deleter_type> window_;
};
}  // namespace particles