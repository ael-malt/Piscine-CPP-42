#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;


class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& src);
public:
	ScalarConverter & operator=(ScalarConverter const & rhs);
	~ScalarConverter();

	static void convert(string str);
};


#endif
