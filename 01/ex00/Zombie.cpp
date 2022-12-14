#include "Zombie.hpp"
#include "Zombie.h"

Zombie::~Zombie(void)
{
	std::cout << "Destructor of Zombie " << this->name << " called." << std::endl;
}

Zombie::Zombie(void)
{
	this->name = "";
	return ;
}

Zombie::Zombie(const std::string &name)
{
	this->name = name;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string &name)
{
	this->name = name;
}