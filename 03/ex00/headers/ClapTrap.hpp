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

# ifndef IOMANIP_HPP
#  define IOMANIP_HPP
#  include <iomanip>
# endif

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &);
		~ClapTrap(void);
		ClapTrap& operator=(ClapTrap const & CT); // Affectation

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		// Getters
		const std::string	&getName(void);
		unsigned int		getLP(void);
		unsigned int		getEP(void);
		unsigned int		getAD(void);

		// Setters
		void				setName(const std::string &);
		void				setLP(unsigned int);
		void				setEP(unsigned int);
		void				setAD(unsigned int);

	private:
		std::string			name;
		unsigned int		lp;
		unsigned int		ep;
		unsigned int		ad;

};

std::ostream & operator<<(std::ostream & o, ClapTrap & F);

#endif