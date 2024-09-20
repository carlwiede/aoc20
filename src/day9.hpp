#ifndef DAY9_HPP
#define DAY9_HPP

#include "day.hpp"

#include <deque>

class Day9 : public Day {

    bool isValidSum(deque<int> &preamble, int value) {

        for (size_t i = 0; i < preamble.size() - 1; i++) {
            if (preamble[i] >= value) continue;
            for (size_t j = i + 1; j < preamble.size(); j++) {
                if (preamble[i] + preamble[j] == value) return true;
            }
        }

        return false;
    }

    void part1(vector<string> input) override {

        size_t lineIndex = 0;
        long firstNoSum = 0;
        deque<int> preamble;

        for (;lineIndex < 25; lineIndex++) {
            preamble.push_back(stoi(input.at(lineIndex)));
        }

        for (;lineIndex < input.size(); lineIndex++) {
            long val = stol(input.at(lineIndex));
            if (!isValidSum(preamble, val)) {
                firstNoSum = val;
                break;
            }
            preamble.pop_front();
            preamble.push_back(val);
        }

        cout << "First non-sum value is " << firstNoSum << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif
