#include "ClapTrap.hpp"
#include <ScavTrap.hpp>

int	main(void)
{
	ScavTrap CT = ScavTrap("Bob");
	ClapTrap CT2 = ClapTrap("Bob2");
	ScavTrap CT_copy = CT;
	CT.guardGate();
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
	std::cout << "Bob is supposed to have zero energy." << std::endl;
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.attack("Patrick");
	CT.beRepaired(10);

	CT2.takeDamage(9);
	CT2.beRepaired(2);
	CT2.attack("Patrick");
	CT2.beRepaired(3);
	CT2.takeDamage(6);
	std::cout << "------ Patrick ne doit plus pouvoir agir ------" << std::endl;
	CT2.beRepaired(10);
	CT2.attack("Patrick");
	CT2.takeDamage(10);

	return (0);
}
