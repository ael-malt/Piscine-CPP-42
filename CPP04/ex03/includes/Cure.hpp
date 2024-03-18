#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Cure : public AMateria
{
public:
	Cure();
	virtual ~Cure();
	Cure(const Cure& type);
	Cure&	operator=(const Cure& copy);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

ostream&	operator<<(ostream&, const Cure&);

#endif
