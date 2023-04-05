#pragma once

#include "abstract/AMateria.hpp"
#include "interface/ICharacter.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const & src);
        ~Ice();
        Ice & operator=(Ice const & rhs);

        AMateria* clone() const;
        void use(ICharacter& target);
};