#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Zoop. This is a brand new brain !" << std::endl;
	return ;
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
	return ;
}

Brain&	Brain::operator=(const Brain &B)
{
	std::cout << "Let's do some chemics and duplicate this brain!" << std::endl;
	*this = B;
	return *this;
}