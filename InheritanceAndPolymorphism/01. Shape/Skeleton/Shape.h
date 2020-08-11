#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include "Vector2D.h"

class Shape {
	Vector2D center;
public:
	double area;
	Shape() :center(Vector2D(0,0)), area(0.0){}
	Shape(Vector2D center_) : center(center_), area(0.0) {
	}

	double getArea() {
		return area;
	}

	std::string getCenter(){
		return (std::string)center;
	}
};
#endif // !SHAPE_H
