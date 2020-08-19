#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

class Directory: public FileSystemObject, public FileSystemObjectsContainer {

public:
	std::vector< std::shared_ptr<FileSystemObject> > items;
	std::string dirName;
	Directory(std::string dirName): FileSystemObject(dirName), dirName(dirName) {}

	virtual size_t getSize() const override {
		return items.size();
	}

	virtual void add(const std::shared_ptr<FileSystemObject>& obj) override {
		items.push_back(obj);
	}

	virtual std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const override {
		return items.begin();
	}
	virtual std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const override {
		return items.end();
	}

	virtual void remove(std::shared_ptr<FileSystemObject> obj) override {
		items.erase(std::find(this->items.begin(), this->items.end(), obj));
	}

	virtual ~Directory () {}
};
#endif // !DIRECTORY_H
