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

// Constructeurs
Fixed::Fixed(void)
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = f.getRawBits();
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = i << Fixed::rawBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(f * (1 << Fixed::rawBits));
}

// Destructeur
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Fonctions membres
int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->value / roundf((1 << Fixed::rawBits))));
}

int		Fixed::toInt(void) const
{
	return ((int)((this->value) >> Fixed::rawBits));
}

void	Fixed::operator=(Fixed const & F)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->value = F.getRawBits();
}

std::ostream & operator<<(std::ostream & o, Fixed const & F)
{
	o << F.toFloat();

	return o;
}