#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include "../includes/Colors.hpp"

using std::string;

class Zombie
{
	private:
		string name;
	public:
		~Zombie(void);
		void	announce(void);
		void	setName(string name);
};

Zombie*	zombieHorde( int N, std::string name );
#endif
