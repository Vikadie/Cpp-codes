#pragma once
#ifndef FILE_H
#define FILE_H

#include "FileSystemObject.h"
#include "ByteContainer.h"

class File : public FileSystemObject, public ByteContainer {
	std::string s;
public:
	File(std::string filename, std::string s) : FileSystemObject(filename), ByteContainer(s), s(s) {}

	virtual size_t getSize() const override {
		return s.length();
	}
};
#endif // !FILE_H
