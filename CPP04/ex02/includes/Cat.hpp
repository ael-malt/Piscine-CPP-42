#ifndef CAT_HPP
# define CAT_HPP

# include "Colors.hpp"
# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

class Cat : public AAnimal
{
private:
	Brain *_brain;
public:
	Cat(void);
	~Cat();
	
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	void	makeSound(void) const;

};

#endif
