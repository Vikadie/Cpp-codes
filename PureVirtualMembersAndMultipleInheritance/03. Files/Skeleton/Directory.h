#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemObjectsContainer.h"

class Directory: public ByteContainer {
	
public:
	Directory(std::string directory): FileSystemObjectsContainer(), FileSystemObject(""), ByteContainer(directory) { }

	virtual void add(const std::shared_ptr<FileSystemObject>& obj) override {}

	virtual size_t getSize() const override {}

};

#endif // !DIRECTORY_H