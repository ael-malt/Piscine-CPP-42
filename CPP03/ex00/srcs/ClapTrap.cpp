#include "ClapTrap.hpp"

using	std::cout;
using	std::endl;

ClapTrap::ClapTrap(string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	cout << GREEN << "Summoned ClapTrap " << BOLD << _name << DEFAULT << endl;
}

ClapTrap::~ClapTrap() {
	cout << RED << "Destroyed ClapTrap " << BOLD << this->_name << DEFAULT << endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	cout << GREEN BOLD << "Summoned ClapTrap copy " << &copy << DEFAULT << endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "Assignement operator called" << std::endl;
	
	_name = copy._name;
	_hit_points = copy._hit_points;
	_energy_points = copy._energy_points;
	_attack_damage = copy._attack_damage;
	return (*this);
}

void ClapTrap::attack(const string& target) {
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		string s;
		_attack_damage == 1? s = "" : s = "s" ;
		cout << ORANGE << "ClapTrap " << GREEN << this->_name << ORANGE << " attacks " << MAGENTA << target << ORANGE << ", causing " << RED << _attack_damage << ORANGE <<" point" << s << " of damage!" << DEFAULT << endl;
		_energy_points--;
	}
	else if (this->_energy_points <= 0 && this->_hit_points > 0)
		cout << ORANGE << "ClapTrap " << GREEN << this->_name << ORANGE << " tried to attack but is too exhausted!" << DEFAULT << endl;
	else if (this->_hit_points <= 0)
		cout << ORANGE << "ClapTrap " << GREEN << this->_name << ORANGE << " tried to attack but is already dead!" << DEFAULT << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points > 0)
	{
		string s;
		amount == 1? s = "" : s = "s" ;
		cout << LIGHT_BLUE << "ClapTrap took " << RED << amount << LIGHT_BLUE << " point" << s << " of damage!" << DEFAULT << endl;
		this->_hit_points -= amount;
		if (this->_hit_points <= 0)
			cout << LIGHT_BLUE << "ClapTrap " << MAGENTA << this->_name << RED BOLD << " DIED!"  << DEFAULT << endl;
	}
	else
		cout << LIGHT_BLUE << "ClapTrap " << GREEN << this->_name << LIGHT_BLUE << " can't take damage, it's already dead!" << DEFAULT << endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_points > 0 && this->_hit_points > 0)
	{
		string s;
		amount == 1? s = "" : s = "s" ;
		cout << LIGHT_CYAN << "ClapTrap " << GREEN << this->_name << LIGHT_CYAN << " regained " << GREEN << amount << LIGHT_CYAN << " hit point" << s << "!" << DEFAULT << endl;
		this->_hit_points += amount;
		this->_energy_points--;
	}
	else if (this->_energy_points <= 0 && this->_hit_points > 0)
		cout << LIGHT_CYAN << "ClapTrap " << GREEN << this->_name << LIGHT_CYAN << " tried to regain hit points but is too exhausted!" << DEFAULT << endl;
	else if (this->_hit_points <= 0)
		cout << LIGHT_CYAN << "ClapTrap " << GREEN << this->_name << LIGHT_CYAN << " tried to regain hit points but is already dead!" << DEFAULT << endl;
}
