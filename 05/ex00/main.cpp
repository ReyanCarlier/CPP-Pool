#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b;
	Bureaucrat *c;
	try
	{
		b = new Bureaucrat("b", 155);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete b;
		return (1);
	}
	std::cout << b;
	try
	{
		b->incrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b->incrementGrade();
		std::cout << "NE DOIT PAS ETRE AFFICHE" << std::endl;
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c = new Bureaucrat("c", 149);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	try
	{
		c->decrementGrade();
		std::cout << c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c->decrementGrade();
		std::cout << "NE DOIT PAS ETRE AFFICHE" << std::endl;
		std::cout << c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete b;
	delete c;
	return (0);
}