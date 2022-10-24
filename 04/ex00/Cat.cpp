#include "Cat.h"
#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Default Cat constructor." << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Oh no, Cat has been destroyed..." << std::endl;
	return ;
}

Cat::Cat(const Cat &C) : Animal::Animal(C)
{
	std::cout << "CopyCat !" << std::endl;
	this->type = "Cat";
	return ;
}

void	Cat::operator=(const Cat &c)
{
	std::cout << "CopyCat operator =." << std::endl;
	this->type = c.type;
	return ;
}

void	Cat::makeSound(void)
{
	std::cout << "\"Meow meow\" - Cat'i Jackson, the snack stealer." << std::endl;
	return ;
}
