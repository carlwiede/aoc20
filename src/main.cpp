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

    int dayNumber;
    try {
        dayNumber = stoi(argv[1]);
    } catch (invalid_argument& e) {
        cout << "That's not even a number." << endl;
        return 0;
    }

    Day* selectedDay = alldays::resolveDay(dayNumber);

    if (selectedDay) {
        selectedDay->solve("input/day" + to_string(dayNumber) + ".txt");
        delete selectedDay;
    } else {
        cout << "Day " << dayNumber << " is not implemented yet." << endl;
    }

    return 0;
}