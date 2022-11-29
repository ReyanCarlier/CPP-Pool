#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <iostream>
#include <typeinfo>
#include <exception>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>

class Scalar {
	public:
		Scalar(void);
		Scalar(Scalar const &);
		~Scalar(void);
		Scalar operator=(Scalar const &);
		Scalar(std::string const &);

		char	toChar(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		double	toDouble(void) const;
	
		class NotDisplayableException : public std::exception {
			public:
				const char* what() const throw() {
					return ("Non displayable");
				}
		};

		class ImpossibleException : public std::exception {
			public:
				const char* what() const throw() {
					return ("impossible");
				}
		};

		class InvalidInputException : public std::exception {
			public:
				const char* what() const throw() {
					return ("invalid input");
				}
		};

	private:
		const std::string	_string;
		char				_char;
		int					_int;
		float				_float;
		double				_double;
		enum type			{CHAR, INT, FLOAT, DOUBLE, INVALID} _type;
};

std::ostream&	operator<<(std::ostream &o, Scalar const &S);

#endif