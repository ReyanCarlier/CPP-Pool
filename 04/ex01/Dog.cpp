#include "Dog.h"
#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Default Dog constructor." << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Oh no, Dog has been destroyed..." << std::endl;
	delete this->brain;
	return ;
}

Dog::Dog(const Dog &D) : Animal::Animal(D)
{
	std::cout << "Another similar Doggo !" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	return ;
}

Dog&	Dog::operator=(const Dog &D)
{
	std::cout << "Doggo operator =." << std::endl;
	this->type = D.type;
	this->brain = new Brain();
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << "\"Bark Bark\" - Sno'op Doggo, the snack eater." << std::endl;
	return ;
}
