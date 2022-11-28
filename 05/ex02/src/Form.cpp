#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name("default"), target("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) { }

Form::Form(const std::string &_name, const std::string &_target) : name(_name), target(_target), isSigned(false), gradeToSign(1), gradeToExecute(1) { }

Form::Form(const Form &F) { *this = F; }

Form::~Form(void) { }

Form::Form(const std::string &_name, const std::string &_target, const int &_gradeToSign, const int &_gradeToExecute)
{
	if (_gradeToSign <= 0 || _gradeToExecute <= 0)
		throw (Form::GradeTooLowException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (Form::GradeTooHighException());
	this->name = _name;
	this->target = _target;
	this->isSigned = false;
	this->gradeToSign = _gradeToSign;
	this->gradeToExecute = _gradeToExecute;
}

Form&	Form::operator=(Form const &F)
{
	if (this != &F)
	{
		this->name = F.name;
		this->target = F.target;
		this->isSigned = F.isSigned;
		this->gradeToSign = F.gradeToSign;
		this->gradeToExecute = F.gradeToExecute;
	}
	return (*this);
}

Form::GradeTooHighException::GradeTooHighException(void) {}

Form::GradeTooHighException::~GradeTooHighException(void) throw() { }

const char*	Form::GradeTooHighException::what() const throw() { return ("grade too high"); }

Form::GradeTooLowException::GradeTooLowException(void) { }

Form::GradeTooLowException::~GradeTooLowException(void) throw() { }

const char*	Form::GradeTooLowException::what() const throw() { return ("grade too low"); }

Form::AlreadySignedException::AlreadySignedException(void) { }

Form::AlreadySignedException::~AlreadySignedException(void) throw() { }

const char* Form::AlreadySignedException::what() const throw() { return ("form is already signed"); }

Form::NotSignedException::NotSignedException(void) { }

Form::NotSignedException::~NotSignedException(void) throw() { }

const char* Form::NotSignedException::what() const throw() { return ("form is not signed"); }

std::string	Form::getName(void) const { return (this->name); }

std::string Form::getTarget(void) const { return (this->target); }

bool		Form::getSigned(void) const { return (this->isSigned); }

int			Form::getGradeToSign(void) const { return (this->gradeToSign); }

int			Form::getGradeToExecute(void) const { return (this->gradeToExecute); }

void		Form::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > (*this).getGradeToSign())
		throw Form::GradeTooLowException();
	if (this->isSigned == true)
		throw Form::AlreadySignedException();
	this->isSigned = true;
}

void		Form::setName(std::string _name) { this->name = _name; }

void		Form::setTarget(std::string _target) { this->target = _target; }

void		Form::setSigned(bool _isSigned) { this->isSigned = _isSigned; }

void		Form::setGradeToSign(int _gradeToSign) { this->gradeToSign = _gradeToSign; }

void		Form::setGradeToExecute(int _gradeToExecute) { this->gradeToExecute = _gradeToExecute; }

void		Form::execute(Bureaucrat const & executor) const
{
	if (this->isSigned == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > this->gradeToExecute)
		throw Form::GradeTooLowException();
	this->executeAction(executor);
}

std::ostream&	operator<<(std::ostream &o, Form const &F)
{
	o << " _____________________" << std::endl;
	o << "|                     |" << std::endl;
	o << "|     FORM DISPLAY    |" << std::endl;
	o << "|_____________________|" << std::endl;
	o << "|                     |" << std::endl;
	o << "| Name       : " << std::setw(6) << F.getName() << " |" << std::endl;
	o << "| Target     : " << std::setw(6) << F.getTarget() << " |" << std::endl;
	o << "| Grade (ex) : " << std::setw(6) << F.getGradeToExecute() << " |" << std::endl;
	o << "| Grade (sg) : " << std::setw(6) << F.getGradeToSign() << " |" << std::endl;
	if (F.getSigned() == true)
		o << "| Signed     : " << std::setw(6) << "true" << " |" << std::endl;
	else
		o << "| Signed     : " << std::setw(6) << "false" << " |" << std::endl;
	o << "|_____________________|" << std::endl;

	return (o);
}
