#pragma once
#include <memory>
#include <sstream>
#include <vector>
#include <string>
#include "Company.h"
using namespace std;

Company* parseUniqueCompanies(string input, int& numCompanies, string(*func)(const Company&)) {
	istringstream in(input);
	string companyName;
	int companyId;
	vector <int> CompanyIds;
	vector <string> CompanyNames;
	while (in >> companyId >> companyName) {
		CompanyIds.push_back(companyId);
		CompanyNames.push_back(companyName);
	}

	

	vector<Company> companies;
	for (unsigned i = 0; i < CompanyIds.size(); i++) {
		Company* comp = new Company(CompanyIds[i], CompanyNames[i]);
		bool foundSimilar = 0;
		for (unsigned j = 0; j < companies.size(); j++)
			if (func(*comp) == func(companies[j])) {
				foundSimilar = 1;
				break;
			}
		if (!foundSimilar)
			companies.push_back(*comp);
	}
	
	numCompanies = companies.size();
	//vector<Company>::iterator c = companies.begin();
	Company* ptrToReturn = new Company[numCompanies];
	for (unsigned i = 0; i < numCompanies; i++)
		*(ptrToReturn + i) = companies[i];

	return ptrToReturn;
}