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

    map<int, tuple<Instruction, int, bool>> readProgram(vector<string> input) {
        map<int, tuple<Instruction, int, bool>> program;
        int lineCounter = 1;

        for (string line : input) {
            vector<string> splitLine = Utils::split(line, " ");
            Instruction inst = determineInstruction(splitLine.at(0));
            int value = stoi(splitLine.at(1));

            program[lineCounter] = make_tuple(inst, value, false);

            lineCounter++;
        }

        return program;
    }

    int getAcc(map<int, tuple<Instruction, int, bool>> program) {
        size_t pc = 1;
        int accTotal = 0;

        while (!get<2>(program[pc])) {
            if (pc >= program.size()) break;
            switch (get<0>(program[pc])) {
                case nop:
                    break;
                case jmp:
                    pc += get<1>(program[pc]);
                    continue;
                case acc:
                    accTotal += get<1>(program[pc]);
            }
            get<2>(program[pc]) = true;
            pc++;
        }

        return accTotal;
    }

    bool isValidProgram(map<int, tuple<Instruction, int, bool>> program) {
        size_t pc = 1;

        while (!get<2>(program[pc])) {

            if (pc == program.size()) return true;
            else if (pc > program.size()) return false;

            switch (get<0>(program[pc])) {
                case nop:
                    break;
                case jmp:
                    pc += get<1>(program[pc]);
                    continue;
                case acc:
                    break;
            }

            get<2>(program[pc]) = true;
            pc++;
        }

        return false;
    }

    int getCorrectedAcc(map<int, tuple<Instruction, int, bool>> program) {
        map<int, tuple<Instruction, int, bool>> newProgram;

        for (size_t line = 1; line <= program.size(); line++) {
            newProgram = program;
            Instruction inst = get<0>(newProgram[line]);
            switch (inst) {
                case nop:
                    get<0>(newProgram[line]) = jmp;
                    break;
                case jmp:
                    get<0>(newProgram[line]) = nop;
                    break;
                case acc:
                    continue;
            }

            if (isValidProgram(newProgram)) return getAcc(newProgram);
        }

        return 0;
    }

    void part1(vector<string> input) override {
        int acc = getAcc(readProgram(input));
        cout << "In the end, acc is " << acc << endl;
    }

    void part2(vector<string> input) override {
        int acc = getCorrectedAcc(readProgram(input));
        cout << "Corrected acc is " << acc << endl;
    }
};

#endif
