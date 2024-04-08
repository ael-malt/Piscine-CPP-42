#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("", 137, 145), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm(target, 137, 145), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy._target, 137, 145), _target(copy._target){
	*this = copy;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	this->_target = copy._target;
	return (*this);
}

void	PresidentialPardonForm::beExecuted(Bureaucrat const &bureaucrat) const {
	if (!this->getSigned())
		throw(PresidentialPardonForm::FormNotSigned());
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw(PresidentialPardonForm::GradeTooLowException());
	ofstream shrubberryFile((this->_target + "_shrubbery").c_str());
}

