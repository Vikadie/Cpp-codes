#pragma once
#ifndef CITU_UTILS
#define CITU_UTILS

#include "City.h"
#include <map>

City* initCity(std::string name, size_t population) {
	return new City(name, population);
}

std::map<size_t, const City*> groupByPopulation(std::vector<const City*> cities, size_t& totalPopulation) {
	totalPopulation = 0;

	std::map<size_t, const City*> citiesByPopulation;
	int population = 0;
	for (auto c: cities) {
		population = c->getPopulation();
		citiesByPopulation[population] = c;
		totalPopulation += population;
	}

	return citiesByPopulation;
}

#endif // !CITU_UTILS
