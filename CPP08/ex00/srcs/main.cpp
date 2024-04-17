#include "EasyFind.hpp"

int main( void ) {
	try
	{
		Array<int> empty_array(1);
		(void)empty_array;
		Array<int> array1(1);
		Array<int> array2(2);
		array1[0] = 42;
		array2[0] = 69;
		array2[1] = 27;
		cout << array1[0] << endl;
		cout << array2[0] << endl;
		cout << array2[1] << endl;
		cout << array2[1] << endl;
		cout << endl;
		Array<int> array3(42);
		for (unsigned int i = 0; i < array3.size(); i++)
			array3[i] = i;
		for (unsigned int i = 0; i < array3.size(); i++)
		{
			cout << array3[i];
			if(i < array3.size() - 1)
				cout << ", ";
		}
		cout << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}