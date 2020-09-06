#include "Range.h"
#include <vector>

Range::Range(): rangeFirst(INT_MIN), rangeLength(0), valueCounts(nullptr) {}

void Range::add(T value)
{
	if (this->empty())
		resize(value, value);
	else if (value < rangeFirst)
		resize(value, rangeFirst + rangeLength - 1);
	else if (value >= rangeFirst + rangeLength)
		resize(rangeFirst, value);

	valueCounts[getIndex(value)]++;
}

size_t Range::getCount(T value) const
{
	if (!(value < rangeFirst || value >= rangeFirst + rangeLength))
		return valueCounts[this->getIndex(value)];
	return 0;
}

void Range::clear()
{
	delete[] valueCounts;
	valueCounts = nullptr;
}

void Range::resize(T first, T last)
{
	int newSize = std::abs(first - last) + 1;
	size_t* temp = new size_t[newSize]{ 0 };
	
	int diff = 0;
	if (first < rangeFirst) // when value < rangeFirst
		diff = rangeFirst - first;

	for (int i = 0; i < rangeLength; i++)
		temp[i + diff] = valueCounts[i];

	rangeFirst = first;
	rangeLength = newSize;
	delete[] valueCounts;
	valueCounts = temp;
}

bool Range::empty() const
{
	if (valueCounts == nullptr)
		return true;
	return false;
}

Range::Range(const Range& other)
{
//	if (this->valueCounts != nullptr)
//		clear();
	rangeFirst = other.rangeFirst;
	rangeLength = other.rangeLength;
	valueCounts = new size_t[other.rangeLength]{ 0 };
	for (int i = 0; i < other.rangeLength; i++)
		valueCounts[i] = other.valueCounts[i];
}

Range& Range::operator=(const Range& other)
{
	if (this != &other) {
		if (valueCounts != nullptr)
			clear();
		if (other.valueCounts != nullptr) {
			rangeFirst = other.rangeFirst;
			rangeLength = other.rangeLength;
			valueCounts = new size_t[other.rangeLength]{ 0 };
			for (int i = 0; i < other.rangeLength; i++)
				valueCounts[i] = other.valueCounts[i];
		}
	}
	return (*this);
}

Range::~Range()
{
	delete[] valueCounts;
	valueCounts = nullptr;
	rangeFirst = INT_MIN;
	rangeLength = 0;
}

size_t Range::getIndex(T value) const
{
	if (value < rangeFirst + rangeLength)
		return (value - rangeFirst);
	return 0;
}
