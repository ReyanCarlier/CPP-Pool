#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) { }

Form::Form(const std::string &_name) : name(_name), isSigned(false), gradeToSign(1), gradeToExecute(1) { }

Form::Form(const Form &F) { *this = F; }

Form::~Form(void) { }

Form::Form(const std::string &_name, const int &_gradeToSign, const int &_gradeToExecute)
{
	if (_gradeToSign <= 0 || _gradeToExecute <= 0)
		throw (Form::GradeTooLowException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (Form::GradeTooHighException());
	this->name = _name;
	this->isSigned = false;
	this->gradeToSign = _gradeToSign;
	this->gradeToExecute = _gradeToExecute;
}

Form&	Form::operator=(Form const &F)
{
	if (this != &F)
	{
		this->name = F.name;
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

std::string	Form::getName(void) const { return (this->name); }

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

void		Form::setSigned(bool _isSigned) { this->isSigned = _isSigned; }

void		Form::setGradeToSign(int _gradeToSign) { this->gradeToSign = _gradeToSign; }

void		Form::setGradeToExecute(int _gradeToExecute) { this->gradeToExecute = _gradeToExecute; }

std::ostream&	operator<<(std::ostream &o, Form const &F)
{
	o << " ____________________" << std::endl;
	o << "|                    |" << std::endl;
	o << "|    FORM DISPLAY    |" << std::endl;
	o << "|____________________|" << std::endl;
	o << "|                    |" << std::endl;
	o << "| Name       : " << std::setw(5) << F.getName() << " |" << std::endl;
	o << "| Grade (ex) : " << std::setw(5) << F.getGradeToExecute() << " |" << std::endl;
	o << "| Grade (sg) : " << std::setw(5) << F.getGradeToSign() << " |" << std::endl;
	if (F.getSigned() == true)
		o << "| Signed     : " << std::setw(5) << "true" << " |" << std::endl;
	else
		o << "| Signed     : " << std::setw(5) << "false" << " |" << std::endl;
	o << "|____________________|" << std::endl;

	return (o);
}
