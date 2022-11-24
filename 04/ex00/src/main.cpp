#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const WrongAnimal* k = new WrongAnimal();
	const WrongCat* l = new WrongCat();

	std::cout << std::endl << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	k->makeSound();
	l->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
}