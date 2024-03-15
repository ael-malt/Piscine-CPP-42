#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	this->_type = "Cat";
	cout << GREEN << "Created a " << BOLD << _type << DEFAULT << endl;
}

Cat::~Cat() {
	cout << RED << "Destroyed a " << BOLD << _type << DEFAULT << endl;
}

Cat::Cat(const Cat& copy) : Animal() {
	cout << GREEN BOLD << "Copy of " << copy._type << DEFAULT << endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
	this->_type = copy._type;
	cout << GREEN BOLD << "Assignment operator called for " << copy._type << DEFAULT << endl;
	return *this;
}

void	Cat::makeSound(void) const {
	cout << MAGENTA << _type << ": " << BOLD << "** Miaou! **" << DEFAULT << endl;
}
