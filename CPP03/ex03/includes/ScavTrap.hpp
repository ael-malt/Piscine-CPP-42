#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "Colors.hpp"
# include "ClapTrap.hpp"

# include <iostream>

using std::string;
class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &copy); // copy constructor
	ScavTrap &operator=(const ScavTrap& copy); // copy assignment constructor

	void	guardGate();
};

#endif // MACRO
