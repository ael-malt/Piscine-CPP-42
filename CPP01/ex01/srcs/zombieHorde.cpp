#include "../includes/Zombie.hpp"

using std::string;
using std::cout;
using std::endl;

Zombie*	zombieHorde( int N, std::string name )
{
	if (N < 0)
	{
		cout << RED << "Error: Enter a positive number" << DEFAULT << endl;
		return (0);
	}
	else
	{
		Zombie *horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			horde[i].setName(name);
			horde[i].announce();
		}
		return (horde);
	}
}
