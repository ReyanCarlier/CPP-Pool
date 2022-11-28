#include "Brain.hpp"

# ifndef STDLIB_HPP
#  define STDLIB_HPP
#  include <stdlib.h>
# endif

Brain::Brain(void)
{
	this->ideasCount = 100;
	this->ideas = new std::string[this->ideasCount];

	const std::string _ideas[5] = {
		"idea 1",
		"idea 2",
		"idea 3",
		"idea 4",
		"idea 5"
	};

	for (int i = 0; i < this->ideasCount; i++)
		this->ideas[i] = _ideas[rand() % 5];
	std::cout << "Zoop. This is a brand new brain !" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain liquefied." << std::endl;
	delete [] this->ideas;
}

Brain::Brain(const Brain &B)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = B;
}

Brain&	Brain::operator=(const Brain &B)
{
	std::cout << "Let's do some chemics and duplicate this brain!" << std::endl;
	if (this != &B)
	{
		this->ideasCount = B.ideasCount;
		this->ideas = new std::string[this->ideasCount];
		for (int i = 0; i < this->ideasCount; i++)
			this->ideas[i] = B.ideas[i];
	}
	return (*this);
}

std::string&	Brain::getIdea(int i)
{
	return (this->ideas[i]);
}