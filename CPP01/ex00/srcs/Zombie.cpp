#include "../includes/Zombie.hpp"
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

Zombie::Zombie(/* args */)
{
	this->name = name;
}
void	Zombie::announce(void)
{
	cout << this->name << ":  BraiiiiiiinnnzzzZ..." << endl;
}
