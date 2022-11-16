#ifndef FORM_HPP
# define FORM_HPP

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const Form &F);
		Form(const std::string &, const std::string &);
		virtual ~Form(void) = 0;
		Form(const std::string &target, const std::string &name, const int &gradeToSign, const int &gradeToExecute);
		Form&	operator=(Form const & F);

		virtual bool		isSigned(void) const;
		virtual void		beSigned(const Bureaucrat &B);
		virtual int			getGradeToSign(void) const;
		virtual int			getGradeToExecute(void) const;
		std::string 		getName(void) const;
		std::string			getTarget(void) const;
		virtual void		execute(const Bureaucrat &executor) const;

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
		std::string	_target;
		std::string	_name;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;
};

std::ostream&	operator<<(std::ostream &out, Form const &F);

#endif