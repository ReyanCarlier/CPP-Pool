#include "Zombie.hpp"

/**
 * @brief Initialize a Zombie on the heap.
 * Deletion is automatic.
 * 
 * @param name 
 */
void	randomChump(std::string name)
{
	Zombie zombie;

	zombie.name = name;
	zombie.announce();
}
