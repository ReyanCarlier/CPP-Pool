#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	return ;
}

Form::Form(const std::string &name) : _name(name), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	return ;
}

Form::Form(const Form &F) : _name(F._name), _isSigned(F._isSigned), _gradeToSign(F._gradeToSign), _gradeToExecute(F._gradeToExecute)
{
	return ;
}

Form::~Form(void)
{
	return ;
}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute)
	: _name(name)
{
	if (gradeToSign <= 0 || gradeToExecute <= 0)
		throw (Form::GradeTooLowException());
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (Form::GradeTooHighException());
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute = gradeToExecute;
	return ;
}

Form&	Form::operator=(Form const &F)
{
	this->_name = F._name;
	this->_isSigned = F._isSigned;
	this->_gradeToSign = F._gradeToSign;
	this->_gradeToExecute = F._gradeToExecute;
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(void)
{
	return ;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

Form::GradeTooLowException::GradeTooLowException(void)
{
	return ;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

Form::AlreadySignedException::AlreadySignedException(void)
{
	return ;
}

Form::AlreadySignedException::~AlreadySignedException(void) throw()
{
	return ;
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

int			Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int			Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool		Form::isSigned(void) const
{
	return (this->_isSigned);
}

void		Form::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > (*this).getGradeToSign())
		throw Form::GradeTooLowException();
	if ((*this)._isSigned)
		throw Form::AlreadySignedException();
	(*this)._isSigned = true;
}

std::ostream&	operator<<(std::ostream &out, Form const &F)
{
	if (F.isSigned())
		std::cout << "Form " << F.getName() << " (signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	else
		std::cout << "Form " << F.getName() << " (NOT signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	return (out);
}
