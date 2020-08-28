#include "FixedArray.h"

FixedArray::FixedArray(const int arraySize): BrokenArray(arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
		_array[i] = 0;
	}
}

FixedArray::~FixedArray()
{
	
	//BrokenArray::~BrokenArray();
}

FixedArray::FixedArray(const FixedArray& other): FixedArray(other.getSize())
{
	for (int i = 0; i < BrokenArray::getSize(); ++i)
	{
		this->_array[i] = other._array[i];
	}
}

FixedArray& FixedArray::operator=(const FixedArray& other)
{
	if (this != &other) {
		BrokenArray::operator=(other);
		for (int i = 0; i < other.getSize(); ++i)
		{
			_array[i] = other._array[i];
		}
	}
	return *this;
}

void FixedArray::addValueToMemory(const int value)
{
	for (int i = 0; i < BrokenArray::getSize(); ++i)
	{
		BrokenArray::_array[i] += value;
	}
}

int FixedArray::getMemorySumValue() const
{
	int sum = 0;

	sum += BrokenArray::getMemorySumValue();

	return sum;
	
}
