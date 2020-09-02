#include "Laptop.h"

Laptop::Laptop(const std::string& name, const double price, const double monitorSize): Hardware(name, price), _monitorSize(monitorSize) {
	printInfo();
	std::cout << " is being created" << std::endl;
}

Laptop::~Laptop()
{
	printInfo();
	std::cout << " is being destroyed" << std::endl;
}

Laptop::Laptop(const Laptop& other): Hardware(other), _monitorSize(other._monitorSize) 
{
	std::cout << "Copy construction for ";
	printInfo();
	std::cout << std::endl;
}

Laptop& Laptop::operator=(const Laptop& other)
{
	if (this != &other) {
		Hardware::operator=(other);
		this->_monitorSize = other._monitorSize;
		std::cout << "Copy assignment for ";
		printInfo();
		std::cout << std::endl;
	}
	else {
		std::cout << "Self-copy prevented for ";
		printInfo();
		std::cout << std::endl;
	}
	return *this;
	// TODO: insert return statement here
}
