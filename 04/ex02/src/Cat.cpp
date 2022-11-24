#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") { std::cout << "Cat default constructor called" << std::endl; }

Cat::~Cat(void) { std::cout << "Oh no, Cat has been destroyed..." << std::endl; }

Cat::Cat(const std::string &type) : Animal::Animal(type) { std::cout << "Generating a " << type << " Cat !" << std::endl; }

Cat::Cat(const Cat &C) : Animal::Animal(C) { std::cout << "CopyCat !" << std::endl; }

Cat&	Cat::operator=(const Cat &c)
{
	std::cout << "CopyCat operator =." << std::endl;
	if (this == &c)
		return (*this);
	Animal::operator=(c);

	return (*this);
}

void	Cat::makeSound(void) const { std::cout << "\"Meow meow\" - Cat'i Jackson, the snack stealer." << std::endl; }