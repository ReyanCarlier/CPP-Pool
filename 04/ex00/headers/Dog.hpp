#ifndef DOG_HPP
# define DOG_HPP

# ifndef ANIMAL_HPP
#  include "Animal.hpp"
# endif

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &D);
		~Dog(void);
		Dog(const std::string &type);
		Dog&	operator=(Dog const &D);
	
		void	makeSound() const;
};

#endif