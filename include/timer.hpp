#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer {
public:
    Timer() : start_time_point(std::chrono::high_resolution_clock::now()) {}

    void reset () {
        start_time_point = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        auto end_time_point = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(end_time_point - start_time_point).count();
    }

    void print_elapsed() const {
        std::cout << "Execution time: " << elapsed() << " seconds" << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_point;
};

#endif
