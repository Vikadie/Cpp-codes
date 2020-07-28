#ifndef FIND_H
#define FIND_H
#pragma once

#include "Company.h"
#include <vector>

using namespace std;

Company* find(vector<Company*> companies, int searchId)
{
	for (auto it : companies)
		if (searchId == it->getId()) {
			return it;
		}
	return nullptr;


#endif // !FIND_H