#ifndef FIXED_HPP
# define FIXED_HPP

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

# ifndef CMATH_HPP
#  define CMATH_HPP
#  include <cmath>
# endif

#ifndef FSTREAM_HPP
# define FSTREAM_HPP
# include <fstream>
#endif

class Fixed {
	public:

		// (DE)CONSTRUCTEURS
			Fixed(void); // Défaut
			Fixed(const Fixed&); // Recopie
			Fixed(const int); // Entier constant
			Fixed(const float); // Float constant
			~Fixed(void); // Destructeur

		// SURCHARGES OPERATEURS
			// Affectation
			void operator=(Fixed const & F); 

			// Comparaisons
			bool operator>(Fixed const & F);
			bool operator<(Fixed const & F);
			bool operator>=(Fixed const & F);
			bool operator<=(Fixed const & F);
			bool operator==(Fixed const & F);
			bool operator!=(Fixed const & F);

			// Opérations
			Fixed operator+(Fixed const & F); // Addition
			Fixed operator-(Fixed const & F); // Soustraction
			Fixed operator/(Fixed const & F); // Division
			Fixed operator*(Fixed const & F); // Multiplication

			// Dé/In.crémentation
			Fixed operator++(void);
			Fixed operator--(void);
			Fixed operator++(int);
			Fixed operator--(int);
		
		// FONCTIONS MEMBRES
			// Getter
			int					getRawBits(void) const; // Retourne la valeur du nombre à virgule fixe
			
			// Setter
			void				setRawBits(int const raw); // Initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
			
			// Conversion
			float				toFloat(void) const;
			int					toInt(void) const;

			// min.max
			Fixed const static	min(Fixed const & F1, Fixed const & F2);
			Fixed static		min(Fixed & F1, Fixed & F2);
			Fixed const static	max(Fixed const & F1, Fixed const & F2);
			Fixed static		max(Fixed & F1, Fixed & F2);

	private:
		int					value;
		static const int 	rawBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & F); // Insertion dans le flux

#endif