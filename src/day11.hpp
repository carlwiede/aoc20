#ifndef DAY11_HPP
#define DAY11_HPP

#include "day.hpp"

class Day11 : public Day {

    char getSeat(vector<string>& seating, size_t x, size_t y) {
        if (y < seating.size() && x < seating.at(y).size()) {
            return seating.at(y).at(x);
        } else {
            return '.';
        }
    }

    int getOccupiedAdjacents(vector<string>& seating, int x, int y) {
        int occupiedAdjacents = 0;

        for (int sx = x - 1; sx <= x + 1; sx++) {
            for (int sy = y - 1; sy <= y + 1; sy++) {
                if (sx == x && sy == y) continue;
                char adjacentSeat = getSeat(seating, sx, sy);
                if (adjacentSeat == '#') occupiedAdjacents++;
            }
        }

        return occupiedAdjacents;
    }

    int countOccupiedSeats(vector<string>& seating) {
        int occupiedSeats = 0;
        for (string line : seating) {
            for (char c : line) {
                if (c == '#') occupiedSeats++;
            }
        }
        return occupiedSeats;
    }

    vector<string> getNextSeating(vector<string>& seating) {
        vector<string> nextSeating = seating;
        for (size_t y = 0; y < seating.size(); y++) {
            for (size_t x = 0; x < seating.at(y).size(); x++) {
                if (seating[y][x] == '.') continue;

                int occupiedAdjacents = getOccupiedAdjacents(seating, x, y);
                if (occupiedAdjacents == 0) {
                    nextSeating[y][x] = '#';
                } else if (occupiedAdjacents >= 4) {
                    nextSeating[y][x] = 'L';
                }
            }
        }
        return nextSeating;
    }

    void part1(vector<string> input) override {

        int occupiedSeats;
        vector<string> previousSeating = input;
        vector<string> nextSeating = getNextSeating(previousSeating);

        while (nextSeating != previousSeating) {
            previousSeating = nextSeating;
            nextSeating = getNextSeating(previousSeating);
        }

        occupiedSeats = countOccupiedSeats(previousSeating);

        cout << occupiedSeats << " seats are occupied" << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif
