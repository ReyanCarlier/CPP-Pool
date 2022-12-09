#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdlib.h>

template <typename T>
class Array {
	public:
		Array(void) {
			this->_array = new T[0];
			this->_size = 0;
		};
		Array(unsigned int n) {
			this->_array = new T[n];
			this->_size = n;
		};
		Array(Array const &src) {
			*this = src;
		};
		~Array(void) {
			delete [] this->_array;
		};
		Array &operator=(Array const &A) {
			if (this != &A) {
				this->_size = A._size;
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++) {
					this->_array[i] = A._array[i];
				}
			}
			return *this;
		};

		T &operator[](unsigned int i) {
			if (i >= this->_size) {
				throw std::exception();
			}
			return this->_array[i];
		};

		unsigned int size(void) const {
			return this->_size;
		};

	private:
		T *_array;
		unsigned int _size;
};

#endif