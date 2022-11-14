#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie *zombieOne = new Zombie("ZombieOne");
	Zombie *zombieThree = newZombie("Three");

	zombieOne->announce();

	randomChump("ZombieTwo");
	zombieThree->announce();

	delete zombieOne;
	delete zombieThree;
	return (0);
}