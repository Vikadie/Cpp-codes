#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include "Company.h"
#include <list>
#include <set>

using namespace std;

void removeDuplicates(list<Company*>& companies) {
	set <string> companySet;
	for (list<Company*>::iterator c = companies.begin(); c != companies.end();) {
		if (companySet.find((*c)->getName()) == companySet.end()) {
			companySet.insert((*c)->getName());
			c++;
		}
		else {
			c = companies.erase(c);
		}
	}
}

#endif // !REMOVE_DUPLICATES_H
