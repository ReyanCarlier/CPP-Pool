#ifndef SPAN_HPP
# define SPAN_HPP

#include <limits>
#include <iostream>
#include <list>
#include <cmath>

class Span {
	public:
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);
		Span operator=(Span const &A);

		void addNumber(int n);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		// Assesseurs
		std::list<int>::iterator begin(void);
		std::list<int>::iterator end(void);

		// Plage d'itérateurs
		void addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end);

	private:
		Span(void);
		unsigned int _size;
		std::list<int> *_array;
		unsigned int _count;
};

#endif