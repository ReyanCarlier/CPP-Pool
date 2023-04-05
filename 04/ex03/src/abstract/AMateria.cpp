#include "abstract/AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->_type = type;
}

AMateria::AMateria(AMateria const & src)
{
    *this = src;
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::setType(std::string const & type)
{
    this->_type = type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

AMateria* AMateria::clone() const
{
    return NULL;
}