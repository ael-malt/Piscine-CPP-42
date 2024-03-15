#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Colors.hpp"

# include <iostream>
using	std::string;
using	std::cout;
using	std::endl;

class Animal
{
protected:
	string	_type;
public:
	Animal(void);
	Animal(string _type);
	virtual ~Animal();
	Animal(const Animal& copy);
	Animal&	operator=(const Animal& copy);

	virtual	void	makeSound(void) const;
	string	getType(void) const;
};



#endif
