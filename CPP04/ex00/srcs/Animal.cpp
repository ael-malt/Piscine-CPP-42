#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
	cout << GREEN << "Created an " << BOLD << _type << DEFAULT << endl;
}

Animal::Animal(string type) : _type(type) {
	cout << GREEN << "Created an Animal: " << BOLD << _type << DEFAULT << endl;
}
Animal::~Animal()
{
	string	n;
	_type == "Animal" ? n = "n " : n = " Animal: " ;
	cout << RED << "Destroyed a" << n << BOLD << _type << DEFAULT << endl;
	
}

Animal::Animal(const Animal& copy) {
	cout << GREEN BOLD << "Copy an " << copy._type << DEFAULT << endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy) {
	this->_type = copy._type;
	cout << GREEN BOLD << "Assignment operator called for " << copy._type << DEFAULT << endl;
	return *this;
}

void	Animal::makeSound(void) const {
	cout << LIGHT_BLUE << _type << ": " << BOLD <<  "** Animal noises **" << DEFAULT << endl;
}

string	Animal::getType(void) const {
	return (this->_type);
}

