#pragma once
#include <string>
#include <utility>
#include <cstdint>

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Sandy {


constexpr int OPENGL_DEFAULT_MAJOR = 4;
constexpr int OPENGL_DEFAULT_MINOR = 6;
constexpr int NO_VALUE = -1;

struct OpenGLVersion {
  public:
    const int major;
    const int minor;

    OpenGLVersion(int majorV, int minorV) : major(majorV), minor(minorV) {}
    OpenGLVersion(const OpenGLVersion &) = default;
    OpenGLVersion(OpenGLVersion &&) = default;
    ~OpenGLVersion() = default;
    OpenGLVersion &operator=(const OpenGLVersion &) = delete;
    OpenGLVersion &operator=(OpenGLVersion &&) = delete;
};

class Window {
  public:
    Window(int windowWidth, int windowHeight, std::string windowName, OpenGLVersion glVersion = { OPENGL_DEFAULT_MAJOR, OPENGL_DEFAULT_MINOR });

    Window(const Window &other) = delete;
    Window &operator=(const Window &other) = delete;

    Window(Window &&other) = delete;
    Window &operator=(Window &&other) = delete;

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] std::string getWindowName() const;
    [[nodiscard]] OpenGLVersion getOpenGLVersion() const;

    void loadOpenGLfunctions(int width = NO_VALUE, int height = NO_VALUE) const;
    void renderCycle() const;
    bool shouldClose() const;

    ~Window();


  private:
    const OpenGLVersion _openGLVersion;
    int _windowWidth;
    int _windowHeight;
    GLFWwindow *_windowPtr;
    std::string _windowName;
};

inline int Window::getWidth() const
{
    return _windowWidth;
}

inline int Window::getHeight() const
{
    return _windowHeight;
}

inline std::string Window::getWindowName() const
{
    return _windowName;
}

inline OpenGLVersion Window::getOpenGLVersion() const
{
    return _openGLVersion;
}

inline void Window::renderCycle() const
{
    glfwSwapBuffers(_windowPtr);
    glfwPollEvents();
}

inline bool Window::shouldClose() const
{
    return static_cast<bool>(glfwWindowShouldClose(_windowPtr));
}
}// namespace Sandy