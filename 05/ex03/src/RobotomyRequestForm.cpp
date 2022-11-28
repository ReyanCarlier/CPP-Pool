#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", "default", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target) : Form("RobotomyRequestForm", _target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RPF) : Form(RPF) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &RPF)
{
	if (this != &RPF)
	{
		Form::operator=(RPF);
	}
	return (*this);
}

/**
 * @brief Executes the form, the target is robotomized with a 50% chance.
 * 
 * @param slave The bureaucrat who executes the form.
 */
void		RobotomyRequestForm::executeAction(const Bureaucrat &slave) const
{
	if (not this->getSigned())
		throw Form::NotSignedException();
	if (slave.getGrade() > (*this).getGradeToExecute())
		throw Form::GradeTooLowException();
	std::cout << slave.getName() << " executed " << this->getName() << std::endl;
	std::cout << "BZZZZZZZZZZZZZZZZZZT *bruit de perceuse*" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->getTarget() << " GoT RoBoToMiZeD BZZZZZZZZZZZZZZZZZT..." << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed hard..." << std::endl;
}