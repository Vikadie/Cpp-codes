#pragma once
#ifndef FILE_H
#define FILE_H

#include "FileSystemObject.h"
#include "ByteContainer.h"


class File: public FileSystemObject, public ByteContainer {
	std::string content;
public:
	File(std::string filename, std::string content): FileSystemObject(filename), ByteContainer(content), content(content) {}

	virtual size_t getSize() const {
		return content.length();
	}

	virtual ~File() {}
};

#endif // !1
