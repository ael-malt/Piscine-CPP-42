#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/Colors.hpp"
using	std::cin;
using	std::cout;
using	std::endl;
using	std::getline;
using	std::string;
using	std::setw;
using	std::right;

PhoneBook::PhoneBook()
{
	this->index	= 0;
	Contact	Contacts[8];
}

PhoneBook::~PhoneBook()
{
}
void	PhoneBook::start_message(void)
{
	cout << BOLD GREEN << "Welcome to My Awesome PhoneBook!" << DEFAULT << endl << endl;
	cout << MAGENTA "Type " BOLD "ADD" DEFAULT MAGENTA " to add a new contact" DEFAULT << endl;
	cout << "Type " BOLD "SEARCH" DEFAULT " to search for a contact" << endl;
	cout << RED "Type " BOLD "EXIT" DEFAULT RED " to exit the program" DEFAULT << endl;
}

void	PhoneBook::check_sin(void)
{
	if (!cin)
	{
		cout << endl;
		cout << "Ctrl + D detected, exiting" << endl;
		exit(EXIT_FAILURE);
	}
}

static bool	IsEmpty(string str)
{
	if (str.empty() || str.find_first_not_of (" \t\n\v\f\r") == str.npos)
		return (1);
	else
		return (0);
}

void	PhoneBook::add_contact(void)
{
	string line;

	// Set First Name
	cout << "Starting the creation of contact number " << index << endl;
	while (IsEmpty(line))
	{
		cout << "Enter new Contact First Name -> ";
		getline(cin, line);
		PhoneBook::check_sin();
	}
	this->Contacts[index].set_first_name(line);
	line.clear();
	// Set Last Name
	while (IsEmpty(line))
	{
		cout << "Enter new Contact Last Name-> ";
		getline(cin, line);
		PhoneBook::check_sin();
	}
	this->Contacts[index].set_last_name(line);
	line.clear();

	// Set NickName
	while (IsEmpty(line))
	{
		cout << "Enter new Contact NickName-> ";
		getline(cin, line);
		PhoneBook::check_sin();
	}
	this->Contacts[index].set_nickname(line);
	line.clear();

	// Set Phone Number
	while (IsEmpty(line))
	{
		cout << "Enter new Contact Phone Number-> ";
		getline(cin, line);
		PhoneBook::check_sin();
	}
	this->Contacts[index].set_phone_number(line);
	line.clear();

	// Set Darkest Secret
	while (IsEmpty(line))
	{
		cout << "Enter new Contact Darkest Secret-> ";
		getline(cin, line);
		PhoneBook::check_sin();
	}
	this->Contacts[index].set_darkest_secret(line);

	if (index < 7)
		index++;
	else
		index = 0;
}

static bool	IsInBounds(int nb)
{
	if (nb >= 0 && nb <= 7)
		return (1);
	return (0);
}

static bool	IsDigit(string Str)
{
	for (size_t i = 0; Str[i]; i++)
		if (!(Str[i] >= '0' && Str[i] <= '9'))
			return (0);
	return (1);
	
}

void	PhoneBook::search_contact(void)
{
	string line;
	cout << "┌──────────┬──────────┬──────────┬──────────┐" << endl;
	cout << "│" << BOLD BLUE << setw(10) << right << "Index" << DEFAULT;
	cout << "│" << BOLD BLUE << setw(10) << right << "First Name" << DEFAULT;
	cout << "│" << BOLD BLUE << setw(10) << right << "Last Name" << DEFAULT;
	cout << "│" << BOLD BLUE << setw(10) << right << "Nickname" << DEFAULT << "│" << endl;
	if(this->Contacts[0].check_contact())
		cout << "├──────────┼──────────┼──────────┼──────────┤" << endl;
	else
		cout << "└──────────┴──────────┴──────────┴──────────┘" << endl;
	for (size_t i = 0; i <= 7 && this->Contacts[i].check_contact(); i++)
	{
		cout << "|" BOLD BLUE << setw(10) << right << i << DEFAULT ;
		if (this->Contacts[0].check_contact())
			this->Contacts[i].get_contact(i);
	}
	if (!this->Contacts[0].check_contact())
		return ;
	while (42)
	{
		cout << "Enter the Contact Name you want to search->";
		getline(cin, line);
		PhoneBook::check_sin();
		if (!IsDigit(line))
			cout << "Try with a number!" << endl;
		else if (IsDigit(line) && !IsInBounds(atoi(line.c_str())))
			cout << "Try with a number between 0 and 7" << endl;
		else if (!line.empty() && IsDigit(line) && IsInBounds(atoi(line.c_str())))
		{
			this->Contacts[atoi(line.c_str())].print_contact();
			return ;
		}
	}
}
