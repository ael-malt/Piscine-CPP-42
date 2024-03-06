#include <iostream>

using	std::cout;
using	std::endl;
using	std::toupper;

int	main(int ac, char **argv)
{
	if (ac == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			cout << (char)toupper(argv[i][j]);
		if (i <= ac - 1)
			cout << ' ';
	}
	cout << endl;
	return (0);
}
