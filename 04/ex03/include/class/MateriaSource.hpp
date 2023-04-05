#pragma once

#include "abstract/AMateria.hpp"
#include "interface/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materia[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & src);
        virtual ~MateriaSource();
        MateriaSource & operator=(MateriaSource const & rhs);

        AMateria* getMateria(int idx) const;
        void setMateria(AMateria* m, int idx);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};