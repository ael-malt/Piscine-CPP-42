#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>
# include <vector>
# include <deque>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::exception;


class NotFound: public exception
{
	virtual const char* what() const throw() {
		return ( RED "Element not found!" DEFAULT);
	}
};

# include "../srcs/easyFind.tpp"

#endif