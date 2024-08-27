#ifndef DAY4_HPP
#define DAY4_HPP

#include "day.hpp"

class Day4 : public Day {
    void part1(vector<string> input) override {
        int valid = 0;

        int fields = 0;
        bool cidMissing = true;
        for (string line : input) {
            if (line.empty()) {
                if (fields == 8 || (fields == 7 && cidMissing)) valid++;
                fields = 0;
                cidMissing = true;
                continue;
            }

            vector<string> parts = Utils::split(line, " ");
            for (string part : parts) {
                fields++;
                if (Utils::split(part, ":").at(0) == "cid") cidMissing = false;
            }
        }
        if (fields == 8 || (fields == 7 && cidMissing)) valid++;

        cout << "There are " << valid << " valid passports." << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif