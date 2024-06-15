#pragma once
#include <ctime>
#include <iostream>

class Timer {
public:
    Timer() : start_time(std::clock()) {}

    void reset() {
        start_time = std::clock();
    }

    double elapsed() const {
        return (std::clock() - start_time) / static_cast<double>(CLOCKS_PER_SEC);
    }

private:
    std::clock_t start_time;
};