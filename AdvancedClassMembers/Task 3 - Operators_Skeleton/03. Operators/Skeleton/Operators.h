#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*std::vector<std::string> operator<< (std::vector<std::string>& result, const std::string& str) {
	std::istringstream in(str);
	std::string temp;
	while (in >> temp)
		result.push_back(temp);
	return result;
}

std::string operator<< (const std::string& str1, const std::string& str2) {
	std::ostringstream out;
	out << str1 << str2;
	return out.str();
}*/

std::vector<std::string>& operator<< (std::vector<std::string>& result, const std::string& str) {
	result.push_back(str);
	return result;
}

std::string operator+ (std::string const str, int const i) {
	char c;
	
	if (i <= 9) {
		c = (char)i + '0';
		return (str + c);
	}
	else {
		int numModulo, numDiv = i;
		std::string numDivStr = "";
		//c = (char)(i % 10) + '0';
		while (numDiv > 0) {
			numModulo = numDiv % 10;
			numDiv = numDiv / 10;
			numDivStr += (char)numModulo + '0';
		}
		std::string num;
		for (int n = numDivStr.length() - 1; n >= 0; n--) {
			num.push_back(numDivStr[n]);
		}

		return (str + num);
	}
}

std::ostream& operator<< (std::ostream& output, const std::vector<std::string>& strVec) {
	for (size_t i = 0; i < strVec.size(); i++) {
		output << strVec[i] << std::endl;
	}
	
	return output;
}