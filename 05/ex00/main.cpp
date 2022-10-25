#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("b", 2);
	std::cout << b;
	try
	{
		b.incrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.incrementGrade();
		std::cout << "NE DOIT PAS ETRE AFFICHE" << std::endl;
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat c("c", 149);
	try
	{
		c.decrementGrade();
		std::cout << c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c.decrementGrade();
		std::cout << "NE DOIT PAS ETRE AFFICHE" << std::endl;
		std::cout << c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}