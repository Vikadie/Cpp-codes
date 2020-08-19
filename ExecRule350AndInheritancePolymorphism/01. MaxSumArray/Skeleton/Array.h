#pragma once
#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array {
private:
	size_t arraySize;
	T* array;
public:
	Array(size_t arrSize): arraySize(arrSize), array(new T[arrSize]) {}

	Array(const Array& other) : arraySize(other.arraySize) {
		delete[] array;
		array = new T[other.arraySize];
		for (size_t i = 0; i < other.arraySize; i++)
			array[i] = other.array[i];
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

	T& operator[](size_t index) {
		return array[index];
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
	}

};
#endif // !ARRAY_H
