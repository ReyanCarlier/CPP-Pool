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

void	Animal::operator=(Animal const &F)
{
	this->type = F.type;
	return ;
}

std::string	const& Animal::getType(void)
{
	return (this->type);
}