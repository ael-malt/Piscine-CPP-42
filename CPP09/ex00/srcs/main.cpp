#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	try
	{
		if (argc < 2)
			throw (BitcoinExchange::FileNotGiven());

		ifstream inFile;
		inFile.open(argv[1]);
		if (!inFile.is_open()) 
			throw (BitcoinExchange::FileNotOpen());

		BitcoinExchange start(inFile);
		inFile.close();
	}
	catch(const exception& e)
	{
		std::cerr << e.what() << endl;
	}
	
	return 0;
}
