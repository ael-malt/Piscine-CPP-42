#include "Span.hpp"

#define VECTOR_SIZE 100

int main( void ) {
	try
	{
		cout << GREEN "My tests:" DEFAULT << endl;

		std::vector<int> tmp_vector(VECTOR_SIZE);
		Span span_vector(VECTOR_SIZE);

		std::srand(std::time(0));

		unsigned int nb = 0;
		for (unsigned int i = 0; i < VECTOR_SIZE; i++)
		{
			nb = abs(((((std::rand() % (VECTOR_SIZE )) + 2) * pow(i * (VECTOR_SIZE - i) , 2)) / 6) );
			if (nb == static_cast<unsigned int>(*easyfind(tmp_vector, nb)))
				nb = abs(((((std::rand() % (VECTOR_SIZE )) + 2) * pow(i * (VECTOR_SIZE - i) , 2)) / 6) );
			if (nb > INT_MAX)
				nb = nb / 2 - 2;

			tmp_vector.at(i) = nb;
		}
		span_vector.insert(tmp_vector.begin(), tmp_vector.end());
		int shortestSpan = span_vector.shortestSpan();
		int longestSpan = span_vector.longestSpan();
		cout << CYAN "shortestSpan: " MAGENTA << shortestSpan << DEFAULT << endl;
		cout << CYAN "longestSpan: " MAGENTA << longestSpan << DEFAULT << endl;


		cout << endl << GREEN "subject tests:" DEFAULT << endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << CYAN "shortestSpan: " MAGENTA << sp.shortestSpan() << DEFAULT << std::endl;
		std::cout << CYAN "longestSpan: " MAGENTA << sp.longestSpan() << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}


