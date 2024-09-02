#ifndef DAY6_HPP
#define DAY6_HPP

#include "day.hpp"

#include <set>

class Day6 : public Day {

    int getIntersectSize(set<char> set1, set<char> set2) {
        set<char> unionSet;
        set_intersection(set1.begin(), set1.end(),
                         set2.begin(), set2.end(),
                         inserter(unionSet, unionSet.begin()));
        return unionSet.size();
    }

    void part1(vector<string> input) override {

        int total = 0;

        set<char> alphabet;
        for (char c = 'a'; c <= 'z'; c++) {
            alphabet.insert(c);
        }

        set<char> groupLetters;
        for (string line : input) {
            if (line.empty()) {
                total += getIntersectSize(alphabet, groupLetters);
                groupLetters.clear();
            } else {
                for (char c : line) groupLetters.insert(c);
            }
        }
        total += getIntersectSize(alphabet, groupLetters);

        cout << "The total sum is " << total << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif