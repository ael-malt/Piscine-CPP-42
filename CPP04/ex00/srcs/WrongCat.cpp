#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	cout << GREEN << "Created a " << BOLD << _type << DEFAULT << endl;
}

WrongCat::~WrongCat() {
	cout << RED << "Destroyed a " << BOLD << _type << DEFAULT << endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal() {
	cout << GREEN BOLD << "Copy of " << copy._type << DEFAULT << endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	this->_type = copy._type;
	cout << GREEN BOLD << "Assignment operator called for " << copy._type << DEFAULT << endl;
	return *this;
}

void	WrongCat::makeSound(void) const {
	cout << MAGENTA << _type << ": " << BOLD << "** Miaou! **" << DEFAULT << endl;
}
