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

class Bureaucrat;
class Form;

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &F);
		RobotomyRequestForm(const std::string &);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const & F);

		void			beSigned(const Bureaucrat &B);
		bool			isSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		std::string 	getName(void) const;
		void			robotomize(Bureaucrat &slave, const std::string &);
		void			secure_close_stream(std::fstream &);

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
		class NotSignedYet : public std::exception
		{
			public:
				NotSignedYet(void);
				~NotSignedYet(void) throw();
				virtual const char* what() const throw();
		};
		class AlreadySignedException : public std::exception
		{
			public:
				AlreadySignedException(void);
				~AlreadySignedException(void) throw();
				virtual const char* what() const throw();
		};

	private:
		std::string _name;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;
};

std::ostream&	operator<<(std::ostream &out, Form const &F);

#endif