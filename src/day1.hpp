#ifndef DAY1_HPP
#define DAY1_HPP

#include "day.hpp"

#include <unordered_set>

class Day1 : public Day {

    void part1(vector<string> input) override {

        unordered_set<int> numbers;

        for (string line : input) {
            int number = stoi(line);
            int comp = 2020 - number;

            if (numbers.find(comp) != numbers.end()) {
                cout << "The two numbers are " << number << " and " << comp << endl;
                cout << "The product is " << number * comp << endl;
                return;
            }

            numbers.insert(number);
        }
    }

    void part2(vector<string> input) override {

        for (size_t i = 0; i < input.size(); i++) {
            int num1 = stoi(input[i]);
            int target = 2020 - num1;
            unordered_set<int> numbers;

            for (size_t j = i + 1; j < input.size(); j++) {
                int num2 = stoi(input[j]);
                int num3 = target - num2;

                if (numbers.find(num3) != numbers.end()) {
                    cout << "The three numbers are " << num1 << ", " << num2 << " and " << num3 << endl;
                    cout << "The product is " << num1 * num2 * num3 << endl;
                    return;
                }

                numbers.insert(num2);
            }
        }
    }
};

#endif