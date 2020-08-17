#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

class Directory : public FileSystemObject, public FileSystemObjectsContainer {
public:
	std::vector<std::shared_ptr<FileSystemObject> > items;
	std::string dirName;
	Directory(std::string directoryName): FileSystemObject(directoryName), dirName(directoryName){}

	void add(const std::shared_ptr<FileSystemObject>& obj) override {
		this->items.push_back(obj);
	}

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const override {
		return this->items.begin();
	}

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const override {
		return this->items.end();
	}

	bool operator() (const std::shared_ptr<FileSystemObject> i, const std::shared_ptr<FileSystemObject> j) { return (i->getName() < j->getName()); }

	virtual size_t getSize() const {
		return items.size();
	}
};
#endif // !DIRECTORY_H
