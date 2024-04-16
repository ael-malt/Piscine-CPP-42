#ifndef Array_HPP
# define Array_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

template <typename T>
class Array {
private:
	T* _Array;
	unsigned int _size;
public:
	Array(void);
	Array(unsigned int n);
	Array(Array& copy);
	Array &operator=(Array& copy);
	~Array(void);
	class IndexOutOfArray : public std::exception
	{
		virtual const char* what() const throw() {return ("Index is out of bounds!");}
	};

	unsigned int	size(void);
	T &operator[](unsigned int index);

};

# include "../srcs/Array.tpp"

#endif