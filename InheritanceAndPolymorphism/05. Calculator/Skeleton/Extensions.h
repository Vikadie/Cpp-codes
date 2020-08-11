#pragma once
#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <iostream>

#include "Division.h"
#include "MemoryManagement.h"
#include "InputInterpreter.h"

class Extensions : public InputInterpreter {

public:
	Extensions(CalculationEngine& engine): InputInterpreter(engine){}

    virtual std::shared_ptr<Operation> getOperation(std::string operation) {
        
        if (InputInterpreter::getOperation(operation) == nullptr) {
            if (operation == "/") {
                return std::make_shared<Division>();
            }

            if (operation == "ms") {
                return std::make_shared<MemorySave>();
            }

            if (operation == "mr") {
                return std::make_shared<MemoryRecall>();
            }
        }
        else {
            return InputInterpreter::getOperation(operation);
        }

        return std::shared_ptr<Operation>(nullptr);
    }

    ~Extensions() {}
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
    std::shared_ptr<InputInterpreter> interpreter = std::make_shared <Extensions>(engine);

    return interpreter;
}
#endif // !EXTENSIONS_H
