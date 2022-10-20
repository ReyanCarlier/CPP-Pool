#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <functional>

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
	private:
		static void debug(void);
		static void info(void);
		static void warning(void);
		static void error(void);
};

#endif