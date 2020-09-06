#include "House.h"

void House::print()
{
	std::cout << "Building type: House, measurements: " << getWidth() << " x " << getLength() << std::endl;
}

House::House(int width, int length) : Building(width, length)
{
	print();
	std::cout << "| Constructor is called" << std::endl;
}

House::~House()
{
	print();
	std::cout << "| Destructor is called" << std::endl;
}
