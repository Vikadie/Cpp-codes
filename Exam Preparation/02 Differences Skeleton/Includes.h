#pragma once
#ifndef INCLUDES_H
#define INCLUDES_H

#include <vector>
#include "City.h"
#include <iostream>
#include <sstream>


std::istream& operator>>(std::istream& in, City& c) {
	unsigned int censusYear;
	std::string name;
	size_t population;
	
	in >> name >> population >> censusYear;

	c = City(censusYear, name, population);

	return in;
}

#define CityDiff std::string

CityDiff operator-(City a, City b) {
	std::ostringstream toReturn;
	std::string sign;
	int difference = a.getPopulation() - b.getPopulation();
	if (difference >= 0)
		sign = "+";
	else
		sign = "";
	if (a.getName() == b.getName()) {
		toReturn << a.getName() << " (" << a.getCensusYear() << " vs. " << b.getCensusYear() << ")" << std::endl
			<< "population: " << sign << difference << std::endl;
	}
	else {
		toReturn << a.getName() << " (" << a.getCensusYear() << ") vs. " << b.getName() << " (" << b.getCensusYear() << ")" << std::endl
			<< "population: " << sign << difference << std::endl;
	}

	return toReturn.str();
}

#endif // !INCLUDES_H
