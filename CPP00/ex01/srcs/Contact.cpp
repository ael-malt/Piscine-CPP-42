#include "../includes/Contact.hpp"

using	std::cout;
using	std::endl;
using	std::setw;
using	std::right;

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}
Contact::~Contact()
{
}

void	Contact::set_first_name(string new_first_name)
{
	this->first_name = new_first_name;
}

void	Contact::set_last_name(string new_last_name)
{
	this->last_name = new_last_name;
}

void	Contact::set_nickname(string new_nickname)
{
	this->nickname = new_nickname;
}

void	Contact::set_phone_number(string new_phone_number)
{
	this->phone_number = new_phone_number;
}

void	Contact::set_darkest_secret(string new_darkest_secret)
{
	this->darkest_secret = new_darkest_secret;
}

string	Contact::truncate_string(string str)
{
	string	new_str;

	if (str.size() > 10)
	{
		new_str = str.substr(0, 9);
		new_str += ".";
		return (new_str);
	}
	return (str);
}

bool	Contact::check_contact(void)
{
	if (this->first_name.empty() || this->last_name.empty() || this->nickname.empty() || this->phone_number.empty() || this->darkest_secret.empty() )
		return (0);
	return (1);
}
void	Contact::get_contact(int index){
	if (!check_contact())
		return ;
	cout << "|" << setw(10) << right << truncate_string(this->first_name);
	cout << "|" << setw(10) << right << truncate_string(this->last_name);
	cout << "|" << setw(10) << right << truncate_string(this->nickname) << "|" << endl;
	if(index != 7)
		cout << "├──────────┼──────────┼──────────┼──────────┤" << endl;
	else 
		cout << "└──────────┴──────────┴──────────┴──────────┘" << endl;

}


void	Contact::print_contact(void)
{
	if (!check_contact())
	{
		cout << "This contact does not exist!" << endl;
		return ;
	}
	cout << "First Name: " << this->first_name << endl;
	cout << "LastName: " << this->last_name << endl;
	cout << "NickName: " << this->nickname << endl;
	cout << "PhoneNumber: " << this->phone_number << endl;
	cout << "DarkestSecret: " << this->darkest_secret << endl;
}

