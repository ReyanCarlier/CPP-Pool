#include "Scalar.hpp"

Scalar::Scalar(void) : _string("0"), _char(0), _int(0), _float(0), _double(0) {}

Scalar::Scalar(Scalar const &S)
{
	*this = S;
}

Scalar::Scalar(const std::string &s) : _string(s)
{
	if (s.empty())
		throw Scalar::InvalidInputException();
	if (s.length() == 1)
	{
		if (isdigit(s[0]))
		{
			this->_int = static_cast<int>(strtol(s.c_str(), NULL, 10));
			this->_type = Scalar::INT;
		}
		else
		{
			this->_char = s[0];
			this->_type = Scalar::CHAR;
		}
	}
	else
	{
		char	*longBuff;
		char	*doubleBuff;
		long	longVal;
		double	doubleVal;

		longVal = strtol(s.c_str(), &longBuff, 10);
		doubleVal = strtof(s.c_str(), &doubleBuff);

		if (*longBuff)
		{
			if (*doubleBuff)
			{
				if (*doubleBuff == 'f')
				{
					this->_float = static_cast<float>(doubleVal);
					this->_type = Scalar::FLOAT;
				}
				else
					throw Scalar::InvalidInputException();
			}
			else
			{
				this->_double = doubleVal;
				this->_type = Scalar::DOUBLE;
			}
		}
		else
		{
			if (longVal > std::numeric_limits<int>::max() || longVal < std::numeric_limits<int>::min())
				throw Scalar::InvalidInputException();
			this->_int = static_cast<int>(longVal);
			this->_type = Scalar::INT;
		}
	}
}

Scalar::~Scalar(void) {}

Scalar	Scalar::operator=(Scalar const &S)
{
	if (this != &S)
	{
		this->_char = S._char;
		this->_int = S._int;
		this->_float = S._float;
		this->_double = S._double;
		this->_type = S._type;
	}
	return (*this);
}

char	Scalar::toChar() const
{
	char			c;

	switch (this->_type)
	{
		case Scalar::CHAR:
			return (this->_char);
		case Scalar::INT:
			if (this->_int > 126 || this->_int < 32)
				throw Scalar::NotDisplayableException();
			c = static_cast<char>(this->_int);
			return (c);
		case Scalar::FLOAT:
			c = static_cast<char>(this->_float);
			if (std::isnan(this->_float) || std::isinf(this->_float))
				throw Scalar::ImpossibleException();
			if (this->_float < std::numeric_limits<char>::min() || this->_float > std::numeric_limits<char>::max())
				throw Scalar::ImpossibleException();
			if (!std::isprint(c))
				throw Scalar::NotDisplayableException();
			return (c);
		case Scalar::DOUBLE:
			c = static_cast<char>(this->_double);
			if (std::isnan(this->_double) || std::isinf(this->_double))
				throw Scalar::ImpossibleException();
			if (this->_double < std::numeric_limits<char>::min() || this->_double > std::numeric_limits<char>::max())
				throw Scalar::ImpossibleException();
			if (!std::isprint(c))
				throw Scalar::NotDisplayableException();
			return (c);
		default:
			break;
	}
	return (0);
}

int		Scalar::toInt() const
{
	switch (this->_type)
	{
		case (Scalar::CHAR):
			return (static_cast<int>(this->_char));
		case (Scalar::INT):
			return (this->_int);
		case (Scalar::FLOAT):
			if (std::isnan(this->_float) || std::isinf(this->_float))
				throw Scalar::ImpossibleException();
			if (this->_float > std::numeric_limits<int>::max() || this->_float < std::numeric_limits<int>::min())
				throw Scalar::ImpossibleException();
			return (static_cast<int>(this->_float));
		case (Scalar::DOUBLE):
			if (std::isnan(this->_double) || std::isinf(this->_double))
				throw Scalar::ImpossibleException();
			if (this->_double > std::numeric_limits<int>::max() || this->_double < std::numeric_limits<int>::min())
				throw Scalar::ImpossibleException();
			return (static_cast<int>(this->_double));
		default:
			break;
	}
	return (0);
}

float	Scalar::toFloat() const
{
	switch (this->_type)
	{
		case (Scalar::CHAR):
			return (static_cast<float>(this->_char));
		case (Scalar::INT):
			return (static_cast<float>(this->_int));
		case (Scalar::FLOAT):
			return (this->_float);
		case (Scalar::DOUBLE):
			return (static_cast<float>(this->_double));
		default:
			break;
	}
	return (0);
}

double	Scalar::toDouble() const
{
	switch (this->_type)
	{
		case (Scalar::CHAR):
			return (static_cast<double>(this->_char));
		case (Scalar::INT):
			return (static_cast<double>(this->_int));
		case (Scalar::FLOAT):
			return (static_cast<double>(this->_float));
		case (Scalar::DOUBLE):
			return (this->_double);
		default:
			break;
	}
	return (0);
}

std::ostream& operator<<(std::ostream& o, const Scalar& S)
{
	o << "char: ";
	try
	{
		o << S.toChar() << std::endl;
	}
	catch (Scalar::NotDisplayableException& e)
	{
		o << "Non displayable" << std::endl;
	}
	catch (Scalar::ImpossibleException& e)
	{
		o << "impossible" << std::endl;
	}
	catch (Scalar::InvalidInputException& e)
	{
		o << "invalid input" << std::endl;
	}
	o << "int: ";
	try
	{
		o << S.toInt() << std::endl;
	}
	catch (Scalar::ImpossibleException& e)
	{
		o << "impossible" << std::endl;
	}
	catch (Scalar::InvalidInputException& e)
	{
		o << "invalid input" << std::endl;
	}
	o << "float: ";
	try
	{
		o << std::fixed << std::setprecision(1) << S.toFloat() << "f" << std::endl;
	}
	catch (Scalar::ImpossibleException& e)
	{
		o << "impossible" << std::endl;
	}
	catch (Scalar::InvalidInputException& e)
	{
		o << "invalid input" << std::endl;
	}
	o << "double: ";
	try
	{
		o << std::fixed << std::setprecision(1) << S.toDouble() << std::endl;
	}
	catch (Scalar::ImpossibleException& e)
	{
		o << "impossible" << std::endl;
	}
	catch (Scalar::InvalidInputException& e)
	{
		o << "invalid input" << std::endl;
	}
	return (o);
}