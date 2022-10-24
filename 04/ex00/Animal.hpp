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

class Animal {
	public:
		Animal(void);
		Animal(const Animal &A);
		~Animal(void);
		void	operator=(Animal const & A);

		std::string const& getType(void);
	protected:
		std::string type;
};

#endif