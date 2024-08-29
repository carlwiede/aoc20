#ifndef DAY5_HPP
#define DAY5_HPP

#include "day.hpp"

#include <cmath>

class Day5 : public Day {
    void part1(vector<string> input) override {

        int highestId = 0;

        for (string pass : input) {
            string row = pass.substr(0,7);
            string col = pass.substr(7);

            int rowValue = 0;
            int colValue = 0;

            // Calculate row
            for (int i = 0; i < 7; i++) {
                if (row.at(i) == 'B') rowValue += pow(2, 6-i);
            }

            // Calculate column
            for (int i = 0; i < 3; i++) {
                if (col.at(i) == 'R') colValue += pow(2, 2-i);
            }

            int idValue = rowValue * 8 + colValue;

            highestId = max(highestId, idValue);
        }

        cout << "The highest seat ID is " << highestId << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif