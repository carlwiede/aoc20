#ifndef DAY3_HPP
#define DAY3_HPP

#include "day.hpp"

#include <tuple>

class Day3 : public Day {
    void part1(vector<string> input) override {
        int trees = 0;
        uint xpos = 0;
        uint ypos = 0;

        while (ypos < input.size()) {
            if (input.at(ypos).at(xpos) == '#') trees++;
            xpos += 3;
            ypos += 1;
            if (xpos >= input.at(0).size()) xpos %= input.at(0).size();
        }

        cout << trees << " trees encountered." << endl;
    }

    void part2(vector<string> input) override {
        vector<tuple<int, int>> slopes;
        slopes.push_back(make_tuple(1, 1));
        slopes.push_back(make_tuple(3, 1));
        slopes.push_back(make_tuple(5, 1));
        slopes.push_back(make_tuple(7, 1));
        slopes.push_back(make_tuple(1, 2));

        long total = 1;

        for (tuple<int, int> slope : slopes) {
            int trees = 0;
            uint xpos = 0;
            uint ypos = 0;

            while (ypos < input.size()) {
                if (input.at(ypos).at(xpos) == '#') trees++;
                xpos += get<0>(slope);
                ypos += get<1>(slope);
                if (xpos >= input.at(0).size()) xpos %= input.at(0).size();
            }

            total *= trees;
        }

        cout << total << " trees encountered." << endl;
    }
};

#endif
