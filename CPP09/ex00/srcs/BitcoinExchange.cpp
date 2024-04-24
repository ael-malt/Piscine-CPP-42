#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(ifstream& inFile) {
	this->index = 0;

	this->CSV.open("data.csv");
	if (!this->CSV.is_open()) 
		throw (BitcoinExchange::FileNotOpen());
	string line;
	getline(this->CSV, line);
}

BitcoinExchange::~BitcoinExchange() {
}