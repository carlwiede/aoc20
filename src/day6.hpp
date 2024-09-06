#ifndef DAY6_HPP
#define DAY6_HPP

#include "day.hpp"

#include <set>

class Day6 : public Day {

    set<char> getAlphabet() {
        set<char> alphabet;
        for (char c = 'a'; c <= 'z'; c++) {
            alphabet.insert(c);
        }
        return alphabet;
    }

    set<char> getIntersect(set<char> set1, set<char> set2) {
        set<char> intersectSet;
        set_intersection(set1.begin(), set1.end(),
                         set2.begin(), set2.end(),
                         inserter(intersectSet, intersectSet.begin()));
        return intersectSet;
    }

    int getIntersectSize(set<char> set1, set<char> set2) {
        return getIntersect(set1, set2).size();
    }

    void part1(vector<string> input) override {

        int total = 0;

        set<char> alphabet = getAlphabet();

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

        int total = 0;

        set<char> charactersEveryoneHas = getAlphabet();
        for (string line : input) {
            if (line.empty()) {
                total += charactersEveryoneHas.size();
                charactersEveryoneHas = getAlphabet();
            } else {
                set<char> currentLineCharacters;
                for (char c : line) currentLineCharacters.insert(c);
                charactersEveryoneHas = getIntersect(charactersEveryoneHas, currentLineCharacters);
            }
        }
        total += charactersEveryoneHas.size();

        cout << "The total sum is " << total << endl;
    }
};

#endif