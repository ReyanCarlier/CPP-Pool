#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# ifndef FORM_HPP
#  include "Form.hpp"
# endif

# ifndef FSTREAM_HPP
#  include <fstream>
# endif

# ifndef STDLIB_H
#  include <stdlib.h>
# endif

# ifndef BUREAUCRAT_HPP
#  include "Bureaucrat.hpp"
# endif

# ifndef STRING_HPP
#  include <string>
# endif

class Bureaucrat;
class Form;

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &F);
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const & F);

		void	executeAction(const Bureaucrat &slave) const;
};

#endif