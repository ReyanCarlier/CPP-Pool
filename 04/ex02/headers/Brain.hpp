#ifndef BRAIN_HPP
# define BRAIN_HPP

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

# ifndef STDLIB_HPP
#  define STDLIB_HPP
#  include <stdlib.h>
# endif

class Brain {
	public:
		Brain(void);
		Brain(const Brain &);
		~Brain(void);
		Brain&	operator=(Brain const &);
		std::string&	getIdea(int);
	private:
		std::string ideas[100];
};

#endif