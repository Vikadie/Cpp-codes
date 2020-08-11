#pragma once
#ifndef DIVISION_H
#define DIVISION_H

#include <vector>
#include "Operation.h"

class Division : public Operation {
    std::vector<int> operands;
    int result;
public:
    void addOperand(int operand) override {
        this->operands.push_back(operand);

        if (this->isCompleted()) {
            if (this->operands[1] != 0)
                this->result = this->operands[0] / this->operands[1];
            else
                this->result = 0;
        }
    }

    bool isCompleted() override {
        return this->operands.size() == 2;
    }

    int getResult() override {
        return this->result;
    }
};

#endif // DIVISION_H
