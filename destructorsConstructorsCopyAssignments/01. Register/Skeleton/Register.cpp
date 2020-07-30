#include "Register.h"

static size_t num;

Register::Register(size_t numCompanies): companiesArray(new Company[numCompanies]), numAdded(numCompanies)
{
	num = 0;
}

void Register::add(const Company& c)
{
	if (num < numAdded)
		this->companiesArray[num] = c;
		num++;
}

Company Register::get(int companyId) const
{
	Company c;
	for (size_t i = 0; i < this->numAdded; i++) {
		if (companiesArray[i].getId() == companyId)
			return companiesArray[i];
	}
	return Company();
}

Register::~Register()
{
	delete[] this->companiesArray;
}
