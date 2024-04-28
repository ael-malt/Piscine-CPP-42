#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "Colors.hpp"

# include <iostream>
# include <fstream>
# include <exception>
# include <stack>
# include <algorithm>
# include <limits.h>
# include <sstream>

// #include 


using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;
using std::ifstream;
using std::stack;

class PmergeMe
{
private:
	/* data */
public:
	PmergeMe(int argc, char const **argv);
	~PmergeMe();
	
	void ParseArgv(int argc, char const **argv);

	class MissingArguments : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Missing argument\n	Try with: ./PmergeMe <Any amount of numbers." DEFAULT); }
	};
	class UnexpectedArg : public exception
	{
		private: string _msg;
		public: 
			virtual ~UnexpectedArg() throw() {}
			UnexpectedArg(string arg) : _msg(RED "Error: Unexpected argument: " MAGENTA "'" + arg + "'" + RED + "\n	Only positive numbers are allowed (no +/- signs)" DEFAULT) {}
			const char* what() const throw() { return (_msg.c_str()); }

	};
};


#endif