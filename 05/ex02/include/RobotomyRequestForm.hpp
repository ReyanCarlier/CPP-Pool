#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &F);
		RobotomyRequestForm(const std::string &_target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const & F);

		void	executeAction(const Bureaucrat &slave) const;
};

std::ostream&	operator<<(std::ostream &out, Form const &F);

#endif