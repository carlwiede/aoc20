#include "day0.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace day0 {
    void solve() {
        cout << "Solution for day 0:" << endl;

        ifstream file("input/day0.txt");
        if (!file.is_open()) {
            cerr << "Failed to open file for day 0." << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
}