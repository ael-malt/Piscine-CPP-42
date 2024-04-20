#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

class Data
{
private:
	int	_nb;
public:
	void setNb(int n);
	int getNb(void) const;

};

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer& src);
public:
	Serializer & operator=(Serializer const & rhs);
	~Serializer();
	
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};


#endif
