#include "Brain.hpp"

Brain::Brain(void)
{
	const std::string ideas[5] = {
		"idea 1",
		"idea 2",
		"idea 3",
		"idea 4",
		"idea 5"
	};

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[rand() % 5];
	std::cout << "Zoop. This is a brand new brain !" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain liquefied." << std::endl;
	return ;
}

Brain::Brain(const Brain &B)
{
	std::cout << "No personnality. A new same brain." << std::endl;
	*this = B;
}

Brain&	Brain::operator=(const Brain &B)
{
	std::cout << "Let's do some chemics and duplicate this brain!" << std::endl;
	if (this == &B)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = B._ideas[i];
	return (*this);
}

std::string&	Brain::getIdea(int i)
{
	return (this->_ideas[i]);
}