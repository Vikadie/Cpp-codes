#pragma once
#ifndef BYTE_CONTAINER_H
#define BYTE_CONTAINER_H

#include "File.h"

class ByteContainer: public virtual FileSystemObjectsContainer, public virtual FileSystemObject {
	std::string s;
public:
	ByteContainer(std::string s): FileSystemObjectsContainer(), FileSystemObject(s), s(s) {}

	virtual void add(const std::shared_ptr<FileSystemObject>& obj) override {}

	virtual size_t getSize() const override {
		size_t s_t = s.length();
		return s_t;
	}

	virtual std::string getBytes() {
		return s;
	}
};

#endif // !BYTE_CONTAINER_H
