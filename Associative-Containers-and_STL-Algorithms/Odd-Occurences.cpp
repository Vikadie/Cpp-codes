#include <iostream>
#include <utility>
#include <sstream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

int main_OddOccurences()
{
	// Odd Occurences
	map <string, int> inputStr;

	string input;
	getline(cin, input);

	istringstream in(input);
	string key;
	list <string> inputOrder = {};
	while (in >> key) {
		string lowerKey = "";
		lowerKey.resize(key.size());
		for (size_t i = 0; i < key.size(); i++) {
			if (key[i] >= 'A' && key[i] <= 'Z')
				lowerKey[i] = key[i] - ('A' - 'a');
			else
				lowerKey[i] = key[i];
		}
		inputStr[lowerKey]++;
		list<string>::iterator it = find(inputOrder.begin(), inputOrder.end(), lowerKey);
		if (it == inputOrder.end()) {
			inputOrder.push_back(lowerKey);
		}
	}

	for (auto i = inputStr.begin(); i != inputStr.end(); i++) {
		if (i->second % 2 == 0)
			inputOrder.remove(i->first);
	}

	while (1)
	{
		cout << inputOrder.front();
		inputOrder.pop_front();
		if (inputOrder.empty())
		{
			break;
		}
		else
		{
			cout << ", ";
		}
	}
	

	return 0;
}