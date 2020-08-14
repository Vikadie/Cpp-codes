#pragma once
#ifndef FILE_H
#define FILE_H

#include "FileSystemObjectsContainer.h"

class File: public ByteContainer {
	std::string s;
public:
	File(std::string filename, std::string s): FileSystemObjectsContainer(), FileSystemObject(filename), ByteContainer(s) {}

	virtual void add(const std::shared_ptr<FileSystemObject>& obj) override {}

	virtual size_t getSize() const override {
		return s.length();
	}

	virtual ~File() {}
};
#endif // !FILE_H
