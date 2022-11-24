#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap ST = ScavTrap("[SCAV]");
	ScavTrap ST_copy(ST);
	ST_copy.setName("[SCAV] mais copie");
	std::cout << ST;
	std::cout << ST_copy;

	ClapTrap CT = ClapTrap("[CLAP]");
	ClapTrap CT_copy = CT;

	CT_copy.setName("[CLAP] mais copie");

	FragTrap FT = FragTrap("[FRAG]");
	FragTrap FT_copy = FT;
	FT_copy.setName("[FRAG] mais copie");

	ST.guardGate();
	ST.attack("a target");
	ST.takeDamage(100);
	ST.attack("FAIL");
	ST.guardGate();
	ST_copy.guardGate();
	ST_copy.attack("a target");

	CT.attack("a target");
	CT.takeDamage(100);
	CT.attack("FAILED");
	CT_copy.attack("a target");

	FT.highFivesGuys();
	FT.takeDamage(100);
	FT.attack("a target");
	FT.highFivesGuys();
	FT_copy.highFivesGuys();
	FT_copy.attack("a target");

	return (0);
}
