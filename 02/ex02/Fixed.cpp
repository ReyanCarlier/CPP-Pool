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
		this->value = 0;
		return ;
	}

	Fixed::Fixed(const Fixed &f)
	{
		this->value = f.getRawBits();
	}

	Fixed::Fixed(const int i)
	{
		this->value = i << Fixed::rawBits;
	}

	Fixed::Fixed(const float f)
	{
		this->value = (int)roundf(f * (1 << Fixed::rawBits));
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
		return (this->value);
	}

	// Setter
	void	Fixed::setRawBits(int const raw)
	{
		this->value = raw;
	}

	// Conversions
	float	Fixed::toFloat(void) const
	{
		return ((float)(this->value / roundf((1 << Fixed::rawBits))));
	}

	int		Fixed::toInt(void) const
	{
		return ((int)((this->value) >> Fixed::rawBits));
	}

// SURCHARGE OPERATEURS

	// Assignation
	void	Fixed::operator=(Fixed const & F)
	{
		this->value = F.getRawBits();
	}

	// Comparaisons
	bool	Fixed::operator>(Fixed const & F)
	{
		return (this->toFloat() > F.toFloat());
	}

	bool	Fixed::operator<(Fixed const & F)
	{
		return (this->toFloat() < F.toFloat());
	}

	bool	Fixed::operator>=(Fixed const & F)
	{
		return (this->toFloat() >= F.toFloat());
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
		this->value += 1;
		return (*this);
	}

	Fixed	Fixed::operator--(void)
	{
		this->value -= 1;
		return (*this);
	}

	Fixed	Fixed::operator++(int)
	{
		Fixed dump(*this);
		this->value += 1;
		return (dump);
	}

	Fixed	Fixed::operator--(int)
	{
		Fixed dump(*this);
		this->value -= 1;
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

	std::ostream & operator<<(std::ostream & o, Fixed const & F)
{
	o << F.toFloat();

	return o;
}