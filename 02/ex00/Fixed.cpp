#include "Fixed.hpp"

#ifndef IOSTREAM_HPP
# define IOSTREAM_HPP
# include <iostream>
#endif

Fixed::Fixed(void)
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(f.getRawBits());
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed &	Fixed::operator=(Fixed const & F)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->value = F.getRawBits();

	return (*this);
}