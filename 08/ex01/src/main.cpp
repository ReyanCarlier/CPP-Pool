#include "Span.hpp"

int main()
{
	Span *sp = new Span(5);
	Span *sp2 = new Span(5);

	sp->addNumber(6);
	sp->addNumber(3);
	sp->addNumber(17);
	sp->addNumber(9);
	sp->addNumber(11);

	sp2->addNumbers(sp->begin(), sp->end());

	std::cout << sp->shortestSpan() << std::endl;
	std::cout << sp->longestSpan() << std::endl;

	std::cout << sp2->shortestSpan() << std::endl;
	std::cout << sp2->longestSpan() << std::endl;

	delete sp;
	delete sp2;

	return 0;
}