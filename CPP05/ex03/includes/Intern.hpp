#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>

# include "Colors.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;
using	std::exception;

class AForm;

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern& copy);
	Intern&	operator=(const Intern& copy);

	AForm* makeForm(string formName, string target);

	class 
	FormNotFound : public exception
	{
	public:
		virtual const char* what() const throw();
	};
	
};

#endif
