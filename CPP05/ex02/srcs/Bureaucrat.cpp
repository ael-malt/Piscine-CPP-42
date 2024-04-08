#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return(RED "Error:	The Grade is too High! \n	Try with a grade lower or equal to 1." DEFAULT);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return(RED "Error:	The Grade is too Low! \n	Try with a grade higher or equal to 150." DEFAULT);
}

Bureaucrat::Bureaucrat(string name, int grade) : _name(name) {
	if(grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name) {
	*this = copy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy) {
	this->_grade = copy._grade;
	const_cast<string&>(this->_name) = copy._name;
	return (*this);
}

string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int		Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::increaseGrade(){
	if((this->_grade < 1) || (this->_grade - 1 < 1))
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	cout << GREEN "Increased grade for bureaucrat " << BOLD BROWN << this->_name << DEFAULT << endl;
	this->_grade--;
}

void	Bureaucrat::decreaseGrade(){
	if(this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if ((this->_grade > 150) || (this->_grade + 1 > 150))
		throw (Bureaucrat::GradeTooLowException());
	cout << ORANGE "Decreased grade for bureaucrat " << BOLD BROWN << this->_name << DEFAULT << endl;
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	if (form.getSignGrade() < this->_grade)
		cout << BOLD BROWN << this->_name << DEFAULT RED << " couldn't sign " << MAGENTA << form.getName() << RED " because: " BOLD "grade too low!" DEFAULT << endl;
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form) {
	if (form.getSignGrade() < this->_grade)
		cout << BOLD BROWN << this->_name << DEFAULT RED << " couldn't execute " << MAGENTA << form.getName() << RED " because: " BOLD "grade too low!" DEFAULT << endl;
	if (form.getSignGrade() >= this->_grade && !form.getSigned())
		cout << BOLD BROWN << this->_name << DEFAULT RED << " couldn't execute " << MAGENTA << form.getName() << RED " because: " BOLD "form is not signed!" DEFAULT << endl;
	cout << GREEN BOLD << this->_name << DEFAULT GREEN << " executed " << MAGENTA << form.getName() << DEFAULT << endl;
	form.beExecuted(*this);
}

ostream& operator<<(ostream& s, const Bureaucrat& obj) {
	s << BOLD BROWN << obj.getName() << DEFAULT LIGHT_BLUE << ", bureaucrat grade " << RED << obj.getGrade() << DEFAULT << endl;
	return (s);
}
