#include "day0.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include "utils.hpp"

using namespace std;

namespace day0 {
    void solve() {
        vector<string> input = Utils::readFile("input/day0.txt");

        for (string line : input) {
            cout << line << endl;
        }
    }
}