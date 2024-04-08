#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm(target, 72, 45), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy._target, 72, 45), _target(copy._target){
	*this = copy;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	this->_target = copy._target;
	return (*this);
}

void	RobotomyRequestForm::beExecuted(Bureaucrat const &bureaucrat) const {
	if (!this->getSigned())
		throw(RobotomyRequestForm::FormNotSigned());
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw(RobotomyRequestForm::GradeTooLowException());
	cout << RED BOLD "**DRILLING NOISES**" DEFAULT << endl;
	srand((unsigned) time(NULL));
	int nb = rand() % 2;
	cout << nb << endl;
	if (nb)
		cout << RED BOLD << this->_target << DEFAULT RED " has been successfully robotimized!" DEFAULT << endl;
	else
		cout << RED BOLD << this->_target << DEFAULT RED " failed to be robotomized!" DEFAULT << endl;
}
