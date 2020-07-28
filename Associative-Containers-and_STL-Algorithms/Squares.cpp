#include <iostream>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int main_squares()
{
	// Squares
	// ititializing
	multimap <int, int, greater<int> > squareMap;

	// read a list of integers
	string input;
	getline(cin, input);

	istringstream in(input);
	int number;
	while (in >> number) {
		int i = sqrt(number);
		if (number == i * i)
			squareMap.insert(pair<int, int> (number, 1));
	}

	for (pair<int, int> i : squareMap)
		cout << i.first << " ";

	return 0;
}