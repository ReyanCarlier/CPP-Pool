#ifndef CAT_HPP
# define CAT_HPP

# ifndef ANIMAL_HPP
#  include "Animal.hpp"
# endif

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &C);
		~Cat(void);
		void	operator=(Cat const &C);
	
		void	makeSound();
};

#endif