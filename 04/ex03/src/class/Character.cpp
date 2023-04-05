#include "class/Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
    this->_inventory = new MateriaSource();
}

Character::Character(Character const & src)
{
    *this = src;
}

Character::~Character()
{
    delete this->_inventory;
}

Character & Character::operator=(Character const & rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        delete this->_inventory;
        for (int idx = 0; idx < 4; idx++)
            this->_inventory->setMateria(rhs._inventory->getMateria(idx)->clone(), idx);
    }
    return *this;
}

std::string const & Character::getName() const
{
    return this->_name;
}

AMateria* Character::getItem(int idx) const
{
    if (idx < 0 || idx > 3)
        return (0);
    return this->_inventory->getMateria(idx);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_inventory->getMateria(i))
        {
            this->_inventory->setMateria(m, i);
            std::cout << "Equipped " << _inventory->getMateria(i)->getType() << " at index " << i << std::endl;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    if (this->_inventory->getMateria(idx))
        this->_inventory->setMateria(NULL, idx);
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        return ;
    std::cout << this->_name << " uses " << this->_inventory->getMateria(idx)->getType() << " on " << target.getName() << std::endl;
    this->_inventory->getMateria(idx)->use(target);
}
