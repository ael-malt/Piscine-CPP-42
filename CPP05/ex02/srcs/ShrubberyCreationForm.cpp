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
	if (this->getSigned())
		throw(ShrubberyCreationForm::FormNotSigned());
	if (bureaucrat.getGrade() < this->getExecGrade())
		throw(ShrubberyCreationForm::GradeTooLowException());
	ofstream shrubberryFile((this->_target + "_shrubbery").c_str());
	shrubberryFile << "                                                      ____                               " << endl;
	shrubberryFile << "                                               ______/    \_____                         " << endl;
	shrubberryFile << "                                              /                 \                        " << endl;
	shrubberryFile << "             ____                            |                   |                       " << endl;
	shrubberryFile << "            /    \_____       ____           |                   |     __                " << endl;
	shrubberryFile << "           /           \     /    \_    ____/                    | ___/  |               " << endl;
	shrubberryFile << "          |             \__ |_      |__|                         |/      |__             " << endl;
	shrubberryFile << "          |                \__\                                            /             " << endl;
	shrubberryFile << "           \                                                              /              " << endl;
	shrubberryFile << "      ___   \                                                         ___/               " << endl;
	shrubberryFile << "      |  \  |                                                        |                   " << endl;
	shrubberryFile << "     /    \  \                                                    ___|                   " << endl;
	shrubberryFile << "    /      \__\                                                  |                       " << endl;
	shrubberryFile << "    |         \|                                                 /                       " << endl;
	shrubberryFile << "     \____                                                  ____/    __                   " << endl;
	shrubberryFile << "          \___                                             |        /  \    ___          " << endl;
	shrubberryFile << "              \                  |                          \      /    \__/   \            " << endl;
	shrubberryFile << "               \ ____            \___                        \____|            |          " << endl;
	shrubberryFile << "                      \              \               ___                       /             " << endl;
	shrubberryFile << "                       \___           \          ___/   \                     |               " << endl;
	shrubberryFile << "                           \     ____  \        /        \____             ___/                     " << endl;
	shrubberryFile << "                            \___/    \ |       /              \        ___/                             " << endl;
	shrubberryFile << "                                      \|      |                \______/                            " << endl;
	shrubberryFile << "                                       |      |                                           " << endl;
	shrubberryFile << "                                       |      |                                           " << endl;
	shrubberryFile << "                                       |      /                                           " << endl;
	shrubberryFile << "                                       |     |                                           " << endl;
	shrubberryFile << "                                       |     |                                           " << endl;
	shrubberryFile << "                                       |     |                                           " << endl;
	shrubberryFile << "                                       |     |                                           " << endl;
	shrubberryFile << "                                      /      |                                           " << endl;
	shrubberryFile << "                                      |      |                                           " << endl;
	shrubberryFile << "                                      /      |                                           " << endl;
	shrubberryFile << "                                     |       |                                           " << endl;
	shrubberryFile << "                                     |       |                                           " << endl;
	shrubberryFile << "                                     |        \                                          " << endl;
	shrubberryFile << "                                     |        |                                          " << endl;
	shrubberryFile << "                                     /        |                                          " << endl;
	shrubberryFile << "                                    |         \                                          " << endl;
	shrubberryFile << "                                    |          |                                         " << endl;
	shrubberryFile << "                                    |          |                                         " << endl;
	shrubberryFile << "                                    |           \                                        " << endl;
	shrubberryFile << "                                    |           |                                        " << endl;
	shrubberryFile << "                                    /           |                                        " << endl;
	shrubberryFile << "                                   |            |                                        " << endl;
}

