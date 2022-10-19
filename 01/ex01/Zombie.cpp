#include "Zombie.hpp"

Zombie::~Zombie(void)
{
	std::cout << "Destructor of Zombie " << this->name << " called." << std::endl;
}

Zombie::Zombie(void)
{
	this->name = "";
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
