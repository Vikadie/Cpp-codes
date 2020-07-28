#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Coffee {

private:
	string name;
	double price = 0;
	double rating = 0;

public:
	Coffee() :
		name(""),
		price(0),
		rating(0) {
	}
	Coffee(string name_, double price_, double rating_) :
		name(name_)
	{
		if (rating_ > 10)
			rating = 10;
		else if (rating < 0)
			rating = 0;
		else
			rating = rating_;
		if (price < 0)
			price = 0;
		else
			price = price_;
	}
	string getName() { return (name); }
	double getRating() { return (rating); }
	double getPrice() { return (price); }
	double priceChange(double discount) {
		price *= (1 - discount);
		return(price);
	}
	void setPrice(double price_) {
		price = price_;
	}

	void addNew(vector<Coffee>& currentMenu) {
		currentMenu.push_back(Coffee(name, price, rating));
	}
};
string print(vector<Coffee>& currentMenu) {
	ostringstream ss;
	if (currentMenu.size() > 0)
		for (auto i : currentMenu)
			ss << i.getName() << " " << i.getPrice() << endl;
	else
		ss << "The menu is empty" << endl;
	return (ss.str());
}
void changePrice(vector<Coffee>& currentMenu, double discount) {
	for (unsigned i = 0; i < currentMenu.size(); i++)
		if (currentMenu[i].getRating() >= 4 && currentMenu[i].getRating() <= 5.99) {
			double newPrice = currentMenu[i].priceChange(discount / 100);
			currentMenu.at(i) = Coffee(currentMenu[i].getName(), newPrice, currentMenu[i].getRating());
		}
}

void deleteDrink(vector<Coffee>& currentMenu) {

	for (unsigned i = 0; i < currentMenu.size(); i++)
		if (currentMenu[i].getRating() < 4)
			if (i == currentMenu.size() - 1) {
				currentMenu.pop_back();
				break;
			}
			else
				currentMenu.erase(currentMenu.begin() + i);
	if (currentMenu.size() == 1 && currentMenu[0].getRating() < 4)
		currentMenu.clear();
}

void deleteDrink(vector<Coffee>& currentMenu, string name) {

	for (unsigned i = 0; i < currentMenu.size(); i++)
		if (currentMenu[i].getName() < name)
			currentMenu.erase(currentMenu.begin() + i);
}


int main() {
	int numberOfDrinks;
	cin >> numberOfDrinks;
	cin.ignore();
	string name, tempPrice, tempRating;
	double price;
	double rating;
	getline(cin, name);
	getline(cin, tempPrice);
	istringstream priceIn(tempPrice);
	priceIn >> price;
	getline(cin, tempRating);
	istringstream ratingIn(tempRating);
	ratingIn >> rating;
	//cin >> price >> rating >> ws;
	static vector <Coffee> Menu;
	Menu.push_back(Coffee(name, price, rating));
	numberOfDrinks--;
	while (numberOfDrinks--) {
		getline(cin, name);
		getline(cin, tempPrice);
		istringstream priceIn(tempPrice);
		priceIn >> price;
		getline(cin, tempRating);
		istringstream ratingIn(tempRating);
		ratingIn >> rating;
		//cin >> price >> rating >> ws;
		Coffee newMenu(name, price, rating);
		newMenu.addNew(Menu);
	}
	double discount = 10;
	changePrice(Menu, discount);
	deleteDrink(Menu);
	cout << print(Menu);

	return 0;
}