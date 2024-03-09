#include <iostream>
#include <fstream>
#include <string>

#include "../includes/Colors.hpp"

using	std::string;
using	std::cout;
using	std::endl;
using	std::ifstream;
using	std::ofstream;

void	read_and_replace(const char **argv, ifstream &src_file, ofstream &dst_file)
{
	string	line;
	size_t	len_to_remove = string(argv[2]).length();
	size_t	i = 0;
	while (getline(src_file, line))
	{
		i = line.find(argv[2]);
		if (i != string::npos)
		{
			line.erase(i, len_to_remove);
			line.insert(i, argv[3]);
		}
		dst_file << line;
		if(!src_file.eof())
			dst_file << endl;
	}
}

int	copy_file(const char **argv)
{
	ifstream src_file(argv[1]);
	if (!src_file.is_open()) 
	{
		cout << RED << "Error opening the source file!" << DEFAULT << endl;
		return (0);
	}
	string	new_filename = string(argv[1]) + ".replace";
	ofstream dst_file(new_filename.c_str());
	if (!dst_file.is_open())
	{
		cout << RED << "Error opening the destination file!" << DEFAULT << endl;
		src_file.close();
		return (0);
	}
	read_and_replace(argv, src_file, dst_file);

	src_file.close();
	dst_file.close();
	return (1);
}

int main(int argc, const char **argv)
{
	if (argc < 4)
	{
		cout << RED <<"Error: Too few arguments! Try with:\n" << GREEN << "    ./Sed_is_for_losers <filename> <str1> <str2>" << DEFAULT << endl;
		return (1);
	}
	else if (argc > 4)
	{
		cout << RED <<"Error: Too many arguments! Try with:\n" << GREEN << "    ./Sed_is_for_losers <filename> <str1> <str2>" << DEFAULT << endl;
		return (1);
	}
	if (!copy_file(argv))
	{
		cout << "Error copying files!" << endl;
		return (1);
	}
	return (0);
}
