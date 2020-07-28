#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
/*
Products and Cities
Write a program use a STL structure that a given number of Cities, Product and PricePerProduct, calculates the Total price (product * pricePerProduct)
The first number is how many cities we want to input
The second is the CITY
The third is the price per product
The fourth is the quantity of products

*/
int main() {
	map < string, double> citiesMap;
	int numCities;
	cin >> numCities;

	while (citiesMap.size() < numCities) {

	string cityName;
	cin >> cityName;

	double price;
	cin >> price;
	int quantity;
	cin >> quantity;

	citiesMap[cityName] += price * quantity;
	}
	
	for (pair <string, double> e : citiesMap) {
		cout << e.first << " " << e.second << endl;
	}


	return 0;
}