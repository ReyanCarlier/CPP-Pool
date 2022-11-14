#include "HumanB.hpp"

# ifndef WEAPON_H
#  include "Weapon.h"
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB(void)
{
	std::cout << "Destructor of HumanB " << this->name << " called." << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their nothingness." << std::endl; 
}

Weapon	&HumanB::getWeapon(void)
{
	return *(this->weapon);
}