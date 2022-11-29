#include "Scalar.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	try
	{
		Scalar S(argv[1]);
		std::cout << S;
	}
	catch (Scalar::InvalidInputException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}