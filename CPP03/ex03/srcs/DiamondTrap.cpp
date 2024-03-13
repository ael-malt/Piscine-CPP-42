#include "DiamondTrap.hpp"

using	std::cout;
using	std::endl;

DiamondTrap::DiamondTrap(string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	FragTrap::_hit_points = 100;
	ScavTrap::_energy_points = 50;
	FragTrap::_attack_damage = 30;
	_current_trap = "DiamondTrap ";
	cout << GREEN << "Summoned " << _current_trap << BOLD << _name << DEFAULT << endl;
}

DiamondTrap::~DiamondTrap() {
	cout << RED << "Destroyed " << _current_trap << BOLD << this->_name << DEFAULT << endl;
}

void	DiamondTrap::whoAmI() {
	cout << "My name is: " << this->_name << endl;
	cout << "My ClapTrap name is:" << ClapTrap::_name;
}

// void DiamondTrap::guardGate() {
// 	cout << YELLOW << _current_trap << GREEN << this->_name << YELLOW << " is now guarding the gate!" << DEFAULT << endl;
// }
