#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal"){
	cout << GREEN << "Created an " << BOLD << _type << DEFAULT << endl;
}

AAnimal::AAnimal(string type) : _type(type) {
	cout << GREEN << "Created an AAnimal: " << BOLD << _type << DEFAULT << endl;
}
AAnimal::~AAnimal()
{
	string	n;
	_type == "AAnimal" ? n = "n " : n = " AAnimal: " ;
	cout << RED << "Destroyed a" << n << BOLD << _type << DEFAULT << endl;
	
}

AAnimal::AAnimal(const AAnimal& copy) {
	cout << GREEN BOLD << "Copy an " << copy._type << DEFAULT << endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	this->_type = copy._type;
	cout << GREEN BOLD << "Assignment operator called for " << copy._type << DEFAULT << endl;
	return *this;
}

void	AAnimal::makeSound(void) const {
	cout << LIGHT_BLUE << _type << ": " << BOLD <<  "** AAnimal noises **" << DEFAULT << endl;
}

string	AAnimal::getType(void) const {
	return (this->_type);
}

