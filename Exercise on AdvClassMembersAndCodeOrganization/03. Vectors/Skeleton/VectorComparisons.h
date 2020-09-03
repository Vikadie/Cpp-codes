#pragma once
#ifndef VECTOR_COMPARISONS_H
#define VECTOR_COMPARISONS_H

class VectorLengthComparer {
public:
	bool operator() (const Vector& a, const Vector& b) const {
		return a.getLength() < b.getLength();
	}
};

//template<typename Vector, typename VectorLengthComparer>
template<typename T, typename Comparer> // T - Vector, Comparer е VectorLengthComparer
class ReverseComparer {
	Comparer c;
public:
	bool operator() (const T& a, const T& b) const {
		return c(b, a); // обръщайки реда на подаване на b и a обръщаме и логиката
	}
	/*bool operator() (const Vector& a, const Vector& b) const {
		return a.getLength() > b.getLength();
	}*/

};
#endif // !VECTOR_COMPARISONS_H
