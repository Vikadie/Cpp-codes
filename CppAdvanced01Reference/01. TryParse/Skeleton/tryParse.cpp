#include <iostream>
#include <string>
#include "TryParse.h"

using namespace std;

bool tryParse(const string& str, int& x)
{	
	if (str.empty() || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')) return false;
	x = stoi(str); 
	return true;
}
