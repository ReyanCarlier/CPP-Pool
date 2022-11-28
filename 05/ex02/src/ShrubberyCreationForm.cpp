#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", "default", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target) : Form("ShrubberyCreationForm", _target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &SCF) : Form(SCF) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &SCF)
{
	if (this != &SCF)
	{
		Form::operator=(SCF);
	}
	return (*this);
}

/**
 * @brief Create <<target>_shrubbery> file in current directory if it doesn't exist and draw
 * an ASCII Art Tree in it.
 * 
 * @param slave
 */
void		ShrubberyCreationForm::executeAction(const Bureaucrat &slave) const
{
	std::fstream stream;
	std::string to_append;

	if (not this->getSigned())
		throw Form::NotSignedException();
	if (slave.getGrade() > (*this).getGradeToExecute())
		throw Form::GradeTooLowException();

	to_append.append(this->getTarget());
	to_append.append("_shrubbery");
	stream.open(to_append.c_str(), std::ios::out | std::ios::trunc);
	std::cout << "try to open file : " << to_append << std::endl;
	if (!stream.is_open())
	{
		std::cout << "Couldn't open file " << to_append << std::endl;
		return;
	}
	std::string	 tree = "                      ___\n\
                _,-'\"\"   \"\"\"\"`--.\n\
             ,-'          __,,-- \\\n\
           ,'    __,--\"\"\"\"dF      )\n\
          /   .-\"Hb_,--\"\"dF      /\n\
        ,'       _Hb ___dF\"-._,-'\n\
      ,'      _,-\"\"\"\"   \"\"--..__\n\
     (     ,-'                  `.\n\
      `._,'     _   _             ;\n\
       ,'     ,' `-'Hb-.___..._,-'\n\
       \\    ,'\"Hb.-'HH`-.dHF\"\n\
        `--'   \"Hb  HH  dF\"\n\
                \"Hb HH dF\n\
                 \"HbHHdF\n\
                  |HHHF\n\
                  |HHH|\n\
                  |HHH|\n\
                  |HHH|\n\
                  |HHH|\n\
                  dHHHb\n\
                .dFd|bHb.               o\n\
      o       .dHFdH|HbTHb.          o /\n\
\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n\
##########################################\n\
	";
	if (!stream.is_open())
		return;
	stream.write(tree.c_str(), tree.length());
	stream.close();
}

std::ostream&	operator<<(std::ostream &o, ShrubberyCreationForm const &SCF)
{
	o << " ____________________" << std::endl;
	o << "|                    |" << std::endl;
	o << "|    FORM DISPLAY    |" << std::endl;
	o << "|____________________|" << std::endl;
	o << "|                    |" << std::endl;
	o << "| Name       : " << std::setw(5) << SCF.getName() << " |" << std::endl;
	o << "| Target     : " << std::setw(5) << SCF.getTarget() << " |" << std::endl;
	o << "| Grade (ex) : " << std::setw(5) << SCF.getGradeToExecute() << " |" << std::endl;
	o << "| Grade (sg) : " << std::setw(5) << SCF.getGradeToSign() << " |" << std::endl;
	if (SCF.getSigned() == true)
		o << "| Signed     : " << std::setw(5) << "true" << " |" << std::endl;
	else
		o << "| Signed     : " << std::setw(5) << "false" << " |" << std::endl;
	o << "|____________________|" << std::endl;

	return (o);
}