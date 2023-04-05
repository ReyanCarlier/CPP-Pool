#pragma once

#include "abstract/AMateria.hpp"
#include "iostream"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const & src);
        ~Cure();
        Cure & operator=(Cure const & rhs);

        AMateria* clone() const;
        void use(ICharacter& target);
};