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
		name(name_),
		price(price_),
		rating(rating_)
	{
	}

	void addNew(vector<Coffee>& currentMenu) {
		currentMenu.push_back(Coffee(name, price, rating));
	}

	double getRating() { return (rating); }

	double getPrice() { 
		if (rating >= 4 && rating <= 5.99) 
			price *= 0.9;
		return price;
	}

	double priceChange(double discount) {
		price *= (1 - discount);
		return(price);
	}

	string getName() { return (name); }
	
	void setPrice(double price_) {
		price = price_;
	}
};
	string print(vector<Coffee>& currentMenu) {
		ostringstream ss;
		if (currentMenu.empty())
			ss << "The menu is empty" << endl;
		else
			for (auto i : currentMenu)
				ss << i.getName() << " " << i.getPrice() << endl; //getPrice / 0.9 if used the function changePrice() with discount
		return (ss.str());
	}

	void changePrice(vector<Coffee>& currentMenu, double discount) {
		for (unsigned i = 0; i < currentMenu.size(); i++)
			if (currentMenu[i].getRating() >= 4 && currentMenu[i].getRating() <= 5.99) {
				double newPrice = currentMenu[i].priceChange(discount/100);
				currentMenu.at(i) = Coffee(currentMenu[i].getName(), newPrice, currentMenu[i].getRating());
			}
	}

	void deleteDrink(vector<Coffee>& currentMenu, unsigned i) {
		if (currentMenu[i].getRating() < 4)
			currentMenu.erase(currentMenu.begin() + i);
		//if (currentMenu.size() == 1 && currentMenu[0].getRating() < 4)
			//currentMenu.clear();
	}


int main() {
	int numberOfDrinks;
	cin >> numberOfDrinks;
	
	string name;
	double price;
	double rating;
	
	vector <Coffee> Menu;
	
	while (numberOfDrinks--) {
		cin.ignore();
		getline(cin, name);
		cin >> price >> rating;
		
		Menu.push_back(Coffee (name, price, rating));
	}
	//double discount = 10;
	//changePrice(Menu, discount);
	for (int i = Menu.size() - 1; i >= 0; i--)
		if (Menu[i].getRating() < 4)            // Check drinks for low rating
			deleteDrink(Menu, i);    // Call delete drink by index
	cout << print(Menu);

	return 0;
}