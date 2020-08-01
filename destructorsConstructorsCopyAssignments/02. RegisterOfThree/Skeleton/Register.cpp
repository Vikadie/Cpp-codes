#include "Register.h"
#include <memory>

static size_t num;
//static std::shared_ptr<Register> sp;

Register::Register(size_t numCompanies): 
	companiesArray(new Company[numCompanies]), 
	numAdded(numCompanies) {
	num = 0;
}

void Register::add(const Company& c)
{
	if (num < this->numAdded) {
		this->companiesArray[num] = c;
		num++;
	}
}

Company Register::get(int companyId) const
{
	/*for (size_t i = 0; i < sp->numAdded; i++) {
		if (sp->companiesArray[i].getId() == companyId) {
			return sp->companiesArray[i];*/
	for (size_t i = 0; i < this->numAdded; i++) {
		if (this->companiesArray[i].getId() == companyId) {
			return this->companiesArray[i];
		}
	}
	return Company();
}

//Register::~Register(){
//	delete[] this->companiesArray;
//}

Register& Register::operator=(const Register& other)
{
	
	if (this != &other) {
		this->numAdded = other.numAdded;
		this->companiesArray = other.companiesArray;
	}
	//sp.reset(this);
	return *this;
}

Register::Register(const Register& other) : numAdded(other.numAdded), companiesArray(other.companiesArray) { num = 0; }
