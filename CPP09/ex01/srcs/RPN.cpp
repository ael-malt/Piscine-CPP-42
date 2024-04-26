#include "RPN.hpp"

RPN::RPN(string input) {
	parseInput(input);
}

float	RPN::checkNumberSize(string::iterator inputIt) {
	for (inputIt i = 0; i < count; i++)
	{
		/* code */
	}
	
	return (0);
}

void RPN::parseInput(string input) {
	if (input.empty())
		throw(RPN::EmptyInput());
	if (input.find_first_not_of(NUMOP" ") != std::string::npos)
		throw(RPN::IncorrectInput());
	if (input.find_first_of(NUMBERS) == std::string::npos)
		throw(RPN::MissingNumbers());
	if (input.find_first_of(OPERATORS) == std::string::npos)
		throw(RPN::MissingOperators());
	
	cout << input << endl;
	
	string::iterator inputIt = input.begin();

	for (; inputIt != input.end(); inputIt++)
	{
		for (; *inputIt != ' '; inputIt++);
		
		checkNumberSize(inputIt);
		this->_inputStack.push(std::atof(*inputIt.c_str()));
	}
	cout << _inputStack.top() << endl;
	
}

RPN::~RPN() {
}