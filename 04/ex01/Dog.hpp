#ifndef DOG_HPP
# define DOG_HPP

# ifndef ANIMAL_HPP
#  include "Animal.hpp"
# endif

# ifndef BRAIN_HPP
#  include "Brain.hpp"
# endif

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &D);
		~Dog(void);
		Dog&	operator=(Dog const &D);
		Brain	*brain;
		void	makeSound();
};

#endif