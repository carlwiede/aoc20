#ifndef DAY3_HPP
#define DAY3_HPP

#include "day.hpp"

class Day3 : public Day {
    void part1(vector<string> input) override {
        int trees = 0;
        int xpos = 0;
        int ypos = 0;

        while (ypos < input.size()) {
            if (input.at(ypos).at(xpos) == '#') trees++;
            xpos += 3;
            ypos += 1;
            if (xpos >= input.at(0).size()) xpos %= input.at(0).size();
        }

        cout << trees << " trees encountered." << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif