#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& copy) : AMateria(copy._type) {
	// cout << GREEN << "Created an Ice Materia: " << BOLD << _type << DEFAULT << endl;
}

Ice& Ice::operator=(const Ice& copy) {
	*this = copy;
	// cout << GREEN << "Assignment operator called for Ice: " << BOLD << copy._type << DEFAULT << endl;
	return *this;
}

Ice::~Ice() {
	cout << RED << "Destroyed: " << BOLD << _type << DEFAULT << endl;
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	cout << BLUE << " shoots an Ice bolt at " << MAGENTA << target.getName() << DEFAULT << endl;
}

ostream& operator<<(ostream& s, const Ice& copy) {
	s << copy.getType() << " Materia";
	return (s);
}
