#include "FragTrap.hpp"

using	std::cout;
using	std::endl;

FragTrap::FragTrap(string name) : ClapTrap(name) {
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	_current_trap = "FragTrap ";
	cout << GREEN << "Summoned " << _current_trap << BOLD << _name << DEFAULT << endl;
}

FragTrap::~FragTrap() {
	cout << RED << "Destroyed " << _current_trap << BOLD << this->_name << DEFAULT << endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	cout << GREEN BOLD << "Summoned " << _current_trap << "copy " << &copy << DEFAULT << endl;
	*this = copy;
}
FragTrap &FragTrap::operator=(const FragTrap& copy) {
	ClapTrap::operator=(copy);
	return (*this);
}

void FragTrap::highFivesGuys() {
	cout << YELLOW << _current_trap << this->_name << " kindly asks for a friendly High Five!" << DEFAULT << endl;
}
