#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

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

class RobotomyRequestForm : public AForm
{
private:
	string _target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& copy);

	void	execute(Bureaucrat const &bureaucrat) const;

};

// ostream&	operator<<(ostream&, const RobotomyRequestForm&);

#endif
