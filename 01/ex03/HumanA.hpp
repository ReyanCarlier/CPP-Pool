#ifndef HUMANA_HPP
# define HUMANA_HPP

# ifndef WEAPON_HPP
#  include "Weapon.hpp"
# endif

class HumanA {
	public:
		HumanA(void);
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

		void		attack(void);

		Weapon		&weapon;
		std::string name;
};

#endif