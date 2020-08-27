#pragma once
#ifndef CITY_UTILS
#define CITY_UTILS

#include <map>
#include "City.h"

City* initCity(std::string name, size_t population) {
	return new City(name, population);
}

std::map <size_t, const City*> groupByPopulation(std::vector<const City*> cities, size_t& totalPopulation) {
	std::map <size_t, const City*> toReturn;
	totalPopulation = 0;
	std::vector<const City*>::iterator itr = cities.begin();
	for (itr; itr != cities.end(); itr++) {
		size_t population = (*itr)->getPopulation();
		toReturn[population] = (*itr);
		totalPopulation += population;
	}

	return toReturn;
}
#endif // !CITY_UTILS
