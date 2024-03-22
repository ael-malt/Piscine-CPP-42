#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

class Bureaucrat
{
private:
	const string	name;
	int				grade;
public:
	Bureaucrat(void);
	~Bureaucrat();

	string	getName(void);
	int		getGrade(void);
};

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::~Bureaucrat()
{
}

#endif
