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

// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }