#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

class NotFound: public exception
{
	const char* what() const throw() {
		return ( RED "Element not found!" DEFAULT);
	}
}

# include "../srcs/EasyFind.tpp"

#endif