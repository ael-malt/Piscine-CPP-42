#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "Colors.hpp"

# include <iostream>
# include <fstream>
# include <exception>
# include <list>
# include <algorithm>
# include <iterator>
# include <limits.h>
# include <sstream>
// #include 

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;
using std::ifstream;
using std::list;

class BitcoinExchange
{
private:
	ifstream _CSV;
	list<float> _value;
	list<long int> _date;
public:
	BitcoinExchange(ifstream& myFile);
	~BitcoinExchange();

	void		checkCSV(void);
	long int	checkDate(string date, string fileName, unsigned int linePos);
	int			getIntLen(int number);
	long int	encodeDate(int year, int month, int day);
	string		decodeDate(long int date);
	void		compareFileCSV(ifstream& inFile);
	float		calculateValXEx(std::list<long int>::iterator dateIt, float value);

	class FileNotGiven : public exception
	{
		public: virtual const char* what() const throw() { return (RED "Error: No file was given" DEFAULT); }
	};

	class FileNotOpen : public exception
	{
		public: const char* what() const throw() { return (RED "Error: Couldn't open file" DEFAULT); }
	};

	class FileBadValue : public exception
	{
		private: string _msg;
		public: 
			virtual ~FileBadValue() throw() {}
			FileBadValue(string file) : _msg(RED "Error: Wrong value found in file: " MAGENTA + file + DEFAULT) {}
			const char* what() const throw() { return (_msg.c_str()); }
	};

	class FileImpossibleDate : public exception
	{
		private: string _msg;
		public: 
			virtual ~FileImpossibleDate() throw() {}
			FileImpossibleDate(string file, string date) : _msg(RED "Error: Impossible Date found in file: " MAGENTA + file + RED + " => " + ORANGE + date + DEFAULT) {}
			const char* what() const throw() { return (_msg.c_str()); }

	};

	class CompFunctor{
	private:
		long int	_target;
	public:
		CompFunctor(unsigned int target): _target(target){}
		bool operator()(long int A, long int B) const{ return std::abs(A - _target) < std::abs(B - _target);}
	};
};



#endif