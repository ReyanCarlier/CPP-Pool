#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b;
	Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed d(5.0f);
	Fixed e(5.0f);


	std::cout << "Valeur de base de a : " << a << std::endl;
	std::cout << "Valeur de base de b : " << b << std::endl;
	std::cout << "Valeur de base de c : " << c << std::endl;
	std::cout << "Valeur de base de d : " << d << std::endl;
	std::cout << "Valeur de base de e : " << e << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		PRE-INCREMENTATION" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Valeur de a : " << ++a << " (1 / 1<<8) (Incrementation effectuee.)" << std::endl;
	std::cout << "Valeur de a : " << a << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		POST-INCREMENTATION" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Valeur de b : " << b++ << " (Incrementation effectuee.)" << std::endl;
	std::cout << "Valeur de b : " << b << " (1 / 1<<8)" << std::endl;

	std::cout << "-----------------------------------------" << std::endl;;
	std::cout << "		MIN/MAX" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;;
	std::cout << "Max entre a et c : " << Fixed::max( a, c ) << std::endl;
	std::cout << "Min entre a et c : " << Fixed::min( a, c ) << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		COMPARAISONS" 						 << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << (a > c ? "a" : "c") << " est le plus grand." << std::endl;
	std::cout << (a < c ? "a" : "c") << " est le plus petit." << std::endl;

	
	std::cout << (d == e ? "d & e sont egaux." : "d & e ne sont pas egaux.") << std::endl;
	std::cout << (a != d ? "a & d sont inegaux." : "a & d ne sont pas inegaux.") << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		OPERATIONS" 				 		 << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "a = " << a << " | d = " << d << std::endl;
	std::cout << "a + d = " << a+d << std::endl;
	std::cout << "a - d = " << a-d << std::endl;
	std::cout << "a * d = " << a*d << std::endl;
	std::cout << "d / a = " << d/a << std::endl;
	return 0;
}