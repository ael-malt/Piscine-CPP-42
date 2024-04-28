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
	// stack<float> _tmpStack;
	stack<float> _inputStack;
	const string _NUMBERS;
	const string _OPERATORS;
	const string _NUMOP;
public:
	RPN(string input);
	~RPN();

	void			parseInput(string input);
	void			countNumOPs(string input);
	unsigned int	checkNumberSize(string::iterator inputIt);
	void			addNumberToStack(string::iterator inputIt, unsigned int NumberSize);
	void			calculateStack(char op);
	float operate(float nb1, float nb2, char op);


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
		public: virtual const char* what() const throw() { return (RED "Error: Incorrect input, only these charachters are allowed: " MAGENTA "0123456789.+-/" DEFAULT); }
	};
	class MissingNumbers : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Incorrect input, no numbers were found" DEFAULT); }
	};
	class MissingOperators : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Incorrect input, no operators were found" DEFAULT); }
	};
	class UnexpectedChar : public exception
	{
		private:
			string _msg;
			string _unexpectedStr;
		public: 
			virtual ~UnexpectedChar() throw() {}
			UnexpectedChar(char unexpected)
			{
				_unexpectedStr = unexpected;
				_msg = RED "Error: unexpected Character found in input instead of a space: " MAGENTA "'" + this->_unexpectedStr + "'" DEFAULT;
			}
			const char* what() const throw() { return (_msg.c_str()); }

	};
	class NumberTooBig : public exception
	{
		private: string _msg;
		public: 
			virtual ~NumberTooBig() throw() {}
			NumberTooBig(float number) {
				std::ostringstream convert;
				convert << number;
				string nbStr = convert.str();
				this->_msg = RED "Error: Number too Big: " MAGENTA "'" + nbStr + "'" DEFAULT;
			}
			const char* what() const throw() { return (_msg.c_str()); }

	};
	class DotAtBeginningOfNumber : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Cannot have a dot '.' at the beginning of a number" DEFAULT); }
	};
	class TooManyDots : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Too many dots '.' in a number" DEFAULT); }
	};
	class NumberEndsWithDot : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: A number cannot end with a dot '.'" DEFAULT); }
	};
	class NotEnoughNumbers : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Not enough numbers in input\n	Need at least 2 numbers" DEFAULT); }
	};
	class TooManyNumbers : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Too many numbers in input" DEFAULT); }
	};
	class TooManyOperators : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Too many operators in input" DEFAULT); }
	};
	class ConsecutiveNumbers : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Consecutive numbers found after first two positions" DEFAULT); }
	};
	class ConsecutiveOperators : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Consecutive operators found after first two positions" DEFAULT); }
	};
	class OperatorsAtBeginning : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Found Operator in one of the first two positions" DEFAULT); }
	};
	class BadOperator : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Found Bad Operator" DEFAULT); }
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