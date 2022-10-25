#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default creator called." << std::endl;
	this->type = "Animal";
	return ;
}

Animal::Animal(const std::string &type)
{
	std::cout << "Animal type " << type << " creator called." << std::endl;
	this->type = type;
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
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "This is an animal sound, but which kind ? A platypus ?" << std::endl;
	return ;
}

std::string		Animal::getType(void) const
{
	return (this->type);
}