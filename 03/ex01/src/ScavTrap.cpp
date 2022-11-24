#include "ScavTrap.hpp"

// DE.CONSTRUCTEURS

	// Name
	ScavTrap::ScavTrap(const std::string & name) : ClapTrap(name, 100, 50, 20) { std::cout << "Construction of ScavTrap " << this->getName() << " !" << std::endl; }

	// Copy
	ScavTrap::ScavTrap(const ScavTrap &ST) : ClapTrap::ClapTrap(ST)
	{
		std::cout << "Copy of " << this->getName() << " ScavTrap." << std::endl;
		(*this) = ST;
	}

	// Operator =
	ScavTrap&	ScavTrap::operator=(ScavTrap const &ST)
	{
		std::cout << "Operator = constructor of ScavTrap " << ST.getName() << " called." << std::endl;
		if (this == &ST)
			return (*this);
		ClapTrap::operator=(ST);
	
		return (*this);
	}

	// Destructeur
	ScavTrap::~ScavTrap(void)
	{
		std::cout << "Destruction of " << this->getName() << " ScavTrap." << std::endl;
		return ;
	}

	// Methodes
	void	ScavTrap::guardGate(void)
	{
		if (this->getLP() == 0)
			std::cout << this->getName() << " ScavTrap bravely guard the Gata, at the cost of his life. RIP." << std::endl;
		else
			std::cout << this->getName() << " ScavTrap is now guarding the door." << std::endl;
	}

	void	ScavTrap::attack(const std::string& target)
	{
		if (this->getLP() == 0)
		{
			std::cout << this->getName() << " ScavTrap has no remaining lp: dead." << std::endl;
			return ;
		}
		if (this->getEP() == 0)
		{
			std::cout << this->getName() << " ScavTrap runs out of energy: Can't attack !" << std::endl;
			return ;
		}
		this->setEP(this->getEP() - 1);
		std::cout << this->getName() << " SCAVTRAP LAUNCH A POWERFULL ATTACK ON " << target << ", CAUSING " << this->getAD() << " DAMAGE POINT(S)." << std::endl;
	
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