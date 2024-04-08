#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main(void)
{
	try
	{
		Form FormA("FormA", 100, 101);
		cout << FormA;
		Bureaucrat Henry("Henry", 1);
		cout << Henry;
		Henry.signForm(FormA);
		cout << FormA;
		Form FormACopy = FormA;
		cout << FormACopy;
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
	cout << endl;
	
	try
	{
		Form FormB("FormB", 41, 69);
		cout << FormB;
		Bureaucrat Bob("Bob", 42);
		Bob.signForm(FormB);
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
	catch(const exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;
	
	try
	{
		Form FormC("FormC", 69, 92);
		cout << FormC;
		Bureaucrat Jack("Jack", 69);
		Jack.signForm(FormC);
		cout << FormC;
		Jack.signForm(FormC);
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
	catch(const exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;

	try
	{
		Bureaucrat Robert("Robert", 420);
	}
	catch(const exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;

	try
	{
		Form FormD("FormD", 149, 150);
		cout << FormD;
		Bureaucrat Timmy("Timmy", 150);
		cout << Timmy;
		Timmy.increaseGrade();
		Timmy.signForm(FormD);
		cout << FormD;
		cout << Timmy;
		Timmy.decreaseGrade();
		Timmy.decreaseGrade();
	}
	catch(const exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;

	return (0);
}
