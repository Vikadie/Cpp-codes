#include "Store.h"

void Store::remove(const int index)
{
	auto itr = _laptops.begin() + index;
	_laptops.erase(itr);
}

void Store::copy(const int fromIndex, const int toIndex)
{
	_laptops[toIndex] = _laptops[fromIndex];
}
