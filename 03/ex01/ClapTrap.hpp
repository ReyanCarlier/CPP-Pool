#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &);
		~ClapTrap(void);
		void operator=(ClapTrap const & CT); // Affectation

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string		name;
		unsigned int	lp;
		unsigned int	ep;
		unsigned int	ad;
};

#endif