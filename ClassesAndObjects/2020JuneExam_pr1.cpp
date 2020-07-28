#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
// Shopping List
int main() {

	int shoppingItems;
	cin >> shoppingItems;

	double sum = 0;
	map <double, vector <string>, greater <double> > shoppingList;
	while (shoppingItems--) {
		string name;
		double price;
		double itemCount;

		cin >> name >> price >> itemCount;

		double finalPrice = price * itemCount;
		shoppingList[finalPrice].push_back(name);
		if (finalPrice > 0)
			sum += finalPrice;
	}
	
	cout << "The total sum is: " << sum << " lv." << endl;
	for (pair <double, vector<string> > prices : shoppingList) {
		for (unsigned i = 0; i < prices.second.size(); i++)
			if (prices.first > 0)
			cout << prices.second[i] << " " << prices.first << endl;
	}

	return 0;
}