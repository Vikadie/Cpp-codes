#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <iostream>
#include <vector>
#include <string>

/*std::vector<std::string> operator+(const std::vector<std::string>& other) {
	std::vector<std::string> result;
	for (unsigned i = 0; i < this->size(); i++) {
		std::string str;
		str = this->at(i) + other[i];
		result.push_back(str);
	}
	return result;
}*/

std::vector<std::string> operator+(const std::vector<std::string>& a, const std::vector<std::string>& b) {
	std::vector<std::string> result;
	for (unsigned i = 0; i < a.size(); i++) {
		std::string str;
		str = a[i] + " " + b[i];
		result.push_back(str);
	}
	return result;
}

#endif // !SUMOFVECTORS_H