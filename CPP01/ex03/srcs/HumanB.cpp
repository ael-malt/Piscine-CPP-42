#include "../includes/HumanB.hpp"

using	std::string;
using	std::cout;
using	std::endl;

HumanB::HumanB(string new_name) : name(new_name), weapon(NULL) {}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (weapon)
		cout << GREEN << this->name << RED << " attacks with " << GREEN << this->weapon->getType() << DEFAULT << endl;
	else
	cout  << GREEN << this->name << RED << " attacks with " << GREEN "no weapon!" << DEFAULT << endl;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
}
