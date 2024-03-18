#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Ice : public AMateria
{
private:
public:
	Ice();
	virtual ~Ice();
	Ice(const Ice& type);
	Ice&	operator=(const Ice& copy);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

ostream&	operator<<(ostream&, const Ice&);

#endif
