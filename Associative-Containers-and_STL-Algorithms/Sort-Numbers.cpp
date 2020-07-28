#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main_SortNumbers() 
{//Sort Numbers
	//definition
	set <float> inpSet;
	float inpNum;

	// inserting the list in the set
	string input;
	getline(cin, input);

	istringstream in(input);
	while (in >> inpNum) {
		inpSet.insert(inpNum);
	}

	//printing the set
	set <float> ::iterator i = inpSet.begin();
	while (1) {
		cout << *i;
		i++;
		if (i == inpSet.end())
			break;
		cout << " <= ";
	}

	return 0;
}