#ifndef DAY_HPP
#define DAY_HPP

#include <string>
#include <vector>

#include "timer.hpp"
#include "utils.hpp"

using namespace std;

class Day {
public:
    void solve(const std::string filename) {
        vector<string> input;

        try {
            input = Utils::readFile(filename);
        } catch (runtime_error& e) {
            cout << e.what() << endl;
            return;
        }

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
