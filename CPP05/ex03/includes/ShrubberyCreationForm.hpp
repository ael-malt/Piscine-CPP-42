#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <exception>
# include <fstream>

# include "Bureaucrat.hpp"
# include "Colors.hpp"
# include "AForm.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;
using	std::ofstream;
using	std::exception;

class ShrubberyCreationForm : public AForm
{
private:
	string _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);

	void	execute(Bureaucrat const &bureaucrat) const;

};

// ostream&	operator<<(ostream&, const ShrubberyCreationForm&);

#endif
