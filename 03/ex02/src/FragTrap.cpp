#include "FragTrap.hpp"

// DE.CONSTRUCTEURS

	// Default
	FragTrap::FragTrap(void)
	{
		this->name = "defaultFlagTrapName";
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
		(*this) = FT;

		std::cout << "Copy of " << this->name << " FragTrap." << std::endl;
		return ;
	}

	FragTrap&	FragTrap::operator=(FragTrap const &FT)
	{
		this->name = FT.name;
		this->lp = FT.lp;
		this->ep = FT.ep;
		this->ad = FT.ad;

		std::cout << "Operator = constructor of FragTrap " << FT.name << " called." << std::endl;
		return (*this);
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

// GETTERS
	const std::string &FragTrap::getName(void)
	{
		return (this->name);
	}

	unsigned int FragTrap::getLP(void)
	{
		return (this->lp);
	}

	unsigned int FragTrap::getEP(void)
	{
		return (this->ep);
	}

	unsigned int FragTrap::getAD(void)
	{
		return (this->ad);
	}
// SETTERS
	void	FragTrap::setName(const std::string &_name)
	{
		this->name = _name;
	}

	void	FragTrap::setLP(unsigned int _lp)
	{
		this->lp = _lp;
	}

	void	FragTrap::setEP(unsigned int _ep)
	{
		this->ep = _ep;
	}

	void	FragTrap::setAD(unsigned int _ad)
	{
		this->ad = _ad;
	}

std::ostream & operator<<(std::ostream & o, FragTrap & F)
{
	o << "------------------------------" << std::endl;
	o << "Name          : " << std::setw(10) << F.getName() << std::endl;
	o << "Life Points   : " << std::setw(10) << F.getLP() << std::endl;
	o << "Attack Damage : " << std::setw(10) << F.getAD() << std::endl;
	o << "Energy Points : " << std::setw(10) << F.getEP() << std::endl;
	o << "------------------------------" << std::endl;

	return o;
}