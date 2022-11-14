#ifndef HUMANB_HPP
# define HUMANB_HPP

# ifndef WEAPON_HPP
#  include "Weapon.hpp"
# endif

class HumanB {
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);

		void		attack(void);
		void		setWeapon(Weapon& weapon);
		Weapon		&getWeapon(void);

	private:
		Weapon 		*weapon;
		std::string name;
};

#endif