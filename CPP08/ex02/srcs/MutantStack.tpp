#include "MutantStack.hpp"

template <typename T>
	MutantStack<T>::MutantStack(MutantStack<T>& copy) {
		if (!this->empty())
			for(unsigned int i = 0; i < this->size(); i++)
				this->pop();

		for(unsigned int i = 0; i < copy.size(); i++)
			this->push(copy.top() - i);

	}
