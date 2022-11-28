#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

# ifndef IOMANIP_HPP
#  define IOMANIP_HPP
#  include <iomanip>
# endif

# ifndef FORM_HPP
#  include "Form.hpp"
# endif

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &B);
		Bureaucrat &operator=(Bureaucrat const & B);
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat(void);

		// Getters
		std::string	getName(void) const;
		int			getGrade(void) const;

		// Members
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(Form &F);
		void		executeForm(const Form &F);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void);
				~GradeTooHighException(void) throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void);
				~GradeTooLowException(void) throw();
				virtual const char* what() const throw();
		};

	private:
		std::string	name;
		int			grade;
};

std::ostream&	operator<<(std::ostream &out, Bureaucrat const &B);

#endif