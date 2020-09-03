#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

template<class T, class Generator>
class Sequence {
private:
	Generator generator;
	std::vector<T> vecGen;
public:
	void generateNext(int numToGenerate) {
		for (int i = 0; i < numToGenerate; i++)
			this->vecGen.push_back(this->generator());
	}

	class Iterator {
		const std::vector<T>& generatorReference;
		int currentIndexInOurGenerator;

		Iterator(const std::vector<T>& generatorReference_, int currentIndexInOurGenerator_) :
			generatorReference(generatorReference_),
			currentIndexInOurGenerator(currentIndexInOurGenerator_) {}
	public:
		// the begin() and end() user defined function inside the Iterator class are static to be seen outside of the class
		static Iterator begin(const std::vector<T>& generator) {
			return Iterator(generator, 0);
		}

		static Iterator end(const std::vector<T>& generator) {
			return Iterator(generator, -1);
		}

		// request of overload of 'operator * ()'
		const T& operator*() const {
			return this->generatorReference.at(this->currentIndexInOurGenerator);
		}

		// request for 'binary operator !=' and 'unary operator ++' operators overload
		Iterator& operator++() { // it is requested by the 'for' loop in the cpp file
			this->currentIndexInOurGenerator++;
			return *this; // *this will request overload of 'operator * ()' to "access private member" as said by Compiler
		}

		bool operator!=(const Iterator& other) const {
			return !(*this == other); // *this will request overload of 'operator * ()' to "access private member" as said by Compiler
		}

		// we need overload of operator '==' to be able to compare
		bool operator==(const Iterator& other) const {
			bool generatorSame = this->generatorReference == other.generatorReference;
			bool bothBositionsAtEnd = isIndexEnd(this->currentIndexInOurGenerator, this->generatorReference)
				&& isIndexEnd(other.currentIndexInOurGenerator, other.generatorReference);
			bool bothPositionsEqual = this->currentIndexInOurGenerator == other.currentIndexInOurGenerator;

			return generatorSame && (bothBositionsAtEnd || bothPositionsEqual);
		}

		//supporting 'operator==' function isIndexEnd showing(returning) if the index is at the end
		// it is static in order to convert 'this' pointer from 'const Sequence<T,Generator>::Iterator' to 'Sequence<T,Generator>::Iterator &' on line 45
		static int isIndexEnd(int index, const std::vector<T>& aGenerator) {
			return index == -1 || index == aGenerator.size();
		}
	};

	//request for overloading begin() and end() by the Compiler. For that we need to create "class Iterator" that will have its own begin() and end() functions
	Iterator begin() const {
		return Iterator::begin(this->vecGen);
	}

	Iterator end() const {
		return Iterator::end(this->vecGen);
	}
};
#endif // !SEQUENCE_H