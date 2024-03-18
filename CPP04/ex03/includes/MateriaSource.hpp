#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"


using std::string;
using std::cout;
using std::endl;

class MateriaSource: public IMateriaSource {
	private:
		AMateria* _templates[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource(void);
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const& type);
};

#endif
