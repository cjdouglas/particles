#include "particles/graphics/window.h"

#include <GLFW/glfw3.h>

#include <stdexcept>

static constexpr int GL_VERSION_MAJOR = 3;
static constexpr int GL_VERSION_MINOR = 3;
static constexpr int HEIGHT = 600;
static constexpr int WIDTH = 800;
static constexpr auto TITLE = "Particles";

namespace particles {
window::window() { initialize(); }

window::~window() { glfwTerminate(); }

void window::initialize() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  const deleter_type window_deleter = [](GLFWwindow* ptr) {
    if (ptr != nullptr) {
      glfwDestroyWindow(ptr);
    }
  };

  window_ = std::unique_ptr<GLFWwindow, deleter_type>(
      glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr), window_deleter);

  if (!window_) {
    glfwTerminate();
    throw std::runtime_error("could not initialize window");
  }

  glfwMakeContextCurrent(window_.get());
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    glfwTerminate();
    throw std::runtime_error("could not initialize GL loader");
  }

  glViewport(0, 0, WIDTH, HEIGHT);
}

void window::loop() const {
  while (!glfwWindowShouldClose(window_.get())) {
    glfwSwapBuffers(window_.get());
    glfwPollEvents();
  }
}

}  // namespace particles