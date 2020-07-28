#pragma once
#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"
#include <iostream>

using namespace std;
// Place your code here
void removeInvalid(list<Company*>& companies) {
	
	list <Company*>::iterator c = companies.begin();
	while (c != companies.end())
		if ((*c)->getId() < 0) 
		{	
			delete (*c); 
			c = companies.erase(c);
		}
		else 
		{ c++; }
		
}

#endif // !REMOVE_INVALID_H
