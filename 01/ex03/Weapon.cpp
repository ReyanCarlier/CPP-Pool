#include "Weapon.hpp"

# ifndef WEAPON_H
#  include "Weapon.h"
# endif

Weapon::Weapon(void)
{
	this->type = "";
	std::cout << "Empty weapon created." << std::endl;
	return ;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << type << " weapon created." << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Destructor of Weapon " << this->type << " called." << std::endl;
}

/**
 * @brief Get the type of Weapon object.
 * 
 * @return std::string& 
 */
const std::string Weapon::getType() const
{
	return (this->type);
}

/**
 * @brief Set the type of Weapon object.
 * 
 * @param type 
 */
void		 Weapon::setType(std::string type)
{
	std::cout << "Changing type of weapon " << this->type << " to " << type << std::endl;
	this->type = type;
	std::cout << "New type = " << this->getType() << std::endl;
	return ;
}
