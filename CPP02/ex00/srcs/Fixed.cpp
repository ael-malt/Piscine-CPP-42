#include "../includes/Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed(void) : fixed_point(0)
{
	cout << GREEN << "Default constructor called" << DEFAULT << endl;
}

Fixed::Fixed(const Fixed &copy) : fixed_point(copy.fixed_point)
{
	cout << GREEN BOLD << "Copy constructor called" << DEFAULT << endl;
	this->fixed_point = copy.getRawBits();
}

Fixed::~Fixed()
{
	cout << RED << "Destructor called" << DEFAULT << endl;
}

Fixed & Fixed::operator = (const Fixed &num)
{
	cout << ORANGE << "Copy assignment operator called" << DEFAULT << endl;
	this->fixed_point = num.getRawBits();
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
