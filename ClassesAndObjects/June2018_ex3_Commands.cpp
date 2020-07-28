#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string in;
	cin >> in;

	vector <int> inVec;
	while(in != "end") {

		if (in == "sum") {
			int a = inVec.back();
			inVec.pop_back();
			int b = inVec.back();
			inVec.pop_back();
			inVec.push_back(a + b);
		}
		else if (in == "subtract") {
			int a = inVec.back();
			inVec.pop_back();
			int b = inVec.back();
			inVec.pop_back();
			inVec.push_back(a - b);
		}
		else if (in == "concat") {
			/*int a = inVec.back();
			inVec.pop_back();
			if (inVec.back() < 0)
				inVec.push_back(a);
			else {
				int b = inVec.back();
				inVec.pop_back();
				inVec.push_back(a + b * 10);
			}*/

			string num1 = to_string(inVec.back());
			inVec.pop_back();
			string num2 = to_string(inVec.back());
			inVec.pop_back();

			string result = num2 + num1;
			int number = stoi(result);
			inVec.push_back(number);
		}
		else if (in == "discard")
			inVec.pop_back();
		else {
			int num;
			if (in[0] == '-' || isdigit(in[0])) {
				num = stoi(in);
				inVec.push_back(num);
			}
			}
		cin >> in;
	}

	for(unsigned j = 0; j < inVec.size(); j++)
		cout << inVec[j] << endl;

	return 0;
}