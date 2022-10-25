#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
	this->_name = "defaultShrubbery";
	this->_isSigned = false;
	this->_gradeToSign = 145;
	this->_gradeToExecute = 137;

	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor of " << this->getName() << " (Shrubbery) called" << std::endl;

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : Form::Form(name)
{
	this->_name = name;
	this->_isSigned = false;
	this->_gradeToSign = 145;
	this->_gradeToExecute = 137;

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &SCF) : Form::Form(SCF)
{
	this->_name = SCF.getName();
	this->_isSigned = SCF.isSigned();
	this->_gradeToSign = SCF.getGradeToSign();
	this->_gradeToExecute = SCF.getGradeToExecute();

	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &SCF)
{
	this->_name = SCF.getName();
	this->_isSigned = SCF.isSigned();
	this->_gradeToSign = SCF.getGradeToSign();
	this->_gradeToExecute = SCF.getGradeToExecute();

	return (*this);
}

bool	ShrubberyCreationForm::isSigned(void) const
{
	return (this->_isSigned);
}

int		ShrubberyCreationForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int		ShrubberyCreationForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

std::string ShrubberyCreationForm::getName(void) const
{
	return (this->_name);
}

ShrubberyCreationForm::GradeTooHighException::GradeTooHighException(void)
{
	return ;
}

ShrubberyCreationForm::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

const char*	ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

ShrubberyCreationForm::GradeTooLowException::GradeTooLowException(void)
{
	return ;
}

ShrubberyCreationForm::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char*	ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

ShrubberyCreationForm::AlreadySignedException::AlreadySignedException(void)
{
	return ;
}

ShrubberyCreationForm::AlreadySignedException::~AlreadySignedException(void) throw()
{
	return ;
}

const char* ShrubberyCreationForm::AlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

void		ShrubberyCreationForm::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > (*this).getGradeToSign())
		throw ShrubberyCreationForm::GradeTooLowException();
	if ((*this)._isSigned)
		throw ShrubberyCreationForm::AlreadySignedException();
	(*this)._isSigned = true;
}

std::ostream&	operator<<(std::ostream &out, ShrubberyCreationForm const &F)
{
	if (F.isSigned())
		std::cout << "ShrubberyCreationForm " << F.getName() << " (signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	else
		std::cout << "ShrubberyCreationForm " << F.getName() << " (NOT signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	return (out);
}
