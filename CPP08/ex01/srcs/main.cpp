#include "Span.hpp"


int main( void ) {
	try
	{
		Span a(100000);

		a.addNumber(1);
		std::srand(std::time(0));

		for (int i = 1; i < 100; i++)
		{
			int nb = abs(((std::rand() % 9991) * pow(i , 2)) / 3);
			a.addNumber(nb);
			// cout << nb << endl;
		}
		// a.addNumber(900);
		unsigned int shortestSpan = a.shortestSpan();
		cout << "shortestSpan: " << shortestSpan << endl;
		cout << "longestSpan: " << a.longestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return 0;
}