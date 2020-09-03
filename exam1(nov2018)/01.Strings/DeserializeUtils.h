#pragma once
#ifndef DESERIALIZE_UTILS_H
#define DESERIALIZE_UTILS_H

#include <string>

std::vector<std::string> deserializeStrings(char* serialized) {
	std::vector<std::string> s;
	int i = 0;
	int size = serialized[i];
	
	while (size-- > 0) {
		i++;
		int length = serialized[i];
		std::string str = "";
		while (length-- > 0) {
			i++;
			str += serialized[i];
		}
		s.push_back(str);
		
	}
	return s;
}
#endif // !DESERIALIZE_UTILS_H
