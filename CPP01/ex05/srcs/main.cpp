#include "../includes/Harl.hpp"

using	std::string;
using	std::cout;
using	std::endl;

int main(int argc, char const *argv[])
{
	(void) argv;
	if (argc > 1)
	{
		cout << RED <<"Error: Too many arguments! Try with:\n" << GREEN << "    ./Harl" << DEFAULT << endl;
		return (1);
	}
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INVALID");
	return 0;
}
