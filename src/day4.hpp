#ifndef DAY4_HPP
#define DAY4_HPP

#include "day.hpp"

class Day4 : public Day {
    void part1(vector<string> input) override {
        int valid = 0;

        int fields = 0;
        bool cidMissing = true;
        for (string line : input) {
            if (line.empty()) {
                if (fields == 8 || (fields == 7 && cidMissing)) valid++;
                fields = 0;
                cidMissing = true;
                continue;
            }

            vector<string> parts = Utils::split(line, " ");
            for (string part : parts) {
                fields++;
                if (Utils::split(part, ":").at(0) == "cid") cidMissing = false;
            }
        }
        if (fields == 8 || (fields == 7 && cidMissing)) valid++;

        cout << "There are " << valid << " valid passports." << endl;
    }

    void part2(vector<string> input) override {
        int valid = 0;

        int fields = 0;
        bool cidMissing = true;
        for (string line : input) {
            if (line.empty()) {
                if (fields == 8 || (fields == 7 && cidMissing)) valid++;
                fields = 0;
                cidMissing = true;
                continue;
            }

            vector<string> parts = Utils::split(line, " ");
            for (string part : parts) {
                vector<string> kv = Utils::split(part, ":");
                string key = kv.at(0);
                string value = kv.at(1);
                if (key == "cid") cidMissing = false;
                else if (key == "byr") {
                    if (stoi(value) < 1920 || stoi(value) > 2002) {
                        break;
                    }
                }
                else if (key == "iyr") {
                    if (stoi(value) < 2010 || stoi(value) > 2020) {
                        break;
                    }
                }
                else if (key == "eyr") {
                    if (stoi(value) < 2020 || stoi(value) > 2030) {
                        break;
                    }
                }
                else if (key == "hgt") {
                    string unit = value.substr(value.size()-2);
                    if (unit == "cm") {
                        int len = stoi(value.substr(0, value.size()-2));
                        if (len < 150 || len > 193) {
                            break;
                        }
                    } else if (unit == "in") {
                        int len = stoi(value.substr(0, value.size()-2));
                        if (len < 59 || len > 76) {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                else if (key == "hcl") {
                    if (value.size() != 7) {
                        break;
                    }
                    if (value.at(0) != '#') {
                        break;
                    }
                    for (char c : value.substr(1)) {
                        if ((c < '0' || c > '9') && (c < 'a' || c > 'f')) {
                            break;
                        }
                    }
                }
                else if (key == "ecl") {
                    if (value != "amb" && value != "blu" && value != "brn" && value != "gry"
                        && value != "grn" && value != "hzl" && value != "oth") {
                            break;
                        }
                }
                else if (key == "pid") {
                    if (value.size() == 9) {
                        try {
                            stoi(value);
                        } catch (const std::invalid_argument& e) {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                fields++;
            }
        }
        if (fields == 8 || (fields == 7 && cidMissing)) valid++;

        cout << "There are " << valid << " valid passports." << endl;
    }
};

#endif
