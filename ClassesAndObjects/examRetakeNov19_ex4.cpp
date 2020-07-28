#include <iostream>
#include <vector>

using namespace std;

// See desription in "4. Bomberman_Description.pdf"

int main() {
	// create the matrix

	unsigned row, col;
	cin >> row >> col;
	vector < vector < int> > matrix;

	string values;
	for (unsigned i = 0; i < row; i++) {
		cin >> values;

		vector<int> tiles;
		for (unsigned j = 0; j < col; j++) {
			tiles.push_back( (int)(values[j] - '0') );
		}

		matrix.push_back(tiles);
	}

	size_t rounds;
	cin >> rounds;

	unsigned power = 0;
	while (rounds--) {
		string command;
		cin >> command;
		
		bool bombed = false;
		int points;

		if (command == "bomb") {
			unsigned x, y;
			cin >> x >> y;

			points = matrix[x][y];
			matrix[x][y] = 0;
			
			for (unsigned i = 1; i <= power; i++) {
				if (x + i < row) {
					points += matrix[x + i][y];
					matrix[x + i][y] = 0;
				}
				if (x >= i) {
					points += matrix[x - i][y];
					matrix[x - i][y] = 0;
				}
				if (y + i < col) {
					points += matrix[x][y + i];
					matrix[x][y + i] = 0;
				}
				if (y >= i) {
					points += matrix[x][y - i];
					matrix[x][y - i] = 0;
				}
			}

			//if (points > 1)
				cout << points << " points" << endl;
			//else
				//cout << points << " point" << endl;
		}
		if (command == "power") {
			string change;
			cin >> change;
			if (change == "up") {
				power++;
				cout << "Increased bomb power to " << power << endl;
			}
			else if (change == "down" and power >= 1) {
				power--;
				cout << "Decreased bomb power to " << power << endl;
			}
				else
					power = 0;
		}

	}

	/* matrix check
	for (unsigned i = 0; i < row; i++) {
		
		for (unsigned j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}