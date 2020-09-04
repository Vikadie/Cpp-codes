#pragma once
#ifndef SORT_BY_H
#define SORT_BY_H

#include "Company.h"
#include <algorithm>

bool (*globalFunc)(const Company& a, const Company& b) = nullptr;

bool anotherSort(Company* companyBegin, Company* companyEnd) {
	return globalFunc(*companyBegin, *companyEnd);
}

void sortBy(Company** companyPtrsBegin, Company** companyPtrsEnd, bool	(*func)(const Company& a, const Company& b)) {
	globalFunc = func;
	std::sort(companyPtrsBegin, companyPtrsEnd, anotherSort);
}
#endif // !SORT_BY_H