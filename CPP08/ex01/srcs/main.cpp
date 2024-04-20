#include "Span.hpp"


int main( void ) {
	try
	{
		Span a(100);

		for (int i = 0; i < 100; i++)
		{
			a.addNumber(i);
		}
		cout << a.shortestSpan() << endl;
		// cout << a.longestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return 0;
}