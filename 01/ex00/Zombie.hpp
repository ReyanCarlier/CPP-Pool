#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		Zombie(const std::string &name);
		std::string name;
		void 		announce (void);
};

#endif