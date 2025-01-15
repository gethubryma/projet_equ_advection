#include "Timer.h"

Timer::Timer() : running(false) {}

Timer::~Timer() {}

void Timer::start() {
    startTime = Clock::now();
    running = true;
}

void Timer::stop() {
    stopTime = Clock::now();
    running = false;
}

void Timer::printMilliseconds() {
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count();
    std::cout << duration << " ms" << std::endl;
}

void Timer::printSeconds() {
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime).count();
    std::cout << duration << " s" << std::endl;
}
