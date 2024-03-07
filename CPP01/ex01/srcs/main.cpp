#include "../includes/Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie *horde = zombieHorde(10, "Bob");

	delete[] horde;
	return (0);
}
