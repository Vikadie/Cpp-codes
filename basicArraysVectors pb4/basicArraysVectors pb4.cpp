#include <iostream>
#include <string>
#include <vector>
using namespace std;

void problem4() {
    char entry;
    int num = 0;
    do {
        cin >> entry;
        if (entry >= '0' && entry <= '9') {
            num = num * 10 + (entry - '0');
        }
    } while (entry != '.');

    cout << sqrt(num);
}

int main()
{
    problem4();
}
