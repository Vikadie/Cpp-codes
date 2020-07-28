#include <iostream>
using namespace std;
void problem8() {
    int sumEven = 0, sumOdd = 0, count = 0, n, num;
    cin >> n;

    while (n != 0) {
        num = n % 10;
        count++;
        if (count % 2 != 0)
            sumOdd += num;
        else
            sumEven += num;
        n = n / 10;
    }
    cout << sumEven * sumOdd;
}

int main()
{
    problem8();
}
