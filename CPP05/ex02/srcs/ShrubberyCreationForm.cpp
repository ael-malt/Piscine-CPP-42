#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("", 137, 145), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm(target, 137, 145), _target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy._target, 137, 145), _target(copy._target){
	*this = copy;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	this->_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::beExecuted(Bureaucrat const &bureaucrat) {
	if (this->getSignGrade() < this->getExecGrade())
		cout << BOLD BROWN << this->_target << DEFAULT RED << " couldn't execute " << MAGENTA << this->getName() << RED " because: " BOLD "grade too low!" DEFAULT << endl;
	if (this->getSignGrade() >= this->getExecGrade() && !this->getSigned())
		cout << BOLD BROWN << this->_target << DEFAULT RED << " couldn't execute " << MAGENTA << this->getName() << RED " because: " BOLD "form is not signed!" DEFAULT << endl;
}
