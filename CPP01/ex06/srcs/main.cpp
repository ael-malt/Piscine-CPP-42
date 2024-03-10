#include "../includes/HarlFilter.hpp"

using	std::string;
using	std::cout;
using	std::endl;

int main(int argc, char const *argv[])
{
	(void) argv;
	if (argc > 2)
	{
		cout << RED <<"Error: Too many arguments! Try with:\n" << GREEN << "    ./harlFilter <DEBUG/INFO/WARNING/ERROR>" << DEFAULT << endl;
		return (1);
	}
	else if (argc < 2)
	{
		cout << RED <<"Error: Too few arguments! Try with:\n" << GREEN << "    ./harlFilter <DEBUG/INFO/WARNING/ERROR>" << DEFAULT << endl;
		return (1);
	}
	HarlFilter harl;
	harl.complain(string(argv[1]));
	return 0;
}
