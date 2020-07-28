#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
Car Dealership A business man has an AutoHouse, he needs a program that calculates all the costs that he has. 
The program should have the following informations ( datas  ): AutoHouse - Capital  ( the capital can not be zero or negative, 
if the condition is true, the Capital default value should be 10 000 ) AutoHouse - Overcharge tax : ( the overcharge can not be zero or negative, 
if the condition is true the Overcharge default value should be 500 ). This is the tax of single sold car.  

- EXAMPLE : Total Incoming = price of the car + overcharge AutoHouse - Storage of all cars.  
- HINT :   You can use array or vector AutoHouse Methods:  - Setters, Getters ( if you need )  \
- Show All Cars ( Print informations about the cars )  
- Buy A Car ( Add cars in storage only if the Capital is sufficient, decrease the Capital in function     of the car price  )  
- Sell All Cars ( Empty the storage and prints Capital Before sells and After Sells, increase the      Capital in function of Total Incoming )

Car - Make ( Brand of car ) 
Car - Year ( Year of manufacture, can not be under 1950 and after 2019, if the condition is true, the Year default value should be 2000 ) 
Car - Price ( Price of car, floating point number, can not be zero or negative, if the condition is true the Price default value should be 1000 ) 
Car Methods :  - Setters, Getters ( if you need )  - Print Info ( Prints MAKE, YEAR, PRICE of the car )
Write a MENU that has the current select options: 1 - Show All Cars 2 - Sell All Cars 3 - Buy a Car 0 - Exit menu
*/

class Car {
private:
	string make;
	int year = 0;
	double price = 0;
public:
	Car() {
		year = 0; price = 0;
	}
	Car(string brand, int year_, double price_) : make(brand) {
		if (year_ >= 1950 && year_ <= 2019)
			year = year_;
		else
			year = 2000;
		if (price_ > 0)
			price = price_;
		else
			price = 1000;
	}
	void setCar(string brand, int year_, double price_) {
		make = brand;
		if (year_ >= 1950 && year_<= 2019)
			year = year_;
		else
			year = 2000;
		if (price_ > 0)
			price = price_;
		else 
			price = 1000;
	}
	string getBrand() { return(make); }
	int getYear() { return(year); }
	double getPrice() { return(price); }
	void ShowAll() {
		cout << "Make : " << make << endl
			<< "Year : " << year << endl
			<< "Price : " << price;
	}
};

class AutoHouse {
private:
	double capital = 0, tax = 0;
	vector < Car > storage;
public:
	AutoHouse() {
		capital = 0;
		tax = 0;
	}
	AutoHouse(double capital_, double tax_) {
		if (capital_ > 0)
			capital = capital_;
		if (tax_ > 0)
			tax = tax_;
	}
	void print() {
		for (auto i : storage) {
			i.ShowAll();
		}
	}
	void buyCar(Car& other) {
		if (capital >= other.getPrice()) {
			storage.push_back(other);
			capital -= other.getPrice();
		}
		//else {
		//	cout << "Not enough capital!";
		//}
	}
	void sellAll() {
		cout << "Capital before sell : " << capital << endl;
		for (auto i : storage) {
			capital += i.getPrice() + tax;
		}
		storage.clear();
		cout << "Capital after sell : " << capital << endl;
	}
	vector < Car> getStorage() {
		return(storage);
	}
};

/*enum choice { Exit = 0, ShowAll, Sell, Buy };

choice menu(AutoHouse& one) {

	cout << "Press 1 to Show All Cars..." << endl
		<< "Press 2 to Sell All Cars..." << endl
		<< "Press 3 to Buy a Car..." << endl
		<< "Press 0 to Exit Menu...;" << endl << endl;

	int choosen;
	cin >> choosen;
	switch ((choice)choosen)
	{
	case Exit:
		break;
	case ShowAll:
		for (auto i : one.getStorage())
		{
			i.ShowAll(); cout << endl;
		}
		break;
	case Sell:
		one.sellAll();
		break;
	case Buy: 
	{
		string model;
		cout << "Model: ";
		cin >> model;
		int year;

		do {
			cout << "Enter year between 1950 and 2019: ";
			cin >> year;
		} while (year < 1950 || year > 2019);
		double price;
		do {
			cout << "Enter price: ";
			cin >> price;
		} while (price <= 0);

		Car other(model, year, price);
		one.buyCar(other);
		break; 
	}
	default:
		cout << "It is a wrong choice!";
		break;
	}

	return((choice)choosen);
}*/

int main() {
	double initCapital;
	cin >> initCapital;

	double taxOvercharge;
	cin >> taxOvercharge;

	AutoHouse one(initCapital, taxOvercharge);

	vector <int> vecOfChoices;
	int userChoice = -1;
	bool exitWhile = false;
	while (!exitWhile)
	{
		cin >> userChoice;

		switch (userChoice)
		{
		case 0:
		{
			exitWhile = true;
		}
		break;
		case 1:
		case 2:
		case 3:
		{
			vecOfChoices.push_back(userChoice);
		}
		break;

		default:
			break;

		}

	}

	sort(vecOfChoices.begin(), vecOfChoices.end(), std::greater<int>());

	for (unsigned int i = 0; i < vecOfChoices.size(); i++)
	{
		switch (vecOfChoices.at(i))
		{
		case 1:
		{
			for (auto i : one.getStorage())
			{
				i.ShowAll(); cout << endl;
			}
		}
		break;

		case 2:
		{
			one.sellAll();
		}
		break;

		case 3:
		{
			string model;
			//cout << "Model: ";
			cin >> model;
			int year;

			do {
				//cout << "Enter year between 1950 and 2019: ";
				cin >> year;
			} while (year < 1950 || year > 2019);
			double price;
			do {
				//cout << "Enter price: ";  ot kiki  
				cin >> price;
			} while (price <= 0);

			Car other(model, year, price);
			one.buyCar(other);
			break;
		}
		break;

		default:
			break;
		}
	}

	return 0;
}