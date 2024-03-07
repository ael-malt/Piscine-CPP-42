#include "../includes/Colors.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void)
{
	string	brain = "HI THIS IS BRAIN";
	string	*stringPTR = &brain;
	string	&stringREF = brain;

	cout << GREEN << "Memory address: " << DEFAULT << endl;
	cout << RED << "String: " << DEFAULT << &brain << endl;
	cout << RED << "StringPTR: " << DEFAULT << stringPTR << endl;
	cout << RED << "StringREF: " << DEFAULT << &stringREF << endl;

	cout << GREEN << "Value: " << DEFAULT << endl;
	cout << RED << "String: " << DEFAULT << brain << endl;
	cout << RED << "StringPTR: " << DEFAULT << *stringPTR << endl;
	cout << RED << "StringREF: " << DEFAULT << stringREF << endl;
}
