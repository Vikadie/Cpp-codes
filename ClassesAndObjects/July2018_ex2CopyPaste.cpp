#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	string str;
	getline(cin, str);
	
	string command;
	cin >> command;

	stack <string > copiedText;
	while (command != "end") {
		
		if (command == "copy") {
			int indexStart, indexStop;
			cin >> indexStart >> indexStop;
			
			string copy;
			if (indexStart < 0)
				indexStart = 0;
			else
				indexStart = str.find_last_of(' ', indexStart) + 1;
				//while (indexStart > 0 && !isspace(str[indexStart - 1]))
				//	indexStart--;

			if (indexStop > str.size())
				copy = str.substr(indexStart, str.size() - indexStart);
			else {
				//while (!isspace(str[indexStop]) && indexStop != string::npos)
				//	indexStop++;
				indexStop = str.find(' ', indexStop);
				copy = str.substr(indexStart, indexStop - indexStart);
			}
			copiedText.push(copy);
		}
		else if (command == "paste") {
			int position;
			cin >> position;
			if (copiedText.size() > 0) {
				string toPaste;
				toPaste = copiedText.top();
				copiedText.pop();
				if (!isspace(str[position]))
					str.insert(position, toPaste);
				else
					str.insert(position, " " + toPaste);
	
			}
		}
		cin >> command;
	}

	cout << str << endl;

	return 0;
}