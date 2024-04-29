#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "Colors.hpp"

# include <iostream>
# include <fstream>
# include <exception>
# include <vector>
# include <deque>
# include <algorithm>
# include <limits.h>
# include <sstream>
# include <sys/time.h>

// #include 


using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;
using std::ifstream;
using std::vector;
using std::deque;

typedef vector<std::pair<unsigned int, unsigned int> > pairVector;

class PmergeMe
{
private:
	vector<unsigned int> _unsorted;
	vector<unsigned int> _vector;
	deque<unsigned int> _deque;
	timeval _startValue;
	timeval _endValue;
	double _vectorTime;
	double _dequeTime;
public:
	PmergeMe(int argc, char const **argv);
	~PmergeMe();
	
	void	ParseArgv(int argc, char const **argv);
	template <typename T>
	void	sort(T& container);
	void	sortPairs(pairVector& pairs, pairVector::iterator current);
	template <typename T>
	void	binarySearchSort(T& container, pairVector pairs, typename T::iterator last);

	class GetTimeError : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: gettimeofday() has failed." DEFAULT); }
	};
	class MissingArguments : public exception {
		public: virtual const char* what() const throw() { return (RED "Error: Missing argument.\n	Try with: ./PmergeMe <Any amount of numbers." DEFAULT); }
	};
	class UnexpectedArg : public exception
	{
		private: string _msg;
		public: 
			virtual ~UnexpectedArg() throw() {}
			UnexpectedArg(string arg) : _msg(RED "Error: Unexpected argument: " MAGENTA "'" + arg + "'" + RED + "\n	Only positive numbers are allowed (no +/- signs)." DEFAULT) {}
			const char* what() const throw() { return (_msg.c_str()); }

	};
};

double	getElapsedTimeMs(timeval startTime, timeval endTime);
template <typename T>
	void	T_swap(T& first, T&second);
template <typename T, typename TIterator>
	static void assignContainerRange(TIterator start, TIterator end, T& dst);
template <typename T>
	static size_t getItPos(T type, typename T::iterator it);
template <typename T, typename val>
	static void ft_emplace(T& container, unsigned int pos, val value);
#endif