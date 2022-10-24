#include "FragTrap.h"
#include "FragTrap.hpp"

// DE.CONSTRUCTEURS

	// Default
	FragTrap::FragTrap(void)
	{
		this->name = "default";
		this->lp = 100;
		this->ep = 100;
		this->ad = 30;
	
		std::cout << "Default FragTrap constructor called." << std::endl;
	}

	// Name
	FragTrap::FragTrap(const std::string & name)
	{
		this->name = name;
		this->lp = 100;
		this->ep = 100;
		this->ad = 30;

		std::cout << "Construction of " << this->name << " FragTrap." << std::endl;
		return;
	}

	// Copy
	FragTrap::FragTrap(const FragTrap &FT) : ClapTrap::ClapTrap(FT)
	{
		this->name = FT.name;
		this->lp = FT.lp;
		this->ep = FT.ep;
		this->ad = FT.ad;

		std::cout << "Copy of " << this->name << " FragTrap." << std::endl;
		return ;
	}

	// Destructeur
	FragTrap::~FragTrap(void)
	{
		std::cout << "Destruction of " << this->name << " FragTrap." << std::endl;
		return ;
	}

	void	FragTrap::highFivesGuys(void)
	{
		if (this->lp == 0)
			std::cout << this->name << " dead body stand with his hand toward the sky. ✋" << std::endl;
		else
			std::cout << "✋ " << this->name << " is asking for a high five ! ✋" << std::endl;
		return ;
	}

	void	FragTrap::attack(const std::string& target)
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
		std::cout << this->name << " LAUNCH A TREMENDOUS ATTACK ON " << target << ", causing " << this->ad << " damage point(s)." << std::endl;
	
		return ;
	}
