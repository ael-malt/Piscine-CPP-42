#include "RPN.hpp"

RPN::RPN(string input) : _NUMBERS("0123456789."), _OPERATORS("+-/*"), _NUMOP("0123456789.+-/*") {
	parseInput(input);
}

// void RPN::pushTmpToInputStack(void) {
// 	while (!this->_inputStack.empty())
// 	{
// 		this->_inputStack.push(this->_inputStack.top());
// 		this->_inputStack.pop();
// 	}
// }
float RPN::operate(float nb1, float nb2, char op) {
	if (op == '+')
		return (nb2 + nb1);
	else if (op == '-')
		return (nb2 - nb1);
	else if (op == '*')
		return (nb2 * nb1);
	else if (op == '/')
		return (nb2 / nb1);
	else
		throw (RPN::BadOperator());
}

void	RPN::calculateStack(char op) {
	if (this->_inputStack.size() == 2)
	{
		float	nb1 = this->_inputStack.top();
		this->_inputStack.pop();
		float	nb2 = this->_inputStack.top();
		this->_inputStack.pop();
		float result = operate(nb1, nb2, op);
		this->_inputStack.push(result);
	}
}

void RPN::addNumberToStack(string::iterator inputIt, unsigned int numberSize) {
	string	numberString = string(inputIt, inputIt + numberSize);
	float		number = atof(numberString.c_str());
	if (number > 10)
		throw(RPN::NumberTooBig(number));
	this->_inputStack.push(number);
	// cout << number << endl;
}

// Check the size of the current member and return it
unsigned int	RPN::checkNumberSize(string::iterator inputIt) {
	unsigned int numberSize = 0;
	unsigned int dotCount = 0;
	string inputCpy = &(*inputIt);
	string ::iterator inputItCpy(inputCpy.begin());

	if (*inputItCpy == '.')
		throw(RPN::DotAtBeginningOfNumber());
	for (; inputItCpy != inputCpy.end() && *inputItCpy != ' '; inputItCpy++)
	{
		if (*inputItCpy == '.')
			dotCount++;
		if (this->_NUMBERS.find_first_of(*inputItCpy) == std::string::npos && inputItCpy != inputCpy.end() && *inputItCpy != ' ')
			throw(RPN::UnexpectedChar(*inputItCpy));
		numberSize++;
	}
	if (dotCount > 1)
		throw(RPN::TooManyDots());
	if (*inputItCpy == '.')
		throw(NumberEndsWithDot());
	return (numberSize);
}

// Count the amout of numbers and operators in the input
void RPN::countNumOPs(string input) {
	string::iterator inputIt = input.begin();
	int amountNb = 0;
	int amountOp = 0;
	unsigned int numberSize = 0;

	int argPos = 0;
	int lastArg = 0;
	while (inputIt != input.end())
	{
		// Skip spaces
		if (*inputIt == ' ')
			inputIt++;
		else if (this->_NUMBERS.find_first_of(*inputIt) != std::string::npos)
		{
			// Check order in respect of the last arg
			if ( argPos > 1 && lastArg == 'n')
				throw (RPN::ConsecutiveNumbers());
			// Check Number length, add it to the stack
			numberSize = checkNumberSize(inputIt);
			addNumberToStack(inputIt, numberSize);
			// Skip to the end of the number
			std::advance(inputIt, numberSize);
			amountNb++;
			argPos++;
			lastArg = 'n';
		}
		else if (this->_OPERATORS.find_first_of(*inputIt) != std::string::npos)
		{
			// Check order in respect of the last arg
			if ((argPos == 0 || argPos == 1))
				throw (RPN::OperatorsAtBeginning());
			if ( argPos > 1 && lastArg == 'o')
				throw (RPN::ConsecutiveOperators());
			calculateStack(*inputIt);
			amountOp++;
			inputIt++;
			argPos++;
			lastArg = 'o';
			// Check if nothing except a space is next to the operator
			if (inputIt != input.end() && *inputIt != ' ')
				throw(RPN::UnexpectedChar(*inputIt));
			// Apply operator to the two numbers in the stack
		}
	}
	if (amountNb < 2)
		throw(RPN::NotEnoughNumbers());
	if (amountNb > amountOp + 1)
		throw(RPN::TooManyNumbers());
	else if (amountNb < amountOp + 1)
		throw(RPN::TooManyOperators());
	
}
void RPN::parseInput(string input) {
	if (input.empty())
		throw(RPN::EmptyInput());
	if (input.find_first_not_of(this->_NUMOP + " ") != std::string::npos)
		throw(RPN::IncorrectInput());
	if (input.find_first_of(this->_NUMBERS) == std::string::npos)
		throw(RPN::MissingNumbers());
	if (input.find_first_of(this->_OPERATORS) == std::string::npos)
		throw(RPN::MissingOperators());
	
	// Check if amount of number and operators correspond and if their order is correct while adding everything to the stack
	countNumOPs(input);
	cout << this->_inputStack.top() << endl;
}

RPN::~RPN() {
}