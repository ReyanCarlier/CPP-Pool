#include "Cat.h"
#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Default Cat constructor." << std::endl;
	this->brain = new Brain();
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Oh no, Cat has been destroyed..." << std::endl;
	delete this->brain;
	return ;
}

Cat::Cat(const Cat &C) : Animal::Animal(C)
{
	std::cout << "CopyCat !" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	return ;
}

Cat&	Cat::operator=(const Cat &c)
{
	std::cout << "CopyCat operator =." << std::endl;
	this->type = c.type;
	this->brain = new Brain();
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << "\"Meow meow\" - Cat'i Jackson, the snack stealer." << std::endl;
	return ;
}
