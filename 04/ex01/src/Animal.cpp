#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
	this->brain = new Brain();
}

Animal::Animal(const std::string type) : type(type)
{
	std::cout << "Animal constructor called" << std::endl;
	this->brain = new Brain();
}

Animal::~Animal(void) { std::cout << "Animal destructor called." << std::endl; delete this->brain; }

Animal::Animal(Animal const & A)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = A;
}

Animal&	Animal::operator=(Animal const &F)
{
	std::cout << "Animal assignation operator called." << std::endl;
	if (this != &F)
	{
		this->type = F.type;
		this->brain = new Brain(*(F.brain));
	}

	return (*this);
}

void	Animal::makeSound(void) const { std::cout << "This is an animal sound, but which kind ? A platypus ?" << std::endl; }

std::string		Animal::getType(void) const { return (this->type); }

Brain			*Animal::getBrain(void) { return (this->brain); }