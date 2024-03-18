#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "Colors.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"


using std::string;
using std::cout;
using std::endl;
using std::ostream;

class ICharacter;

class AMateria
{
static AMateria** dropped;
protected:
	string	_type;
public:
	AMateria();
	AMateria(string const &type);
	virtual ~AMateria();
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& copy);

	string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	void drop();
	virtual void use(ICharacter& target);
	static void clean();
};

ostream&	operator<<(ostream&, const AMateria&);

# endif
