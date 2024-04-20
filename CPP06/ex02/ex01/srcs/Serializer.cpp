#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& src) {
	*this = src;
}

Serializer::~Serializer(void) {}

Serializer & Serializer::operator=(Serializer const & rhs) { (void) rhs; return (*this); }

uintptr_t	Serializer::serialize(Data* ptr) { return(reinterpret_cast<uintptr_t>(ptr)); }
Data*		Serializer::deserialize(uintptr_t raw) { return(reinterpret_cast<Data*>(raw)); };

void Data::setNb(int n) {
	this->_nb = n;
}

int Data::getNb(void) const {
	return(this->_nb);
}
