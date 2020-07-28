#include <iostream>
#include <vector>
using namespace std;

int main() {
	unsigned repet;
	cin >> repet;
	vector <int> sortedVec;
	while (repet--) {
		int newInt;
		cin >> newInt;

		vector<int>::iterator it = sortedVec.begin();
		for (; it < sortedVec.end(); it++) {
			if (newInt > *it) {
				break;	
			}
		}
		sortedVec.insert(it, newInt);
		}
		
	for (vector<int>::iterator i = sortedVec.begin(); i != sortedVec.end(); i++) {
		cout << *i << " ";
	}

	return 0;

}