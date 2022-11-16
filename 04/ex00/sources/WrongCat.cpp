#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
	std::cout << "WrongCat(void) constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat(\"" << type << "\") constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& WC) : WrongAnimal(WC)
{
	std::cout << "WrongCat copy constructor called on " << WC._type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& WC)
{
	this->_type = WC._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called for " << this->_type << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << std::endl;
}