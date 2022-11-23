#include "ClapTrap.hpp"

// DE.CONSTRUCTEURS

	// Default
	ClapTrap::ClapTrap(void)
	{
		this->_name = "default";
		this->_lp = 10;
		this->_ep = 10;
		this->_ad = 0;

		std::cout << "Default construction of " << this->getName() << " ClapTrap." << std::endl;
		return ;
	};

	// Name
	ClapTrap::ClapTrap(const std::string& name)
	{
		this->_name = name;
		this->_lp = 10;
		this->_ep = 10;
		this->_ad = 0;

		std::cout << "Construction of " << this->getName() << " ClapTrap." << std::endl;
		return ;
	}

	// Copy
	ClapTrap::ClapTrap(const ClapTrap &CT)
	{
		std::cout << "Copy of " << this->getName() << " ClapTrap." << std::endl;
		(*this) = CT;
		return ;
	}

	ClapTrap&	ClapTrap::operator=(ClapTrap const &CT)
	{
		std::cout << "Operator = constructor of ClapTrap " << CT._name << " called." << std::endl;
		if (this == &CT)
			return (*this);
		this->_name = CT._name;
		this->_ad = CT._ad;
		this->_ep = CT._ep;
		this->_lp = CT._lp;
		
		return (*this);
	}

	// Destructeur
	ClapTrap::~ClapTrap(void)
	{
		std::cout << "Destruction of " << this->getName() << " ClapTrap." << std::endl;
		return ;
	}

// GETTERS
	const std::string &ClapTrap::getName(void)
	{
		return (this->_name);
	}

	unsigned int ClapTrap::getLP(void)
	{
		return (this->_lp);
	}

	unsigned int ClapTrap::getEP(void)
	{
		return (this->_ep);
	}

	unsigned int ClapTrap::getAD(void)
	{
		return (this->_ad);
	}
// SETTERS
	void	ClapTrap::setName(const std::string &name)
	{
		this->_name = name;
	}

	void	ClapTrap::setLP(unsigned int lp)
	{
		this->_lp = lp;
	}

	void	ClapTrap::setEP(unsigned int ep)
	{
		this->_ep = ep;
	}

	void	ClapTrap::setAD(unsigned int ad)
	{
		this->_ad = ad;
	}

// FONCTIONS MEMBRES

	// Attack
	void	ClapTrap::attack(const std::string& target)
	{
		if (this->getLP() == 0)
		{
			std::cout << this->getName() << " ClapTrap has no remaining lp: dead." << std::endl;
			return ;
		}
		if (this->getEP() == 0)
		{
			std::cout << this->getName() << " ClapTrap runs out of energy: Can't attack !" << std::endl;
			return ;
		}
		this->setEP(this->getEP() - 1);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAD() << " damage point(s)." << std::endl;
	
		return ;
	}

	// Take Damage
	void	ClapTrap::takeDamage(unsigned int amount)
	{
		if (this->getLP() == 0)
		{
			std::cout << this->getName() << " has no remaining lp, don't beat a man while he's on the ground." << std::endl;
			return ;
		}
		if (amount > this->getLP())
			this->setLP(0);
		else
			this->setLP(this->getLP() - amount);
		std::cout << this->getName() << " received " << amount << " damage point(s): " << this->getLP() << "lp remaining." << std::endl;

		return ;
	}

	// Repair
	void	ClapTrap::beRepaired(unsigned int amount)
	{
		if (this->getLP() == 0)
		{
			std::cout << this->getName() << " has no remaining lp: dead." << std::endl;
			return ;
		}
		if (this->getEP() == 0)
		{
			std::cout << this->getName() << " runs out of energy: Can't repair !" << std::endl;
			return ;
		}
		this->setEP(this->getEP() - 1);
		this->setLP(this->getLP() + amount);
		std::cout << this->getName() << " repairs " << amount << "lp: "<< this->getLP() << "lp remaining." << std::endl;
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