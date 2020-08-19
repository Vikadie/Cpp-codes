#include "IndexedSet.h"

IndexedSet::IndexedSet(): valuesSet(), valuesArray(nullptr) { }

IndexedSet::IndexedSet(const IndexedSet& other): valuesSet(other.valuesSet) 
{
	if (other.valuesArray != nullptr) {
		clearIndex();
		valuesSet.clear();
		for (size_t i = 0; i < other.size(); i++)
			valuesSet.insert(other.valuesArray[i]);
		buildIndex();
	}
	else
		valuesArray = nullptr;
}

void IndexedSet::add(const Value& v)
{
	valuesSet.insert(v);
	clearIndex();
}

size_t IndexedSet::size() const
{
	return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index)
{
	if (valuesSet.size() != index)
		if (valuesArray == nullptr)
			buildIndex();
	
	return valuesArray[index];
	// TODO: insert return statement here
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other)
{
	if (this != &other) {
		clearIndex();
		valuesSet.clear();
		for (size_t i = 0; i < other.size(); i++) {
			valuesSet.insert(other.valuesArray[i]);
		}
	}
	return (*this);
}

IndexedSet::~IndexedSet()
{
	clearIndex();
}

void IndexedSet::buildIndex()
{
	std::set<Value>::iterator itr = valuesSet.begin();
	clearIndex();
	valuesArray = new Value[valuesSet.size()];
	size_t i = 0;
	for (itr; itr != valuesSet.end(); itr++) {
		valuesArray[i] = (*itr);
		i++;
	}
}

void IndexedSet::clearIndex()
{
	delete[] valuesArray;
	valuesArray = nullptr;
}
