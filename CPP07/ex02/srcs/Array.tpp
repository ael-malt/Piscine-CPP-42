#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _Array(new T), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _Array(new T[n]), _size(n) {}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& copy) {
	for (unsigned int i = 0; i < copy->_size; i++)
	{
		if (i > copy._size)
			throw (IndexOutOfArray());
		this->_Array[i] = copy._Array[i];
	}
	this->_size = copy._size;
	return (*this);
}

template <typename T>
Array<T>::Array(Array& copy) : _size(copy.size) {
	this->_Array = new T[copy._size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_Array[i] = copy._Array[i];
}

template <typename T>
Array<T>::~Array(void) { delete[] (_Array); }

template <typename T>
	unsigned int	Array<T>::size(void) { return (this->_size); }

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
	{
		throw(IndexOutOfArray());
		return (this->_Array[0]);
	}
	return (this->_Array[index]);
}
