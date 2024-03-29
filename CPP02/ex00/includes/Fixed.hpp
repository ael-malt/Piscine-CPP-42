#ifndef FIXED_HPP
# define FIXED_HPP

# include "./Colors.hpp"
# include <iostream>

class Fixed
{
private:
	int	fixed_point;
	const static int fractional_bits = 8;
public:
	Fixed(void);
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed & operator = (const Fixed &num);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
