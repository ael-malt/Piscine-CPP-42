#ifndef RPN_HPP
# define RPN_HPP

# include "Colors.hpp"

# include <iostream>
# include <fstream>
# include <exception>
# include <stack>
# include <algorithm>
# include <limits.h>
# include <sstream>
// #include 

#define NUMBERS "0123456789"
#define OPERATORS "+-/"
#define NUMOP "0123456789+-/"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;
using std::ifstream;
using std::stack;

class RPN
{
private:
	stack<float> _inputStack;
public:
	RPN(string input);
	~RPN();

	void	parseInput(string input);
	float	checkNumberSize(string::iterator inputIt);
	class MissingArgument : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Missing argument\n	Try with: ./RPN \"1 + 1\"" DEFAULT); }
	};
	class TooManyArguments : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Too many arguments\n	Try with: ./RPN \"1 + 1\"" DEFAULT); }
	};
	class EmptyInput : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Input is empty" DEFAULT); }
	};
	class IncorrectInput : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Incorrect input, only these charachters are allowed: " MAGENTA "0123456789+-/" DEFAULT); }
	};
	class MissingNumbers : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Incorrect input, no numbers were found" DEFAULT); }
	};
	class MissingOperators : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Incorrect input, no operators were found" DEFAULT); }
	};
};

class BitcoinExchange
{
	class FileBadValue : public exception
	{
		private: string _msg;
		public: 
			virtual ~FileBadValue() throw() {}
			FileBadValue(string file) : _msg(RED "Error: Wrong value found in file: " MAGENTA + file + DEFAULT) {}
			const char* what() const throw() { return (_msg.c_str()); }
	};

	class FileImpossibleDate : public exception
	{
		private: string _msg;
		public: 
			virtual ~FileImpossibleDate() throw() {}
			FileImpossibleDate(string file, string date) : _msg(RED "Error: Impossible Date found in file: " MAGENTA + file + RED + " => " + ORANGE + date + DEFAULT) {}
			const char* what() const throw() { return (_msg.c_str()); }

	};

	class CompFunctor{
	private:
		long int	_target;
	public:
		CompFunctor(unsigned int target): _target(target){}
		bool operator()(long int A, long int B) const{ return std::abs(A - _target) < std::abs(B - _target);}
	};
};



#endif