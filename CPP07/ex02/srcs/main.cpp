#include "Iter.hpp"


// static int	ft_toupper(int c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - ' ');
// 	return (c);
// }
template <typename T> void ft_toupper(T &c) {
	c >= 'a' && c <= 'z' ? c -= ' ' : c;
}

template <typename T> void ft_tolower(T &c) {
	c >= 'A' && c <= 'Z' ? c += ' ' : c;
}

template <typename T> void printVal(T &val) {
	cout << val;
}

int main( void ) {
	char Arr[6] = {"abcde"};

	cout << "Before ft_toupper" << endl;
	iter(Arr, 5, printVal);
	cout << endl;
	iter(Arr, 5, ft_toupper);
	cout << "After ft_toupper" << endl;
	iter(Arr, 5, printVal);
	cout << endl;
	
	cout << endl;
	
	cout << "Before ft_tolower" << endl;
	iter(Arr, 5, printVal);
	cout << endl;
	iter(Arr, 5, ft_tolower);
	cout << "After ft_tolower" << endl;
	iter(Arr, 5, printVal);
	cout << endl;

	return 0;
}