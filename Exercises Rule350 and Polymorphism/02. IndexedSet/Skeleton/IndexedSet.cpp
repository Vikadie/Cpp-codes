#include "IndexedSet.h"

IndexedSet::IndexedSet(): valuesSet(), valuesArray(nullptr) { }

IndexedSet::IndexedSet(const IndexedSet& other)
{
	//if (this->valuesArray != nullptr)
		//clearIndex();
	this->valuesSet = other.valuesSet;
	buildIndex();
}

void IndexedSet::add(const Value& v)
{
	this->valuesSet.insert(v);
	clearIndex();
}

size_t IndexedSet::size() const
{
	return this->valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index)
{
	if (valuesArray == nullptr)
		buildIndex();
	return valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other)
{
	if (this != &other) {
		clearIndex();
		this->valuesSet = other.valuesSet;
		this->valuesArray = new Value[other.size()];
		for (size_t i = 0; i < other.size(); i++) {
			this->valuesArray[i] = other.valuesArray[i];
		}
	}
	return (*this);
}

IndexedSet::~IndexedSet()
{
	clearIndex();
	valuesSet.clear();
}

void IndexedSet::buildIndex()
{
	//clearIndex();
	this->valuesArray = new Value[this->size()];
	auto itr = valuesSet.begin();
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
