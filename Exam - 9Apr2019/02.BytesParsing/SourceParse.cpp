#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include "Defines.h"

ErrorCode parseData(const std::string& commands,
    const char* rawDataBytes,
    const size_t	   	     rawDataBytesCount,
    std::vector<long long>& outParsedNumbers) {

    if (commands.length() == 0 || rawDataBytesCount == 0)
        return ErrorCode::PARSE_EMPTY;
    size_t currentIndex = 0;

    for (size_t i = 0; i < commands.length(); i++) {
        int size = 0;
        if (commands[i] == 's')
            size = 2;
        else if (commands[i] == 'i')
            size = 4;
        else
            size = 8;

        if (currentIndex + size > rawDataBytesCount)
            return ErrorCode::PARSE_FAILURE;
        long long parseElement = 0;
        int indexElement = 0;
        for (size_t j = currentIndex; j < currentIndex + size; j++) {
            parseElement += rawDataBytes[j] * (long long)pow(2, indexElement * 8);
            indexElement++;
           
        }
       
        outParsedNumbers.emplace_back(parseElement);

        currentIndex += size;
    }
    return ErrorCode::PARSE_SUCCESS;
}

void printResult(const ErrorCode                errorCode,
    const std::vector<long long>& parsedNumbers) {

    std::ostringstream ss;
    for (int i = 0; i < parsedNumbers.size(); i++)
        ss << parsedNumbers[i] << " ";
    switch (errorCode)
    {
    case ErrorCode::PARSE_EMPTY: std::cout << "No input provided"; break;
    case ErrorCode::PARSE_FAILURE: std::cout << ss.str() << "Warning, buffer underflow detected"; break;
    case ErrorCode::PARSE_SUCCESS: std::cout << ss.str(); break;
    default:
        break;
    }
     std::cout << std::endl;
}