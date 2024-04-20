#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>
# include <vector>
# include <deque>
# include <algorithm>
# include <limits.h>
# include <ctime>
# include <cmath>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::exception;

typedef std::vector<int>::iterator IT;

class Span
{
private:
	unsigned int _size;
	std::vector<int> _v;
public:
	// Span();
	Span(unsigned int);
	Span(const Span& copy);
	Span& operator=(Span& copy);

	~Span();

	void	addNumber(int number);
	int		shortestSpan() const;
	int		longestSpan() const;

	class TooManyElements: public exception
	{
		virtual const char* what() const throw() {
			return ( RED "Error: Too many elements\n	max _size reached!" DEFAULT);
		}
	};

	class NotEnoughElements: public exception
	{
		virtual const char* what() const throw() {
			return ( RED "Error: Not enough numbers!\n	Need at least 2 numbers" DEFAULT);
		}
	};
};



#endif