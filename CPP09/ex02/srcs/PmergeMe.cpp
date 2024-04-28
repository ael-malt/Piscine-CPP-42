#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char const **argv) {
	ParseArgv(argc, argv);
}
void PmergeMe::ParseArgv(int argc, char const **argv) {
	string expectedChars("0123456789");
	for (int i = 0; i < argc; i++)
	{
		if((string(argv[i])).find_first_of(expectedChars) == string::npos)
			throw(PmergeMe::UnexpectedArg(string(argv[i])));
	}
	
}
PmergeMe::~PmergeMe() {
}
