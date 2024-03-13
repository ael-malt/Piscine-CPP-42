#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "Colors.hpp"
# include "ClapTrap.hpp"

# include <iostream>

using std::string;
class FragTrap : public ClapTrap
{
public:
	FragTrap(string name);
	~FragTrap(void);
	FragTrap(const FragTrap &copy); // copy constructor
	FragTrap &operator=(const FragTrap& copy); // copy assignment constructor

	void highFivesGuys(void);
};

#endif // MACRO
