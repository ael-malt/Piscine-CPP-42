#include "../includes/Zombie.hpp"

using std::string;

void	randomChump( std::string name )
{
	Zombie new_zombie(name);
	new_zombie.announce();
}
