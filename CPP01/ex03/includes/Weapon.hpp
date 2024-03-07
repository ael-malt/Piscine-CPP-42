#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
using	std::string;

class Weapon
{
private:
	string	type;
public:
	Weapon(void);
	~Weapon(void);
	const string	getType(void);
	void 			setType(string new_type);
};

Weapon::Weapon(void)
{
}

Weapon::~Weapon()
{
}


#endif
