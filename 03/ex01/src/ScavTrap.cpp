#include "ScavTrap.hpp"

// DE.CONSTRUCTEURS

	// Name
	ScavTrap::ScavTrap(const std::string & _name)
	{
		this->name = _name;
		this->lp = 100;
		this->ep = 50;
		this->ad = 20;

		std::cout << "Construction of " << this->name << " ScavTrap." << std::endl;
		return;
	}

	// Copy
	ScavTrap::ScavTrap(const ScavTrap &ST) : ClapTrap::ClapTrap(ST)
	{
		std::cout << "Copy of " << this->name << " ScavTrap." << std::endl;
		(*this) = ST;
		return ;
	}

	ScavTrap&	ScavTrap::operator=(ScavTrap const &ST)
	{
		this->name = ST.name;
		this->ad = ST.ad;
		this->ep = ST.ep;
		this->lp = ST.lp;

		std::cout << "Operator = constructor of ScavTrap " << ST.name << " called." << std::endl;
		return *this;
	}

	// Destructeur
	ScavTrap::~ScavTrap(void)
	{
		std::cout << "Destruction of " << this->name << " ScavTrap." << std::endl;
		return ;
	}

// GETTERS
	const std::string &ScavTrap::getName(void)
	{
		return (this->name);
	}

	unsigned int ScavTrap::getLP(void)
	{
		return (this->lp);
	}

	unsigned int ScavTrap::getEP(void)
	{
		return (this->ep);
	}

	unsigned int ScavTrap::getAD(void)
	{
		return (this->ad);
	}
// SETTERS
	void	ScavTrap::setName(const std::string &_name)
	{
		this->name = _name;
	}

	void	ScavTrap::setLP(unsigned int _lp)
	{
		this->lp = _lp;
	}

	void	ScavTrap::setEP(unsigned int _ep)
	{
		this->ep = _ep;
	}

	void	ScavTrap::setAD(unsigned int _ad)
	{
		this->ad = _ad;
	}

	void	ScavTrap::guardGate(void)
	{
		if (this->lp == 0)
			std::cout << this->name << " bravely guard the Gata, at the cost of his life. RIP." << std::endl;
		else
			std::cout << this->name << " ScavTrap is now guarding the door." << std::endl;
	}

	void	ScavTrap::attack(const std::string& target)
	{
		if (this->lp == 0)
		{
			std::cout << this->name << " has no remaining lp: dead." << std::endl;
			return ;
		}
		if (this->ep == 0)
		{
			std::cout << this->name << " runs out of energy: Can't attack !" << std::endl;
			return ;
		}
		this->ep -= 1;
		std::cout << this->name << " LAUNCH A POWERFULL ATTACK ON " << target << ", causing " << this->ad << " damage point(s)." << std::endl;
	
		return ;
	}

std::ostream & operator<<(std::ostream & o, ScavTrap & F)
{
	o << "------------------------------" << std::endl;
	o << "Name          : " << std::setw(10) << F.getName() << std::endl;
	o << "Life Points   : " << std::setw(10) << F.getLP() << std::endl;
	o << "Attack Damage : " << std::setw(10) << F.getAD() << std::endl;
	o << "Energy Points : " << std::setw(10) << F.getEP() << std::endl;
	o << "------------------------------" << std::endl;

	return o;
}