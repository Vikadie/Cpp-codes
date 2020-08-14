#pragma once
#ifndef HAS_ID_H
#define HAS_ID_H

class HasId {
public:
	HasId() {}

	virtual int getId() const = 0;

	virtual ~HasId(){}
};

#endif // !HAS_ID_H
