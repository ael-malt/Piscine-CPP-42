#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"
# include "Colors.hpp"
# include "AForm.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;
using	std::exception;

class ShrubberyCreationForm : public AForm
{
private:
	string _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(string name);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);

	void	beExecuted(Bureaucrat const &bureaucrat);

};



#endif
