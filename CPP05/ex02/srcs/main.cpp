#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main(void)
{
	try
	{
		AForm *ShrubForm1 = new ShrubberyCreationForm("ShrubForm1");
		cout << *ShrubForm1;

		Bureaucrat Tim("Tim", 65);
		cout << Tim;

		Bureaucrat Hamid("Hamid", 50);
		cout << Hamid;

		Tim.signForm(*ShrubForm1);
		cout << *ShrubForm1;

		Hamid.executeForm(*ShrubForm1);
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}

	try
	{
		AForm *ShrubForm1 = new Robotomy("ShrubForm1");
		cout << *ShrubForm1;

		Bureaucrat Henry("Henry", 102);
		cout << Henry;

		Bureaucrat Paco("Paco", 50);
		cout << Paco;

		Henry.signForm(*ShrubForm1);
		cout << *ShrubForm1;

		Paco.executeForm(*ShrubForm1);
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
	return (0);
}
