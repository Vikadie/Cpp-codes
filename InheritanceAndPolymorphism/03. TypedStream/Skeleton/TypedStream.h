#pragma once
#ifndef TYPED_STREAM_H
#define TYPED_STREAM_H

#include <vector>
#include "Vector2D.h"

template<typename T>
class TypedStream {
	std::string inp;
protected:
	std::istringstream stream;
	
	virtual TypedStream<T>& operator>>(T& i) {
		this->stream >> i;
		return *this;
	}
public:
	TypedStream() = default;
	TypedStream(const std::string& input) : inp(input) {	}

	std::vector<T> readToEnd() {
		std::vector<T> vec;
		std::istringstream in(inp);
		T element;
		while (in >> element) {
			vec.push_back(element);
		}
		return vec;
	}
};

template<>
class TypedStream <Vector2D> {
	std::string inp;
protected:
	std::istringstream stream;

	virtual TypedStream<Vector2D>& operator>>(Vector2D& v) {
		double x, y;
		this->stream >> x >> y;

		v = Vector2D(x, y);

		return *this;
	}
public:
	TypedStream() = default;
	TypedStream(const std::string& input) : inp(input) {	}

	std::vector<Vector2D> readToEnd() {
		std::vector<Vector2D> vec;
		std::istringstream in(inp);
		double x, y;
		while (in >> x >> y) {
			vec.push_back(Vector2D(x, y));
		}
		return vec;
	}
};
#endif // !TYPED_STREAM_H
