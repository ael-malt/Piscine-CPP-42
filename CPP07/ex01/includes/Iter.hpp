#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

template <typename T> void Iter(T* arr, size_t length, void (*func)(T&))
{
	for(size_t i = 0; i < length; i++)
		func(arr[i]);
}

#endif