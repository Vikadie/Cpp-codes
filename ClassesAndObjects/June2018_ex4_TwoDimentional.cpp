#include <iostream>
#include <vector>

using namespace std;

void transformBack(vector < vector <char> >& matrix, int startRow, int startCol, int startChar, int charFill) {

}

int main() {
	static int row, col;
	cin >> row >> col;
	vector <vector <char> > matrix;

	for (unsigned i = 0; i < row; i++) {
		vector <char> rrow;
		for (unsigned j = 0; j < col; j++) {
			char startChar;
			cin >> startChar;
			rrow.push_back(startChar);
		}
		matrix.push_back(rrow);
	}

	char charFill;
	cin >> charFill;

	int startRow, startCol;
	cin >> startRow >> startCol;


	char startChar = matrix[startRow][startCol];
// 4 reazdela ot tochkata +1 -1 po i, +1 -1 po j (ot nachaloto do kraq)
	
	// ot tochkata nazad po redove
	for (int i = startRow; )

	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < col; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}