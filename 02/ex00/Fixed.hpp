#ifndef FIXED_HPP
# define FIXED_HPP

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed&);
		~Fixed(void);
		Fixed & operator=(Fixed const & F);

		int					getRawBits(void) const; // Retourne la valeur du nombre à virgule fixe
		void				setRawBits(int const raw); // Initialise la valeur du nombre à virgule fixe avec celle passée en paramètre

	private:
		int					rawBits;
		static const int 	fractBits = 8;
};

#endif