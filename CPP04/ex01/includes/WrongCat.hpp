#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Colors.hpp"
# include "WrongAnimal.hpp"
# include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	~WrongCat();
	
	WrongCat(const WrongCat& copy);
	WrongCat& operator=(const WrongCat& copy);
	void	makeSound(void) const;
};

#endif
