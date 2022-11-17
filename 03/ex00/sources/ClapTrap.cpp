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
	ClapTrap::ClapTrap(const std::string& _name)
	{
		this->name = _name;
		this->lp = 10;
		this->ep = 10;
		this->ad = 0;

		std::cout << "Construction of " << this->name << " ClapTrap." << std::endl;
		return ;
	}

	// Copy
	ClapTrap::ClapTrap(const ClapTrap &CT)
	{
		std::cout << "Copy of " << this->name << " ClapTrap." << std::endl;
		(*this) = CT;
		return ;
	}

	ClapTrap&	ClapTrap::operator=(ClapTrap const &CT)
	{
		std::cout << "Operator = constructor of ClapTrap " << CT.name << " called." << std::endl;
		this->name = CT.name;
		this->ad = CT.ad;
		this->ep = CT.ep;
		this->lp = CT.lp;
		
		return (*this);
	}

	// Destructeur
	ClapTrap::~ClapTrap(void)
	{
		std::cout << "Destruction of " << this->name << " ClapTrap." << std::endl;
		return ;
	}

// GETTERS
	const std::string &ClapTrap::getName(void)
	{
		return (this->name);
	}

	unsigned int ClapTrap::getLP(void)
	{
		return (this->lp);
	}

	unsigned int ClapTrap::getEP(void)
	{
		return (this->ep);
	}

	unsigned int ClapTrap::getAD(void)
	{
		return (this->ad);
	}
// SETTERS
	void	ClapTrap::setName(const std::string &_name)
	{
		this->name = _name;
	}

	void	ClapTrap::setLP(unsigned int _lp)
	{
		this->lp = _lp;
	}

	void	ClapTrap::setEP(unsigned int _ep)
	{
		this->ep = _ep;
	}

	void	ClapTrap::setAD(unsigned int _ad)
	{
		this->ad = _ad;
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

std::ostream & operator<<(std::ostream & o, ClapTrap & F)
{
	o << "------------------------------" << std::endl;
	o << "Name          : " << std::setw(10) << F.getName() << std::endl;
	o << "Life Points   : " << std::setw(10) << F.getLP() << std::endl;
	o << "Attack Damage : " << std::setw(10) << F.getAD() << std::endl;
	o << "Energy Points : " << std::setw(10) << F.getEP() << std::endl;
	o << "------------------------------" << std::endl;

	return o;
}