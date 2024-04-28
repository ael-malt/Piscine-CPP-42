#include "PmergeMe.hpp"

int main(int argc, char const **argv)
{
	try
	{
		if (argc < 2)
			throw (PmergeMe::MissingArguments());
		argc--;
		(*argv)++;
		PmergeMe start(argc, argv);
	}
	catch(const exception& e)
	{
		std::cerr << e.what() << endl;
	}
	
	return 0;
}
