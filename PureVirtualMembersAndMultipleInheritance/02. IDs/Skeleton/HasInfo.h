#pragma once
#ifndef HAS_INFO_H
#define HAS_INFO_H

class HasInfo {
public:
	HasInfo() {}

	virtual std::string getInfo() const = 0;

	virtual ~HasInfo(){}

};

#endif // !HAS_INFO_H
