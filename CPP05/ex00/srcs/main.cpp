//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "Bureaucrat.hpp"


int	main(void)
{
	try
	{
		Bureaucrat Henry("Henry", 1);
		cout << Henry;
		Henry.decreaseGrade();
		Bureaucrat HenryCopy = Henry;
		cout << HenryCopy;
		HenryCopy.increaseGrade();
		cout << HenryCopy;
		HenryCopy.increaseGrade();

	}
	catch(const exception& e)
	{
		cerr << e.what() << endl;
	}
	
	try
	{
		Bureaucrat Bob("Bob", 42);
		Bob.increaseGrade();
		cout << Bob;
		Bob.increaseGrade();
		cout << Bob;
		Bob.decreaseGrade();
		cout << Bob;
		Bob.decreaseGrade();
		cout << Bob;
		Bob.decreaseGrade();
		cout << Bob;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	
	try
	{
		Bureaucrat Jack("Jack", 69);
		Jack.increaseGrade();
		cout << Jack;
		Jack.increaseGrade();
		cout << Jack;
		Jack.increaseGrade();
		cout << Jack;
		Jack.increaseGrade();
		cout << Jack;
		Jack.increaseGrade();
		cout << Jack;
		Jack.increaseGrade();
		cout << Jack;
		Jack.decreaseGrade();
		cout << Jack;
		Jack.decreaseGrade();
		cout << Jack;
		Jack.decreaseGrade();
		cout << Jack;
		Jack.decreaseGrade();
		cout << Jack;
		Jack.decreaseGrade();
		cout << Jack;
		Jack.decreaseGrade();
		cout << Jack;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}

	try
	{
		Bureaucrat Robert("Robert", 420);
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}

	try
	{
		Bureaucrat Timmy("Timmy", 150);
		cout << Timmy;
		Timmy.decreaseGrade();

	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	
	return (0);
}
