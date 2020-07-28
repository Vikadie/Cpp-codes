#include <iostream>
#include <vector>

using namespace std;

int main() {

    unsigned N;
    cin >> N;
    vector < vector < int> > matrix;

    for (unsigned i = 0; i < N; i++) {
        vector <int> rowVector;
        for (unsigned j = 0; j < N; j++) {
            int ele;
            cin >> ele;
            rowVector.push_back(ele);
        }
        matrix.push_back(rowVector);
    }

    int sum = 0;
    for (unsigned i = 0; i < N; i++) {
        
        for (unsigned j = 0; j < N; j++) {
            
            if (i != j && j != N-1-i && matrix[i][j] % 2 != 0)
                sum += matrix[i][j];
        }
        
    }

    cout << "The sum is: " << sum;

	return 0;
}