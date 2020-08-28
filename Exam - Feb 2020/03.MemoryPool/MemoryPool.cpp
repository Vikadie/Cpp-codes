#include "MemoryPool.h"

MemoryPool::MemoryPool(const int memoryPoolSize): _MEMORY_POOL_SIZE(memoryPoolSize), _memoryBuffer(new int[memoryPoolSize]), _isMemoryBufferOccupied(new bool[memoryPoolSize])
{
	for (int i = 0; i < memoryPoolSize; i++) {
		_memoryBuffer[i] = 0;
		_isMemoryBufferOccupied[i] = false;
	}
}

MemoryPool::~MemoryPool()
{
	delete[] _memoryBuffer;
	delete[] _isMemoryBufferOccupied;
	_memoryBuffer = nullptr;
	_isMemoryBufferOccupied = nullptr;
}

ErrorCode MemoryPool::requestMemory(MemoryNode& outNode)
{
	if (outNode.size > _MEMORY_POOL_SIZE)
		return ErrorCode::REQUEST_FAILURE_BIGGER_THAN_BUFFER;
	int freeMemory = 0;
	bool free = false;
	for (int i = 0; i < _MEMORY_POOL_SIZE; i++)
		if (_isMemoryBufferOccupied[i] == false) {
			freeMemory++;
			if (!free) {
				outNode.bufferStartIndex = i;
				free = true;
			}
		}
	if (outNode.size > freeMemory)
		return ErrorCode::REQUEST_FAILURE_NOT_ENOUGH_MEMORY;
	outNode.memory = new int[outNode.size];
	for (int i = 0; i < outNode.size; i++)
		outNode.memory[i] = 0;
	occupyMemory(outNode);
	return ErrorCode::REQUEST_SUCCESS;
}

void MemoryPool::releaseMemory(const MemoryNode& outNode)
{
	int memoryToRelease = outNode.size;
	for (int i = 0; i < _MEMORY_POOL_SIZE; i++)
	{
		if (_isMemoryBufferOccupied[i] == true) {
			_isMemoryBufferOccupied[i] = false;
			memoryToRelease--;
		}
		if (memoryToRelease == 0)
			break;
	}
}

void MemoryPool::zeroMemoryValue(const MemoryNode& node)
{
	int memoryToRelease = node.size;
	
	for (int i = node.bufferStartIndex; i < _MEMORY_POOL_SIZE; i++)
	{
		if (_isMemoryBufferOccupied[i] == true) {
			_isMemoryBufferOccupied[i] = false;
			*(_memoryBuffer + i) = 0;
			memoryToRelease--;
		}
		if (memoryToRelease == 0)
			break;
	}
}

void MemoryPool::occupyMemory(const MemoryNode& node)
{
	for (int i = 0; i < node.size; i++) {
		*(_memoryBuffer + i + node.bufferStartIndex) = node.memory[i];
		_isMemoryBufferOccupied[i + node.bufferStartIndex] = true;
	}
}
