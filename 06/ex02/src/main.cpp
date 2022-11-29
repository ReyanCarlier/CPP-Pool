#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include <iostream>
#include <cmath>

Base * generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identity(Base * p)
{
	A * a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A" << std::endl;
	B * b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B" << std::endl;
	C * c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void identify(Base & p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception & e)
	{
		(void)e;
	}
	try
	{
		B & b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception & e)
	{
		(void)e;
	}
	try
	{
		C & c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception & e)
	{
		(void)e;
	}
}

int main(void)
{
	srand(time(NULL));
	Base * b = generate();

	identity(b);
	identify(*b);

	delete b;
	return (0);
}