#ifndef BASE_HPP
# define BASE_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

class Base
{
public:
	Base*	generate(void);

	virtual	~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
