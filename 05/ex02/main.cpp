#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat john("John", 1);

	std::cout << john << std::endl;

	try
	{
		john.incrementGrade();
		john.incrementGrade();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		ShrubberyCreationForm test("test");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot initialize test because " << e.what() << std::endl;
	}

	ShrubberyCreationForm a("a");
	ShrubberyCreationForm b("b");
	ShrubberyCreationForm c("c");
	std::cout << john << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	try {
		//john.signForm(a);
		a.createTree(john, "a");
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	john.signForm(b);
	john.signForm(b);
	
	try
	{
		john.decrementGrade();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	john.signForm(c);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}