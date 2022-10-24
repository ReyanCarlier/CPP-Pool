#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default creator called." << std::endl;
	this->type = "Animal";
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
	return ;
}

Animal::Animal(Animal const & A)
{
	std::cout << "Animal copy constructor called." << std::endl;
	this->type = A.type;
	return ;
}

Animal&	Animal::operator=(Animal const &F)
{
	this->type = F.type;
	std::cout << "Animal operator= constructor." << std::endl;
	return (*this);
}

void	Animal::makeSound(void)
{
	std::cout << "This is an animal, but which kind ? A platypus ?" << std::endl;
	return ;
}

std::string	const& Animal::getType(void)
{
	return (this->type);
}