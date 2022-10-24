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
		~Animal(void);
		Animal&	operator=(Animal const & A);

		std::string const& getType(void);
		void		makeSound(void);
	private:
		Brain *brain;
	protected:
		std::string type;
};

#endif