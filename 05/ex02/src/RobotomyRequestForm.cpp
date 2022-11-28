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

	std::cout << "BZZZZZZZZZZZZZZZZZZT *bruit de perceuse*" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->getTarget() << " GoT RoBoToMiZeD BZZZZZZZZZZZZZZZZZT..." << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed hard..." << std::endl;
}

std::ostream&	operator<<(std::ostream &o, RobotomyRequestForm const &RPF)
{
	o << " ____________________" << std::endl;
	o << "|                    |" << std::endl;
	o << "|    FORM DISPLAY    |" << std::endl;
	o << "|____________________|" << std::endl;
	o << "|                    |" << std::endl;
	o << "| Name       : " << std::setw(5) << RPF.getName() << " |" << std::endl;
	o << "| Target     : " << std::setw(5) << RPF.getTarget() << " |" << std::endl;
	o << "| Grade (ex) : " << std::setw(5) << RPF.getGradeToExecute() << " |" << std::endl;
	o << "| Grade (sg) : " << std::setw(5) << RPF.getGradeToSign() << " |" << std::endl;
	if (RPF.getSigned() == true)
		o << "| Signed     : " << std::setw(5) << "true" << " |" << std::endl;
	else
		o << "| Signed     : " << std::setw(5) << "false" << " |" << std::endl;
	o << "|____________________|" << std::endl;

	return (o);
}