#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& WA);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& WA);
		std::string getType() const;
		void makeSound() const;

	protected:
		std::string _type;
};

#endif