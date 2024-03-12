#include "../includes/Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed(void) : fixed_point(0)
{
	cout << GREEN << "Default constructor called" << DEFAULT << endl;
}

Fixed::Fixed(const int i) : fixed_point(i << this->fractional_bits)
{
	cout << GREEN << "Int constructor called" << DEFAULT << endl;
}

Fixed::Fixed(const float f) : fixed_point(int(roundf(f * (1 << this->fractional_bits))))
{
	cout << GREEN << "Float constructor called" << DEFAULT << endl;
}

Fixed::Fixed(const Fixed &copy) : fixed_point(copy.fixed_point)
{
	cout << GREEN BOLD << "Copy constructor called" << DEFAULT << endl;
	this->fixed_point = copy.fixed_point;
}

Fixed::~Fixed()
{
	cout << RED << "Destructor called" << DEFAULT << endl;
}

Fixed & Fixed::operator = (const Fixed &num)
{
	cout << ORANGE << "Copy assignment operator called" << DEFAULT << endl;
	this->fixed_point = num.fixed_point;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	cout << MAGENTA << "getRawBits member function called" << DEFAULT << endl;
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	cout << CYAN << "setRawBits member function called" << DEFAULT << endl;
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	return (((float)this->fixed_point / (1 << fractional_bits)));
}

int Fixed::toInt(void) const
{
	return ((int) (this->fixed_point / (1 << fractional_bits)));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
