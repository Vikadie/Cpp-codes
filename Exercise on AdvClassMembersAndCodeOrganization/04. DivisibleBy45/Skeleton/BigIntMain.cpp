#include <iostream>
#include <string>

#include "BigInt.h"

bool divisibleBy5(BigInt& num) {
    size_t len = num.getDigits().length();
    return num.getDigits()[len - 1] == '0' || num.getDigits()[len - 1] == '5';
}


bool divisibleBy9(BigInt& num) {
    int sum = 0;
    for (size_t j = 0; j < num.getDigits().length(); j++)
        sum += num.getDigits()[j] - '0';

    return sum % 9 == 0;
}


bool divisibleBy45(BigInt& num) {
    return divisibleBy9(num) && divisibleBy5(num);
}



int main()
{
    std::string rangeStart;
    std::string rangeEnd;

    std::cin >> rangeStart >> rangeEnd;

    BigInt start = BigInt(rangeStart);
    BigInt end = BigInt(rangeEnd);

    BigInt i = start;
    for (; i < end; i += 1) {
        if (divisibleBy45(i))
            break;
    }

    for (i; i < end; i += 45)
        std::cout << i << std::endl;
    

    return 0;
}
