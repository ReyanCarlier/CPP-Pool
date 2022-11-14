#include "HumanA.hpp"

# ifndef WEAPON_H
#  include "Weapon.h"
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

/**
 * @brief Destroy the Human A:: Human A object
 * 
 */
HumanA::~HumanA(void)
{
	std::cout << "Destructor of HumanA " << this->name << " called." << std::endl;
}

/**
 * @brief Construct a new Human A:: Human A object
 * 
 * @param name 
 * @param weapon 
 */
HumanA::HumanA(std::string name, Weapon& weap) : weapon(weap)
{
	this->name = name;
	this->weapon = weapon;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}