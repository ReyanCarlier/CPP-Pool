#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# ifndef CLAPTRAP_HPP
#  include <ClapTrap.hpp>
# endif

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &);
		~ScavTrap(void);
		ScavTrap&	operator=(ScavTrap const & ST);

		void	guardGate(void);
		void	attack(const std::string &target);
};

std::ostream & operator<<(std::ostream & o, ScavTrap & F);

#endif