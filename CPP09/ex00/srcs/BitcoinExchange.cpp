#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(ifstream& inFile) {
	this->_CSV.open("data.csv");
	if (!this->_CSV.is_open()) 
		throw (BitcoinExchange::FileNotOpen());
	checkCSV();
	// decodeDate(*this->_date.begin());
	compareFileCSV(inFile);
}

float	BitcoinExchange::calculateValXEx(std::list<long int>::iterator dateIt, float value) {
	long int distance = std::distance(this->_date.begin(), dateIt);
	std::list<float>::iterator valueIt = this->_value.begin();
	std::advance(valueIt, distance);
	return (value * *valueIt);
}

void BitcoinExchange::compareFileCSV(ifstream& inFile) {
	unsigned int linePos = 0;
	string line, fileValue, fileDate;
	float value;
	long int date;
	std::list<long int>::iterator it;
	string charSet = "0123456789|.- ";
	while(inFile && !inFile.eof())
	{
		getline(inFile, line);
		fileDate = string(line.substr(0, line.find_first_of('|')));
		date = checkDate(fileDate, "Input File", linePos);
		if (line[0] && (date != 0)) {
			// if (linePos > 0 && line.find_first_not_of(charSet) != string::npos)
			// {
			// 	cout << line << endl;
			// 	throw (BitcoinExchange::FileBadValue("inFile"));
			// }
			if ((it = std::find(this->_date.begin(), this->_date.end(), date)) == this->_date.end())
				it = std::min_element(this->_date.begin(), this->_date.end(), CompFunctor(date));

			if ((fileValue = string(line.substr(line.find_first_of('|') + 1, line.length()))).find_first_of("0123456789") == string::npos)
				cerr << RED "Error: No Value"  << DEFAULT << endl;

			value = atof(fileValue.c_str());
			if (value < 0)
				cerr << RED "Error: Not a postive number" DEFAULT << endl;
			else if (value > 1000)
				cerr << RED "Error: too large a number" DEFAULT << endl;
			else 
				cout << fileDate << " => " << value << " = " << calculateValXEx(it, value) << endl;
		}
		linePos++;
	}
}
long int	BitcoinExchange::encodeDate(int year, int month, int day) { return ((year * 10000) + (month * 100) + day); }

string	BitcoinExchange::decodeDate(long int date) {
	string fullDate;
	std::stringstream out;

	long int day = date % 100;
	date = date / 100;
	long int month = date % 100;
	date = date / 100;
	long int year = date;

	out << year << '-';
	if (month < 10)
		out << 0;
	out << month << '-';
	if (day < 10)
		out << 0;
	out << day;

	fullDate = out.str();
	return (fullDate);
}

int	BitcoinExchange::getIntLen(int number)
{
	int counter = 0;
	while(number)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

long int	BitcoinExchange::checkDate(string date, string fileName, unsigned int linePos) {
	int day, month, year = 0;
	year = atoi(date.substr(0, date.find_first_of('-')).c_str());
	month = atoi(date.substr(date.find_first_of('-') + 1, date.find_last_of('-')).c_str());
	day = atoi(date.substr(date.find_last_of('-') + 1, date.length()).c_str());
	
	if ( year < 0 || year >= 10000 || month < 0 || month > 12 || day < 0 || day > 31 ) {
		if (!fileName.compare("data.csv"))
			throw(BitcoinExchange::FileImpossibleDate("data.csv", date));
		else if (!linePos)
			return (0);
		else
			throw(BitcoinExchange::FileImpossibleDate(fileName, date));
	}
	
	if ((month == 2 && day >= 29 && (year % 4)) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
		if (!fileName.compare("data.csv"))
			throw(BitcoinExchange::FileImpossibleDate("data.csv", date));
		else if (!linePos)
			return (0);
		else
			throw(BitcoinExchange::FileImpossibleDate(fileName, date));
	}

	if (!fileName.compare("data.csv"))
		this->_date.push_back(BitcoinExchange::encodeDate(year, month, day));
	return (BitcoinExchange::encodeDate(year, month, day));
}

void	BitcoinExchange::checkCSV(void) {
	string line;
	unsigned int linePos = 0;
	float value;
	string charSet = "0123456789,.-";
	getline(this->_CSV, line);
	while (this->_CSV)
	{
		getline(this->_CSV, line);
		if (!line.empty() && line[0]) {
			if (linePos > 0 && line.find_first_not_of(charSet) != string::npos)
				throw (BitcoinExchange::FileBadValue("data.csv"));
			checkDate(line.substr(0, line.find_first_of(',')), "data.csv", linePos);
			line = line.substr(line.find_first_of(',') + 1, line.length());
			if (!line[0] || line[0] == ' ')
				throw (BitcoinExchange::FileBadValue("data.csv"));
			value = atof(line.c_str());
			if (value < 0 || value > static_cast<float>(INT_MAX))
				throw (BitcoinExchange::FileBadValue("data.csv"));
			this->_value.push_back(value);
			linePos++;
		}
	}
}

BitcoinExchange::~BitcoinExchange() {
}