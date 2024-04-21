#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>
# include <vector>
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

	void				addNumber(int number);
	void				insert(IT begin, IT end);

	unsigned int					shortestSpan() const;
	unsigned int					longestSpan() const;

	int					getSize() const;
	std::vector<int>	getVec() const;

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

template <typename T>
typename T::iterator easyfind(T& container, int nb) {
	typename T::iterator it = container.begin();
	for (; it != container.end() && *it != nb ;it++) {}
		return (it);
}


#endif