#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

int main()
{
	unsigned int	animalCount = 10;
	Animal* 		animals[animalCount];

	for (unsigned int i = 0; i < animalCount; i++)
	{
		if (i >= 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	Cat copy(*(Cat *)animals[0]);
	std::cout << std::endl;
	for (unsigned int i = 0; i < animalCount; i++)
	{
		std::cout << std::setw(30) << std::left << copy.getBrain()->getIdea(i);
		std::cout << std::setw(30) << std::left << ((Cat *)animals[0])->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < animalCount; i++)
	{
		delete animals[i];
	}
}