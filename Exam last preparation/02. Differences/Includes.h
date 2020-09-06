#pragma once
#ifndef INCLUDES_H
#define INCLUDES_H

#include <vector>
#include "City.h"
#include <iostream>
#include <sstream>

std::istream& operator>>(std::istream& stream, City& c) {
	unsigned int censusYear = 0;
	std::string name;
	int population = 0;

	stream >> name >> population >> censusYear;

	c = City(censusYear, name, population);

	return stream;
}

class CityDiff {
	std::string name;
	int population;
public:
	CityDiff(std::string _name, int _population) : name(_name), population(_population) {}

	std::string getName() {
		return this->name;
	}

	int getPopulation() {
		return this->population;
	}

	friend std::ostream& operator<<(std::ostream& out, const CityDiff& a);
};

CityDiff operator-(const City& a, const City& b) {
	std::string name;
	int population = 0;
	std::ostringstream ss;

	ss << a.getName() << " (" << a.getCensusYear();
	if (a.getName() == b.getName()) {
		ss << " vs " << b.getCensusYear() << ")";
	}
	else {
		ss << ") vs. " << b.getName() << " (" << b.getCensusYear() << ")";
	}
	name = ss.str();

	population = (int)(a.getPopulation() - b.getPopulation());

	CityDiff c = CityDiff(name, population);
	return c;
}

std::ostream& operator<<(std::ostream& out, CityDiff& a) {
	out << a.getName() << std::endl << "population: ";
	if (a.getPopulation() > 0)
		out << "+";
	out << a.getPopulation() << std::endl;
	return out;
}

#endif // !INCLUDES_H
