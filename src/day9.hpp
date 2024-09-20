#ifndef DAY9_HPP
#define DAY9_HPP

#include "day.hpp"

#include <deque>
#include <numeric>

class Day9 : public Day {

    bool isValidSum(deque<long> &preamble, int value) {

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
        deque<long> preamble;

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

        size_t lineIndex = 0;
        long firstNoSum = 0;
        deque<long> preamble;

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

        // Rewind
        long min, max;

        for (;lineIndex > 0; lineIndex--) {
            vector<long> contiguous;
            for (int i = lineIndex - 1; i >= 0; i--) {
                long val = stol(input.at(i));
                contiguous.push_back(val);
                long sum = accumulate(contiguous.begin(), contiguous.end(), 0LL);

                if (sum > firstNoSum) break;
                else if (sum == firstNoSum) {
                    min = *min_element(contiguous.begin(), contiguous.end());
                    max = *max_element(contiguous.begin(), contiguous.end());
                    cout << "Sum from contiguous is " << min + max << endl;
                    return;
                }
            }
        }
    }
};

#endif
