#pragma once
#ifndef ARRAY_H
#define ARRAY_H

template<class T> 
class Array {
private:
	size_t arraySize;
	T* array;
	
	
public:
	Array(size_t _arraySize): arraySize(_arraySize), array(new T[arraySize]){}

	Array(const Array& other) : arraySize(other.arraySize) {
		delete[] array;
		array = new T[other.arraySize];
		for (size_t i = 0; i < other.arraySize; i++)
			this->array[i] = other.array[i];
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			this->arraySize = other.arraySize;
			delete[] array;
			array = new T[other.arraySize];
			for (size_t i = 0; i < other.arraySize; i++)
				array[i] = other.array[i];
		}
		return (*this);
	}

	T& operator[](size_t num) {
		return this->array[num];
	}

	size_t getSize() {
		return this->arraySize;
	}

	T* begin() {
		return &array[0];
	}

	T* end() {
		return &array[arraySize];
	}

	~Array() {
		delete[] array;
		array = nullptr;
	}
};
#endif // !ARRAY_H
