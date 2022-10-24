#ifndef CAT_HPP
# define CAT_HPP

# ifndef ANIMAL_HPP
#  include "Animal.hpp"
# endif

# ifndef BRAIN_HPP
#  include "Brain.hpp"
# endif

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &C);
		~Cat(void);
		Cat&	operator=(Cat const &C);
		Brain	*brain;
		void	makeSound();
};

#endif