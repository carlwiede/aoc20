#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Utils {
public:
    static vector<string> readFile(const string filename) {
        vector<string> lines;

        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Failed to open file " << filename << endl;
            return lines;
        }

        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }

        file.close();

        return lines;
    }
};

#endif