#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Defines.h"

ErrorCode executeCommand(const std::string& command,
    std::vector<MemoryNode>& memory) {
    std::istringstream in(command);
    std::string word;
    bool allocate = false;

    in >> word;
    if (word == "Allocate")
        allocate = true;

    int memoryT;
    in >> word;
    if (word == "Single")
        memoryT = MemoryType::SINGLE;
    else
        memoryT = MemoryType::MULTIPLE;
    
    
    in >> word;
    int index = stoi(word);
 /*   if (index < 0 && index >= BUFFER_SIZE)
        return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;*/
    if (allocate)
        switch (memoryT)
        {
        case MemoryType::SINGLE: {
            if (memory[index].memoryType == MemoryType::UNKNOWN) {
                memory[index].memoryType = memoryT;
                memory[index].rawMemory = new int;
            }
            else if (memory[index].memoryType == MemoryType::MULTIPLE)
                return ErrorCode::MEMORY_LEAK;
            break; }
        case MemoryType::MULTIPLE: {
            if (memory[index].memoryType == MemoryType::UNKNOWN) {
                memory[index].memoryType = memoryT;
                memory[index].rawMemory = new int[ALLOCATION_MULTIPLE_SIZE];
            }
            else if (memory[index].memoryType == MemoryType::SINGLE)
                return ErrorCode::MEMORY_LEAK;
            break; }
        default:
            break;
        }
    else {
        switch (memoryT)
        {
        case MemoryType::SINGLE: {
            if (memory[index].memoryType == MemoryType::SINGLE) {
                memory[index].memoryType = MemoryType::UNKNOWN;
                delete memory[index].rawMemory;
                memory[index].rawMemory = nullptr;
            }
            else if (memory[index].memoryType == MemoryType::UNKNOWN)
                return ErrorCode::DOUBLE_FREE;
            else
                return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
            break; }
        case MemoryType::MULTIPLE: {
            if (memory[index].memoryType == MemoryType::MULTIPLE) {
                memory[index].memoryType = MemoryType::UNKNOWN;
                delete[] memory[index].rawMemory;
                memory[index].rawMemory = nullptr;
            }
            else if (memory[index].memoryType == MemoryType::UNKNOWN)
                return ErrorCode::DOUBLE_FREE;
            else
                return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
            break; }
        default:
            break;
        }
        }
    return ErrorCode::EXECUTE_SUCCESS;
}

void printResult(const ErrorCode     errorCode,
    const std::string& command) {
    switch (errorCode)
    {
    case ErrorCode::EXECUTE_SUCCESS: std::cout << command << " - success" << std::endl; break;
    case ErrorCode::DOUBLE_FREE: std::cout << command << " - system crash prevented, will skip this deallocation" << std::endl; break;
    case ErrorCode::MEMORY_LEAK: std::cout << command << " - memory leak prevented, will not make allocation" << std::endl; break;
    case ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH: std::cout << command << " - Warning allocate/deallocate mismatch, will skip this deallocation" << std::endl; break;
    default:
        break;
    }
}