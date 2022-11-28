#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# ifndef FORM_HPP
#  include "Form.hpp"
# endif

# ifndef FSTREAM_HPP
#  include <fstream>
# endif

# ifndef BUREAUCRAT_HPP
#  include "Bureaucrat.hpp"
# endif

# ifndef STRING_HPP
#  include <string>
# endif

class Bureaucrat;
class Form;

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &F);
		ShrubberyCreationForm(const std::string &_target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & F);

		void	executeAction(const Bureaucrat &slave) const;
};

#endif