#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <stdlib.h>
using std::string;
class Contact
{
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;

	public:
		Contact();
		~Contact();
		void	set_first_name(string new_first_name);
		void	set_last_name(string new_last_name);
		void	set_nickname(string new_nickname);
		void	set_phone_number(string new_phone_number);
		void	set_darkest_secret(string new_darkest_secret);
		void	get_contact(int index);
		bool	check_contact(void);
		void	print_contact(void);
		string	truncate_string(string str);
};

#endif
