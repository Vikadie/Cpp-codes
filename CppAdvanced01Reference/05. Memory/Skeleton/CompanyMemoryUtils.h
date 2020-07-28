#ifndef COMPANY_MEMORY_UTILS_H
#define COMPANY_MEMORY_UTILS_H

#include "Company.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

typedef unsigned char byte;

using namespace std;

vector<Company> readCompaniesFromMemory(byte* memory, int numCompanies)
{
	vector <Company> companies;
	
	while (numCompanies--) {
		int companyId = 0;
		companyId = (int)(*memory++);
		string companyName = "";
		while (*memory != 0) {
			companyName += *memory++;
		}
		*memory++;
		int numEmployess = (int)(*memory++);
		vector<pair<char, char> > companyEmployees;
		pair <char, char> employeeInitials;
		for (unsigned i = 0; i < numEmployess; i++) {
			employeeInitials.first = *memory++;
			employeeInitials.second = *memory++;
			companyEmployees.push_back(employeeInitials);
		}

		companies.push_back(Company(companyId, companyName, companyEmployees));
	}
	return companies;
}


#endif // !COMPANY_MEMORY_UTILS_H

#pragma once
