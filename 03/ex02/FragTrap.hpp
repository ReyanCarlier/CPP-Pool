#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# ifndef CLAPTRAP_HPP
#  include "ClapTrap.hpp"
# endif

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap &);
		~FragTrap(void);
		FragTrap&	operator=(FragTrap const & ST);
		void	highFivesGuys(void);
		void	attack(const std::string &target);
};

#endif