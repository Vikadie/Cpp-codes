#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	// Miners	
	unordered_map <string, int> miners;
	vector <string> inputOrder;
	string resource;
	int quantity;

	 while(cin >> resource && resource != "stop" && cin >> quantity) {
		 
		 /*
		 //cheking if this this resource appear for the first time 
		 vector <string>::iterator it = find(inputOrder.begin(), inputOrder.end(), resource);
		 if (it == inputOrder.end())
			inputOrder.push_back(input);
		*/

		 // adding the resource -> quantity pair in the map or just updating the value of quantity
		 miners[resource] += quantity;

		 //cheking if this this resource appear for the first time
		 if (miners[resource] == quantity)
			 inputOrder.push_back(resource);
		
	 }

	 // printing the resource -> quantity pairs in the order of their first insertion
	 for (vector<string>::iterator i = inputOrder.begin(); i != inputOrder.end(); i++) {
		 cout << *i << " -> " << miners[*i] << endl;
	 }
	return 0;
}