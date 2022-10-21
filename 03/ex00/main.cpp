#include "ClapTrap.h"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap CT = ClapTrap("Bob");
	ClapTrap CT2 = ClapTrap("Bob2");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	std::cout << "------ Patrick ne doit plus pouvoir agir ------" << std::endl;
	CT.attack("Patrick");
	CT.beRepaired(10);

	CT2.takeDamage(9);
	CT2.beRepaired(2);
	CT2.attack("Patrick");
	CT2.beRepaired(3);
	CT2.takeDamage(6);
	std::cout << "------ Patrick ne doit plus poivoir agir ------" << std::endl;
	CT2.beRepaired(10);
	CT2.attack("Patrick");
	CT2.takeDamage(10);

	return (0);
}
