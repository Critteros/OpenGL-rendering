#include "Window.h"
#include <stdexcept>

#include <spdlog/spdlog.h>

namespace Sandy {
Window::Window(int windowWidth, int windowHeight, std::string windowName, OpenGLVersion glVersion)
    : _openGLVersion(glVersion),
      _windowWidth{ windowWidth },
      _windowHeight{ windowHeight },
      _windowPtr{ nullptr },
      _windowName{ std::move(windowName) }
{
    if ((windowHeight <= 0) || (windowWidth <= 0)) {
        throw std::runtime_error{ "Invalid Window dimensions" };
    }
    if (!static_cast<bool>(glfwInit())) {
        spdlog::critical("GLFW initializatin failed!");
        throw std::runtime_error{ "GLFW initialization failed!" };
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _openGLVersion.major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _openGLVersion.minor);

    _windowPtr = glfwCreateWindow(windowWidth, windowHeight, "LearnOpenGL", nullptr, nullptr);

    if (_windowPtr == nullptr) {
        spdlog::critical("Failed to create GLFW window");
        throw std::runtime_error{ "Failed to create GLFW window" };
    }

    glfwMakeContextCurrent(_windowPtr);
}

void Window::loadOpenGLfunctions(int width, int height) const
{
    if ((width < -1) || (height < -1)) {
        throw std::runtime_error{ "Invalid viewport dimensions" };
    }
    if (!static_cast<bool>(gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))) {
        spdlog::critical("GLAD function loading failed!");
        throw std::runtime_error{ "Failed to load OpenGL functions!" };
    }
    width = width == NO_VALUE ? _windowWidth : width;
    height = height == NO_VALUE ? _windowHeight : height;
    glViewport(0, 0, width, height);
}


Window::~Window()
{
    glfwDestroyWindow(_windowPtr);
    glfwTerminate();
}
}// namespace Sandy