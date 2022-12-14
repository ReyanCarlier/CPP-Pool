#ifndef MIN_HPP
# define MIN_HPP

template <typename T>
T min(T const &a, T const &b) {
	return (a < b ? a : b);
}

#endif