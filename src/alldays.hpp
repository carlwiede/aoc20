#ifndef ALLDAYS_HPP
#define ALLDAYS_HPP

#include "day0.hpp"
#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"

namespace alldays {
    Day* resolveDay(int day) {
        switch (day) {
        case 0:
            return new Day0();
        case 1:
            return new Day1();
        case 2:
            return new Day2();
        case 3:
            return new Day3();
        default:
            cout << "Day " << day << " is not implemented yet." << endl;
            return nullptr;
        }
    }
}

#endif