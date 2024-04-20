#include "Base.hpp"

Base*	generate(void) 
{
	srand(time(NULL));
	int	num = rand() % 3;
	switch (num)
	{
	case 0:
		return (dynamic_cast<Base*>(new A));
	case 1:
		return (dynamic_cast<Base*>(new B));
	case 2:
		return (dynamic_cast<Base*>(new C));
	}
	return (new Base);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "Pointer is of type: " GREEN "A" DEFAULT << endl;
	if (dynamic_cast<B*>(p))
		cout << "Pointer is of type: " GREEN "B" DEFAULT << endl;
	if (dynamic_cast<C*>(p))
		cout << "Pointer is of type: " GREEN "C" DEFAULT << endl;
}

void identify(Base& p) {
	try
	{
		A& BaseA = dynamic_cast<A&>(p);
		cout << "Pointer is of type: " GREEN "A" DEFAULT << endl;
		(void)BaseA;
	}
	catch(const std::exception& e){}
	try
	{
		B& BaseA = dynamic_cast<B&>(p);
		cout << "Pointer is of type: " GREEN "B" DEFAULT << endl;
		(void)BaseA;
	}
	catch(const std::exception& e){}
	try
	{
		C& BaseA = dynamic_cast<C&>(p);
		cout << "Pointer is of type: " GREEN "C" DEFAULT << endl;
		(void)BaseA;
	}
	catch(const std::exception& e){}
}

int main(void)
{
	Base* obj = generate();
	identify(obj);
	identify(*obj);
	delete obj;
	return 0;
}
