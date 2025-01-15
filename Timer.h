#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

class Timer {
private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    TimePoint startTime;
    TimePoint stopTime;
    bool running;

public:
    Timer();
    ~Timer();

    void start();
    void stop();
    void printMilliseconds();
    void printSeconds();
};

#endif
