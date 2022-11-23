#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Bob = ClapTrap("Bob");
	ClapTrap Patrick = ClapTrap("Patrick");
	std::cout << Bob;
	std::cout << Patrick;
	Bob.attack("Patrick");
	Bob.attack("Patrick");
	Bob.attack("Patrick");
	Bob.setAD(1);
	Bob.attack("Patrick");
	Bob.attack("Patrick");
	Bob.attack("Patrick");
	Bob.attack("Patrick");
	Bob.attack("Patrick");
	Bob.attack("Patrick");
	Bob.attack("Patrick");
	std::cout << Bob;
	std::cout << "------ Bob ne doit plus pouvoir agir ------" << std::endl;
	Bob.attack("Patrick");
	Bob.beRepaired(10);

	std::cout << std::endl;
	Patrick.takeDamage(9);
	Patrick.beRepaired(2);
	Patrick.attack("Patrick");
	Patrick.beRepaired(3);
	Patrick.takeDamage(6);
	std::cout << "------ Patrick ne doit plus pouvoir agir ------" << std::endl;
	Patrick.beRepaired(10);
	Patrick.attack("Patrick");
	Patrick.takeDamage(10);
	std::cout << Patrick;
	return (0);
}