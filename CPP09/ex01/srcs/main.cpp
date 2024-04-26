#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	try
	{
		if (argc < 2)
			throw (RPN::MissingArgument());
		if (argc > 2)
			throw (RPN::TooManyArguments());
		RPN start((string(argv[1])));
	}
	catch(const exception& e)
	{
		std::cerr << e.what() << endl;
	}
	
	return 0;
}
