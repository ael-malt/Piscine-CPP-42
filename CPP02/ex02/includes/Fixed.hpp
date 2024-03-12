#ifndef FIXED_HPP
# define FIXED_HPP

# include "./Colors.hpp"
# include <iostream>
# include <cmath>

using std::ostream;
class Fixed
{
private:
	int	fixed_point;
	const static int fractional_bits = 8;
public:
	Fixed(void);
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &a);
	~Fixed();
	Fixed & operator = (const Fixed &a);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	// Comparison Operators
	bool operator>(const Fixed num) const ;
	bool operator<(const Fixed num) const ;
	bool operator>=(const Fixed num) const ;
	bool operator<=(const Fixed num) const ;
	bool operator==(const Fixed num) const ;
	bool operator!=(const Fixed num) const ;

	// Arythmetic Operators

	//Increment Operators

	// Decrement operators
};

ostream& operator<<(ostream& out, const Fixed& fixed);

#endif
