#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	try {
		std::cout << *easyfind(v, 3) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Not found 3" << std::endl;
	}
	try {
		std::cout << *easyfind(v, 6) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Not found 6" << std::endl;
	}
	return 0;
}
