#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	unsigned int	hordeSize = 100;
	Zombie			*horde = zombieHorde(hordeSize, "MemberOfHorde");

	for (unsigned int i = 0; i < hordeSize; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}