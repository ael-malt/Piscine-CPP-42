#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include "Colors.hpp"
# include "Brain.hpp"
# include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

class AAnimal : virtual public Brain
{
protected:
	string	_type;
public:
	AAnimal(void);
	AAnimal(string _type);
	virtual ~AAnimal();
	AAnimal(const AAnimal& copy);
	AAnimal&	operator=(const AAnimal& copy);

	virtual	void	makeSound(void) const = 0;
	string	getType(void) const;
};



#endif
