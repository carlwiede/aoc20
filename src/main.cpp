#include <iostream>

#include "alldays.hpp"

using namespace std;

void printUsage() {
    cout << "Usage: make run day=<day>" << endl;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printUsage();
        return 1;
    }

    int day = stoi(argv[1]);

    cout << "Solution for day " << day << ":" << endl << endl;

    Day* selectedDay = alldays::resolveDay(day);

    if (selectedDay) {
        selectedDay->solve("input/day" + to_string(day) + ".txt");
        delete selectedDay;
    }

    return 0;
}