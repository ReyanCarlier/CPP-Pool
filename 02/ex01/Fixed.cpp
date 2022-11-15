#include "Fixed.hpp"

#ifndef IOSTREAM_HPP
# define IOSTREAM_HPP
# include <iostream>
#endif

#ifndef FSTREAM_HPP
# define FSTREAM_HPP
# include <fstream>
#endif

# ifndef CMATH_HPP
#  define CMATH_HPP
#  include <cmath>
# endif

// DE.CONSTRUCTEURS
	Fixed::Fixed(void)
	{
		this->rawBits = 0;
		std::cout << "Default constructor called" << std::endl;
		return ;
	}

	Fixed::Fixed(const Fixed &f)
	{
		std::cout << "Copy constructor called" << std::endl;
		this->rawBits = f.getRawBits();
	}

	Fixed::Fixed(const int i)
	{
		std::cout << "Int constructor called" << std::endl;
		this->rawBits = i << Fixed::fractBits;
	}

	Fixed::Fixed(const float f)
	{
		std::cout << "Float constructor called" << std::endl;
		this->rawBits = (int)roundf(f * (1 << Fixed::fractBits));
	}

	// Destructeur
	Fixed::~Fixed(void)
	{
		std::cout << "Destructor called" << std::endl;
	}

// FONCTIONS MEMBRES

	// Getter
	int	Fixed::getRawBits(void) const
	{
		return (this->rawBits);
	}

	// Setter
	void	Fixed::setRawBits(int const raw)
	{
		this->rawBits = raw;
	}

	// Conversions
	float	Fixed::toFloat(void) const
	{
		return ((float)(this->rawBits / roundf((1 << Fixed::fractBits))));
	}

	int		Fixed::toInt(void) const
	{
		return ((int)((this->rawBits) >> Fixed::fractBits));
	}

// SURCHARGE OPERATEURS

	// Assignation
	Fixed&	Fixed::operator=(Fixed const & F)
	{
		std::cout << "Copy assignement operator called" << std::endl;
		this->rawBits = F.getRawBits();

		return (*this);
	}

// FLUX

std::ostream & operator<<(std::ostream & o, Fixed const & F)
{
	o << F.toFloat();

	return o;
}