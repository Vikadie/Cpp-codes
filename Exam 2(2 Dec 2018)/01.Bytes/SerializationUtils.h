#pragma once
#ifndef SERIALIZATION_UTILS_H
#define SERIALIZATION_UTILS_H

char* serializeStrings(const std::vector<std::string>& lines, int& serializedSize) {
	serializedSize = lines.size();
	for (size_t i = 0; i < lines.size(); i++)
		serializedSize += lines[i].length();
	char* toReturn = new char[serializedSize];
	int j = 0;
	for (size_t i = 0; i < lines.size(); i++) {
		toReturn[j] = (char)lines[i].size(); j++;
		for (size_t len = 0; len < lines[i].length(); len++) {
			toReturn[j] = lines[i][len];
			j++;
		}
	}
	return toReturn;
}
#endif // !SERIALIZATION_UTILS_H
