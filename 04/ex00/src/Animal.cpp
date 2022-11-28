#include "Animal.hpp"

Animal::Animal(void) : type("Animal") { std::cout << "Animal default creator called." << std::endl; }

Animal::Animal(const std::string &_type) : type(_type) { std::cout << "Animal type " << type << " creator called." << std::endl; }

Animal::~Animal(void) { std::cout << "Animal destructor called." << std::endl; }

Animal::Animal(Animal const & A)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = A;
}

Animal&	Animal::operator=(Animal const &F)
{
	std::cout << "Animal assignation operator called." << std::endl;
	if (this != &F)
		this->type = F.type;
	return (*this);
}

std::string	Animal::getType(void) const { return (this->type); }

void		Animal::makeSound(void) const { std::cout << "*This is an animal sound, but which kind ? A platypus ?*" << std::endl; }