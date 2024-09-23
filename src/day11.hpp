#ifndef DAY11_HPP
#define DAY11_HPP

#include "day.hpp"

class Day11 : public Day {

    int countOccupiedSeats(vector<string>& seating) {
        int occupiedSeats = 0;
        for (string line : seating) {
            for (char c : line) {
                if (c == '#') occupiedSeats++;
            }
        }
        return occupiedSeats;
    }

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

    int getVisibleOccupiedAdjacents(vector<string>& seating, int x, int y) {
        int occupiedVisibleAdjacents = 0;

        // E
        for (size_t sx = x + 1; sx < seating.at(y).size(); sx++) {
            char seat = getSeat(seating, sx, y);
            if (seat != '.') {
                if (seat == '#') occupiedVisibleAdjacents++;
                break;
            }
        }

        // S
        for (size_t sy = y + 1; sy < seating.size(); sy++) {
            char seat = getSeat(seating, x, sy);
            if (seat != '.') {
                if (seat == '#') occupiedVisibleAdjacents++;
                break;
            }
        }

        // W
        for (int sx = x - 1; sx >= 0; sx--) {
            char seat = getSeat(seating, sx, y);
            if (seat != '.') {
                if (seat == '#') occupiedVisibleAdjacents++;
                break;
            }
        }

        // N
        for (int sy = y - 1; sy >= 0; sy--) {
            char seat = getSeat(seating, x, sy);
            if (seat != '.') {
                if (seat == '#') occupiedVisibleAdjacents++;
                break;
            }
        }

        // NE
        size_t sx = x + 1;
        for (int sy = y - 1; sy >= 0 && sx < seating.at(sy).size(); sy--, sx++) {
            char seat = getSeat(seating, sx, sy);
            if (seat != '.') {
                if (seat == '#') occupiedVisibleAdjacents++;
                break;
            }
        }

        // SE
        for (size_t sy = y + 1, sx = x + 1; sy < seating.size() && sx < seating.at(sy).size(); sy++, sx++) {
            char seat = getSeat(seating, sx, sy);
            if (seat != '.') {
                if (seat == '#') occupiedVisibleAdjacents++;
                break;
            }
        }

        // SW
        size_t sy = y + 1;
        for (int sx = x - 1; sy < seating.size() && sx >= 0; sy++, sx--) {
            char seat = getSeat(seating, sx, sy);
            if (seat != '.') {
                if (seat == '#') occupiedVisibleAdjacents++;
                break;
            }
        }

        // NW
        for (int sy = y - 1, sx = x - 1; sy >= 0 && sx >= 0; sy--, sx--) {
            char seat = getSeat(seating, sx, sy);
            if (seat != '.') {
                if (seat == '#') occupiedVisibleAdjacents++;
                break;
            }
        }

        return occupiedVisibleAdjacents;
    }

    vector<string> getNextSmartSeating(vector<string>& seating) {
        vector<string> nextSeating = seating;
        for (size_t y = 0; y < seating.size(); y++) {
            for (size_t x = 0; x < seating.at(y).size(); x++) {
                if (seating[y][x] == '.') continue;

                int occupiedAdjacents = getVisibleOccupiedAdjacents(seating, x, y);
                if (occupiedAdjacents == 0) {
                    nextSeating[y][x] = '#';
                } else if (occupiedAdjacents >= 5) {
                    nextSeating[y][x] = 'L';
                }
            }
        }

        return nextSeating;
    }

    void part2(vector<string> input) override {
        int occupiedSeats;
        vector<string> previousSeating = input;
        vector<string> nextSeating = getNextSmartSeating(previousSeating);

        while (nextSeating != previousSeating) {
            previousSeating = nextSeating;
            nextSeating = getNextSmartSeating(previousSeating);
        }

        occupiedSeats = countOccupiedSeats(previousSeating);

        cout << occupiedSeats << " seats are occupied" << endl;
    }
};

#endif
