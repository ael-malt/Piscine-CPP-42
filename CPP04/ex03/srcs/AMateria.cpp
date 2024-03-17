#include "AMateria.hpp"

AMateria::AMateria(string const & type) {
	
}

AMateria::AMateria(string type) : _type(type) {
	cout << GREEN << "Created an AMateria: " << BOLD << _type << DEFAULT << endl;
}
AMateria::~AMateria()
{
	string	n;
	_type == "AMateria" ? n = "n " : n = " AMateria: " ;
	cout << RED << "Destroyed a" << n << BOLD << _type << DEFAULT << endl;
	
}
