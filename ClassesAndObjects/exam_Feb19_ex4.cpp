#include <iostream>
#include <vector>
#include <set>

using namespace std;
/* The Matrix
Write a program make a matrix that calculates the SUM of the simple numbers BELOW 2 diagonals.
HINT - Simple number is a number that can be divided by 1 and himself ( 1, 3, 5, 7, 13, 17 ... )
The maximum size of matrix should be 100x100
*/
int main() {
	vector < vector < int > > matrix;
	set <int > ansSet;
	unsigned size;
	int ssum = 0;

	cin >> size;
	for (unsigned i = 0; i < size; i++) {
		vector < int > rrow;
		for (unsigned j = 0; j < size; j++) {
			int element;
			cin >> element;
			rrow.push_back(element);
		}
		matrix.push_back(rrow);
	}
	int lowRow;
	if (size % 2 == 0) {
		lowRow = size / 2;
	}
	else {
		lowRow = (size + 1) / 2;
	}
	
	for (unsigned i = lowRow; i < size; i++)
		for (unsigned j = size - i; j < i; j++) {
			bool isPrime = true;
			for (unsigned k = 2; k < matrix[i][j]; k++) {
				if (matrix[i][j] % k == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime)
				ssum += (matrix[i][j]);
		}

	//for (auto i : ansSet)
	//	ssum += i;

	cout << ssum;

	return 0;
}