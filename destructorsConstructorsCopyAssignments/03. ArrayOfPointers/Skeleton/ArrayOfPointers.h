#pragma once
#ifndef ARRAY_OF_POINTERS_H
#define ARRAY_OF_POINTERS_H

#include <vector>
#include "Company.h"

class ArrayOfPointers {
private:
	std::vector<Company*> vecCompanies;
public:
	ArrayOfPointers() {}

	//ArrayOfPointers(const ArrayOfPointers& other)  {	}

	void add(Company* c) {
		this->vecCompanies.push_back(c);
		//delete c;
	}

	size_t getSize() {
		return this->vecCompanies.size();
	}

	Company* get(const size_t i) {
		return vecCompanies[i];
	}

	/*ArrayOfPointers& operator=(const ArrayOfPointers& other) {
		if (this != other) {
			this->c = other.c;
			this->;
		}
		return *this;
	}
	*/
	~ArrayOfPointers() {
		for (size_t i = 0; i < vecCompanies.size(); i++) {
			delete vecCompanies[i];
			vecCompanies[i] = nullptr;
		}
			
	}
};
#endif // !ARRAY_OF_POINTERS_H
