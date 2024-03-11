#include "../includes/HarlFilter.hpp"

using	std::string;
using	std::cout;
using	std::endl;

HarlFilter::HarlFilter(void)
{
	functions[0] = &HarlFilter::debug;
	functions[1] = &HarlFilter::info;
	functions[2] = &HarlFilter::warning;
	functions[3] = &HarlFilter::error;
}

HarlFilter::~HarlFilter()
{
}

void HarlFilter::debug(void)
{
	cout << GREEN << "[DEBUG]" << DEFAULT << endl;
	cout << GREEN << "I can't resist their 'Galactic Espresso Explosion' with a swirl of caramel and a sprinkle of stardust. It's out of this world!" << DEFAULT << endl;
	cout << endl;
}

void HarlFilter::info(void)
{
	cout << YELLOW << "[INFO]" << DEFAULT << endl;
	cout << YELLOW << "I'm not sure if it's just me, but sometimes I feel like the barista is giving me a weird look when I order my 'Cosmic Cinnamon Cloud Latte'. Maybe it's just my imagination." << DEFAULT << endl;
	cout << endl;
}

void HarlFilter::warning(void)
{
	cout << ORANGE << "[WARNING]" << DEFAULT << endl;
	cout << ORANGE << "Listen, I've been coming here for ages, and I've never had a problem with my 'Supernova Mocha'. But today, it seems a little off. I hope this isn't becoming a trend." << DEFAULT << endl;
	cout << endl;
}

void HarlFilter::error(void)
{
	cout << RED BOLD << "[ERROR]" << DEFAULT << endl;
	cout << RED BOLD << "Excuse me, but I specifically asked for my 'Interstellar Macchiato' to be extra hot. This is lukewarm at best. I need this fixed, pronto." << DEFAULT << endl;
	cout << endl;
}

void HarlFilter::complain( string level )
{
	string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			break ;
		i++;
	}

	switch (i)
	{
	case (0):
		debug();
		info();
		warning();
		error();
		break;
	case (1):
		info();
		warning();
		error();
		break;
	case (2):
		warning();
		error();
		break;
	case (3):
		error();
		break;
	default:
		cout << RED << "Error: Invalid level!" << DEFAULT << endl;
		break;
	}
}
