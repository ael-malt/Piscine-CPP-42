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
	cout << endl;
	try
	{
		AForm *RobForm1 = new RobotomyRequestForm("RobForm1");
		cout << *RobForm1;

		Bureaucrat Henry("Henry", 102);
		cout << Henry;

		Bureaucrat Paco("Paco", 50);
		cout << Paco;

		Henry.signForm(*RobForm1);
		cout << *RobForm1;

		Paco.executeForm(*RobForm1);
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
	cout << endl;
	try
	{
		AForm *RobForm2 = new RobotomyRequestForm("RobForm2");
		cout << *RobForm2;

		Bureaucrat Jack("Jack", 59);
		cout << Jack;

		Bureaucrat Bob("Bob", 40);
		cout << Bob;

		Jack.signForm(*RobForm2);
		cout << *RobForm2;

		Bob.executeForm(*RobForm2);
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
	return (0);
}
