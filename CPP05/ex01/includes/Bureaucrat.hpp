#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# include "Colors.hpp"
# include "Form.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;
using	std::exception;

class Form;

class Bureaucrat
{
private:
	const string	_name;
	int				_grade;
public:
	Bureaucrat(string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat&	operator=(const Bureaucrat& copy);

	string	getName(void) const;
	int		getGrade(void) const;

	void	increaseGrade();
	void	decreaseGrade();
	void	signForm(Form &form);
	
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
