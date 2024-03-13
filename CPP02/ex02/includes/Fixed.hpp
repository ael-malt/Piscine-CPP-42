#ifndef FIXED_HPP
# define FIXED_HPP

# include "./Colors.hpp"
# include <iostream>
# include <cmath>

using std::ostream;
class Fixed
{
private:
	int					fixed_point;
	const static int	fractional_bits = 8;
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
	bool	operator>(const Fixed num) const ;
	bool	operator<(const Fixed num) const ;
	bool	operator>=(const Fixed num) const ;
	bool	operator<=(const Fixed num) const ;
	bool	operator==(const Fixed num) const ;
	bool	operator!=(const Fixed num) const ;

	// Arythmetic Operators
	Fixed	operator+(const Fixed &num) const ;
	Fixed	operator-(const Fixed &num) const ;
	Fixed	operator*(const Fixed &num) const ;
	Fixed	operator/(const Fixed &num) const ;
	
	//Increment Operators
	Fixed&	operator++(void); // before
	Fixed	operator++(int); // after

	// Decrement operators
	Fixed&	operator--(void); // before
	Fixed	operator--(int); // after

	/*
	The int parameter is a dummy parameter.
	Its value is not used within the function;
	its presence in the function signature is solely to distinguish the postfix
	operator from the prefix operator.
	Compiler just knows which one to call.
	*/

	// min/max
	static	Fixed& min(Fixed& num1, Fixed& num2);
	static	const Fixed& min(const Fixed& num1, const Fixed& num2);
	static	Fixed& max(Fixed& num1, Fixed& num2);
	static	const Fixed& max(const Fixed& num1, const Fixed& num2);
};

ostream& operator<<(ostream& out, const Fixed& fixed);

#endif
