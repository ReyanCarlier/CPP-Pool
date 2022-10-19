#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie *horde;
	int		hordeSize = 5;

	horde = zombieHorde(hordeSize, "MemberOfHorde");
	for (int i = 0; i < hordeSize; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}