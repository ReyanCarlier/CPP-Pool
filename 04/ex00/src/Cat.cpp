#include "Cat.hpp"

Cat::~Cat(void) { std::cout << "Oh no, Cat has been destroyed..." << std::endl; }

Cat::Cat(void) : Animal::Animal("Cat") { std::cout << "Generating a Cat !" << std::endl; }

Cat::Cat(const Cat &C) : Animal::Animal(C)
{
	std::cout << "CopyCat !" << std::endl;
	Animal::operator=(C);
}

Cat&	Cat::operator=(const Cat &c)
{
	std::cout << "CopyCat operator =." << std::endl;
	if (this != &c)
		Animal::operator=(c);
	return (*this);
}

void	Cat::makeSound(void) const { std::cout << "\"Meow meow\" - Cat'i Jackson, the snack stealer. (type : " << this->getType() << ")" << std::endl; }
