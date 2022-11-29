#include "Array.hpp"

int main(void)
{
	Array <int> a(5);
	Array <int> b(5);

	std::cout << "Size of a: " << a.size() << std::endl;
	std::cout << "Size of b: " << b.size() << std::endl;

	int * c = new int();

	std::cout << *c << std::endl;

	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
		b[i] = i + 1;
	}

	try {
		std::cout << a[10] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "a: ";
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl << "b: ";
	for (int i = 0; i < 5; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	delete c;
}