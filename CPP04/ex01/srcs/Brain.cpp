#include "Brain.hpp"

Brain::Brain(void)
{
	cout << GREEN << "Created a " << BOLD << "Brain" << DEFAULT << endl;
}

Brain::Brain(string type) {
	cout << GREEN << "Created a Brain for " << BOLD << type << DEFAULT << endl;
}

Brain::~Brain() {
	cout << RED << "Destroyed a brain" << DEFAULT << endl;
}

Brain::Brain(const Brain& copy) {
	cout << GREEN BOLD << "Copy a Brain" << DEFAULT << endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy) {
	*this->_ideas = *copy._ideas;
	cout << GREEN BOLD << "Assignment operator called for Brain" << DEFAULT << endl;
	return *this;
}

void	Brain::addIdea(const string idea) {
	for (size_t i = 0; i < 100; i++)
	{
		if (this->_ideas[i].empty())
		{
			this->_ideas[i] = idea;
			break ;
		}
	}
	
}

void	Brain::printIdeas(void) const {
	for (size_t i = 0; i < 100; i++)
	{
		if (!this->_ideas[i].empty())
			cout << LIGHTER_BLUE << "Idea " << YELLOW << i << LIGHTER_BLUE << ": " << BROWN << _ideas[i] << DEFAULT << endl;
		else
			break ;
	}
	
}

