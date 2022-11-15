#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# ifndef CLAPTRAP_HPP
#  include "ClapTrap.hpp"
# endif

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &);
		~ScavTrap(void);
		ScavTrap&	operator=(ScavTrap const & ST);

		void	guardGate(void);
		void	attack(const std::string &target);

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

#endif