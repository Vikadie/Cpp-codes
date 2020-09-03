#pragma once
#ifndef READER_H
#define READER_H
#include <iostream>
#include <sstream>

class Reader {
	std::istream& in;
public:
	Reader(std::istream& in): in(in) { }

	friend std::istream& operator>>(Reader& r, std::vector<int>& arr);
};

std::istream& operator>>(Reader& r, std::vector<int>& arr) {
	std::string str;
	getline(r.in, str);
	std::istringstream i(str);
	int num;
	while (i >> num)
		arr.push_back(num);

	return r.in;
}
#endif // !READER_H
