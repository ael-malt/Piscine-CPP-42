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

int	Span::shortestSpan() const {
	if (this->_size < 2)
		throw (Span::NotEnoughElements());
	std::vector<int> cpy = this->_v;

	std::sort(cpy.begin(), cpy.end());

	// IT it;
	// IT it1;
	int shortestSpan = INT_MAX;

	// for (; it1 != this->_v.begin(); it++, it++)
	// {
	// 	if (static_cast<unsigned int>(*it1 - *it) < shortestSpan)
	// 		shortestSpan = static_cast<unsigned int>(*it1 - *it);
	// }
	return(shortestSpan);
}

int	Span::longestSpan() const {
	if (this->_size < 2)
		throw (Span::NotEnoughElements());
	
	int	max = *std::max_element(this->_v.begin(), this->_v.end());
	int	min = *std::min_element(this->_v.begin(), this->_v.end());
	return (static_cast<unsigned int>(max - min));
	return (0);
}
