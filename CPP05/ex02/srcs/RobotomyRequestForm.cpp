#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("", 137, 145), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm(target, 137, 145), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy._target, 137, 145), _target(copy._target){
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
	ofstream shrubberryFile((this->_target + "_shrubbery").c_str());
}

