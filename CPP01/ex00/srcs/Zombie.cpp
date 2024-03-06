#include "../includes/Zombie.hpp"
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

Zombie::Zombie(string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
}

void	Zombie::announce(void)
{
	cout << this->name << ":  BraiiiiiiinnnzzzZ..." << endl;
}
