#include "../includes/Fixed.hpp"

using std::cout;
using std::endl;

// Constructors

Fixed::Fixed(void) : fixed_point(0) {
	cout << GREEN << "Default constructor called" << DEFAULT << endl;
}

Fixed::Fixed(const int i) : fixed_point(i << this->fractional_bits) {
	cout << GREEN << "Int constructor called" << DEFAULT << endl;
}

Fixed::Fixed(const float f) : fixed_point(int(roundf(f * (1 << this->fractional_bits)))) {
	cout << GREEN << "Float constructor called" << DEFAULT << endl;
}

Fixed::Fixed(const Fixed &copy) : fixed_point(copy.fixed_point) {
	cout << GREEN BOLD << "Copy constructor called" << DEFAULT << endl;
	this->fixed_point = copy.fixed_point;
}

Fixed::~Fixed() {
	cout << RED << "Destructor called" << DEFAULT << endl;
}

// Member functions

void	Fixed::setRawBits(int const raw) {
	cout << CYAN << "setRawBits member function called" << DEFAULT << endl;
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const {
	return (((float)this->fixed_point / (1 << fractional_bits)));
}

int Fixed::toInt(void) const {
	return ((int) (this->fixed_point / (1 << fractional_bits)));
}

int	Fixed::getRawBits(void) const {
	cout << MAGENTA << "getRawBits member function called" << DEFAULT << endl;
	return (this->fixed_point);
}

////////////// Operator overload

// Copy Operator
Fixed & Fixed::operator=(const Fixed &num) {
	cout << ORANGE << "Copy assignment operator called" << DEFAULT << endl;
	this->fixed_point = num.fixed_point;
	return (*this);
}

// Shift operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

// Comparison Operators
bool Fixed::operator>(const Fixed num) const {
	return (this->getRawBits() > num.getRawBits() ? true : false);
}

bool Fixed::operator<(const Fixed num) const {
	return (this->getRawBits() < num.getRawBits() ? true : false);
	
}

bool Fixed::operator>=(const Fixed num) const {
	return (this->getRawBits() >= num.getRawBits() ? true : false);
	
}

bool Fixed::operator<=(const Fixed num) const {
	return (this->getRawBits() <= num.getRawBits() ? true : false);
	
}

bool Fixed::operator==(const Fixed num) const {
	return (this->getRawBits() == num.getRawBits() ? true : false);
	
}

bool Fixed::operator!=(const Fixed num) const {
	return (this->getRawBits() != num.getRawBits() ? true : false);
	
}

// Arythmetic Operators
Fixed Fixed::operator+(const Fixed &num) const {
	return (this->toFloat() + num.toFloat());
}

Fixed Fixed::operator-(const Fixed &num) const {
	return (this->toFloat() - num.toFloat());
}

Fixed Fixed::operator*(const Fixed &num) const {
	return (this->toFloat() * num.toFloat());
}

Fixed Fixed::operator/(const Fixed &num) const {
	if (num.toFloat() == 0) {
		std::cout << RED << "Error: Can't divide by 0. Value will be set to 0" << DEFAULT << std::endl;
		return 0;
	}
	return (this->toFloat() / num.toFloat());
}

//Increment Operators
Fixed& Fixed::operator++(void){ // before
	this->fixed_point += 1;
	return (*this);
}

Fixed Fixed::operator++(int){ // after
	Fixed tmp = *this;
	this->fixed_point += 1;
	return (tmp);
} 

// Decrement operators
Fixed& Fixed::operator--(void){ // before
	this->fixed_point -= 1;
	return (*this);
}

Fixed Fixed::operator--(int){ // after
	Fixed tmp = *this;
	this->fixed_point -= 1;
	return (tmp);
} 

// Min
Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
		return (num1.getRawBits() > num2.getRawBits() ? num2 : num1);
}
const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
		return (num1.getRawBits() > num2.getRawBits() ? num2 : num1);
}

//Max
Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}
const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) {
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}
