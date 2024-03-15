#ifndef DOG_HPP
# define DOG_HPP

# include "Colors.hpp"
# include "Animal.hpp"
# include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

class Dog : public Animal
{
public:
	Dog(void);
	~Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& copy);
	
	void	makeSound(void) const;
};

#endif
