#pragma once
#include <memory>
using namespace std;

shared_ptr<Company> makeCompany(vector <string> properties) {
	 
	
	int id = stoi(properties[0]);
	string name = properties[1];
	
	vector<pair<char, char> > companyEmployees;
	pair <char, char> employeeInitials;
	for (unsigned e = 2; e < properties.size(); e++)
		{
			employeeInitials.first = properties[e][0];
			employeeInitials.second = properties[e][1];
			companyEmployees.push_back(employeeInitials);
		}

	shared_ptr<Company> company(new Company(id, name, companyEmployees));
	
	return company;
	
}