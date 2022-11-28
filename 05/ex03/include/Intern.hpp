#ifndef INTERN_HPP
# define INTERN_HPP

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

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &I);
		~Intern(void);
		Intern&	operator=(Intern const & I);

		Form*	makeForm(const std::string &formName, const std::string &target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				FormNotFoundException(void);
				~FormNotFoundException(void) throw();
				virtual const char* what() const throw();
		};
};

#endif