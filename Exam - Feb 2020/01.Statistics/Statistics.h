#pragma once
#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include "Structs.h"
#include <iostream>
#include <algorithm>

class Statistics {
private:
	std::vector<PersonInfo> elder;
	std::vector<PersonInfo> adults;
	std::vector<PersonInfo> minors;
public:
	Statistics() {}

	void printStatistics() {
		std::sort(elder.begin(), elder.end(), [](const PersonInfo& a, const PersonInfo& b)
			{
				return a.age > b.age;
			});

		std::cout << "Elders data:" << std::endl;
		for (size_t i = 0; i < elder.size(); i++) {
			std::cout << elder[i].firstName << " " << elder[i].lastName << " " << elder[i].height << std::endl;
		}
		
		std::sort(adults.begin(), adults.end(), [](const PersonInfo& a, const PersonInfo& b)
			{
				return a.age < b.age;
			});

		std::cout << "Adults data:" << std::endl;
		for (size_t i = 0; i < adults.size(); i++) {
			std::cout << adults[i].firstName << " " << adults[i].lastName << " " << adults[i].height << std::endl;
		}

		std::sort(minors.begin(), minors.end(), [](const PersonInfo& a, const PersonInfo& b)
			{
				return a.age < b.age;
			});

		std::cout << "Minors data:" << std::endl;
		for (size_t i = 0; i < minors.size(); i++) {
			std::cout << minors[i].firstName << " " << minors[i].lastName << " " << minors[i].height << std::endl;
		}
	};

	friend bool operator< (const PersonInfo& a, const PersonInfo& b);
	friend Statistics& operator<<(Statistics& s, PersonInfo& person);
};


#endif // !STATISTICS_H
