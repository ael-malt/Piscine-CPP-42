#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include "Colors.hpp"

#include <iostream>
#include <fstream>
#include <exception>
#include <list>
// #include 

using std::cout;
using std::endl;
using std::exception;
using std::ifstream;
using std::list;

class BitcoinExchange
{
private:
	ifstream CSV;
	list<float> value;
	list<long int> date;
	short unsigned int index;
	short unsigned int len;
	
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);
public:
	BitcoinExchange(ifstream& myFile);
	~BitcoinExchange();

	class FileNotGiven : public exception
	{
		public: virtual const char* what() const throw() { return (RED "Error: No file was given" DEFAULT); }
	};

	class FileNotOpen : public exception
	{
		public: const char* what() const throw() { return (RED "Error: Couldn't open file" DEFAULT); }
	};
};



#endif