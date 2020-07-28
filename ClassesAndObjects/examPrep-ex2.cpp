#include <iostream>

using namespace std;

int main() {
	unsigned t;
	cin >> t;

	unsigned count = 0;
	char arr[100] = {};
	for(unsigned i = 0; i < t; i++) {
		char element;
		cin >> element;
		arr[count] = element;
		count++;
	}

	bool hasEntered = false;
	for (unsigned i = 0; i < t; i++) {
		if (arr[i] >= '0' and arr[i] <= '9') {
			cout << arr[i] << " ";
			hasEntered = true;
		}
	}
	if (hasEntered) {
		cout << endl;
		hasEntered = false;
	}
	for (unsigned i = 0; i < t; i++) {
		if (arr[i] >= 'a' and arr[i] <= 'z') {
			cout << arr[i] << " ";
			hasEntered = true;
		}
	}
	if (hasEntered) {
		cout << endl;
		hasEntered = false;
	}
	for (unsigned i = 0; i < t; i++) {
		if (!isalnum(arr[i]) or (arr[i] >= 'A' and arr[i] <= 'Z'))
			cout << arr[i] << " ";
	}

	return 0;
}