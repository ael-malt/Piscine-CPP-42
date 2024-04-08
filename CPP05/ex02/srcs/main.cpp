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
	cout << endl;
	try
	{
		AForm *PresForm1 = new PresidentialPardonForm("PresForm1");
		cout << *PresForm1;

		Bureaucrat Zouzou("Zouzou", 59);
		cout << Zouzou;

		Bureaucrat Lester("Lester", 40);
		cout << Lester;

		// Zouzou.signForm(*PresForm1);
		cout << *PresForm1;

		Lester.executeForm(*PresForm1);
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
	cout << endl;
	try
	{
		AForm *PresForm1 = new PresidentialPardonForm("PresForm1");
		cout << *PresForm1;

		Bureaucrat Zouzou("Zouzou", 25);
		cout << Zouzou;

		Bureaucrat Lester("Lester", 4);
		cout << Lester;

		Zouzou.signForm(*PresForm1);
		cout << *PresForm1;

		Lester.executeForm(*PresForm1);
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
	return (0);
}
