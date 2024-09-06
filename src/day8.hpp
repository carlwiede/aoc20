#ifndef DAY8_HPP
#define DAY8_HPP

#include "day.hpp"

#include <map>
#include <tuple>

class Day8 : public Day {

    enum Instruction {
        nop,
        acc,
        jmp
    };

    Instruction determineInstruction(string rawInstruction) {
        if (rawInstruction == "nop") {
            return nop;
        } else if (rawInstruction == "jmp") {
            return jmp;
        } else {
            return acc;
        }
    }

    map<int, tuple<Instruction, int, bool>> readInstructions(vector<string> input) {
        map<int, tuple<Instruction, int, bool>> instructions;
        int lineCounter = 1;

        for (string line : input) {
            vector<string> splitLine = Utils::split(line, " ");
            Instruction inst = determineInstruction(splitLine.at(0));
            int value = stoi(splitLine.at(1));

            instructions[lineCounter] = make_tuple(inst, value, false);

            lineCounter++;
        }

        return instructions;
    }

    int run(map<int, tuple<Instruction, int, bool>> instructions) {
        int pc = 1;
        int acc_total = 0;

        while (!get<2>(instructions[pc])) {
            switch (get<0>(instructions[pc])) {
                case nop:
                    break;
                case jmp:
                    pc += get<1>(instructions[pc]);
                    continue;
                case acc:
                    acc_total += get<1>(instructions[pc]);
            }
            get<2>(instructions[pc]) = true;
            pc++;
        }

        return acc_total;
    }

    void part1(vector<string> input) override {
        int acc = run(readInstructions(input));
        cout << "In the end, acc is " << acc << endl;
    }

    void part2(vector<string> input) override {
        cout << "Part 2 not implemented." << endl;
    }
};

#endif