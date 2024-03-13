#include "ScavTrap.hpp"

using	std::cout;
using	std::endl;

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	_current_trap = "ScavTrap ";
	cout << GREEN << "Summoned " << _current_trap << BOLD << _name << DEFAULT << endl;
}

ScavTrap::~ScavTrap() {
	cout << RED << "Destroyed " << _current_trap << BOLD << this->_name << DEFAULT << endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	cout << GREEN BOLD << "Summoned " << _current_trap << "copy " << &copy << DEFAULT << endl;
	*this = copy;
}
ScavTrap &ScavTrap::operator=(const ScavTrap& copy) {
	ClapTrap::operator=(copy);
	return (*this);
}

void ScavTrap::guardGate() {
	cout << YELLOW << _current_trap << GREEN << this->_name << YELLOW << " is now guarding the gate!" << DEFAULT << endl;
}
