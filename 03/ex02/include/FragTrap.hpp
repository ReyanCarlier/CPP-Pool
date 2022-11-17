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
		std::string		name;
		unsigned int	lp;
		unsigned int	ep;
		unsigned int	ad;
};

std::ostream & operator<<(std::ostream & o, FragTrap & F);

#endif