#include "ScavTrap.h"
#include "ScavTrap.hpp"

// DE.CONSTRUCTEURS

	// Default
	ScavTrap::ScavTrap(void)
	{
		this->name = "default";
		this->lp = 100;
		this->ep = 50;
		this->ad = 20;
	
		std::cout << "Default ScavTrap constructor called." << std::endl;
	}

	// Name
	ScavTrap::ScavTrap(const std::string & name)
	{
		this->name = name;
		this->lp = 100;
		this->ep = 50;
		this->ad = 20;

		std::cout << "Construction of " << this->name << " ScavTrap." << std::endl;
		return;
	}

	// Copy
	ScavTrap::ScavTrap(const ScavTrap &ST) : ClapTrap::ClapTrap(ST)
	{
		this->name = ST.name;
		this->lp = ST.lp;
		this->ep = ST.ep;
		this->ad = ST.ad;

		std::cout << "Copy of " << this->name << " ScavTrap." << std::endl;
		return ;
	}

	// Destructeur
	ScavTrap::~ScavTrap(void)
	{
		std::cout << "Destruction of " << this->name << " ScavTrap." << std::endl;
		return ;
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
