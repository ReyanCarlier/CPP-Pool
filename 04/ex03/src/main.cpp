#include "class/Character.hpp"
#include "class/Cure.hpp"
#include "class/Ice.hpp"
#include "class/MateriaSource.hpp"

int main()
{
    
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        delete tmp;
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);
        me->use(4, *bob);
        me->use(-1, *bob);
        tmp = me->getItem(2);
        me->unequip(2);
        delete tmp;
        tmp = src->createMateria("cure");
        me->equip(tmp);
        me->use(2, *bob);
        delete bob;
        delete me;
        delete src;
    }
    return 0;
}