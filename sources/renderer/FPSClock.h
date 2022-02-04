#pragma once
#include <spdlog/spdlog.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <chrono>

namespace Sandy {

class FPSClock {
  public:
    FPSClock()
    {
        auto currentTime = std::chrono::system_clock::now();
        _framesCount++;
        constexpr double refreshInterval = 0.5;
        auto delta = std::chrono::duration<double>(currentTime - _timerBegin).count();
        if (delta >= refreshInterval) {
            const double fpsValue = _framesCount * 1 / refreshInterval;
            spdlog::info("FPS: {0:.2f}", fpsValue);
            _lastFPS = fpsValue;

            _framesCount = 0;
            _timerBegin = std::chrono::system_clock::now();
        }
    }

    static void SetBegin()
    {
        _timerBegin = std::chrono::system_clock::now();
    }

    static double GetLastFPS()
    {
        return _lastFPS;
    }

  private:
    static std::chrono::time_point<std::chrono::system_clock> _timerBegin;
    static double _lastFPS;
    static unsigned _framesCount;
};
}// namespace Sandy