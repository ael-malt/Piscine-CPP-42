#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;
using	std::exception;

class Form
{
private:
	const string	_name;
	bool			_signed;
	const int		_signGrade;
	const int		_execGrade;
public:
	Form(string name, int grade);
	~Form();
	Form(const Form& copy);
	Form&	operator=(const Form& copy);

	string	getName(void) const;
	int		getSigned(void) const;
	int		getSignGrade(void) const;
	int		getExecGrade(void) const;


	class GradeTooHighException : public exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public exception
	{
	public:
		virtual const char* what() const throw();
	};
	
};

ostream&	operator<<(ostream&, const Bureaucrat&);

#endif
