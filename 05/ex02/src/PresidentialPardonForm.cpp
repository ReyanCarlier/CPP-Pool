#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", "default", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm(void) { std::cout << "Destructor of " << this->getName() << " (Presidential) called" << std::endl; }

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

	std::cout << this->getTarget() << " get an absolute redemption from Zaphod Beeblebrox !" << std::endl;
}

std::ostream&	operator<<(std::ostream &o, PresidentialPardonForm const &PDF)
{
	o << " ____________________" << std::endl;
	o << "|                    |" << std::endl;
	o << "|    FORM DISPLAY    |" << std::endl;
	o << "|____________________|" << std::endl;
	o << "|                    |" << std::endl;
	o << "| Name       : " << std::setw(5) << PDF.getName() << " |" << std::endl;
	o << "| Target     : " << std::setw(5) << PDF.getTarget() << " |" << std::endl;
	o << "| Grade (ex) : " << std::setw(5) << PDF.getGradeToExecute() << " |" << std::endl;
	o << "| Grade (sg) : " << std::setw(5) << PDF.getGradeToSign() << " |" << std::endl;
	if (PDF.getSigned() == true)
		o << "| Signed     : " << std::setw(5) << "true" << " |" << std::endl;
	else
		o << "| Signed     : " << std::setw(5) << "false" << " |" << std::endl;
	o << "|____________________|" << std::endl;

	return (o);
}