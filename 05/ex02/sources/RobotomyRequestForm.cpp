#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
{
	this->_name = "defaultRobotomy";
	this->_isSigned = false;
	this->_gradeToSign = 72;
	this->_gradeToExecute = 45;

	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor of " << this->getName() << " (Robotomy) called" << std::endl;

	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target, const std::string &name) : Form::Form(target, name)
{
	this->_target = target;
	this->_name = name;
	this->_isSigned = false;
	this->_gradeToSign = 72;
	this->_gradeToExecute = 45;

	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &SCF) : Form::Form(SCF)
{
	this->_name = SCF.getName();
	this->_isSigned = SCF.isSigned();
	this->_gradeToSign = SCF.getGradeToSign();
	this->_gradeToExecute = SCF.getGradeToExecute();

	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &SCF)
{
	this->_name = SCF.getName();
	this->_isSigned = SCF.isSigned();
	this->_gradeToSign = SCF.getGradeToSign();
	this->_gradeToExecute = SCF.getGradeToExecute();

	return (*this);
}

bool	RobotomyRequestForm::isSigned(void) const
{
	return (this->_isSigned);
}

int		RobotomyRequestForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int		RobotomyRequestForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

std::string RobotomyRequestForm::getName(void) const
{
	return (this->_name);
}

RobotomyRequestForm::GradeTooHighException::GradeTooHighException(void)
{
	return ;
}

RobotomyRequestForm::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

const char*	RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

RobotomyRequestForm::GradeTooLowException::GradeTooLowException(void)
{
	return ;
}

RobotomyRequestForm::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char*	RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

RobotomyRequestForm::AlreadySignedException::AlreadySignedException(void)
{
	return ;
}

RobotomyRequestForm::AlreadySignedException::~AlreadySignedException(void) throw()
{
	return ;
}

RobotomyRequestForm::NotSignedYet::NotSignedYet(void)
{
	return ;
}

RobotomyRequestForm::NotSignedYet::~NotSignedYet(void) throw()
{
	return ;
}

const char* RobotomyRequestForm::NotSignedYet::what() const throw()
{
	return ("can't execute an unsigned form.");
}


const char* RobotomyRequestForm::AlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

/**
 * @brief Sign Robotomy' form if the Bureaucrat <B> has enough rights.
 * 
 * @param B 
 */
void		RobotomyRequestForm::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > (*this).getGradeToSign())
		throw RobotomyRequestForm::GradeTooLowException();
	if ((*this)._isSigned)
		throw RobotomyRequestForm::AlreadySignedException();
	(*this)._isSigned = true;
}

/**
 * @brief Create <<target>_shrubbery> file in current directory if it doesn't exist and draw
 * an ASCII Art Tree in it.
 * 
 * @param slave 
 * @param target 
 */
void		RobotomyRequestForm::execute(Bureaucrat &slave)
{
	if (not this->isSigned())
		throw RobotomyRequestForm::NotSignedYet();
	if (slave.getGrade() > (*this).getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowException();

	std::cout << "BZZZZZZZZZZZZZZZZZZT *bruit de perceuse*" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->getTarget() << " GoT RoBoToMiZeD BZZZZZZZZZZZZZZZZZT..." << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed hard..." << std::endl;
}

std::ostream&	operator<<(std::ostream &out, RobotomyRequestForm const &F)
{
	if (F.isSigned())
		std::cout << "RobotomyRequestForm " << F.getName() << " (signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	else
		std::cout << "RobotomyRequestForm " << F.getName() << " (NOT signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	return (out);
}
