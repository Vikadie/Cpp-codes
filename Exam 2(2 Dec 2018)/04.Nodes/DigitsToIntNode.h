#pragma once
#ifndef DIGITS
#define DIGITS

#include "NodeBase.h"

class DigitsToIntNode : public NodeBase {
	int result;
	std::string accumulator;
public:
	DigitsToIntNode(size_t id): NodeBase(id) {}

	void process(byte data) override {

		if (data != '.') {
			if (data >= '0' && data <= '9')
				accumulator += data;// -'0';
		}
		else {
			result = stoi(accumulator);
			accumulator = "";
			this->sendToConnected(result);
		}
	}


};
#endif // !DIGITS

