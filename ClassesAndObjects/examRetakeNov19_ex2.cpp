#include <iostream>
#include <map>
#include <vector>

using namespace std;
/*
As a good citizen of the planet Earth you are assigned a task to help in proper eco-friendly garbage sorting.

You will be working in a special warehouse that only accepts glass, metal and plastic. 
if for any reason some other type of garbage is delivered to the warehouse – you should NOT process it. 
The garbage will be sorted in 3 big industrial lines.  One for “glass”, one for “metal” and respectively one for “plastic”. 
Depending on the current instruction - each new piece of garbage should be added in either the front of the existing ones in 
that line or respectively in the back. You should number each item with a unique counter identifier(shared for the whole warehouse) starting from 1.
Note: materials that should not be processed by your warehouse should NOT be numbered with a unique identifier.
Input
First read a single integer (N) representing how many rows of commands will follow.
Then read N rows of data for the commands.
Restrictions
Time limit: 250ms (0.25s) Memory limit: 16 MB

Examples
Input
3
glass front
glass back
glass front
Output
glass - 3 1 2
//explanation: //glass with id 1 is added to the front //glass with id 2 is added to the back //glass with id 3 is added to the front

Input
3
glass front
metal back 
metal front
Output
glass - 1
metal - 3 2

Input
7
glass back
glass back 
metal back
banana front
metal front 
plastic front
plastic back
Output
glass - 1 2
metal - 4 3  
plastic - 5 6
//explanation: //there are 7 items, but only unique //identifier counter goes only up to 6, //because the “banana” material should not //be processed
*/
int main() {
	int inputs, count = 0;
	map <string, vector < int > > wharehouse;

	cin >> inputs;

	while (inputs--) {
		count++;
		
		string garbageType;
		string command;
		vector<int> ids;

		cin >> garbageType >> command;
		if (garbageType != "glass" && garbageType != "metal" && garbageType != "plastic") {
			count--;
			continue;
		}
		if (command == "back") {
			wharehouse[garbageType].push_back(count);
		}
		else if (command == "front") {
			wharehouse[garbageType].emplace(wharehouse[garbageType].begin(), count);
		}
	}

	for (auto i = wharehouse.begin(); i != wharehouse.end(); i++)
	{
		cout << i->first << " - ";
		for (size_t elem : wharehouse[i->first]) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}