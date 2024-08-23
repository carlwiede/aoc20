#include "day0.hpp"

#include <iostream>
#include <string>

#include "utils.hpp"

using namespace std;

namespace day0 {
    void solve() {
        vector<string> input = Utils::readFile("input/day0.txt");
        part1(input);
        cout << endl;
        part2(input);
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