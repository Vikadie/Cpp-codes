#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
/*
Min and Max Temperature
Write a program for a weather channel. The channel needs to know how many towns we have, and the Minimum and Maximum RECORD temperature in the town.
WARNING: The outputs should be in alphabetical order !
For the current program you'll need a STL Container.
Input 2 ( Number of DIFFERENT towns ) Sofia (Town 1) -17 (Min temperature) 24 (Max temperature) Sofia (Town 1) -18 (Min temperature) 23 (Max temperature) Plovdiv (Town 2) -2 (Min temperature) 8 (Max temperature)
Output Plovdiv -2 8 Sofia -18 24
Restrictions In the first case Sofia the MIN temperature is -17, MAX temperature is 24. In the second case the MIN temperature is -18, MAX temperature is 23.
YOU CAN SEE THAT REMAINS THE RECORDED LOWEST OR BIGGEST ONE ! 
*/
int main() {
	int towns;
	cin >> towns;

	map < string , vector < double> > wether;
	 do {
		string townName;
		cin >> townName;
		double maxTemp, minTemp;
		vector <double> MinMax;
		cin >> minTemp;
		MinMax.push_back(minTemp);
		cin >> maxTemp;
		MinMax.push_back(maxTemp);
		
		auto result = wether.find(townName);
		if (result != wether.end()) {
			if (result->second[0] > minTemp)
				result->second[0] = minTemp;
			if (result->second[1] < maxTemp)
				result->second[1] = maxTemp;
		} else
			wether[townName] = MinMax;
	} while (wether.size() < towns);

	// printing
	for (auto i = wether.begin(); i != wether.end(); i++) {
		cout << i->first << " ";
		for (auto j : i->second)
			cout << j << " ";
		cout << endl;
	}
	
	return 0;
}
