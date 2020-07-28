#include <iostream>

using namespace std;

void problem1() {
    int a, b;
    double c = 0;
    char op = 0;
    char y_n;

    cout << "Enter first integer number followed by second, separated by space of Enter:" << endl;
    std::cin >> a >> b;

    if (a and b)
    {
        do {
            // cin.ignore();
            cout << "Choose an operation (+, -, *, /):" << endl;
            cin >> op;

            switch (op) {
            case '+': c = (double)a + b; break;
            case '-': c = (double)a - b; break;
            case '*': c = (double)a * b; break;
            case '/': c = (double)a / b; break;
            default: {
                cout << "Try again! \n";
                op = 0;
            }
            }

        } while (!op);



        cout << "The result of your calculation is: " << c << endl;
    }
    else {
        cout << "some of the entries is not integer." << endl << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << "Would you like to do another calculation (Y or N) ? ";
    cin >> y_n;

    if (y_n == 'Y' or y_n == 'y')
        problem1();
    else
        cout << "Thank you and good-bye!";
}

int main()
{
    problem1();
}

