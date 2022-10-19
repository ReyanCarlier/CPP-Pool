#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("A1");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("A2");
		bob.attack();
	}
	{
		Weapon club = Weapon("B1");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("B2");
		jim.attack();
	}
	return 0;
}