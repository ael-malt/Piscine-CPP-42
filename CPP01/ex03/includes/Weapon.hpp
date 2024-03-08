#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
using	std::string;

class Weapon
{
private:
	string	type;

public:
	Weapon(string new_type);
	~Weapon(void);
	const string	&getType(void);
	void			setType(string new_type);
};

#endif
