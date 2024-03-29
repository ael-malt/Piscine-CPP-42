#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"
# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;
using	std::exception;

class Bureaucrat;
class AForm
{
private:
	const string	_name;
	bool			_signed;
	const int		_signGrade;
	const int		_execGrade;
public:
	AForm();
	AForm(string name, const int signGrade, const int execGrade);
	virtual ~AForm();
	AForm(const AForm& copy);
	AForm&	operator=(const AForm& copy);

	string	getName(void) const;
	bool		getSigned(void) const;
	int		getSignGrade(void) const;
	int		getExecGrade(void) const;
	void	beSigned(Bureaucrat const &bureaucrat);
	virtual void	beExecuted(Bureaucrat const &bureaucrat);


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

ostream&	operator<<(ostream&, const AForm&);

#endif
