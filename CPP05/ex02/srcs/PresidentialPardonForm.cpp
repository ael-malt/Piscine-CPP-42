#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm(target, 25, 5), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy._target, 25, 5), _target(copy._target){
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
	cout << GREEN BOLD << this->_target << DEFAULT GREEN " has been pardoned by Zaphod Beeblebrox" DEFAULT << endl;
}
