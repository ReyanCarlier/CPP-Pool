#include "FragTrap.hpp"

// DE.CONSTRUCTEURS

	// Name
	FragTrap::FragTrap(const std::string & name) : ClapTrap(name, 100, 100, 30) { std::cout << "Construction of " << this->getName() << " FragTrap." << std::endl; }

	// Copy
	FragTrap::FragTrap(const FragTrap &FT) : ClapTrap::ClapTrap(FT)
	{
		std::cout << "Copy of " << this->getName() << " FragTrap." << std::endl;
		(*this) = FT;
	}

	FragTrap&	FragTrap::operator=(FragTrap const &FT)
	{
		std::cout << "Operator = constructor of FragTrap " << FT.getName() << " called." << std::endl;
		if (this == &FT)
			return (*this);
		ClapTrap::operator=(FT);
		
		return (*this);
	}

	// Destructeur
	FragTrap::~FragTrap(void) { std::cout << "Destruction of " << this->getName() << " FragTrap." << std::endl; }

	void	FragTrap::highFivesGuys(void)
	{
		if (this->getLP() == 0)
			std::cout << this->getName() << " FragTrap's dead body stand with his hand toward the sky. ✋" << std::endl;
		else
			std::cout << "✋ " << this->getName() << " FragTrap is asking for a high five ! ✋" << std::endl;
	}

	void	FragTrap::attack(const std::string& target)
	{
		if (this->getLP() == 0)
		{
			std::cout << this->getName() << " has no remaining lp: dead." << std::endl;
			return ;
		}
		if (this->getEP() == 0)
		{
			std::cout << this->getName() << " runs out of energy: Can't attack !" << std::endl;
			return ;
		}
		this->setEP(this->getEP() - 1);
		std::cout << this->getName() << " FRAGTRAP LAUNCH A TREMENDOUS ATTACK ON " << target << ", causing " << this->getAD() << " damage point(s)." << std::endl;
	}

std::ostream & operator<<(std::ostream & o, FragTrap & F)
{
	o << "------------------------------" << std::endl;
	o << "Name          : " << std::setw(10) << F.getName() << std::endl;
	o << "Life Points   : " << std::setw(10) << F.getLP() << std::endl;
	o << "Energy Points : " << std::setw(10) << F.getEP() << std::endl;
	o << "Attack Damage : " << std::setw(10) << F.getAD() << std::endl;
	o << "------------------------------" << std::endl;

	return o;
}