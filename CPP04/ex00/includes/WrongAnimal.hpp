#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Colors.hpp"

# include <iostream>
using	std::string;
using	std::cout;
using	std::endl;

class WrongAnimal
{
protected:
	string	_type;
public:
	WrongAnimal(void);
	WrongAnimal(string _type);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal&	operator=(const WrongAnimal& copy);

	void	makeSound(void) const;
	string	getType(void) const;
};



#endif
