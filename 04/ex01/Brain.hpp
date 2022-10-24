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

class Brain {
	public:
		Brain(void);
		Brain(const Brain &);
		~Brain(void);
		Brain&	operator=(Brain const &);
	private:
		std::string ideas[100];
};

#endif