#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <map>

int main()
{
	std::cout << "MutantStack:" << std::endl;
	MutantStack<std::map<std::string, int> > mstack;

	mstack.push(std::map<std::string, int>());
	mstack.top()["test"] = 1;
	mstack.push(std::map<std::string, int>());
	mstack.top()["test"] = 2;
	mstack.push(std::map<std::string, int>());
	mstack.top()["test"] = 3;

	std::cout << "Top: " << mstack.top()["test"] << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.pop();

	std::cout << "Top: " << mstack.top()["test"] << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(std::map<std::string, int>());
	mstack.top()["test"] = 4;

	std::cout << "Top: " << mstack.top()["test"] << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;

	std::cout << "Iterators:" << std::endl;
	MutantStack<std::map<std::string, int> >::iterator it = mstack.begin();
	MutantStack<std::map<std::string, int> >::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << it->begin()->second << std::endl;
		++it;
	}

	return 0;
}