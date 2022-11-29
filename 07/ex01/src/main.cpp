#include "iter.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, print);
	std::cout << std::endl;
	iter(arr, 5, addOne);
	iter(arr, 5, print);
	std::cout << std::endl;
	return (0);
}