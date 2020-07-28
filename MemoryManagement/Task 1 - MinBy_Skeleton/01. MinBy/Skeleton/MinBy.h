#pragma once
#ifndef MIN_BY_H
#define MIN_BY_H

// Place your code here
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string minBy(vector<string> values, bool (*func)(const string&, const string&)) {
	string answer = "";
	if (values.size() > 0)
		answer = values[0];
	for (string v : values)
		if (func(v, answer))
			answer = v;

	return answer;
}

#endif // !MIN_BY_H
