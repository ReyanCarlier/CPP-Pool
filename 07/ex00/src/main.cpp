#include "max.hpp"
#include "min.hpp"
#include "swap.hpp"
#include <iostream>
#include <string>

int main(void)
{
	int a = 42;
	int b = 21;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min<int>(a, b) << std::endl;
	std::cout << "max(a, b) = " << max<int>(a, b) << std::endl;
	std::cout << "swap(a, b)" << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	float e = 42.42;
	float f = 21.21;

	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << min<float>(e, f) << std::endl;
	std::cout << "max(e, f) = " << max<float>(e, f) << std::endl;
	std::cout << "swap(e, f)" << std::endl;
	swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;

	return (0);
}