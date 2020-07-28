#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int ReadWithNoise(string str) {
    // string str;
    unsigned index = 0;
    int number = 0;

    for (index; index < str.length(); index++) {

        if (str[index] >= '0' && str[index] <= '9') {
            number = number * 10 + (str[index] - '0');
        }
        else if (str[index] == '.') break;
    }

    return number;
}

void problem5() {
    string entry;
    unsigned num;

    srand((unsigned)time(0));

    // за да лимитираме размера на стринга до 32 знака
     num = (unsigned)rand() % 32 + 1; // тъй като rand() е int и може да върне отр числа, го правим само на положителни с (unsigned)
        // за да не е безкрайно числото го лимитираме от 1 (+1) до 32 (%32)

     // генерираме стринга отново с rand(), конвертиран към (char)
     for (; num; num--)
         entry.push_back((char)rand());
    
    cout << entry << endl;
    cout << sqrt(ReadWithNoise(entry));
}

int main()
{
    problem5();
}
