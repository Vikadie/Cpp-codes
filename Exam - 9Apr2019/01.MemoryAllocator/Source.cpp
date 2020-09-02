#include <iostream>
#include <vector>
#include <string>
#include "Defines.h"

#include <sstream>

ErrorCode executeCommand(const std::string& command,
    std::vector<int*>& memory) {
    std::istringstream in(command);
    std::string order;
    int index = 0;

    in >> order;
    if (order == "Allocate") {
        in >> index;
        if (index < 0 || index >= memory.size())
            return ErrorCode::INDEX_OUT_OF_BOUND;
        if (memory[index] == nullptr)
            memory[index] = new int;
        else
            return ErrorCode::MEMORY_LEAK;
        return ErrorCode::EXECUTE_SUCCESS;
    }
    else if (order == "Deallocate") {
        in >> index;
        if (index < 0 || index >= memory.size())
            return ErrorCode::INDEX_OUT_OF_BOUND;
        if (memory[index] != nullptr) {
            delete memory[index];
            memory[index] = nullptr;
        }
        else
            return ErrorCode::DOUBLE_FREE;
        return ErrorCode::EXECUTE_SUCCESS;
    }
    else if (order == "Idle") {
        return ErrorCode::EXECUTE_IDLE;
    }
}

void printResult(const ErrorCode     errorCode,
    const std::string& command) {
    std::cout << command << " - ";
    switch (errorCode)
    {
    case ErrorCode::EXECUTE_SUCCESS: std::cout << "success"; break;
    case ErrorCode::MEMORY_LEAK: std::cout << "memory leak prevented, will not make allocation"; break;
    case ErrorCode::DOUBLE_FREE: std::cout << "system crash prevented, will skip this deallocation"; break;
    case ErrorCode::INDEX_OUT_OF_BOUND: std::cout << "out of bound"; break;
    case ErrorCode::EXECUTE_IDLE: std::cout << "this exam is a piece of cake! Where is the OOP already?!?"; break;
    default:
        break;
    }
    std::cout << std::endl;
}