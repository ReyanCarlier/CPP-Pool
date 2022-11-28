#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b;
	Bureaucrat *c;

	try
	{
		b = new Bureaucrat("b", 149);
		std::cout << *b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	try
	{
		b->incrementGrade();
		std::cout << *b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b->incrementGrade();
		std::cout << *b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete b;

	try
	{
		c = new Bureaucrat("c", 149);
		std::cout << *c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	try
	{
		c->decrementGrade();
		std::cout << *c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c->decrementGrade();
		std::cout << *c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete c;

	return (0);
}