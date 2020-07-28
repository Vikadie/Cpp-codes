#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <string>


using namespace std;

int main() {
	string startNum, endNum;

	string str;
	getline(cin, startNum);
	getline(cin, endNum);
	
	//cout << INT32_MAX << "-------" << to_string(INT32_MAX).size() << "-------" << to_string(INT32_MAX) << endl;
	long long sn = 0, en = 0;
	unsigned num = 1;
	cout << INT64_MAX << "  ----  " << INT32_MAX << "  ----  " << endl;
	if (endNum.size() < to_string(INT64_MAX).size() && stoll(endNum) < INT64_MAX) {
		sn = stoll(startNum);
		en = stoll(endNum);

		set <long long int> ans;
		for (long long int i = sn; i < en; i += num) {
			if (i % 45 == 0) {
				ans.insert(i); num = 45;
			}
		}
		for (auto j : ans) 
			cout << j << endl;
	}
	else {
		bool diff = false;
		string start = "";
		string end = "";
		string leading = "";
		if (startNum.size() < endNum.size())
			while (startNum.size() < endNum.size())
				startNum = "0" + startNum;
		for (unsigned i = 0; i < endNum.size(); i++)
			if (!diff && startNum[i] == endNum[i]) {
				leading += startNum[i];
			}
			else {
				if (i <= startNum.size())
					start += (startNum[i]);
				end += endNum[i];
				diff = true;
			}

		if (start != "" && end != "") {
			sn = stoll(start);
			en = stoll(end);
		}

		set <long long int> ans;
		
		for (long long int i = sn; i < en; i += num) {
			if (i % 45 == 0) {
				ans.insert(i);
				num = 45;
			}
		}
		unsigned k = startNum.size() - leading.size();
		for (auto j : ans) {
			cout << leading;
			string str = to_string(j);
			while (str.size() < k)
				str = "0" + str;
			cout << str << endl;
		}
	}

	return 0;
}