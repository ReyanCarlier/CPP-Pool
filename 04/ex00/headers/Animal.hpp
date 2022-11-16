#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &A);
		virtual ~Animal(void);
		Animal(const std::string &type);
		Animal&	operator=(Animal const & A);

		std::string 	getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string type;
};

#endif