#include "Zombie.hpp"

/**
 * @brief Initialize a new Zombie on the stack.
 * This Zombie must be manually deleted.
 * 
 * @param name 
 * @return Zombie* 
 */
Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie;

	zombie->setName(name);

	return (zombie);
}
