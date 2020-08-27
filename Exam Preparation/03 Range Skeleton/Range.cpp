#include "Range.h"
#include <iostream>

Range::Range(): rangeFirst(0), rangeLength(0), valueCounts(nullptr) { }

void Range::add(T value)
{
	/*if (rangeLength == 0) {
		rangeLength = 1;
		rangeFirst = value;
		valueCounts = new size_t[rangeLength];
		valueCounts[0] = 1;
	}
	else {
		bool flagSet = false;
		for (int i = 0; i < rangeLength; i++)
			if (value == rangeFirst + i) {
				valueCounts[i]++;
				//std::cout << "Value at index " << i << " incremeted to " << valueCounts[i] << std::endl;
				flagSet = true;
				break;
			}
			else if (value < rangeFirst + i)
			{
				int diff = (rangeFirst - value);
				rangeFirst = value;
				size_t* temp = new size_t[rangeLength];
				for (int i = 0; i < rangeLength; i++)
					temp[i] = valueCounts[i];
				delete[] valueCounts;
				valueCounts = new size_t[rangeLength + diff];
				valueCounts[0] = 1;
				int j = 0;
				while (diff > j)
				{
					valueCounts[j + 1] = 0;
					j++;
				}
				for (int i = 0; i < rangeLength; i++)
					valueCounts[diff + i] = temp[i];
				rangeLength += diff;
				flagSet = true;
				break;
			}
		if (!flagSet) {
			int diff = (value - rangeFirst - (rangeLength - 1));
			size_t* temp = new size_t[rangeLength];
			for (int i = 0; i < rangeLength; i++)
				temp[i] = valueCounts[i];
			delete[] valueCounts;
			valueCounts = new size_t[rangeLength + diff];
			for (int i = 0; i < rangeLength; i++)
				valueCounts[i] = temp[i];
			for (int i = 0; i < diff; i++) {
				valueCounts[rangeLength + i] = 0;
			}
			rangeLength += diff;
			valueCounts[rangeLength - 1] = 1;
			//std::cout << "Value at index " << rangeLength - 1 << " incremeted to " << valueCounts[rangeLength - 1] << std::endl;
		}
	}*/

	if (rangeLength == 0) // empty
		resize(value, value);
	else if (value < rangeFirst)
		resize(value, rangeFirst + rangeLength - 1);
	else if (value >= rangeFirst + rangeLength)
		resize(rangeFirst, value);

	valueCounts[getIndex(value)]++;
}

size_t Range::getCount(T value) const
{
	if (value < rangeFirst || value >= rangeFirst + rangeLength)
		return 0;
	size_t index = static_cast<size_t>(value - rangeFirst);
	return valueCounts[index];
}

void Range::clear()
{
	delete[] valueCounts;
	valueCounts = nullptr;
	rangeFirst = 0;
	rangeLength = 0;
}

void Range::resize(T first, T last)
{
	int newSize = std::abs(first - last) + 1;
	size_t* temp = new size_t[newSize];
	for (int i = 0; i < newSize; i++)
		temp[i] = 0;
	int diff = 0;
	if (first < rangeFirst) // when value < rangeFirst
		diff = rangeFirst - first;

	for (int i = 0; i < rangeLength; i++)
		temp[i + diff] = valueCounts[i];

	/*if (diff)
		for (int i = 0; i < diff; i++)
			temp[i] = 0;
	else
		for (int i = 0; i < newSize - rangeLength; i++)
			temp[i + rangeLength] = 0;*/

	rangeFirst = first;
	rangeLength = newSize;
	delete[] valueCounts;
	valueCounts = temp;
}

bool Range::empty() const
{	
	if (rangeLength == 0)
		return true;
	return false;
}

Range::Range(const Range& other): rangeFirst(0), rangeLength(0), valueCounts(nullptr)
{
	if (other.valueCounts) {
		rangeFirst = other.rangeFirst;
		rangeLength = other.rangeLength;
		valueCounts = new size_t[other.rangeLength]; // Range::CopyValues(other)
		for (int i = 0; i < other.rangeLength; i++)
			valueCounts[i] = other.valueCounts[i];
	}
}

Range& Range::operator=(const Range& other)
{
	if (this != &other) {
		if (valueCounts)
			clear();
		if (other.valueCounts) {
			this->rangeFirst = other.rangeFirst;
			this->rangeLength = other.rangeLength;
			valueCounts = new size_t[other.rangeLength]; // Range::CopyValues(other)
			for (int i = 0; i < other.rangeLength; i++)
				valueCounts[i] = other.valueCounts[i];
		}
	}
		// TODO: insert return statement here
		return *this;
}

Range::~Range()
{
	clear();
}

size_t Range::getIndex(T value) const
{
	size_t index = static_cast<size_t>(value - rangeFirst);
	return index;
}
