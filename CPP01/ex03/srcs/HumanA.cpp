#include "../includes/HumanA.hpp"

using	std::string;
using	std::cout;
using	std::endl;


HumanA::HumanA(string new_name, Weapon &new_weapon) : name(new_name), weapon(new_weapon) {}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	cout << BLUE << this->name << RED << " attacks with " BLUE << this->weapon.getType() << DEFAULT << std::endl;
}

void	HumanA::setWeapon(Weapon &new_weapon)
{
	this->weapon = new_weapon;
}
