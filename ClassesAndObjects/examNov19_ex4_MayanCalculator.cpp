#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>


using namespace std;

/*
Mayan Calculator
Since ancient times the Mayan people had special flow of describing numbers.
Your job is to understand their technique of describing numbers and start re-using it.
You will be provided with exact description for the digits “0123456789” (exactly in that order).
Their representation may span on several lines.
After that you will be provided with a simple integer, which you should represent in the provided Mayan representation.
NOTE: the width of the numbers is not provided to you, but you are assured that:
width of digit 0 == width of digit 1 == width of digit 2 == … == width of digit 9
Example input:
2                           //number of lines for Mayan digits representation
aabbccddeeffgghhiijj        //digits ‘0123456789’ 1st row
aabbccddeeffgghhiijj        //digits ‘0123456789’ 2nd row
8330                        //number to represent

Example output:
iiddddaa
iiddddaa

Input
First a single integers (N) indicating how many lines of ‘digit representing data’.
Next read (N) lines of ‘digit representing data’. Digit will only be represented in the ‘0123456789’ exact order.
On the last row – read a single integer (T) – the number to represent (print to the console) with the Mayan description.

*/
int main() {
	int N;
	cin >> N >> ws;
	
	vector <vector< vector <char> > >mayanAlphabet;

	int task;
	while (N--) {
		
		string digitRepre;
		getline(cin, digitRepre);

		//cout << digitRepre;
		size_t len = digitRepre.size();
		size_t digitSize = len / 10;
		vector <vector <char> > code;
		for (size_t i = 0; i < len; i += digitSize) {
			vector <char> digit;
			for (size_t j = 0; j < digitSize; j++)
				digit.push_back(digitRepre[i + j]);

			code.push_back(digit);
		}

		mayanAlphabet.push_back(code);

	}

	cin >> task;
	string s = to_string(task);

	for (size_t it = 0; it < mayanAlphabet.size(); it++) {
		for (size_t i = 0; i < s.size(); i++) {
			int index = (int)(s[i] - '0');
			for (size_t j = 0; j < mayanAlphabet[it][index].size(); j++)
				cout << mayanAlphabet[it][index][j];
		}
		cout << endl;
	}

	return 0;
}