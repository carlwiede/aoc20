#include <iostream>
#include <string>

#include "day0.hpp"
#include "day1.hpp"
#include "day2.hpp"

using namespace std;

void print_usage() {
    cout << "Usage: ./aoc <day>" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    int day = stoi(argv[1]);

    cout << "Solution for day " << day << ":" << endl << endl;

    switch (day) {
        case 0:
            day0::solve();
            break;
        case 1:
            day1::solve();
            break;
        case 2:
            day2::solve();
            break;
        default:
            cout << "Day " << day << " is not implemented yet." << endl;
    }

    return 0;
}