#ifndef UTILS_HPP
#define UTILS_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Utils {
public:
    static std::vector<std::string> readFile(const std::string filename) {
        std::vector<std::string> lines;

        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file '" + filename + "'");
        }

        std::string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }

        file.close();

        return lines;
    }

    static std::vector<std::string> split(std::string src, std::string delim) {
        std::vector<std::string> tokens;
        int delimIndex;
        while ((delimIndex = src.find(delim)) >= 0) {
            tokens.push_back(src.substr(0, delimIndex));
            src = src.substr(delimIndex + delim.size());
        }
        tokens.push_back(src);
        return tokens;
    }
};

#endif
