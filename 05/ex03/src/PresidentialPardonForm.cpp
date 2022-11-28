#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", "default", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target) : Form("PresidentialPardonForm", _target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &SCF) : Form::Form(SCF) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &SCF)
{
	if (this != &SCF)
	{
		Form::operator=(SCF);
	}
	return (*this);
}

/**
 * @brief Executes the form, the target is pardoned by the president.
 * 
 * @param slave The bureaucrat who executes the form.
 */
void		PresidentialPardonForm::executeAction(const Bureaucrat &slave) const
{
	if (this->getSigned() == false)
		throw Form::NotSignedException();
	if (slave.getGrade() > (*this).getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << slave.getName() << " executed " << this->getName() << std::endl;
	std::cout << this->getTarget() << " get an absolute redemption from Zaphod Beeblebrox !" << std::endl;
}