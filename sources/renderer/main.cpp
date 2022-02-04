#include <iostream>

#include <spdlog/spdlog.h>
#include <fmt/core.h>

extern "C" {
#include <glad/glad.h>
}

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "colors.h"
#include "Window.h"
#include "FPSClock.h"

#include <iostream>

int main()
{
    constexpr int windowWidth = 800;
    constexpr int windowHeight = 600;

    Sandy::Window window{ windowWidth, windowHeight, "Welcome to OpenGL!" };
    window.loadOpenGLfunctions();

    Sandy::FPSClock::SetBegin();
    while (!window.shouldClose()) {
        const Sandy::FPSClock clock{};
        glClearColor(RGBA(255.f, 0.f, 0.f, 1.f));
        glClear(GL_COLOR_BUFFER_BIT);

        window.renderCycle();
    }

    return 0;
}