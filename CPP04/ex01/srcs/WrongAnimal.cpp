#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
	cout << GREEN << "Created a " << BOLD << _type << DEFAULT << endl;
}

WrongAnimal::WrongAnimal(string type) : _type(type) {
	cout << GREEN << "Created a WrongAnimal: " << BOLD << _type << DEFAULT << endl;
}
WrongAnimal::~WrongAnimal()
{
	string	n;
	_type == "WrongAnimal" ? n = " " : n = " WrongAnimal: " ;
	cout << RED << "Destroyed a" << n << BOLD << _type << DEFAULT << endl;
	
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	cout << GREEN BOLD << "Copy an " << copy._type << DEFAULT << endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	this->_type = copy._type;
	cout << GREEN BOLD << "Assignment operator called for " << copy._type << DEFAULT << endl;
	return *this;
}

void	WrongAnimal::makeSound(void) const {
	cout << LIGHT_BLUE << _type << ": " << BOLD <<  "** WrongAnimal noises **" << DEFAULT << endl;
}

string	WrongAnimal::getType(void) const {
	return (this->_type);
}

