#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int	main(void)
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
	return (0);
}
