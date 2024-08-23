#include <iostream>

#include "alldays.hpp"

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

    Day* solver = nullptr;

    switch (day) {
        case 0:
            solver = new Day0();
            break;
        case 1:
            solver = new Day1();
            break;
        case 2:
            solver = new Day2();
            break;
        default:
            cout << "Day " << day << " is not implemented yet." << endl;
            return 1;
    }

    if (solver) {
        solver->solve("input/day" + to_string(day) + ".txt");
        delete solver;
    }

    return 0;
}