#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie *zombieOne;
	Zombie *zombieThree = new Zombie("Three");

	zombieOne = newZombie("ZombieOne");
	zombieOne->announce();

	randomChump("ZombieTwo");
	zombieThree->announce();

	delete zombieOne;
	delete zombieThree;
	return (0);
}