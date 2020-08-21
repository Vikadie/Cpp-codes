#include "StringConcatenator.h"

StringConcatenator::StringConcatenator()
{
}

StringConcatenator::~StringConcatenator()
{
}

std::string StringConcatenator::concatenate(const ConcatenateStrategy strategy, const char* left, const size_t leftSize, const char* right, const size_t rightSize) const
{
	std::string result;
	int sizeL = leftSize;
	int sizeR = rightSize;
	switch (strategy)
	{
	case ConcatenateStrategy::LEFT_1_RIGHT_1:{ 
		
		while (sizeL > 0 && sizeR > 0) {
			result += (*left);
			result += (*right);
			left++;
			sizeL--;
			right++;
			sizeR--;
		}
		if (sizeR > 0)
			while (sizeR > 0) {
				result += (*right);
				right++;
				sizeR--;
			}
		else {
			while (sizeL > 0) {
				result += (*left);
				left++;
				sizeL--;
			}
			}
		break; 
	}
	case ConcatenateStrategy::LEFT_1_RIGHT_2: { 
		while (sizeL > 0 && sizeR > 0) {
			result += (*left);
			result+= (*right);
			left++;
			sizeL--;
			right++;
			sizeR--;
			if (sizeR > 0) {
				result += (*right);
				right++;
				sizeR--;
			}
		}
		if (sizeR > 0)
			while (sizeR > 0) {
				result += (*right);
				right++;
				sizeR--;
			}
		else {
			while (sizeL > 0) {
				result += (*left);
				left++;
				sizeL--;
			}
		}
		break; }
	case ConcatenateStrategy::LEFT_2_RIGHT_1: {
		while (sizeL > 0 && sizeR > 0) {
			result += (*left);
			left++;
			sizeL--;
			if (sizeL > 0) {
				result += (*left);
				result += (*right);
				right++;
				sizeR--;
				left++;
				sizeL--;
			}
		}
		if (sizeR)
			while (sizeR > 0) {
				result += (*right);
				right++;
				sizeR--;
			}
		else {
			while (sizeL > 0) {
				result += (*left);
				left++;
				sizeL--;
			}
		}
		break; }
	default:
		break;
	}
	return result;
}
