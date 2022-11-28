#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") { std::cout << "Dog default constructor called" << std::endl; }

Dog::~Dog(void) { std::cout << "Oh no, Dog has been destroyed..." << std::endl; }

Dog::Dog(const std::string &_type) : Animal::Animal(type) { std::cout << "Generating a " << _type << " Doggo !" << std::endl; }

Dog::Dog(const Dog &D) : Animal::Animal(D) { std::cout << "Another similar Doggo !" << std::endl; }

Dog&	Dog::operator=(const Dog &D)
{
	std::cout << "Doggo operator =." << std::endl;
	if (this == &D)
		return (*this);
	Animal::operator=(D);

	return (*this);
}

void	Dog::makeSound(void) const { std::cout << "\"Bark Bark\" - Sno'op Doggo, the snack eater." << std::endl; }