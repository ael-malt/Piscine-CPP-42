#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "Colors.hpp"
# include <iostream>

using std::string;
class ClapTrap
{
private:
	string	_name;
	int		_hit_points;
	int		_energy_points;
	int		_attack_damage;
public:
	ClapTrap(string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &copy); // copy constructor
	ClapTrap &operator=(const ClapTrap& copy); // copy assignment constructor

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif // MACRO
