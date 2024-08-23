#ifndef DAY2_HPP
#define DAY2_HPP

#include "day.hpp"

class Day2 : public Day {
    void part1(vector<string> input) override {
        vector<string> parts = Utils::split(input.at(0), " ");

        for (string part : parts) {
            cout << part << endl;
        }

        cout << "Part 1 not implemented." << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif