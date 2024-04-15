#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

template <typename T> void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T> T min(T &x, T &y)
{
	if (x < y)
		return (x);
	return (y);
}

template <typename T> T max(T &x, T &y)
{
	if (x > y)
		return (x);
	return (y);
}


#endif
