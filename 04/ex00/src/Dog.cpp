#include "Dog.hpp"

Dog::~Dog(void) { std::cout << "Oh no, Dog has been destroyed..." << std::endl; }

Dog::Dog(void) : Animal::Animal("Dog") { std::cout << "Generating a Doggo !" << std::endl; }

Dog::Dog(const Dog &D) : Animal::Animal(D)
{
	std::cout << "Another similar Doggo !" << std::endl;
	Animal::operator=(D);
}

Dog&	Dog::operator=(const Dog &d)
{
	std::cout << "Doggo operator =." << std::endl;
	if (this != &d)
		Animal::operator=(d);
	return (*this);
}

void	Dog::makeSound(void) const { std::cout << "\"Bark Bark\" - Sno'op Doggo, the snack eater. (type : " << this->getType() << ")" << std::endl; }
