#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& copy) : AMateria(copy._type) {
	// cout << GREEN << "Created a Cure Materia" << DEFAULT << endl;
}

Cure& Cure::operator=(const Cure& copy) {
	*this = copy;
	// cout << GREEN << "Assignment operator called for Cure: " << BOLD << copy._type << DEFAULT << endl;
	return *this;
}

Cure::~Cure() {
	cout << RED << "Destroyed: " << BOLD << _type << DEFAULT << endl;
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}
static char get_last_char(string str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (str[i]);
}
void Cure::use(ICharacter& target) {
	string s = "";
	if (!target.getName().empty())
		get_last_char(target.getName()) == 's' ? s = "'" : s = "'s";
	cout << PINK << " cures " << MAGENTA << target.getName() << s << PINK << " wounds*" << DEFAULT << endl;
}

ostream& operator<<(ostream& s, const Cure& copy) {
	s << copy.getType() << " Materia";
	return (s);
}
