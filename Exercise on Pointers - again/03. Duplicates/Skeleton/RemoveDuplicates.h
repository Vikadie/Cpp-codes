#pragma once
#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include <list>
#include <set>
#include "Company.h"

void removeDuplicates(std::list<Company*>& companies) {
	std::list<Company*>::iterator itr = companies.begin();
	std::set<std::string> companySet;

	for (itr; itr != companies.end();) {
		if (companySet.find((*itr)->getName()) == companySet.end()) {
			companySet.insert((*itr)->getName());
			itr++;
		}
		else
			itr = companies.erase(itr);
	}
}
#endif // !REMOVE_DUPLICATES_H
