#pragma once
#ifndef SCI_H
#define SCI_H

#include "Discovery.h"
#include <map>
#include <vector>

class ScientificField {
	std::map<int, std::vector<std::string> > Philosophy, Linguistics, Physics, Chemistry;
public:
	ScientificField operator<<(const Discovery& v) {
		std::string name = v.name;
		int fieldType = v.fieldType;
		int year = v.year;
		std::string scientistName = v.scientistName;

		std::ostringstream os;
		os << name << " " << year << " - " << scientistName;
		std::string str = os.str();
		switch (fieldType)
		{
		case 1: this->Philosophy[year].push_back(str); break;
		case 2: this->Linguistics[year].push_back(str); break;
		case 3: this->Physics[year].push_back(str); break;
		case 4: this->Chemistry[year].push_back(str); break;
		default:
			break;
		}
		return *this;
	}

	void print() {
		std::cout << "Physics:" << std::endl;
		for (std::pair<int, std::vector<std::string> > p : Physics) {
			for (int i = 0; i < p.second.size(); i++)
				std::cout << p.second[i] << std::endl;
		}

		std::cout << "Linguistics:" << std::endl;
		for (std::pair<int, std::vector<std::string> > p : Linguistics) {
			for (int i = 0; i < p.second.size(); i++)
				std::cout << p.second[i] << std::endl;
		}

		std::cout << "Philosophy:" << std::endl;
		for (std::pair<int, std::vector<std::string> > p : Philosophy) {
			for (int i = 0; i < p.second.size(); i++)
				std::cout << p.second[i] << std::endl;
		}

		std::cout << "Chemistry:" << std::endl;
		for (std::pair<int, std::vector<std::string> > p : Chemistry) {
			for (int i = 0; i < p.second.size(); i++)
				std::cout << p.second[i] << std::endl;
		}
	}
};
#endif // !SCI_H
