#ifndef SORT_BY_H
#define SORT_BY_H

#include "Company.h"
#include <algorithm>

bool (*globalFunc)(const Company&, const Company&) = nullptr;

bool anotherSort(Company* companyPtrsBegin, Company* companyPtrsEnd) {
	return globalFunc(*companyPtrsBegin, *companyPtrsEnd);
}

void sortBy(Company** companyPtrsBegin, Company** companyPtrsEnd, bool (*func)(const Company&, const Company&)) {
	globalFunc = func;
	std::sort(companyPtrsBegin, companyPtrsEnd, anotherSort);
}

#endif // !SORT_BY_H
