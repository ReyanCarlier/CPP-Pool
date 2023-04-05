#pragma once

#include <string>
#include <interface/ICharacter.hpp>

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const & src);
        virtual ~AMateria();
        AMateria & operator=(AMateria const & rhs);

        std::string const & getType() const; //Returns the materia type
        void setType(std::string const & type);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};