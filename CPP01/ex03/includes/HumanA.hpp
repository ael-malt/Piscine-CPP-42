#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "../includes/Weapon.hpp"
#include <iostream>

using std::string;

class HumanA
{
private:
	string	name;
	Weapon	&weapon;
public:
	HumanA(string new_name, Weapon &new_weapon);
	~HumanA();
	void	attack();
};




#endif
