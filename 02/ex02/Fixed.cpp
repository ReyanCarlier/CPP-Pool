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
		return ;
	}

	Fixed::Fixed(const Fixed &f)
	{
		this->rawBits = f.getRawBits();
	}

	Fixed::Fixed(const int i)
	{
		this->rawBits = i << Fixed::fractBits;
	}

	Fixed::Fixed(const float f)
	{
		this->rawBits = (int)roundf(f * (1 << Fixed::fractBits));
	}

	// Destructeur
	Fixed::~Fixed(void)
	{
		return ;
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

// SURCHARGES OPERATEURS

	// Assignation
	Fixed&	Fixed::operator=(Fixed const & F)
	{
		this->rawBits = F.getRawBits();
		return (*this);
	}

	// Comparaisons
	bool	Fixed::operator>(Fixed const & F)
	{
		return ((*this).toFloat() > F.toFloat());
	}

	bool	Fixed::operator<(Fixed const & F)
	{
		return (this->toFloat() < F.toFloat());
	}

	bool	Fixed::operator>=(Fixed const & F)
	{
		return ((*this).toFloat() >= F.toFloat());
	}

	bool	Fixed::operator<=(Fixed const & F)
	{
		return (this->toFloat() <= F.toFloat());
	}

	bool	Fixed::operator==(Fixed const & F)
	{
		return (this->toFloat() == F.toFloat());
	}

	bool	Fixed::operator!=(Fixed const & F)
	{
		return (this->toFloat() != F.toFloat());
	}

	// Opérations
	Fixed	Fixed::operator+(Fixed const & F)
	{
		return (Fixed(this->toFloat() + F.toFloat()));
	}

	Fixed	Fixed::operator-(Fixed const & F)
	{
		return (Fixed(this->toFloat() - F.toFloat()));
	}

	Fixed	Fixed::operator/(Fixed const & F)
	{
		return (Fixed(this->toFloat() / F.toFloat()));
	}

	Fixed	Fixed::operator*(Fixed const & F)
	{
		return (Fixed(this->toFloat() * F.toFloat()));
	}

	// Dé/In.crémentation
	Fixed	Fixed::operator++(void)
	{
		this->rawBits += 1;
		return (*this);
	}

	Fixed	Fixed::operator--(void)
	{
		this->rawBits -= 1;
		return (*this);
	}

	Fixed	Fixed::operator++(int)
	{
		Fixed dump(*this);
		this->rawBits += 1;
		return (dump);
	}

	Fixed	Fixed::operator--(int)
	{
		Fixed dump(*this);
		this->rawBits -= 1;
		return (dump);
	}

	// Min.Max
	Fixed const	Fixed::min(Fixed const & F1, Fixed const & F2)
	{
		return (F1.toFloat() < F2.toFloat() ? F1 : F2);
	}

	Fixed	Fixed::min(Fixed & F1, Fixed & F2)
	{
		return (F1.toFloat() < F2.toFloat() ? F1 : F2);
	}

	Fixed const	Fixed::max(Fixed const & F1, Fixed const & F2)
	{
		return (F1.toFloat() > F2.toFloat() ? F1 : F2);
	}

	Fixed	Fixed::max(Fixed & F1, Fixed & F2)
	{
		return (F1.toFloat() > F2.toFloat() ? F1 : F2);
	}

// FLUX

std::ostream & operator<<(std::ostream & o, Fixed const & F)
{
	o << F.toFloat();

	return o;
}