#ifndef ORDERED_INSERTER_H
#define ORDERED_INSERTER_H

#include <iostream>
#include <vector>
#include "Company.h"

using namespace std;

class OrderedInserter {
private:
	vector <const Company*> &companies;
public:
	OrderedInserter(vector<const Company*> &companies_) :
		companies{ companies_ } {
	};

	void insert(const Company* c) {
		vector <const Company*>::iterator it = this->companies.begin();
		if (companies.empty())
			this->companies.insert(it, c);
		else
			for (unsigned i = 0; i < companies.size(); i++) {
				if (companies[i]->getId() >= c->getId()) {
					this->companies.insert(it + i, c);
					break;
				}
				if (i == companies.size() - 1) {
					this->companies.push_back(c);
					break;
				}
			}
	}
};
#endif // !ORDERED_INSERTER_H
