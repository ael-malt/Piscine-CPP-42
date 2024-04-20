#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) { (void) rhs; return (*this); }

void ScalarConverter::convert(string input) {
string pseudoLiterals[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	int		_int;
	float	_float;

	if (input.size() == 1 && std::isalpha(input[0]) && std::isprint(input[0])){
		cout << "char: " << "\'" << static_cast<char>(input[0]) << "\'" << endl;
		cout << "int: " << static_cast<int>(input[0]) << endl;
		cout << "float: " << static_cast<float>(input[0]) << endl;
		cout << "double: " << static_cast<double>(input[0]) << endl;
		return ;
	}

	_float = std::atof(input.c_str());
	_int = std::atoi(input.c_str());

	for (int i = 0; i < 6; i++)
		if (!input.compare(pseudoLiterals[i])){
			cout << "char: impossible" << endl;
			cout << "int: impossible" << endl;
				if (i <= 2)
				cout << "float: " << pseudoLiterals[i] << 'f' << endl;
			else 
				cout << "float: " << pseudoLiterals[i] << endl;
			cout << "double: " << pseudoLiterals[i] << endl;
			return ;
		}

	if ((_int > 127 || _int < 0) && !std::isprint(_int))
		cout << "char: impossible" << endl;
	else if (!std::isprint(_int))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << "\'" << static_cast<char>(_int) << "\'" << endl;

	cout << "int: " <<  static_cast<int>(_int) << endl;
	if (_float - static_cast<int>(_float) == 0)
		cout << "float: " << static_cast<float>(_float) << ".0" << "f" << endl;
	else
		cout << "float: " << static_cast<float>(_float) << "f" << endl;
	if (_float - static_cast<int>(_float) == 0)
		cout << "double: " << static_cast<float>(_float) << ".0" << endl;
	else
		cout << "double: " << static_cast<float>(_float) << endl;
}
