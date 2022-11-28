#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &B) : name(B.name), grade(B.grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->name = _name;
	this->grade = _grade;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &B)
{
	if (this != &B)
	{
		this->name = B.name;
		this->grade = B.grade;
	}
	return (*this);
}

void		Bureaucrat::signForm(Form &F)
{
	try
	{
		F.beSigned(*this);
		std::cout << this->name << " signed " << F.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << F.getName() << " because " << e.what() << std::endl;
	}
}

std::string	Bureaucrat::getName(void) const { return (this->name); }

int			Bureaucrat::getGrade(void) const { return (this->grade); }

void		Bureaucrat::incrementGrade(void)
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	std::cout << "Bureaucrat " << this->name << " grade incremented to " << this->grade << "." << std::endl;
}

void		Bureaucrat::decrementGrade(void)
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	std::cout << "Bureaucrat " << this->name << " grade decremented to " << this->grade << "." << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) { }

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() { }

const char*	Bureaucrat::GradeTooHighException::what() const throw() { return ("[GradeTooHighException] : Grade too high."); }

Bureaucrat::GradeTooLowException::GradeTooLowException(void) { }

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() { }

const char*	Bureaucrat::GradeTooLowException::what() const throw() { return ("[GradeTooLowException] : Grade too low."); }

std::ostream&	operator<<(std::ostream &o, Bureaucrat const &B)
{
	o << " ____________________" << std::endl;
	o << "|                    |" << std::endl;
	o << "| BUREAUCRAT DISPLAY |" << std::endl;
	o << "|____________________|" << std::endl;
	o << "|                    |" << std::endl;
	o << "| Name	: " << std::setw(10) << B.getName() << " |" << std::endl;
	o << "| Grade	: " << std::setw(10) << B.getGrade() << " |" << std::endl;
	o << "|____________________|" << std::endl;

	return (o);
}
