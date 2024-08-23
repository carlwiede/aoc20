#ifndef UTILS_HPP
#define UTILS_HPP

#include <fstream>
#include <iostream>
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

    static vector<string> split(string src, string delim) {
        vector<string> tokens;
        int delimIndex;
        while ((delimIndex = src.find(delim)) >= 0) {
            tokens.push_back(src.substr(0, delimIndex));
            src = src.substr(delimIndex + 1);
        }
        tokens.push_back(src);
        return tokens;
    }
};

#endif