#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;

class AMateria;

class Character
{
private:
	AMateria	*inventory;
public:
	Character();
	virtual ~Character();
	Character(const Character& copy);
	Character&	operator=(const Character& copy);
	
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
