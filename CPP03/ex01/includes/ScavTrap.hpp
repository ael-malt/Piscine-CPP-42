#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "Colors.hpp"
# include "ClapTrap.hpp"

# include <iostream>

using std::string;
class ScavTrap : public ClapTrap
{
public:
	ScavTrap(string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &copy); // copy constructor
	ScavTrap &operator=(const ScavTrap& copy); // copy assignment constructor

	void	guardGate();
};

#endif // MACRO
