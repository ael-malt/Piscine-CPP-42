#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "Colors.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"


using std::string;
using std::cout;
using std::endl;

class ICharacter;

class AMateria
{
	static AMateria**	dropped;
protected:
	string	_type;
public:
	AMateria(string const & type);
	AMateria(const AMateria& copy);
	virtual ~AMateria();
	AMateria& operator=(const AMateria& copy);

	string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	string const & getType() const;
	void drop();
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	static void clean();
	
};
# endif
