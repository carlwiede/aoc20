#ifndef DAY2_HPP
#define DAY2_HPP

#include "day.hpp"

#include <algorithm>

class Day2 : public Day {
    void part1(vector<string> input) override {

        int valid = 0;

        for (string line : input) {
            vector<string> parts = Utils::split(line, " ");
            vector<string> numRange = Utils::split(parts.at(0), "-");
            int min = stoi(numRange.at(0));
            int max = stoi(numRange.at(1));

            char special = parts.at(1).front();

            string password = parts.at(2);
            int occurrences = count(password.begin(), password.end(), special);

            if (min <= occurrences && occurrences <= max) {
                valid++;
            }
        }

        cout << "There are " << valid << " valid passwords." << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif