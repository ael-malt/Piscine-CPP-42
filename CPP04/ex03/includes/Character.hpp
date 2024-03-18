#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ostream;
class AMateria;

class Character : public ICharacter {
private:
	AMateria	*_inventory[4];
	string		_name;
public:
	Character(void);
	Character(string const);
	virtual ~Character(void);
	Character(const Character& copy);
	Character&	operator=(const Character& copy);
	
	string	const	&getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

ostream&	operator<<(ostream&, const Character&);

#endif
