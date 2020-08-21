#include "MemoryMonitor.h"
#include <iostream>

MemoryMonitor::MemoryMonitor()
{
}

MemoryMonitor::~MemoryMonitor()
{
}

void MemoryMonitor::pushNode(const int nodeSize)
{
	int size = 0;
	MemoryNode mn = MemoryNode();
	mn.size = nodeSize;
	mn.data = new int[nodeSize];
	size = nodeSize * sizeof(int);
	_nodes.push_back(mn);

	std::cout << "Pushed node with memory occupation: " << size << std::endl;
}

void MemoryMonitor::popNode()
{
	if (_nodes.size() > 0) {
		int size = 0;
		MemoryNode mn = _nodes.back();
		size += sizeof(int) * mn.size;

		std::cout << "Popped node with memory occupation: " << size << std::endl;
		_nodes.pop_back();
		delete[] mn.data;
	}
	else {
		std::cout << "No nodes to pop" << std::endl;
	}
}

void MemoryMonitor::printMemoryOccupation(const int numberOfNodes)
{
	int size = 0;
	if (numberOfNodes >= 0 && numberOfNodes <= _nodes.size())
		for (int i = 0; i < numberOfNodes; i++)
			size += sizeof(int) * _nodes[i].size;
	else
		for (auto e : _nodes) {
			size += sizeof(int) * e.size;
		}

	std::cout << "Memory occupation for first " << numberOfNodes << " memory nodes is: " << size << std::endl;
}

MemoryNode MemoryMonitor::getLastNode() const
{
	return _nodes.back();
}
