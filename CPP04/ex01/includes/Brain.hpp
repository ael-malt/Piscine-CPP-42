#if !defined BRAIN_HPP
#define BRAIN_HPP

# include "Colors.hpp"
# include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

class Brain
{
protected:
	string _ideas[100];
public:
	Brain(void);
	Brain(string type);
	virtual ~Brain();
	Brain(const Brain& copy);
	Brain&	operator=(const Brain& copy);

	virtual void	addIdea(const string idea);
	virtual void	printIdeas(void) const;
};



#endif
