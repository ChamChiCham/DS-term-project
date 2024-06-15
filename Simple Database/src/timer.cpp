#include "timer.h"
#include <print>

void Timer::reset() {
    start_time = std::clock();
}

void Timer::elapsed()
{
    end_time = std::clock();
}

void Timer::show() const
{
    std::println("Elasped Time: {}", (end_time - start_time) / static_cast<double>(CLOCKS_PER_SEC));
}

Timer timer;