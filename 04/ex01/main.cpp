#include "Cat.h"
#include "Dog.h"

int	main(void)
{
	Animal* meta = new Animal();
	std::cout<< "type = " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;

	Dog *doggo = new Dog();
	Dog doggo_copy = *doggo;

	Cat *garfield = new Cat();
	Cat garfield_copy = *garfield;

	doggo->makeSound();
	std::cout << "type = " << doggo->getType() << std::endl;
	doggo_copy.makeSound();
	std::cout << "type = " << doggo_copy.getType() << std::endl;
	
	garfield->makeSound();
	std::cout << "type = " << garfield->getType() << std::endl;
	garfield_copy.makeSound();
	std::cout << "type = " << garfield_copy.getType() << std::endl;

	delete doggo;
	delete garfield;

	doggo_copy.makeSound();
	garfield_copy.makeSound();
	return (0);
}