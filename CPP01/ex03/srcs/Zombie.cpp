#include "../includes/Zombie.hpp"
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

Zombie::~Zombie(void)
{
	cout << this->name << " Was destroyed" << endl;
}

void	Zombie::announce(void)
{
	cout << this->name << ":  BraiiiiiiinnnzzzZ..." << endl;
}


void	Zombie::setName(string name)
{
	this->name = name;
}
