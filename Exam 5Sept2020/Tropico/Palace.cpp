#include "Palace.h"

void Palace::print()
{
	std::cout << "Building type: Palace, measurements: " << getWidth() << " x " << getLength() << std::endl;
}

Palace::Palace(int width, int length): Building(width, length)
{
	print();
	std::cout << "| Constructor is called" << std::endl;
}

Palace::~Palace()
{
	print();
	std::cout << "| Destructor is called" << std::endl;
}
