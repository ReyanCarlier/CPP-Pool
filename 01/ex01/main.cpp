#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie			*horde;
	unsigned int	hordeSize = 1;

	horde = zombieHorde(hordeSize, "MemberOfHorde");
	for (unsigned int i = 0; i < hordeSize; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}