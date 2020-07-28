#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void problem2() {
    size_t Rrow = 0;
    size_t Ccol = 0;

    cin >> Rrow >> Ccol;

    vector < vector < int > > matrix1;

    string line;

    cin.ignore();
    for(size_t row = 0; row < Rrow; row++){
        getline(cin, line);
        istringstream in(line);
        vector <int> wholeRow;
        for (size_t col = 0; col < Ccol; col++) {
            int intTemp;
            in >> intTemp;
            wholeRow.push_back(intTemp);
        }
        matrix1.push_back(wholeRow);
    }

    int searchNum;

    cin >> searchNum;

    bool foundOne = false;
    for (size_t row = 0; row < Rrow; row++) {
        size_t col;
        for (col = 0; col < Ccol; col++)
            if (matrix1[row][col] == searchNum) {
                cout << row << " " << col << endl;
                foundOne = true;
            }
        if (row == Rrow - 1 && foundOne == false)
            cout << "not found" << endl;
    }

}

int main()
{
    problem2();

    return 0;
}
