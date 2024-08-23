#ifndef DAY_HPP
#define DAY_HPP

#include <string>
#include <vector>

#include "timer.hpp"
#include "utils.hpp"

class Day {
public:
    void solve(const std::string filename) {
        std::vector<std::string> input = Utils::readFile(filename);

        Timer * timer = new Timer();

        part1(input);
        timer->print_elapsed();

        cout << endl;
        timer->reset();

        part2(input);
        timer->print_elapsed();
    }

    virtual ~Day() {}

protected:
    virtual void part1(std::vector<std::string> input) = 0;
    virtual void part2(std::vector<std::string> input) = 0;
};

#endif