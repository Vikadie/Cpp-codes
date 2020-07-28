#pragma once
#include "Company.h"

using namespace std;



byte* serializeToMemory(string companiesString, size_t &bytesWritten) {

	int firstByteToWrite = 0;
	string str = "";
	istringstream companiesIn(companiesString);
	Company company;
	while (companiesIn >> company) {
		int id; unsigned employeesNum; string name; vector<pair<char, char> > employees;
		id = company.getId();
		str += (char)id;
	//	cout << "id: "<< str << endl;
		name = company.getName();
		str += name;
		str += (char)0;
	//	cout << "+name: " << str << endl;
		employees = company.getEmployees();
		employeesNum = employees.size();
		str += (char)employeesNum;
	//	cout << "+employeesNum: " << str << endl;
		for (unsigned i = 0; i < employeesNum; i++) {
			str += employees[i].first;
			str += employees[i].second;
		}
		firstByteToWrite++;

	//	cout << "whole row added" << str << endl;
	}
	str = (char)firstByteToWrite + str;
	bytesWritten = str.length();

	byte* answer = new byte[bytesWritten];
	for (unsigned i = 0; i < bytesWritten; i++)
		*(answer + i) = str[i];
	return answer;
}