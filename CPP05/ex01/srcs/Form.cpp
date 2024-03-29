#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
	return(RED "Error:	The Grade is too High!" DEFAULT);
}

const char* Form::GradeTooLowException::what() const throw() {
	return(RED "Error:	The Grade is too Low!" DEFAULT);
}

Form::Form(string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if(signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form() {}

Form::Form(const Form& copy): _name(copy._name), _signed(false), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
	*this = copy;
}

Form&	Form::operator=(const Form& copy) {
	const_cast<string&>(this->_name) = copy._name;
	this->_signed = copy._signed;
	const_cast<int&>(this->_signGrade) = copy._signGrade;
	const_cast<int&>(this->_execGrade) = copy._execGrade;
	return (*this);
}

string	Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSigned(void) const {
	return (this->_signed);
}

int		Form::getSignGrade(void) const {
	return (this->_signGrade);
}

int		Form::getExecGrade(void) const {
	return (this->_execGrade);
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
	else if (bureaucrat.getGrade() <= this->_signGrade)
	{
		if (this->_signed == true)
			cout << BOLD BROWN << bureaucrat.getName() << DEFAULT ORANGE " tried to sign form " << MAGENTA << this->_name << ORANGE " but it's already signed!" << DEFAULT << endl;
		else
		{
			this->_signed = true;
			cout << BOLD BROWN << bureaucrat.getName() << DEFAULT ORANGE " signed form " << MAGENTA << this->_name << "!" << DEFAULT << endl;
		}
	}
}

ostream& operator<<(ostream& s, const Form& obj) {
	string isSigned = "";
	obj.getSigned() == 0 ? isSigned = "false" : isSigned = "true" ;
	s << MAGENTA << obj.getName() << DEFAULT LIGHT_BLUE << ", is signed: " << RED << isSigned << DEFAULT LIGHT_BLUE << ", form sign grade: " << RED << obj.getSignGrade() << DEFAULT LIGHT_BLUE << ", form sign grade: " << RED << obj.getExecGrade() << DEFAULT << endl;
	return (s);
}
