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
		// Constructeurs / Destructeurs
		Fixed(void); // Défaut
		Fixed(const Fixed&); // Recopie
		Fixed(const int); // Entier constant
		Fixed(const float); // Float constant
		~Fixed(void); // Destructeur

		// Opérateurs
		void operator=(Fixed const & F); // Affectation

		// Fonctions membres
		int					getRawBits(void) const; // Retourne la valeur du nombre à virgule fixe
		void				setRawBits(int const raw); // Initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
		float				toFloat(void) const;
		int					toInt(void) const;

	private:
		int					value;
		static const int 	rawBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & F); // Insertion dans le flux

#endif