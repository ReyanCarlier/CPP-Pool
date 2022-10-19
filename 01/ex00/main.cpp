#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie *zombieOne;
	
	zombieOne = newZombie("ZombieOne");
	zombieOne->announce();

	randomChump("ZombieTwo");

	delete zombieOne;
	return (0);
}