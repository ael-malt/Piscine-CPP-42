#include "DiamondTrap.hpp"

using	std::cout;
using	std::endl;

DiamondTrap::DiamondTrap(string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	FragTrap::_hit_points = 100;
	ScavTrap::_energy_points = 50;
	FragTrap::_attack_damage = 30;
	this->_current_trap = "DiamondTrap ";
	cout << GREEN << "Summoned " << _current_trap << BOLD << _name << DEFAULT << endl;
}

DiamondTrap::~DiamondTrap() {
	cout << RED << "Destroyed DiamondTrap " << BOLD << this->_name << DEFAULT << endl;
}

void	DiamondTrap::whoAmI() {
	cout << "My name is: " << this->_name << endl;
	cout << "My ClapTrap name is:" << ClapTrap::_name << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	cout << GREEN BOLD << "Summoned DiamondTrap copy for " << copy._name << DEFAULT << endl;
	*this = copy;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap& copy) {
	cout << GREEN BOLD << "Assignment operator called for DiamondTrap " << copy._name << DEFAULT << endl;
	ClapTrap::operator=(copy);
	return (*this);
}
