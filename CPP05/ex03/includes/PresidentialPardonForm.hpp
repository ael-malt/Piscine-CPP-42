#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

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
using	std::ofstream;
using	std::exception;

class PresidentialPardonForm : public AForm
{
private:
	string _target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& copy);

	void	execute(Bureaucrat const &bureaucrat) const;
};

// ostream&	operator<<(ostream&, const PresidentialPardonForm&);

#endif
