#pragma once
#ifndef FILTER
#define FILTER

#include "NodeBase.h"
#include <algorithm>

class FilterNode : public NodeBase {
	std::vector<byte> filtered;
public:
	FilterNode(size_t id, std::vector<byte> filtered) : NodeBase(id), filtered(filtered) {}

	void process(byte data) override {
		auto itr = std::find(filtered.begin(), filtered.end(), data);
		if (itr == filtered.end()) 
			this->sendToConnected(data);
	}

};
#endif // !FILTER