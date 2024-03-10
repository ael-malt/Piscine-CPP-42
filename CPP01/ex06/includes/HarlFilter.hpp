#include <iostream>

#include "../includes/Colors.hpp"

using	std::string;

class HarlFilter
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void (HarlFilter::*functions[4])();
public:
	HarlFilter(void);
	~HarlFilter();
	void complain( std::string level );
};

