#include "Intern.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern &I) { *this = I; }

Intern&	Intern::operator=(Intern const & I)
{
	(void)I;
	return (*this);
}

Form*	Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form*		tmp = NULL;

	int i = 0;

	while (i < 3 && formName != formNames[i])
		i++;
	if (i == 3)
	{
		std::cerr << "Form not found" << std::endl;
		return (NULL);
	}
	switch (i)
	{
		case 0:
			tmp = new RobotomyRequestForm(target);
			break;
		case 1:
			tmp = new PresidentialPardonForm(target);
			break;
		case 2:
			tmp = new ShrubberyCreationForm(target);
			break;
	}
	std::cout << "Intern creates " << formName << std::endl;
	return (tmp);
}

Intern::FormNotFoundException::FormNotFoundException(void) { }

Intern::FormNotFoundException::~FormNotFoundException(void) throw() { }

const char*	Intern::FormNotFoundException::what() const throw() { return ("form not found"); }