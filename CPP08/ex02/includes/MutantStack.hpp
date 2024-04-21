#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <stack>
# include <deque>
# include <algorithm>

# include "Colors.hpp"

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::exception;

template <typename T>
class MutantStack : public std::stack<T, typename std::deque<T> >
{
private:
	/* data */
public:
	MutantStack(void) {}
	MutantStack(MutantStack<T>&);
	MutantStack<T>& operator=(MutantStack<T>& copy) {
		if (copy.empty())
			this->c.clear();
		this->c = copy.c;
	};
	~MutantStack() {}

	typedef typename MutantStack<T>::container_type::iterator iterator;
	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
};

# include "../srcs/MutantStack.tpp"

// MutantStack::MutantStack(void)
// {
// }

// MutantStack::~MutantStack()
// {
// }

#endif