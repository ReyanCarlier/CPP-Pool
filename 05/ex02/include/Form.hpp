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
	private:
		std::string	name;
		std::string target;
		bool		isSigned;
		int			gradeToSign;
		int			gradeToExecute;

	public:
		Form(void);
		Form(const Form &F);
		Form(const std::string &_name, const std::string &_target);
		~Form(void);
		Form(const std::string &name, const std::string &_target, const int &gradeToSign, const int &gradeToExecute);
		Form&	operator=(Form const & F);

		// Getters
		std::string		getName(void) const;
		std::string 	getTarget(void) const;
		bool			getSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;

		// Setters
		void			setName(std::string);
		void			setTarget(std::string);
		void			setSigned(bool);
		void			setGradeToSign(int);
		void			setGradeToExecute(int);

		// Members
		void			beSigned(const Bureaucrat &B);
		void			execute(Bureaucrat const &) const;
		virtual	void	executeAction(Bureaucrat const &) const = 0;

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

		class AlreadySignedException : public std::exception
		{
			public:
				AlreadySignedException(void);
				~AlreadySignedException(void) throw();
				virtual const char* what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				NotSignedException(void);
				~NotSignedException(void) throw();
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, Form const &F);

#endif