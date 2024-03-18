#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (size_t i = 0; i < 4; i++)
		this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	for (int i = 0; i < 4; ++i)
		delete (this->_templates[i]);
	for (int i = 0; i < 4; ++i)
		if (copy._templates[i])
			this->_templates[i] = copy._templates[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {

	delete[] (*this->_templates);
	for (int i  = 0; i < 4; i++)
		this->_templates[i] = copy._templates[i];
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	cout << RED << "MateriaSource" << " destroyed" << DEFAULT << endl;
	for (int i = 0; i < 4; ++i)
		delete (_templates[i]);
}

void MateriaSource::learnMateria(AMateria* m) {
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_templates[i] == NULL)
		{
			_templates[i] = m;
			return ;
		}
	}
	
}

AMateria* MateriaSource::createMateria(string const& type) {
	for (int i  = 0; i < 4; i++)
	{
		if (_templates[i] != NULL && type == _templates[i]->getType())
		{
			return (_templates[i]->clone());
		}
	}
	return (0);
}
