#include "AMateria.hpp"

AMateria** AMateria::dropped = NULL;

AMateria::AMateria(void) : _type("VOID") {}

AMateria::AMateria(string const & type) : _type(type) {
	cout << GREEN << "Created Materia of type: " << BOLD << this->_type << DEFAULT << endl;
}

AMateria::AMateria(const AMateria& copy) : _type(copy._type) {
	// cout << GREEN << "Created an AMateria: " << BOLD << _type << DEFAULT << endl;
}

AMateria& AMateria::operator=(const AMateria& copy) {
	if (this != &copy) {
		this->_type = copy._type;
	}
	// cout << GREEN << "Assignment operator called for AMateria: " << BOLD << copy._type << DEFAULT << endl;
	return *this;
}

AMateria::~AMateria() {
	// cout << RED << "Destroyed AMateria: " << BOLD << _type << DEFAULT << endl;
}

string const & AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	cout << ORANGE << "Used AMateria " << GREEN << _type << ORANGE << "to hit " << MAGENTA << &target << endl;
}

void AMateria::drop()
{
	AMateria **floor;
	int i = 0;
	while (dropped != NULL && dropped[i] != NULL)
		if (dropped[i++] == this)
			return ;
	floor = new AMateria*[i + 2];
	floor[i + 1] = NULL;
	floor[i] = this;
	for (int j = 0; j < i; j++)
		floor[j] = dropped[j];
	delete[] dropped;
	dropped = floor;
}

void AMateria::clean() {
	cout << BROWN << "Cleaning dropped items..." << DEFAULT << endl;
	for (size_t i = 0; dropped != NULL && dropped[i] != NULL; i++)
		delete (dropped[i]);
	delete[] dropped;
	cout << BROWN << "Finished Cleanning Dropped items.." << DEFAULT << endl;
}

ostream& operator<<(ostream& s, const AMateria& other) {
	s << other.getType();
	return (s);
}
