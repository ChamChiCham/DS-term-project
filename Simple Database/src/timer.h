#pragma once
#include <ctime>
#include <iostream>

class Timer {
public:
    void reset();
    void elapsed();
    void show() const;

private:
    std::clock_t start_time{};
    std::clock_t end_time{};
};

extern Timer timer;