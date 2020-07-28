#include <iostream>
#include <vector>

using namespace std;

int main() {

    size_t Rrow = 0;

    cout << "Enter size of matrix: ";
    cin >> Rrow;

    vector < vector < int > > matrix1;

    for (size_t row = 0; row < Rrow; row++) {
        vector <int> wholeRow;
        for (size_t col = 0; col < Rrow; col++) {
            int entry;
            cout << "Enter matrix[" << row << "][" << col << "] = ";
            cin >> entry;
            wholeRow.push_back(entry);
        }
        matrix1.push_back(wholeRow);
    }
    
    int summ = 0;
    for (size_t j = 0; j < Rrow; j++)
        for (size_t i = 0; i < Rrow; i++)
            if (i > j)
                summ += matrix1[j][i];

    cout << summ;


	return 0;
}