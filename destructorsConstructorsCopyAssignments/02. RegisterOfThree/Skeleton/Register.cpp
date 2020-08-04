#include "Register.h"


Register::Register(size_t numCompanies): 
	companiesArray(new Company[numCompanies]), 
	numAdded(0) {}

void Register::add(const Company& c)
{
	
	Company* ptrToArr = companiesArray;
	ptrToArr += numAdded;
	*ptrToArr = c;
	numAdded++;
	
	/*if (num < this->numAdded) {
		this->companiesArray[num] = c;
		num++;
	}*/
}

Company Register::get(int companyId) const
{
	for (size_t i = 0; i < this->numAdded; i++) {
		if (this->companiesArray[i].getId() == companyId) {
			return this->companiesArray[i];
		}
	}
	return Company();
}

Register::~Register(){
	delete[] this->companiesArray;
}

Register& Register::operator=(const Register& other)
{
	
	Company* newData;
	if (other.numAdded == 0) {
		newData = nullptr;
	}
	else {
		newData = new Company[other.numAdded];
	}
	this->numAdded = other.numAdded;
	this->companiesArray = newData;
	for (size_t i = 0; i < other.numAdded; i++) {
		this->companiesArray[i] = other.companiesArray[i];
	}
	return *this;
	
	/*if (this != &other) {
		this->numAdded = other.numAdded;
		this->companiesArray = other.companiesArray;
	}
	
	return *this;*/
}

Register::Register(const Register& other) : numAdded(other.numAdded), companiesArray(other.companiesArray) { }
