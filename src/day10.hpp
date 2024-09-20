#ifndef DAY10_HPP
#define DAY10_HPP

#include "day.hpp"

#include <algorithm>
#include <set>

class Day10 : public Day {

    set<int> getRatingSet(vector<string> input) {
        set<int> ratings;
        for (string line : input) {
            int number = stoi(line);
            ratings.insert(number);
        }
        return ratings;
    }

    vector<int> getRatingVector(vector<string> input) {
        vector<int> ratings;
        for (string line : input) {
            int number = stoi(line);
            ratings.push_back(number);
        }
        return ratings;
    }

    void part1(vector<string> input) override {

        set<int> ratings = getRatingSet(input);
        ratings.insert(*ratings.rbegin() + 3);

        int oneJolts = 0, threeJolts = 0, latestRating = 0;

        while(!ratings.empty()) {
            switch(*ratings.begin() - latestRating) {
                case 1:
                    oneJolts++;
                    break;
                case 3:
                    threeJolts++;
            }
            latestRating = *ratings.begin();
            ratings.erase(ratings.begin());
        }

        cout << "Differences total to " << oneJolts * threeJolts << endl;
    }

    // this ain't it
    int getTimelinesBruteForce(set<int> ratings) {
        int lowestValue = *ratings.begin();
        ratings.erase(ratings.begin());

        if (ratings.empty()) {
            return 1;
        }

        int timelines = getTimelinesBruteForce(ratings);

        if (ratings.size() > 2 && *(++ratings.begin()) - lowestValue <= 3) {
            ratings.erase(ratings.begin());
            timelines += getTimelinesBruteForce(ratings);
        }

        if (ratings.size() > 2 && *(++ratings.begin()) - lowestValue <= 3) {
            ratings.erase(ratings.begin());
            timelines += getTimelinesBruteForce(ratings);
        }

        return timelines;
    }

    long long getTimelinesFast(vector<int> ratings) {

        vector<long long> timelines(ratings.size(), 0);
        timelines[0] = 1;

        for (size_t i = 1; i < timelines.size(); i++) {
            for (size_t j = 1; j <= 3; j++) {
                if (i >= j && ratings[i] - ratings[i - j] <= 3) {
                    timelines[i] += timelines[i - j];
                }
            }
        }

        return timelines.back();
    }

    void part2(vector<string> input) override {

        vector<int> ratings = getRatingVector(input);
        ratings.push_back(0);
        sort(ratings.begin(), ratings.end());
        ratings.push_back(ratings.back() + 3);

        long long timelines = getTimelinesFast(ratings);

        cout << "There are " << timelines << " timelines" << endl;
    }
};

#endif
