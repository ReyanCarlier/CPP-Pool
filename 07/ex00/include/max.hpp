#ifndef MAX_HPP
# define MAX_HPP

template <typename T>
T max(T const &a, T const &b) {
	return (a > b ? a : b);
}

#endif