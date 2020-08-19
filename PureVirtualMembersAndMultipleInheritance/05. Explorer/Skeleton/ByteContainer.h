#pragma once

#ifndef BYTE_CONTAINER_H
#define BYTE_CONTAINER_H

class ByteContainer {
	std::string s;
public:
	ByteContainer(std::string s): s(s) {}

	std::string getBytes() {
		return this->s;
	}

	~ByteContainer() {}
};
#endif // !BYTE_CONTAINER_H
