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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target, const std::string &name) : Form::Form(target, name)
{
	this->_target = target;
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

ShrubberyCreationForm::NotSignedYet::NotSignedYet(void)
{
	return ;
}

ShrubberyCreationForm::NotSignedYet::~NotSignedYet(void) throw()
{
	return ;
}

const char* ShrubberyCreationForm::NotSignedYet::what() const throw()
{
	return ("can't execute an unsigned form.");
}


/**
 * @brief Sign Shrubbery' form if the Bureaucrat <B> has enough rights.
 * 
 * @param B 
 */
void		ShrubberyCreationForm::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > (*this).getGradeToSign())
		throw ShrubberyCreationForm::GradeTooLowException();
	if ((*this)._isSigned)
		throw ShrubberyCreationForm::AlreadySignedException();
	(*this)._isSigned = true;
}

/**
 * @brief Create <<target>_shrubbery> file in current directory if it doesn't exist and draw
 * an ASCII Art Tree in it.
 * 
 * @param slave 
 * @param target 
 */
void		ShrubberyCreationForm::createTree(Bureaucrat &slave, const std::string &target)
{
	std::fstream stream;
	std::string to_append;

	if (not this->isSigned())
		throw ShrubberyCreationForm::NotSignedYet();
	if (slave.getGrade() > (*this).getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();

	to_append.append(target);
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

std::ostream&	operator<<(std::ostream &out, ShrubberyCreationForm const &F)
{
	if (F.isSigned())
		std::cout << "ShrubberyCreationForm " << F.getName() << " (signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	else
		std::cout << "ShrubberyCreationForm " << F.getName() << " (NOT signed) can be signed by grade " << F.getGradeToSign() << " and can be executed by grade " << F.getGradeToExecute() << "." << std::endl;
	return (out);
}
