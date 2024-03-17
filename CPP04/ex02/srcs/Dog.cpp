#include "../includes/Dog.hpp"

Dog::Dog(void) : AAnimal("Dog") {
	this->_type = "Dog";
	this->_brain = new Brain("Dog");
	cout << GREEN << "Created a " << BOLD << _type << DEFAULT << endl;
}

Dog::~Dog() {
	cout << RED << "Destroyed a " << BOLD << _type << DEFAULT << endl;
	delete this->_brain;
}

Dog::Dog(const Dog& copy) : Brain("Dog"), AAnimal() {
	cout << GREEN BOLD << "Copy of " << copy._type << DEFAULT << endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy) {
	this->_type = copy._type;
	cout << GREEN BOLD << "Assignment operator called for " << copy._type << DEFAULT << endl;
	return *this;
}

void	Dog::makeSound(void) const {
	cout << BROWN << _type << ": " << BOLD << "** Wouf! **" << DEFAULT << endl;
}
