#pragma once

#include "interface/ICharacter.hpp"
#include "class/MateriaSource.hpp"
#include <iostream>

class Character : public ICharacter
{
    private:
        std::string _name;
        MateriaSource *_inventory;
    public:
        Character(std::string const & name);
        Character(Character const & src);
        virtual ~Character();
        Character & operator=(Character const & rhs);

        AMateria* getItem(int idx) const;
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};