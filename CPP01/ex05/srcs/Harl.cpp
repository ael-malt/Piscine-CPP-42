#include "../includes/Harl.hpp"

using	std::string;
using	std::cout;
using	std::endl;

Harl::Harl(void)
{
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	cout << GREEN << "There's nothing quite like diving into a bowl of their 'Tropical Temptation Tango', a fusion of mango, coconut, and pineapple that sends my taste buds on a Caribbean vacation." << DEFAULT << endl;
}

void Harl::info(void)
{
	cout << YELLOW << "I've noticed something peculiar about their 'Mystical Mint Medley'. Sometimes it has a refreshing kick, but other times it's milder. I wonder if it depends on the batch?" << DEFAULT << endl;
}

void Harl::warning(void)
{
	cout << ORANGE << "Hey, I've been coming here faithfully, but lately, I've noticed the portion sizes of my 'Exotic Euphoria Explosion' are shrinking. I hope this isn't a trend, or I might have to explore other options." << DEFAULT << endl;
}

void Harl::error(void)
{
	cout << RED BOLD << "This is not what I ordered at all! I asked for their 'Safari Sunset Surprise', but instead, I got a scoop of plain vanilla. This mistake is intolerable, and I demand it to be rectified immediately!" << DEFAULT << endl;
}

void Harl::complain( string level )
{
	string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	cout << RED << "Error: Invalid level!" << DEFAULT << endl;
	
}
