#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
	this->_target = "defaultTarget";
	this->_name = "defaultPresidentialName";
	this->_isSigned = false;
	this->_gradeToSign = 25;
	this->_gradeToExecute = 5;

	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor of " << this->getName() << " (Presidential) called" << std::endl;

	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target, const std::string &name) : Form::Form(target, name)
{
	this->_target = target;
	this->_name = name;
	this->_isSigned = false;
	this->_gradeToSign = 25;
	this->_gradeToExecute = 5;

	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &SCF) : Form::Form(SCF)
{
	this->_target = SCF.getTarget();
	this->_name = SCF.getName();
	this->_isSigned = SCF.isSigned();
	this->_gradeToSign = SCF.getGradeToSign();
	this->_gradeToExecute = SCF.getGradeToExecute();

	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &SCF)
{
	this->_name = SCF.getName();
	this->_isSigned = SCF.isSigned();
	this->_gradeToSign = SCF.getGradeToSign();
	this->_gradeToExecute = SCF.getGradeToExecute();

	return (*this);
}

bool	PresidentialPardonForm::isSigned(void) const
{
	return (this->_isSigned);
}

int		PresidentialPardonForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int		PresidentialPardonForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

std::string PresidentialPardonForm::getName(void) const
{
	return (this->_name);
}

PresidentialPardonForm::GradeTooHighException::GradeTooHighException(void)
{
	return ;
}

PresidentialPardonForm::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

const char*	PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

PresidentialPardonForm::GradeTooLowException::GradeTooLowException(void)
{
	return ;
}

PresidentialPardonForm::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char*	PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

PresidentialPardonForm::AlreadySignedException::AlreadySignedException(void)
{
	return ;
}

PresidentialPardonForm::AlreadySignedException::~AlreadySignedException(void) throw()
{
	return ;
}

PresidentialPardonForm::NotSignedYet::NotSignedYet(void)
{
	return ;
}

PresidentialPardonForm::NotSignedYet::~NotSignedYet(void) throw()
{
	return ;
}

const char* PresidentialPardonForm::NotSignedYet::what() const throw()
{
	return ("[Error] : Can't pardon if the form isnt't signed.");
}


const char* PresidentialPardonForm::AlreadySignedException::what() const throw()
{
	return ("[Error] : PresidentialPardonForm is already signed");
}

/**
 * @brief Sign Presidential' form if the Bureaucrat <B> has enough rights.
 * 
 * @param B 
 */
void		PresidentialPardonForm::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > (*this).getGradeToSign())
		throw PresidentialPardonForm::GradeTooLowException();
	if ((*this)._isSigned)
		throw PresidentialPardonForm::AlreadySignedException();
	(*this)._isSigned = true;
}

/**
 * @brief Create <<target>_shrubbery> file in current directory if it doesn't exist and draw
 * an ASCII Art Tree in it.
 * 
 * @param slave 
 * @param target 
 */
void		PresidentialPardonForm::execute(Bureaucrat &slave, const std::string &target)
{
	if (not this->isSigned())
		throw PresidentialPardonForm::NotSignedYet();
	if (slave.getGrade() > (*this).getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();

	std::cout << target << " get an absolute redemption from Zaphod Beeblebrox !" << std::endl;
}

std::ostream&	operator<<(std::ostream &out, PresidentialPardonForm const &F)
{
	if (F.isSigned())
		std::cout << "PresidentialPardonForm " << F.getName() << " (signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	else
		std::cout << "PresidentialPardonForm " << F.getName() << " (NOT signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	return (out);
}
