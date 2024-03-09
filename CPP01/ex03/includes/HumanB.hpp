#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../includes/Weapon.hpp"
#include "../includes/Colors.hpp"
#include <iostream>

using std::string;

class HumanB
{
private:
	string	name;
	Weapon	*weapon;
public:
	HumanB(string new_name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon &new_weapon);
};



#endif
