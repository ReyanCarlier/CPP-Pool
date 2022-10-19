#ifndef WEAPON_HPP
# define WEAPON_HPP

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif


/**
 * @brief Weapon Class.
 * -> getType();
 * -> setType(string type);
 * 
 */
class Weapon {
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		const std::string	getType() const;
		void		 		setType(std::string type);

		std::string		type;
};

#endif