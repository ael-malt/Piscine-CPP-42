#include "Span.hpp"

// Span::Span(): _size(0), _v(std::vector<int>()) {}

Span::Span(unsigned int size) : _size(size), _v(std::vector<int>()){}

Span::Span(const Span& copy) : _size(copy._size), _v(copy._v) {}

Span& Span::operator=(Span& copy) {
	for (unsigned int i = 0; i < copy._size; i++)
		this->_v.at(i) = copy._v.at(i);
	this->_size = copy._size;
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int number) {
	if (this->_v.size() >= this->_size)
		throw (Span::TooManyElements());
	this->_v.push_back(number);
}

void	Span::insert(IT begin, IT end) {
	if(std::distance(begin, end) > this->_size)
		throw (Span::TooManyElements());
	this->_v.insert(this->_v.end(), begin, end);
}

unsigned int	Span::shortestSpan() const {
	if (this->_size < 2)
		throw (Span::NotEnoughElements());
	std::vector<int> cpy = this->_v;
	for (unsigned int i = 0; i < cpy.size(); i++)
		cpy.at(i) = this->_v.at(i);

	std::sort(cpy.begin(), cpy.end());
	IT it = cpy.begin();
	IT it1 = cpy.begin();
	it1++;
	unsigned int shortestSpan = INT_MAX;

	for (; it1 != cpy.end(); it1++, it++)
	{
		unsigned int span = abs(*it1 - *it);
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return(shortestSpan);
}

unsigned int	Span::longestSpan() const {
	if (this->_size < 2)
		throw (Span::NotEnoughElements());
	
	int	max = *std::max_element(this->_v.begin(), this->_v.end());
	int	min = *std::min_element(this->_v.begin(), this->_v.end());
	unsigned int span = abs(max - min);
	return (span);
	return (0);
}

int	Span::getSize() const { return (this->_size); }

std::vector<int>	Span::getVec() const { return (this->_v); }
