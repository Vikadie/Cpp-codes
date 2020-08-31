#pragma once
#ifndef SUM
#define SUM

#include "NodeBase.h"

class SumNode : public NodeBase {
	int result = 0;
public:
	SumNode(size_t id) : NodeBase(id) {}

	void process(byte data) override {
		
		if (data != 0) {
			//if (isdigit(data))
			result += (data);// -'0');
		} 
		else
			this->sendToConnected(result);
	}



};
#endif // !SUM