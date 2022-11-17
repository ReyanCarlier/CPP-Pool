#include "Bureaucrat.hpp"

# ifndef FORM_HPP
#  include "Form.hpp"
# endif

Bureaucrat::Bureaucrat(void)
{
	this->name = "default";
	this->grade = 150;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &B)
{
	this->name = B.name;
	this->grade = B.grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->name = name;
	this->grade = grade;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &B)
{
	this->name = B.name;
	this->grade = B.grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void		Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed form " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign form " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void		Bureaucrat::incrementGrade(void)
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	std::cout << "Bureaucrat " << this->name << " grade incremented to " << this->grade << "." << std::endl;
	return ;
}

void		Bureaucrat::decrementGrade(void)
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	std::cout << "Bureaucrat " << this->name << " grade decremented to " << this->grade << "." << std::endl;
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	return ;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[GradeTooHighException] : Grade too high.");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	return ;
}


Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[GradeTooLowException] : Grade too low.");
}

std::ostream&	operator<<(std::ostream &out, Bureaucrat const &B)
{
	out << B.getName() << ", bureaucrat grade " << B.getGrade() << "." << std::endl;
	return (out);
}
