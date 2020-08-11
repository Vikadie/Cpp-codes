#pragma once
#ifndef SUBSTRACTION_H
#define SUBSTRACTION_H

#include <vector>
#include "Operation.h"

static std::vector<int> operandsVec;
static int result;

class MemorySave : public Operation {

public:
    void addOperand(int operand) override {
        operandsVec.push_back(operand);
    }
    bool isCompleted() override {
        return false;
    }

    int getResult() override {
        return result;
    }
};

class MemoryRecall : public Operation {
public:
    void addOperand(int operand) override {
        // this operation never runs
    }
    bool isCompleted() override {
        return operandsVec.size() > 0;
    }
    int getResult() override {
        result = operandsVec.back();
        operandsVec.pop_back();
        return result;
    }
};


#endif // SUBSTRACTION_H
