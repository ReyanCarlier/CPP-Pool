#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void	secure_delete(Form *form)
{
	if (form)
		delete form;
}

int main()
{
	srand(time(NULL));

	Bureaucrat bob("Bob", 5);
	Bureaucrat patrick("Patrick", 45);
	Bureaucrat carlos("Carlos", 137);

	std::cout << bob << std::endl;
	std::cout << patrick << std::endl;
	std::cout << carlos << std::endl;

	Intern intern;

	Form* formA;
	Form* formB;
	Form* formC;
	Form* formD;

	try
	{
		formA = intern.makeForm("shrubbery creation", "A");
		formB = intern.makeForm("robotomy request", "B");
		formC = intern.makeForm("presidential pardon", "C");
		formD = intern.makeForm("test", "test");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (formA)
	{
		std::cout << std::endl;
		bob.executeForm(*formA);
		patrick.executeForm(*formA);
		carlos.executeForm(*formA);
		std::cout << std::endl;
		bob.signForm(*formA);
		patrick.signForm(*formA);
		carlos.signForm(*formA);
		std::cout << std::endl;
		bob.executeForm(*formA);
		patrick.executeForm(*formA);
		carlos.executeForm(*formA);
		std::cout << *formA;
	}
	if (formB)
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << std::endl;
		bob.executeForm(*formB);
		patrick.executeForm(*formB);
		carlos.executeForm(*formB);
		std::cout << std::endl;
		bob.signForm(*formB);
		patrick.signForm(*formB);
		carlos.signForm(*formB);
		std::cout << std::endl;
		bob.executeForm(*formB);
		patrick.executeForm(*formB);
		carlos.executeForm(*formB);
		std::cout << *formB;
	}
	if (formC)
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << std::endl;
		bob.executeForm(*formC);
		patrick.executeForm(*formC);
		carlos.executeForm(*formC);
		std::cout << std::endl;
		bob.signForm(*formC);
		patrick.signForm(*formC);
		carlos.signForm(*formC);
		std::cout << std::endl;
		bob.executeForm(*formC);
		patrick.executeForm(*formC);
		carlos.executeForm(*formC);
		std::cout << *formC;
	}
	if (formD)
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << std::endl;
		bob.executeForm(*formD);
		patrick.executeForm(*formD);
		carlos.executeForm(*formD);
		std::cout << std::endl;
		bob.signForm(*formD);
		patrick.signForm(*formD);
		carlos.signForm(*formD);
		std::cout << std::endl;
		bob.executeForm(*formD);
		patrick.executeForm(*formD);
		carlos.executeForm(*formD);
		std::cout << *formD;
	}
	secure_delete(formA);
	secure_delete(formB);
	secure_delete(formC);
	secure_delete(formD);
}