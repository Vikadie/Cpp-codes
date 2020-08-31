#pragma once
#ifndef STREAM_INPUT_ITERATOR_H
#define STREAM_INPUT_ITERATOR_H

#include <sstream>
#include <vector>

class StreamInputIterator {
	std::vector<int> vec;
	std::istream& in;
	int index;

	static int isEndIndex(int indeX, std::vector<int> vec) {
		return indeX == -1 || indeX == vec.size();
	}
public:
	StreamInputIterator(std::istream& in, int index) : in(in), index(index) {
		int digit;
		while (in >> digit)
			vec.push_back(digit);
	}

	static StreamInputIterator begin(std::istream& in) {
		
		return StreamInputIterator(in, 0);
	}

	static StreamInputIterator end(std::istream& in, std::string endString) {
		return StreamInputIterator(in, -1);
	}

	const int& operator*() const {
		return this->vec.at(this->index);
	}

	StreamInputIterator& operator++() {
		this->index++;
		return *this;
	}

	bool operator!=(const StreamInputIterator& other) const {
		return !(*this == other);
	}

	bool operator==(const StreamInputIterator& other) const {
		//bool match = this->vec == other.vec;
		bool bothPositionsAreEnd = isEndIndex(this->index, this->vec) && isEndIndex(other.index, other.vec);
		bool positionMatch = this->index == other.index;

		return (bothPositionsAreEnd || positionMatch); // originally it should be (match && (bothPositionsAreEnd || positionMatch))
	}
};
#endif // !STREAM_INPUT_ITERATOR_H
