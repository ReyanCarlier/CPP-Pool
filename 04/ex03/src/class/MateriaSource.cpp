#include "class/MateriaSource.hpp"
#include <iostream>
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    *this = src;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->_materia[i])
            delete this->_materia[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
            if (this->_materia[i])
                delete this->_materia[i];
        for (int i = 0; i < 4; i++)
            if (rhs._materia[i])
                this->_materia[i] = rhs._materia[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materia[i])
        {
            this->_materia[i] = m;
            std::cout << "Learned " << m->getType() << " at index " << i << std::endl;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
        {
            return this->_materia[i]->clone();
        }
    }
    std::cout << "No " << type << " found" << std::endl;
    return (0);
}

AMateria* MateriaSource::getMateria(int idx) const
{
    if (idx < 0 || idx > 3)
        return (0);
    if (!this->_materia[idx])
        return (0);
    return this->_materia[idx];
}

void MateriaSource::setMateria(AMateria* m, int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    this->_materia[idx] = m;
}