#include <iostream>
#include <string>
#include "Defines.h"

ErrorCode decryptMessage(const std::string & commands,
                         const char *        leftBufferData,
                         const size_t	   	 leftBufferSize,
                         const char *        rightBufferData,
                         const size_t	   	 rightBufferSize,
                         std::string &       outMessage);

void printResult(const ErrorCode     errorCode,
                 const std::string & decryptedMessage);

int main()
{
    std::string commands;
    std::string leftBuffer;
    std::string rightBuffer;
    std::string decryptedMessage;

    getline(std::cin, commands);
    getline(std::cin, leftBuffer);
    getline(std::cin, rightBuffer);

    const ErrorCode errorCode = decryptMessage(commands,
                                               leftBuffer.c_str(),
                                               leftBuffer.size(),
                                               rightBuffer.c_str(),
                                               rightBuffer.size(),
                                               decryptedMessage);

    printResult(errorCode, decryptedMessage);

    return 0;
}

//ErrorCode decryptMessage(const std::string& commands, const char* leftBufferData, const size_t leftBufferSize, const char* rightBufferData, const size_t rightBufferSize, std::string& outMessage)
//{
//    if (commands.empty())
//        return ErrorCode::DECRYPT_EMPTY;
//    else {
//        outMessage = "";
//        size_t i = 0;
//        while (i < commands.length()) {
//            bool right = false;
//            if (commands[i] == 'r')
//                right = true;
//            i++;
//            if ((!right && commands[i] - '0' >= leftBufferSize) || (right && commands[i] - '0' >= rightBufferSize))
//                return ErrorCode::DECRYPT_FAILURE;
//            if (!right)
//                outMessage += leftBufferData[commands[i] - '0'];
//            else
//                outMessage += rightBufferData[commands[i] - '0'];
//            i++;
//        }
//    }
//    return ErrorCode::DECRYPT_SUCCESS;
//}
//
//void printResult(const ErrorCode errorCode, const std::string& decryptedMessage)
//{
//    switch (errorCode)
//    {
//    case ErrorCode::DECRYPT_EMPTY: std::cout << "No input provided" << std::endl; break;
//    case ErrorCode::DECRYPT_FAILURE: std::cout << decryptedMessage << " Warning buffer out-of-bound detected" << std::endl; break;
//    case ErrorCode::DECRYPT_SUCCESS: std::cout << decryptedMessage << std::endl; break;
//    default:
//        break;
//    }
//}
