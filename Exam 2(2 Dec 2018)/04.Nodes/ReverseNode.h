#pragma once
#ifndef REVERSE
#define REVERSE

#include "NodeBase.h"
#include <stack>

class ReverseNode : public NodeBase {
	std::stack<byte> result;
public:
	ReverseNode(size_t id) : NodeBase(id) {}

	void process(byte data) override {
		
		if (data != '.') {
			result.push(data);
		}
		else {
			while (!result.empty()) {
				byte dataR = result.top();
				result.pop();
				this->sendToConnected(dataR);
			}
		}
	}


};
#endif // !REVERSE
