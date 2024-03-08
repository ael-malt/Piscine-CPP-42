#include "../includes/Zombie.hpp"
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

Zombie::~Zombie(void)
{
	cout << RED << this->name << " Was destroyed" << DEFAULT << endl;
}

void	Zombie::announce(void)
{
	cout << GREEN << this->name << ":  BraiiiiiiinnnzzzZ..." << DEFAULT << endl;
}


void	Zombie::setName(string name)
{
	this->name = name;
}
