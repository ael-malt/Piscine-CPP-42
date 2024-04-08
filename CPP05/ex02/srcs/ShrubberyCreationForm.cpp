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

void	ShrubberyCreationForm::beExecuted(Bureaucrat const &bureaucrat) const {
	if (!this->getSigned())
		throw(ShrubberyCreationForm::FormNotSigned());
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw(ShrubberyCreationForm::GradeTooLowException());
	ofstream shrubberryFile((this->_target + "_shrubbery").c_str());
	shrubberryFile << "                                                                                         " << endl;
	shrubberryFile << "                                                                                         " << endl;
	shrubberryFile << "                                                                                         " << endl;
	shrubberryFile << "                                                      ____¶»                             " << endl;
	shrubberryFile << "                                               ______/.: @\\_____¶»     .                 " << endl;
	shrubberryFile << "                                              /.:     ^%'      @\\        .               " << endl;
	shrubberryFile << "                                             | ^%'   .           |       .               " << endl;
	shrubberryFile << "                                             /.:                @.\\        .             " << endl;
	shrubberryFile << "                                           _/.^%'          .      |                      " << endl;
	shrubberryFile << "             ____¶»               ____¶» /.:^%'       :.        __/.: .                  " << endl;
	shrubberryFile << "            /.: @\\_____¶»     ___/.: @\\_/.^%'                  |   ^__'                  " << endl;
	shrubberryFile << "           /.^%'     @\\      /.:   ^%'   ^%'     :             |___/.:|                  " << endl;
	shrubberryFile << "          | ^%'       @\\__¶»^\\%'      .                   .    |/.:  ^%\\¶»               " << endl;
	shrubberryFile << "          |       .       @\\__\\        .                          ^%'  /.:               " << endl;
	shrubberryFile << "          @\\      :                     :        _¶»                  /.^%'              " << endl;
	shrubberryFile << "      ___¶»\\        .           .        o___o _/.|_¶»    .        __|.^%'               " << endl;
	shrubberryFile << "      | @\\  |.      :       ___¶»          O  /.:^%/               \\    ^%'              " << endl;
	shrubberryFile << "     /.: @\\ @.      . .    /.:@\\_¶»   .     _/.^%' /.:          ____|                    " << endl;
	shrubberryFile << "    /.^%'@\\__\\        .   |^%'@\\        .  /.:^%' /.^%'   .    |                         " << endl;
	shrubberryFile << "    |^%'    @\\|.         @\\   @\\__¶»      /.^%'  | ^%'        /.:                        " << endl;
	shrubberryFile << "    @\\___¶»    .           |__¶» .|      |^%'    /.:      ___/.^%'_¶»                    " << endl;
	shrubberryFile << "         @\\__¶»      .       @\\   @\\     |      /.^%'   |     ^%'/:\\    __¶»     .       " << endl;
	shrubberryFile << "             @\\        .      |     @\\   /.:    |^%'    @\\      /.^%\\__/.:\\        .     " << endl;
	shrubberryFile << "              @\\______¶»     .  \\___¶»@\\| ^%.  /.:       @\\____| ^%'     ^%'|            " << endl;
	shrubberryFile << "                .    @\\        .    @\\      . .   |^%'_¶»    .        .     ..:          " << endl;
	shrubberryFile << "                      @\\___¶»       @\\        . /.:_/.\\        :           | ^%'         " << endl;
	shrubberryFile << "                        . @\\     ____¶».       /.^/^%'|___¶»      .      __/.:           " << endl;
	shrubberryFile << "                           @\\___/.: @\\ .      /.'/.:    . @\\        .___/.: ^%'          " << endl;
	shrubberryFile << "                                 ^%'@\\|       | ^%'| ^%'   @\\______/.:  ^%'              " << endl;
	shrubberryFile << "                                       |      | _/%'         .      ^%'                  " << endl;
	shrubberryFile << "                                       |      |/%'                                       " << endl;
	shrubberryFile << "                                       |      /.^%'                                      " << endl;
	shrubberryFile << "                                       |     | ^%'                                       " << endl;
	shrubberryFile << "                                       |     |                                           " << endl;
	shrubberryFile << "                                       |     |                                           " << endl;
	shrubberryFile << "                                       |     |                                           " << endl;
	shrubberryFile << "                                      /      |                                           " << endl;
	shrubberryFile << "                                      |      |                                           " << endl;
	shrubberryFile << "                                      /      |                                           " << endl;
	shrubberryFile << "                                     |       |                                           " << endl;
	shrubberryFile << "                                     |       |                                           " << endl;
	shrubberryFile << "                                     |        \\                                          " << endl;
	shrubberryFile << "                                     |        |                                          " << endl;
	shrubberryFile << "                                     /        |                                          " << endl;
	shrubberryFile << "                                    |         \\                                          " << endl;
	shrubberryFile << "                                    |          |                                         " << endl;
	shrubberryFile << "                                   /           |                                         " << endl;
	shrubberryFile << "                                   |            \\                                        " << endl;
	shrubberryFile << "                                   |            |                                        " << endl;

	ofstream shrubberryFile1((this->_target + "_shrubbery_bonus").c_str());
	shrubberryFile1 << "                                                                                         " << endl;
	shrubberryFile1 << "                                                                                         " << endl;
	shrubberryFile1 << "                                                                                         " << endl;
	shrubberryFile1 << "                                                      " BROWN " _____" GREEN "¶»" GREEN "                              " << endl;
	shrubberryFile1 << "                                               " BROWN " ______" BROWN "/" GREEN ".: @ " BROWN "\\____" GREEN "¶»     .                 " << endl;
	shrubberryFile1 << "                                              " BROWN " /" GREEN ".:     ^%'      @" BROWN "\\" GREEN "        .               " << endl;
	shrubberryFile1 << "                                             " BROWN " / ^%'   .           " BROWN "\\       .               " << endl;
	shrubberryFile1 << "                                             " BROWN "/" GREEN ".:                @." BROWN " \\" GREEN "        .             " << endl;
	shrubberryFile1 << "                                          " BROWN "__/" GREEN ".^%'          .      " BROWN " |                      " << endl;
	shrubberryFile1 << "             " BROWN "____" GREEN "¶»            " BROWN "____" GREEN "¶»    " BROWN "/" GREEN ".:^%'       :.         " BROWN "__" BROWN "/" GREEN ".: .                  " << endl;
	shrubberryFile1 << "            " BROWN "/" GREEN ".: @" BROWN "\\" BROWN "_____" GREEN "¶»  " BROWN "   " BROWN "/" GREEN ".: @" BROWN "\\" BROWN "____" BROWN "/" GREEN ".^%'                   " BROWN "|     ^__'                  " << endl;
	shrubberryFile1 << "           " BROWN "/" GREEN ".^%'     @" BROWN "\\" GREEN "      " BROWN "/" GREEN ".:   ^%'   ^%'     :              " BROWN "| ____" BROWN "/" GREEN "." BROWN "/                  " << endl;
	shrubberryFile1 << "          " BROWN "|" GREEN " ^%'       @" BROWN "\\" BROWN "__" GREEN "¶»^" BROWN "\\%'" GREEN "      .                    .    " BROWN "|" GREEN "" BROWN "/" GREEN ".:  ^%" BROWN "\\" GREEN "" GREEN "¶»               " << endl;
	shrubberryFile1 << "          " BROWN "|" GREEN "       .       @" BROWN "\\" BROWN "__" BROWN "\\" GREEN "        .                           ^%'  " BROWN "/" GREEN ".:               " << endl;
	shrubberryFile1 << "          @" BROWN "\\" GREEN "      :                     :          " BROWN "_" GREEN "¶»" GREEN "                 " BROWN "/" GREEN ".^%'              " << endl;
	shrubberryFile1 << "      " BROWN "___" GREEN "¶»" GREEN " " BROWN "\\" GREEN "        .           .        o___o " BROWN "_" GREEN " " BROWN "/" GREEN "." BROWN "|" BROWN "_" GREEN "¶»    .        " BROWN "__" BROWN "|" GREEN ".^%'               " << endl;
	shrubberryFile1 << "      " BROWN "|" GREEN " @" BROWN "\\" GREEN "  " BROWN "|" GREEN ".      :       " BROWN "___" GREEN "¶»" GREEN "           O  " BROWN "/" GREEN ".:^%" BROWN "/" GREEN "               " BROWN "\\" GREEN "    ^%'              " << endl;
	shrubberryFile1 << "     " BROWN "/" GREEN ".: @" BROWN "\\" GREEN " @.      . .    " BROWN "/" GREEN ".:@" BROWN "\\" GREEN "¶»   .     " BROWN "_" GREEN " " BROWN "/" GREEN ".^%' " BROWN "/" GREEN ".:         " BROWN " ____" BROWN "|" GREEN "                    " << endl;
	shrubberryFile1 << "    " BROWN "/" GREEN ".^%'@" BROWN "\\" BROWN "__" BROWN "\\" GREEN "        .   " BROWN "/" GREEN "^%'@" BROWN "/" GREEN "        .  " BROWN "/" GREEN ".:^%' " BROWN " /" GREEN ".^%'   .   " BROWN "|" GREEN "                         " << endl;
	shrubberryFile1 << "    " BROWN "|" GREEN "^%'    @" BROWN "\\" GREEN BROWN "|" GREEN ".         @" BROWN "\\" GREEN "   @" BROWN "\\" BROWN "__" GREEN "¶»      " BROWN " /" GREEN ".^%'  " BROWN "|" GREEN " ^%'       " BROWN "_/" GREEN ".:                        " << endl;
	shrubberryFile1 << "    @" BROWN "\\" BROWN "___" GREEN "¶»    .           " BROWN "\\" BROWN "__" GREEN "¶» ." BROWN "|" GREEN "      " BROWN "|" GREEN "^%'    " BROWN "/" GREEN ".:     " BROWN "____" BROWN "/" GREEN ".^%'" BROWN "_" GREEN "¶»                    " << endl;
	shrubberryFile1 << "         @" BROWN "\\" BROWN "__" GREEN "¶»      .       @" BROWN "\\" GREEN "   @" BROWN "\\" GREEN "     " BROWN "|" GREEN "      " BROWN "/" GREEN ".^%'   " BROWN "|" GREEN "     ^%'" BROWN "/" GREEN ":" BROWN "\\" GREEN "    " BROWN " __" GREEN "¶»" GREEN "      .       " << endl;
	shrubberryFile1 << "             @" BROWN "\\" GREEN "        .      " BROWN " \\" GREEN "    @" BROWN "\\" GREEN "   " BROWN "|" GREEN ".:    " BROWN "|" GREEN "^%'    @" BROWN "\\" GREEN "      " BROWN "/" GREEN ".^%" BROWN "\\_" BROWN "__" BROWN "/" GREEN ".:" BROWN "\\" GREEN "        .     " << endl;
	shrubberryFile1 << "              @" BROWN "\\" BROWN "______" GREEN "¶»     .  " BROWN "\\" BROWN "___" GREEN "¶»@" BROWN "\\_" BROWN "/" GREEN " ^%.  " BROWN "/" GREEN ".:       @" BROWN "\\" BROWN "____" BROWN "|" GREEN " ^%'    ^%'" BROWN "|" GREEN "            " << endl;
	shrubberryFile1 << "                .    @" BROWN "\\" GREEN "        .   @" BROWN "\\" GREEN "       . . " BROWN "|" GREEN "^%'" BROWN " _" GREEN "¶»    .        .     " BROWN " |" GREEN "..:          " << endl;
	shrubberryFile1 << "                      @" BROWN "\\" BROWN "___" GREEN "¶»       @" BROWN "\\" GREEN "        . " BROWN "/" GREEN ".:" BROWN " /" GREEN "." BROWN "\\" GREEN "        :            " BROWN "|" GREEN " ^%'         " << endl;
	shrubberryFile1 << "                        . @" BROWN "\\" GREEN "     " BROWN "____" GREEN "¶»" GREEN " .      " BROWN "/" GREEN ".^" BROWN " /" GREEN "^%'" BROWN "|" BROWN "___" GREEN "¶»      .      " BROWN "__" BROWN "/" GREEN ".:           " << endl;
	shrubberryFile1 << "                           @" BROWN "\\" BROWN "___" BROWN "/" GREEN ".: @" BROWN "\\" GREEN " .      " BROWN "/" GREEN ".'" BROWN "  |" GREEN ".:  . @" BROWN "\\       " GREEN "." BROWN "____" BROWN "/" GREEN ".: ^%'          " << endl;
	shrubberryFile1 << "                                  ^%'@" BROWN "\\" BROWN "|" GREEN "      " BROWN "|" GREEN " ^%'" BROWN "|" GREEN " ^%'   @" BROWN "\\" BROWN "______" BROWN "/" GREEN ".:  ^%'              " << endl;
	shrubberryFile1 << "                                       " BROWN "|" GREEN "      " BROWN "|" GREEN " " BROWN "_" GREEN " " BROWN "/" GREEN "%'         .      ^%'                  " << endl;
	shrubberryFile1 << "                                       " BROWN "|" GREEN "      " BROWN "|" GREEN "" BROWN "/" GREEN "%'                                       " << endl;
	shrubberryFile1 << "                                       " BROWN "|" GREEN "      " BROWN "/" GREEN ".^%'                                      " << endl;
	shrubberryFile1 << "                                       " BROWN "|" GREEN "     " BROWN "|" GREEN " ^%'                                       " << endl;
	shrubberryFile1 << "                                       " BROWN "|" GREEN "     " BROWN "|" GREEN "                                           " << endl;
	shrubberryFile1 << "                                       " BROWN "|" GREEN "     " BROWN "|" GREEN "                                           " << endl;
	shrubberryFile1 << "                                       " BROWN "|" GREEN "     " BROWN "|" GREEN "                                           " << endl;
	shrubberryFile1 << "                                      " BROWN "/" GREEN "      " BROWN "|" GREEN "                                           " << endl;
	shrubberryFile1 << "                                      " BROWN "|" GREEN "      " BROWN "|" GREEN "                                           " << endl;
	shrubberryFile1 << "                                      " BROWN "/" GREEN "      " BROWN "|" GREEN "                                           " << endl;
	shrubberryFile1 << "                                     " BROWN "|" GREEN "       " BROWN "|" GREEN "                                           " << endl;
	shrubberryFile1 << "                                     " BROWN "|" GREEN "       " BROWN "|" GREEN "                                           " << endl;
	shrubberryFile1 << "                                     " BROWN "|" GREEN "        " BROWN "\\" GREEN "                                          " << endl;
	shrubberryFile1 << "                                     " BROWN "|" GREEN "        " BROWN "|" GREEN "                                          " << endl;
	shrubberryFile1 << "                                     " BROWN "/" GREEN "        " BROWN "|" GREEN "                                          " << endl;
	shrubberryFile1 << "                                    " BROWN "|" GREEN "         " BROWN "\\" GREEN "                                          " << endl;
	shrubberryFile1 << "                                    " BROWN "|" GREEN "          " BROWN "|" GREEN "                                         " << endl;
	shrubberryFile1 << "                                   " BROWN "/" GREEN "           " BROWN "|" GREEN "                                         " << endl;
	shrubberryFile1 << "                                   " BROWN "|" GREEN "            " BROWN "\\" GREEN "                                        " << endl;
	shrubberryFile1 << "                                   " BROWN "|" GREEN "            " BROWN "|" GREEN "                                        " << endl;
}

