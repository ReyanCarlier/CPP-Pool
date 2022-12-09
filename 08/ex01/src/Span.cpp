#include "Span.hpp"

Span::Span(unsigned int n) {
	if (n == 0) {
		throw std::exception();
	}
	this->_size = n;
	this->_array = new std::list<int>;
	this->_count = 0;
}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span(void) {
	delete this->_array;
}

Span Span::operator=(Span const &A) {
	if (this != &A) {
		this->_size = A._size;
		this->_count = A._count;
		this->_array = new std::list<int>(*A._array);
	}
	return *this;
}

/**
 * @brief Ajoute un nombre dans le tableau
 * 
 * @param n 
 */
void Span::addNumber(int n) {
	if (this->_count >= this->_size) {
		throw std::exception();
	}
	this->_array->push_back(n);
	this->_count++;
}

/**
 * @brief Retourne la plus petite distance entre les nombres stockés. Min ne peut être négatif.
 * 
 * @return int 
 */
int Span::shortestSpan(void) const {
	if (this->_count < 2) {
		throw std::exception();
	}
	int min = std::numeric_limits<int>::max();
	std::list<int>::const_iterator it = this->_array->begin();
	std::list<int>::const_iterator it2 = this->_array->begin();

	while (it != this->_array->end()) {
		it2 = it;
		it2++;
		while (it2 != this->_array->end()) {
			if (std::abs(*it - *it2) < min) {
				min = std::abs(*it - *it2);
			}
			it2++;
		}
		it++;
	}
	return min;
}

/**
 * @brief Retourne la plus grande distance entre les nombres stockés.
 * 
 * @return int 
 */
int Span::longestSpan(void) const {
	if (this->_count < 2) {
		throw std::exception();
	}
	int max = std::numeric_limits<int>::min();
	std::list<int>::const_iterator it = this->_array->begin();
	std::list<int>::const_iterator it2 = this->_array->begin();

	while (it != this->_array->end()) {
		it2 = it;
		it2++;
		while (it2 != this->_array->end()) {
			if (std::abs(*it - *it2) > max) {
				max = std::abs(*it - *it2);
			}
			it2++;
		}
		it++;
	}
	return max;
}

/**
 * @brief Ajoute une plage d'itérateurs à la liste.
 * 
 * @param begin 
 * @param end 
 */
void	Span::addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end) {
	while (begin != end) {
		this->addNumber(*begin);
		begin++;
		this->_count++;
	}
}

/**
 * @brief Retourne un itérateur sur le début de la liste.
 * 
 * @return std::list<int>::iterator 
 */
std::list<int>::iterator Span::begin(void) {
	return this->_array->begin();
}

/**
 * @brief Retourne un itérateur sur la fin de la liste.
 * 
 * @return std::list<int>::iterator 
 */
std::list<int>::iterator Span::end(void) {
	return this->_array->end();
}
