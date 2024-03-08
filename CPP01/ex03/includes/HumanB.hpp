#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../includes/Weapon.hpp"
#include <iostream>

using std::string;

class HumanB
{
private:
	string	club;
public:
	HumanB(void);
	HumanB(string new_name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &new_weapon);

};



#endif
