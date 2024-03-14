#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
	ClapTrap	ClapA("ClapA");
	ClapTrap	ClapB("ClapB");
	ScavTrap	ScavA("ScavA");
	ScavTrap	ScavB("ScavB");
	FragTrap	FragA("FragA");
	FragTrap	FragB("FragB");
	DiamondTrap DiamondTrapA("DiamondTrapA");
	DiamondTrap DiamondTrapB("DiamondTrapB");
	
	DiamondTrapA.takeDamage(1);
	DiamondTrapA.takeDamage(1);
	ScavTrap DiamondTrapD	= DiamondTrapA;
	std::cout << DiamondTrapD.getHP() << std::endl;

	ClapA.attack("ClapB");
	ClapB.takeDamage(1);

	ClapB.attack("ClapA");
	ClapA.takeDamage(1);

	ClapA.beRepaired(2);
	
	ClapB.attack("ClapA");
	ClapA.takeDamage(2);

	ClapA.attack("ClapB");
	ClapB.takeDamage(5);

	ClapB.beRepaired(3);

	ClapA.attack("ClapB");
	ClapB.takeDamage(8);
	
	ClapB.attack("ClapA");
	ClapB.beRepaired(3);
	ClapA.attack("ClapB");
	ClapB.takeDamage(8);

	ScavB.attack("ClapA");
	ClapA.takeDamage(20);

	ScavB.guardGate();

	ScavA.beRepaired(12);

	ScavB.attack("ClapB");
	ClapB.takeDamage(20);

	ScavA.attack("ScavB");
	ScavB.takeDamage(10);

	ScavA.guardGate();

	ScavB.attack("ScavA");
	ScavA.takeDamage(20);

	ScavB.attack("ScavA");
	ScavA.takeDamage(93);
	
	FragB.attack("ScavB");
	FragB.takeDamage(30);

	FragA.attack("FragB");
	FragA.takeDamage(30);
	
	FragA.highFivesGuys();
	
	ScavB.attack("FragA");
	FragA.takeDamage(99999999);

	DiamondTrapA.attack("DiamondTrapB");
	DiamondTrapB.takeDamage(30);

	return (0);
}
