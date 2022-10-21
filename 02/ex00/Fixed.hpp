#ifndef FIXED_HPP
# define FIXED_HPP

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

class Fixed {
	public:
		Fixed(void); // Constructeur par défaut
		Fixed(const Fixed&); // Constructeur par recopie	
		~Fixed(void); // Destructeur
		Fixed & operator=(Fixed const & F); // Opérateur d'affectation
		// Fixed operator+(Fixed const & F) const; // Opérateur d'addition
		int					getRawBits(void) const; // Retourne la valeur du nombre à virgule fixe
		void				setRawBits(int const raw); // Initialise la valeur du nombre à virgule fixe avec celle passée en paramètre

	private:
		int					value;
		static const int 	rawBits = 8;
};

#endif