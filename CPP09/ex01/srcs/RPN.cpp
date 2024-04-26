#include "RPN.hpp"

RPN::RPN(string input) {
	parseInput(input);
}

float	RPN::checkNumberSize(string::iterator inputIt) {
	//Check the size of the current member and return it
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
	
	// Check if amount of number and operators correspond

	// Check if their order is correct ex: 
	// 1 1 + 2 - 3 - 1 is correct.
	// 1 + 1 + 2 - 3 - 1 is NOT correct.

	string::iterator inputIt = input.begin();

	for (; inputIt != input.end(); inputIt++)
	{
		for (; *inputIt != ' '; inputIt++);
		// Check if current pos is a nb or an op

		// If its a number get it's size
		checkNumberSize(inputIt);
		// After checking the size get the number from inputIt to nbSize

		//If it's an operator add it to the stack

		// Push number or operator to the stack
		// this->_inputStack.push(std::atof(*inputIt.c_str()));
	}
	cout << _inputStack.top() << endl;
	
}

RPN::~RPN() {
}