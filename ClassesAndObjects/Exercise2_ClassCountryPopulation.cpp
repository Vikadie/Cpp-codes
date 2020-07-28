#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
/*Write a program, make a Class Country. For given numbers the program should filter the countries by POPULATION only if the population is EQUAL to the country population.
*/
class countryClass {
private:
	string country, capital;
	int population = 0;
public:
	countryClass(string country_, string capital_, int population_) :
		country(country_),
		capital(capital_),
		population(population_) {

	}

	int getPopulation() { return(population); }

	void getCountryInfo() {
		
		cout << "Country -> " << country << endl
			<< "Capital -> " << capital << endl
			<< "Population (millions) -> " << population << endl;

		}
};


int main() {
	// filter countires by population
	int countriesNum;
	cout << "How many countries you want to input ? " << endl;
	cin >> countriesNum;

	vector <countryClass> countries;

	while (countriesNum--) {
		string country, capital;
		int population = 0;

		cout << "Enter Country -> " << endl;
		cin >> country;

		cout << "Enter Capital -> " << endl;
		cin >> capital;

		cout << "Enter Population -> " << endl;
		cin >> population;

		countries.push_back(countryClass(country, capital, population));
	}

	int filter;
	cout << "Which is the populations (millions) that you want to filter ? " << endl;
	cin >> filter;
	cout << "The countries with Population " << filter << " millions are:" << endl;
	vector <countryClass>::iterator countInt = countries.begin();
	for (countInt; countInt != countries.end(); countInt++) {
		if (countInt->getPopulation() == filter) {
			countInt->getCountryInfo();
		}
	}


	return 0;
}