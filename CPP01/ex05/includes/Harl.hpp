#include <iostream>

#include "../includes/Colors.hpp"

using	std::string;

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void (Harl::*functions[4])();
public:
	Harl(void);
	~Harl();
	void complain( std::string level );
};

