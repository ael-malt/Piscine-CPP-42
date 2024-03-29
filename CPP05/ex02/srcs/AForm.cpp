#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return(RED "Error:	The Grade is too High!" DEFAULT);
}

const char* AForm::GradeTooLowException::what() const throw() {
	return(RED "Error:	The Grade is too Low!" DEFAULT);
}

AForm::AForm() : _name(""), _signed(false), _signGrade(0), _execGrade(0) {}

AForm::AForm(string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if(signGrade < 1 || execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm() {}

AForm::AForm(const AForm& copy): _name(copy._name), _signed(false), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
	*this = copy;
}

AForm&	AForm::operator=(const AForm& copy) {
	const_cast<string&>(this->_name) = copy._name;
	this->_signed = copy._signed;
	const_cast<int&>(this->_signGrade) = copy._signGrade;
	const_cast<int&>(this->_execGrade) = copy._execGrade;
	return (*this);
}

string	AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getSigned(void) const {
	return (this->_signed);
}

int		AForm::getSignGrade(void) const {
	return (this->_signGrade);
}

int		AForm::getExecGrade(void) const {
	return (this->_execGrade);
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	else if (bureaucrat.getGrade() <= this->_signGrade)
	{
		if (this->_signed == true)
			cout << BOLD BROWN << bureaucrat.getName() << DEFAULT ORANGE " tried to sign Aform " << MAGENTA << this->_name << ORANGE " but it's already signed!" << DEFAULT << endl;
		else
		{
			this->_signed = true;
			cout << BOLD BROWN << bureaucrat.getName() << DEFAULT ORANGE " signed Aform " << MAGENTA << this->_name << "!" << DEFAULT << endl;
		}
	}
}

ostream& operator<<(ostream& s, const AForm& obj) {
	string isSigned = "";
	obj.getSigned() == 0 ? isSigned = "false" : isSigned = "true" ;
	s << MAGENTA << obj.getName() << DEFAULT LIGHT_BLUE << ", is signed: " << RED << isSigned << DEFAULT LIGHT_BLUE << ", Aform sign grade: " << RED << obj.getSignGrade() << DEFAULT LIGHT_BLUE << ", Aform sign grade: " << RED << obj.getExecGrade() << DEFAULT << endl;
	return (s);
}
