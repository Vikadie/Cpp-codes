#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

/*
int *fill_matrix(size_t R) {
    static int matrix[10][10];
    string str;
    size_t j = 0;
    cin.ignore();
    while (j < R) {
        getline(cin, str);
        istringstream in(str);
        int intTemp, i = 0;
        while (in >> intTemp) {
            matrix[j][i] = intTemp;
            i++;
        }
        j++;
    }

    return *matrix;
}
*/


void problem1() {
    const size_t rrow = 10;
    const size_t ccol = 10;
    int matrix1[rrow][ccol] = {};
    size_t R = 0;

    cin >> R;

    string line;
    size_t j = 0;
    cin.ignore();
    while (j < R) {
        getline(cin, line);
        istringstream in(line);
        int intTemp, i = 0;
        while (in >> intTemp) {
            matrix1[j][i] = intTemp;
            i++;
        }
        j++;
    }

    //int* matrix1 = fill_matrix(R);

    cin >> R;

    int matrix2[rrow][ccol] = {};
    j = 0;
    cin.ignore();
    while (j < R) {
        getline(cin, line);
        istringstream in(line);
        int intTemp, i = 0;
        while (in >> intTemp) {
            matrix2[j][i] = intTemp;
            i++;
        }
        j++;
    }
/*   int* matrix2 =  fill_matrix(R);

    for (size_t row = 0; row < R; row++) {
        for (size_t col = 0; col < ccol; col++) {
            cin >> matrix1[row][col];
        }
    }

    cin >> R;

    int matrix2[rrow][ccol];

    for (size_t row = 0; row < R; row++) {
        for (size_t col = 0; col < ccol; col++) {
            cin >> matrix2[row][col];
        }
    }
*/

    bool equal = true;
    for (size_t row = 0; row < rrow; row++) {
        for (size_t col = 0; col < ccol; col++)
            if (matrix1[row][col] != matrix2[row][col]) {
                equal = false; break;
            }
        if (equal == false) break;
    }

    if (equal)
        cout << "equal";
    else
        cout << "not equal";

}

int main()
{
    problem1();

    return 0;
}
