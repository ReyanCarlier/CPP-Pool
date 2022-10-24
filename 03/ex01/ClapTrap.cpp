#include "ClapTrap.h"
#include "ClapTrap.hpp"

// DE.CONSTRUCTEURS

	// Default
	ClapTrap::ClapTrap(void)
	{
		this->name = "default";
		this->lp = 10;
		this->ep = 10;
		this->ad = 0;

		std::cout << "Default construction of " << this->name << " ClapTrap." << std::endl;
		return ;
	};

	// Name
	ClapTrap::ClapTrap(const std::string& name)
	{
		this->name = name;
		this->lp = 10;
		this->ep = 10;
		this->ad = 0;

		std::cout << "Construction of " << this->name << " ClapTrap." << std::endl;
		return ;
	}

	ClapTrap&	ClapTrap::operator=(ClapTrap const &CT)
	{
		this->name = CT.name;
		this->ad = CT.ad;
		this->ep = CT.ep;
		this->lp = CT.lp;

		std::cout << "Operator = constructor of ClapTrap " << CT.name << " called." << std::endl;
		return *this;
	}

	// Copy
	ClapTrap::ClapTrap(const ClapTrap &CT)
	{
		this->name = CT.name;
		this->lp = CT.lp;
		this->ep = CT.ep;
		this->ad = CT.ad;

		std::cout << "Copy of " << this->name << " ClapTrap." << std::endl;
		return ;
	}

	// Destructeur
	ClapTrap::~ClapTrap(void)
	{
		std::cout << "Destruction of " << this->name << " ClapTrap." << std::endl;
		return ;
	}

// FONCTIONS MEMBRES

	// Attack
	void	ClapTrap::attack(const std::string& target)
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
		std::cout << this->name << " attacks " << target << ", causing " << this->ad << " damage point(s)." << std::endl;
	
		return ;
	}

	// Take Damage
	void	ClapTrap::takeDamage(unsigned int amount)
	{
		if (this->lp == 0)
		{
			std::cout << this->name << " has no remaining lp, don't beat a man while he's on the ground." << std::endl;
			return ;
		}
		if (amount > this->lp)
			this->lp = 0;
		else
			this->lp -= amount;
		std::cout << this->name << " received " << amount << " damage point(s): " << this->lp << "lp remaining." << std::endl;

		return ;
	}

	// Repair
	void	ClapTrap::beRepaired(unsigned int amount)
	{
		if (this->lp == 0)
		{
			std::cout << this->name << " has no remaining lp: dead." << std::endl;
			return ;
		}
		if (this->ep == 0)
		{
			std::cout << this->name << " runs out of energy: Can't repair !" << std::endl;
			return ;
		}
		this->ep -= 1;
		this->lp += amount;
		std::cout << this->name << " repairs " << amount << "lp: "<< this->lp << "lp remaining." << std::endl;
	}