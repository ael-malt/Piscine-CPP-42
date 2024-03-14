#include "ClapTrap.hpp"


int main(void)
{	
	ClapTrap	A("A");
	ClapTrap	B("B");
	ClapTrap	C("C");


	A.takeDamage(1);
	A.takeDamage(1);
	ClapTrap D	= A;
	std::cout << D.getHP() << std::endl;
	
	A.attack("B");
	B.takeDamage(1);

	B.attack("A");
	A.takeDamage(1);

	A.beRepaired(2);
	
	B.attack("A");
	A.takeDamage(2);

	A.attack("B");
	B.takeDamage(5);

	B.beRepaired(3);

	A.attack("B");
	B.takeDamage(8);
	
	B.attack("A");
	B.beRepaired(3);
	A.attack("B");
	B.takeDamage(8);
	
	for (size_t i = 0; i < 11; i++)
	{
		C.attack("A");
		A.takeDamage(0);
	}
	return (0);
}
