#include "easyFind.hpp"


int main( void ) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};

	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	std::deque<int> d(arr, arr + sizeof(arr) / sizeof(int));

	try
	{
		cout << 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}poweroff