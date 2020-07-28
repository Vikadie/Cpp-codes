/*
*/


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	string command;
	map < string, pair <string, size_t> > table;
	vector <size_t> answer;
	string id;
	string name;
	size_t age;
	pair<string, size_t> tableData;

	cin >> command;
	while (command != "end") {
		map <string, pair<string, size_t> >::iterator ids = table.begin();
		if (command == "entry") {
			cin >> id >> name >> age;
			tableData.first = name;
			tableData.second = age;
			table[id] = tableData;
		}
		else if (command == "name") {
			string searchedName;
			cin >> searchedName;
			size_t count = 0;
			for (ids; ids != table.end(); ids++) {
				if (ids->second.first == searchedName) {
					count++;
				}
			}
			answer.push_back(count);
		}
		else if (command == "age") {
			size_t startAge, endAge;
			cin >> startAge >> endAge;
			size_t count = 0;
			for (ids; ids != table.end(); ids++) {
				if (ids->second.second >= startAge && ids->second.second < endAge)
					count++;
			}
			answer.push_back(count);
		}
		cin >> command;
	}

	for(auto i: answer)
		cout << i << endl;
	return 0;
}