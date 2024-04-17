#include "Intern.hpp"

const char* Intern::FormNotFound::what() const throw() {
	return(RED "Error: Form doesn't exist!" DEFAULT);
}

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& copy){
	*this = copy;
}

Intern&	Intern::operator=(const Intern& copy) {
	(void) copy;
	return (*this);
}

AForm* Intern::makeForm(string formName, string target) {
	string formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	size_t i = 0;
	while(i < 3)
	{
		if (formName == formNames[i])
			break;
		i++;
	}
	switch (i)
	{
	case (0):
		return (new PresidentialPardonForm(target));
	case (1):
		return (new RobotomyRequestForm(target));
	case (2):
		return (new ShrubberyCreationForm(target));
	default:
		throw (Intern::FormNotFound());
	}
}
