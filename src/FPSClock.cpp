#include "FPSClock.h"

namespace Sandy {
unsigned FPSClock::_framesCount;
std::chrono::time_point<std::chrono::system_clock> FPSClock::_timerBegin;
double FPSClock::_lastFPS = 0;
}// namespace Sandy