#include "easyFind.hpp"


int main( void ) {
	int arr[] = {1, 12, 7, 27, 3, 42, 21};

	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	std::deque<int> d(arr, arr + sizeof(arr) / sizeof(int));

	try
	{
		cout << "Element: " << *easyfind(v, 27) << " found in v" << endl;

		cout << "Element: " << *easyfind(d, 5) << " found in d" << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}