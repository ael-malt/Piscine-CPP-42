#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>
# include <cmath>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;


// enum e_type {
// 	NONE,
// 	CHAR,
// 	INT,
// 	FLOAT,
// 	DOUBLE,
// 	LITERALS
// };

class ScalarConverter
{
private:
	// char	_char;
	// int 	_int;
	// float	_float;
	// double	_double;
	// string	_str;
	
	// bool	_impossible;
	// e_type	_type;
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter & operator=(ScalarConverter const & rhs);
	~ScalarConverter();
public:
	
	static void convert(string str);
};


#endif
