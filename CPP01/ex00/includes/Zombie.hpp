#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

using std::string;

class Zombie
{
	private:
		string name;
	public:
		Zombie(string name);
		~Zombie(void);
		void	announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
