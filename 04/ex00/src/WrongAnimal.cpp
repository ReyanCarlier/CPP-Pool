#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("defaultWrongAnimal")
{
	std::cout << "WrongAnimal(void) constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal(\"" << type << "\") constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WA) : _type(WA._type)
{
	std::cout << "WrongAnimal copy constructor called on " << WA._type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WA)
{
	this->_type = WA._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Default WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}