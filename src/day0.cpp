#include "day0.hpp"

#include <iostream>
#include <string>

#include "timer.hpp"
#include "utils.hpp"

using namespace std;

namespace day0 {
    void solve() {
        vector<string> input = Utils::readFile("input/day0.txt");

        Timer * timer = new Timer();

        part1(input);
        timer->print_elapsed();

        cout << endl;
        timer->reset();

        part2(input);
        timer->print_elapsed();
    }

    void part1(vector<string> input) {
        cout << "The input is:" << endl;
        for (string line : input) {
            cout << line << endl;
        }
    }

    void part2(vector<string> input) {
        cout << "The line length is:" << endl;
        for (string line : input) {
            cout << line.length() << endl;
        }
    }
}