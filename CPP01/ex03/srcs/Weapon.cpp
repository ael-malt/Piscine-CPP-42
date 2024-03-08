#include "../includes/Weapon.hpp"

using	std::string;

Weapon::Weapon(string new_type)
{
	type = new_type;
}

Weapon::~Weapon(void)
{
}

const string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(string new_type)
{
	type = new_type;
}
