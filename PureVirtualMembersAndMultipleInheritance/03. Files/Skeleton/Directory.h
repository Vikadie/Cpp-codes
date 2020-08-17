#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemObjectsContainer.h"

class Directory: public FileSystemObject, public FileSystemObjectsContainer {
	std::vector <std::shared_ptr<FileSystemObject> > files;
public:
	Directory(std::string directory): FileSystemObjectsContainer(), FileSystemObject(directory) { }

	virtual void add(const std::shared_ptr<FileSystemObject>& obj) override {
		this->files.push_back(obj);
	}

	virtual size_t getSize() const override {
		size_t total = 0;
		for (size_t i = 0; i < files.size(); i++) {
			total += (*files[i]).getSize();
		}
		return total;
	}

};

#endif // !DIRECTORY_H