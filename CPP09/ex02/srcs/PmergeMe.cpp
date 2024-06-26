#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char const **argv) {
	// Parse all the arguments
	ParseArgv(argc, argv);

	// Get start time
	if (gettimeofday(&this->_startValue, NULL) == -1) throw (PmergeMe::GetTimeError());

	// Sort _vector
	sort(this->_vector);
	if (gettimeofday(&this->_endValue, NULL) == -1) throw (PmergeMe::GetTimeError());
	// Calculate the time it took
	this->_vectorTime = getElapsedTimeMs(this->_startValue, this->_endValue);

	if (gettimeofday(&this->_startValue, NULL) == -1) throw (PmergeMe::GetTimeError());

	// Sort _deque
	sort(this->_deque);
	if (gettimeofday(&this->_endValue, NULL) == -1) throw (PmergeMe::GetTimeError());
	// Calculate the time it took
	this->_dequeTime = getElapsedTimeMs(this->_startValue, this->_endValue);

	// Print _unsorted
	cout << "Before: ";
	for (vector<unsigned int>::iterator unsortedIt = this->_unsorted.begin(); unsortedIt != this->_unsorted.end(); unsortedIt++ )
	{
		cout << *unsortedIt;
		
		unsortedIt + 1 != this->_unsorted.end() ? cout << ' ' : cout << endl;
	}
	// Print sorted _vector
	cout << "After: ";
	for (vector<unsigned int>::iterator vectorIt = this->_vector.begin(); vectorIt != this->_vector.end(); vectorIt++)
	{
		cout << *vectorIt;
		vectorIt + 1 != this->_vector.end() ? cout << ' ' : cout << endl;
	}
	// Print time to sort with vector
	cout << "Time to process a range of " << argc << " elements with std::vector : " << this->_vectorTime << endl;
	// Print time to sort with deque
	cout << "Time to process a range of " << argc << " elements with std::deque : " << this->_dequeTime << endl;
}

template <typename T>
void PmergeMe::binarySearchSort(T& container, pairVector pairs, typename T::iterator last) {
	T	pend;
	T	mainChain;
	T	range;

	for (pairVector::iterator It = pairs.begin();It != pairs.end(); It++)
	{
		pend.push_back((*It).first);
		mainChain.push_back((*It).second);
	}
	if (last != container.end())
		pend.push_back(*last);

	for (typename T::iterator middle ; pend.size() ; pend.erase(pend.begin()))
	{
		range = mainChain;
		middle = range.begin() + static_cast<unsigned int>(range.size() / 2);
		while(range.size() > 2) {
			typename T::iterator limit = middle + 1;
			(*middle <= *pend.begin() ? limit = range.end() : middle = range.begin());
			assignContainerRange(middle, limit, range);
			middle = range.begin() + static_cast<unsigned int>(range.size() / 2);
		}
		*range.begin() > *pend.begin() ? middle = range.begin() : middle = range.end() - 1;
		ft_emplace(mainChain, getItPos(mainChain, middle), *pend.begin());
	}
	assignContainerRange(mainChain.begin(), mainChain.end(), container);
}

void PmergeMe::sortPairs(pairVector& pairs, pairVector::iterator current) {
	if (current != pairs.end())
	{
		sortPairs(pairs, current + 1);
		if ((*current).second < (*current).first)
			T_swap((*current).first, (*current).second);
		for (pairVector::iterator It = current; It != pairs.end(); It++)
			if (It + 1 != pairs.end() && (*It).second > (*(It + 1)).second)
				T_swap(*It, *(It + 1));
	}
}

template <typename T>
void PmergeMe::sort(T& container) {
	// First put all the numbers in pairs
	pairVector pairs;
	typename T::iterator last = container.end();
	if (container.size() % 2) last--;
	for (typename T::iterator It = container.begin(); It != container.end();)
	{
		if (It != last) {
			pairs.push_back(std::make_pair(*It, *(It + 1)));
			It += 2;
		}
		else
			It++;
	}
	// Then sort the pairs putting the biggest of 
	sortPairs(pairs, pairs.begin());
	binarySearchSort(container, pairs, last);
}

void PmergeMe::ParseArgv(int argc, char const **argv) {
	string expectedChars("0123456789");
	// Check if only numbers are present in argv
	for (int i = 0; i < argc; i++)
	{
		if((string(argv[i])).find_first_not_of(expectedChars) != string::npos)
			throw(PmergeMe::UnexpectedArg(string(argv[i])));
		// Add the number to the _unsorted - _vector _deque
		this->_unsorted.push_back(atoi(argv[i]));
		this->_vector.push_back(atoi(argv[i]));
		this->_deque.push_back(atoi(argv[i]));
	}
}

PmergeMe::~PmergeMe() {}


// Utils


double getElapsedTimeMs(timeval startTime, timeval endTime) {
	long seconds = endTime.tv_sec - startTime.tv_sec;
	long microSeconds = endTime.tv_usec - startTime.tv_usec;
	return (seconds + microSeconds*1e-6);
}

template <typename T, typename val>
static void ft_emplace(T& container, unsigned int pos, val value) {
	T tmpContainer;
	for (typename T::iterator It = container.begin(); It != container.end(); It++)
	{
		if (getItPos(container, It) == pos) {
			tmpContainer.push_back(value);
			for (typename T::iterator tmpIt = It; tmpIt != container.end(); tmpIt++)
			{
				tmpContainer.push_back(*tmpIt);
				if (It != container.end() - 1)
					It++;
			}
		}
		else
			tmpContainer.push_back(*It);
	}
	container.clear();
	assignContainerRange(tmpContainer.begin(), tmpContainer.end(), container);
	
}
template <typename T>
void T_swap(T& first, T&second) {
	T tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
static size_t getItPos(T container, typename T::iterator It) {
	size_t i = 0;
	for (typename T::iterator typeIt = container.begin(); *typeIt != *It ; typeIt++, i++) {}
	return (i);
}

//Assign a range of iterators of a container to another container
template <typename T, typename TIterator>
static void assignContainerRange(TIterator start, TIterator end, T& dst) {
	T src = T(start, end);
	dst.clear();
	for (typename T::iterator It = src.begin(); It != src.end(); It++)
		dst.push_back(*It);
}