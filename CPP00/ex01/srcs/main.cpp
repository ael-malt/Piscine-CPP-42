#include <iostream>
#include <stdlib.h>
#include "../includes/PhoneBook.hpp"

using	std::cin;
using	std::cout;
using	std::endl;
using	std::getline;
int	main(void)
{
	PhoneBook	PhoneBook;
	string	line;

	PhoneBook.start_message();
	line = "start";
	while (line != "EXIT")
	{
		cout << "> ";
		getline(cin, line);
		PhoneBook.check_sin();
		if (line == "ADD")
			PhoneBook.add_contact();
		if (line == "SEARCH")
			PhoneBook.search_contact();
	}
}
