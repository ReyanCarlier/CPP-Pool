#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# ifndef BRAIN_HPP
#  include "Brain.hpp"
# endif

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

class Animal {
	public:
		Animal(void);
		Animal(const Animal &A);
		virtual ~Animal(void) = 0;
		Animal&	operator=(Animal const & A);
		Animal(std::string type);

		virtual void	makeSound(void) const;

		Brain			*getBrain(void);
		std::string 	getType(void) const;

	protected:
		std::string type;
		Brain		*brain;
};

#endif