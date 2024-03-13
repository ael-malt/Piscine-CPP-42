#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "Colors.hpp"
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# include <iostream>

using std::string;
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	string	name;
public:
	DiamondTrap(string name);
	~DiamondTrap(void);
	
	using ScavTrap::attack;
	void	whoAmI();
};

#endif // MACRO
