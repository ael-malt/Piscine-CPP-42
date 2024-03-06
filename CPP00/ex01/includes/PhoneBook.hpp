#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include "Contact.hpp"
class PhoneBook
{
	private:
		Contact Contacts[8];
		int	index;
	public:

		PhoneBook();
		~PhoneBook();
		void	start_message(void);
		void	check_sin(void);
		void	add_contact(void);
		void	search_contact(void);
};
#endif
