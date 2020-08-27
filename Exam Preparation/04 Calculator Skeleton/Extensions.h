#pragma once
#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include "CalculationEngine.h"
#include "InputInterpreter.h"


class DivisionOperation : public Operation {
    std::vector<int> operands;
    int result;
public:
    void addOperand(int operand) override {
        this->operands.push_back(operand);

        if (this->isCompleted()) {
            this->result = this->operands[0] / this->operands[1];
        }
    }

    bool isCompleted() override {
        return this->operands.size() == 2;
    }

    int getResult() override {
        return this->result;
    }
};

static std::vector<int> operandsMemory;

class MS : public Operation {
    int result;
public:
    void addOperand(int operand) override {
        operandsMemory.push_back(operand);
        this->result = operand;
    }

    bool isCompleted() override {
        return false;
    }

    int getResult() override {
        return 0;
    }
};


class MR : public Operation {
    int result;
public:
    void addOperand(int operand) override {

    }

    bool isCompleted() override {
        return true;
    }

    int getResult() override {
        this->result = operandsMemory.back();
        operandsMemory.pop_back();
        return this->result;
    }
};


class Extensions : public InputInterpreter {
public:
    Extensions(CalculationEngine& engine) : InputInterpreter(engine) {}

    virtual std::shared_ptr<Operation> getOperation(std::string operation) override {

        if (operation == "*") {
            return std::make_shared<MultiplicationOperation>();
        }
        else if (operation == "/") {
            return std::make_shared<DivisionOperation>();
        }
        else if (operation == "mr") {
            return std::make_shared<MR>();
        }
        else if (operation == "ms") {
            return std::make_shared<MS>();
        }

        return std::shared_ptr<Operation>(nullptr);
    }
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
	std::shared_ptr<InputInterpreter> interpreter = std::make_shared<Extensions>(engine);

	return interpreter;
}

#endif // !EXTENSIONS_H
