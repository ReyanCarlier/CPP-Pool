#include "Dog.h"
#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Default Dog constructor." << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Oh no, Dog has been destroyed..." << std::endl;
	return ;
}

Dog::Dog(const std::string &type) : Animal::Animal(type)
{
	std::cout << "Generating a " << type << " Doggo !" << std::endl;
	this->type = type;
	return ;
}

Dog::Dog(const Dog &D) : Animal::Animal(D)
{
	std::cout << "Another similar Doggo !" << std::endl;
	this->type = D.type;
	return ;
}

Dog&	Dog::operator=(const Dog &d)
{
	std::cout << "Doggo operator =." << std::endl;
	this->type = d.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "\"Bark Bark\" - Sno'op Doggo, the snack eater. (type : " << this->getType() << ")" << std::endl;
	return ;
}
