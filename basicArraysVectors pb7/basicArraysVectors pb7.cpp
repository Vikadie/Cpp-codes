#include <iostream>
using namespace std;

void SwitchDigit(int num) {
    switch (num) {
    case 0: cout << "zero"; break;
    case 1: cout << "one"; break;
    case 2: cout << "two"; break;
    case 3: cout << "three"; break;
    case 4: cout << "four"; break;
    case 5: cout << "five"; break;
    case 6: cout << "six"; break;
    case 7: cout << "seven"; break;
    case 8: cout << "eight"; break;
    case 9: cout << "nine"; break;
    }
}

void SwitchTen(int num) {
    switch (num) {
    case 1: cout << "ten"; break;
    case 2: cout << "twenty "; break;
    case 3: cout << "thirty "; break;
    case 5: cout << "fifty "; break;
    default: {
        SwitchDigit(num);
        cout << "ty ";
    }
    }
}

void problem7() {
    int n, num_dig, num_ten, num_hun, num_th;
    cin >> n;

    // thousands if any
    num_dig = n % 10;
    num_ten = (n / 10) % 10;
    num_hun = ((n / 10) / 10) % 10;
    num_th = (((n / 10) / 10) / 10);
    // thousands
    if (num_th > 0) {
        SwitchDigit(num_th);
        cout << " thousand ";
    }
    // hundreds
    if (num_hun > 0){
        SwitchDigit(num_hun);
        cout << " hundred ";
    }
    // tens
    if (num_ten > 1) {
         SwitchTen(num_ten);
    } 
    else if (num_ten == 1) {
        switch (num_dig) {
        case 0: cout << "ten"; break;
        case 1: cout << "eleven"; break;
        case 2: cout << "twelve"; break;
        case 3: cout << "thirteen"; break;
        default: {
            SwitchDigit(num_ten);
            cout << 'teen';
        }
        }
    }
    // last digit
    if (num_ten != 1)
        SwitchDigit(num_dig);
}

int main()
{
    problem7();
}
