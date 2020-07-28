#include "Find.h"
#include "Company.h"
#include <iostream>

using namespace std;

Company* find(vector<Company*> companies, int searchId)
{	
	for (auto it: companies)
		if (searchId == it->getId()) {
			return it;
		}	
	return nullptr;
}