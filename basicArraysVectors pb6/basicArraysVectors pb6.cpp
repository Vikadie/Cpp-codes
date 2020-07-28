#include <iostream>
using namespace std;

void problem6() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                cout << (char)(i + 97) << (char)(j + 97) << (char)(k + 97) << endl;

}

int main()
{
    problem6();
}
