#ifndef DAY7_HPP
#define DAY7_HPP

#include "day.hpp"

#include <map>
#include <tuple>

class Day7 : public Day {

    map<string, vector<tuple<int, string>>> bagMap;

    bool eventuallyContainsGold(string bagName) {
        vector<tuple<int, string>> bags = bagMap[bagName];
        bool containsGold = false;

        for (tuple<int,string> bag : bags) {
            if (get<1>(bag) == "shiny gold") return true;
            containsGold |= eventuallyContainsGold(get<1>(bag));
        }

        return containsGold;
    }

    map<string, vector<tuple<int, string>>> getBagMap(vector<string> input) {
        map<string, vector<tuple<int, string>>> bagMap;
        for (string line : input) {
            string bagName = Utils::split(line, " bags ").at(0);

            vector<string> bagContents = Utils::split(line, " contain ");
            vector<string> individualBags = Utils::split(bagContents.at(1), ", ");
            individualBags.at(individualBags.size()-1).pop_back();
            vector<tuple<int, string>> bagList;
            for (string bag : individualBags) {
                string strippedBag = Utils::split(bag, " bag").at(0);

                if (strippedBag.rfind("no other", 0) == 0) {
                    break;
                }

                int numBag = strippedBag.at(0) - '0';
                string strBag = strippedBag.substr(2);
                bagList.push_back(make_tuple(numBag, strBag));
            }

            bagMap[bagName] = bagList;
        }

        return bagMap;
    }

    void part1(vector<string> input) override {
        bagMap = getBagMap(input);
        int total = 0;

        for (string line : input) {
            string bagName = Utils::split(line, " bags ").at(0);
            if (eventuallyContainsGold(bagName)) total ++;
        }

        cout << total << " bags eventually contain shiny gold" << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif