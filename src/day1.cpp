#include "day1.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#include "timer.hpp"
#include "utils.hpp"

using namespace std;

namespace day1 {
    void solve() {
        vector<string> input = Utils::readFile("input/day1.txt");

        Timer * timer = new Timer();

        part1(input);
        timer->print_elapsed();

        cout << endl;
        timer->reset();

        part2(input);
        timer->print_elapsed();
    }

    void part1(vector<string> input) {
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

    void part2(vector<string> input) {

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
}
