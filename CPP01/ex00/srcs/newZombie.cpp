#include "../includes/Zombie.hpp"

using std::string;

Zombie*	newZombie(string name)
{
	return (new Zombie(name));
}

