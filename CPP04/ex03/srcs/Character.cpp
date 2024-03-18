#include "Character.hpp"

Character::Character(void) : _name("Default"){
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(string const name) : _name(name){ 
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& param): _name(param.getName()) {
	for (int i  = 0; i < 4; i++)
		_inventory[i] = param._inventory[i];
}

Character&	Character::operator=(const Character& copy) {
	this->_name = copy.getName();
	for (size_t i = 0; i < 4; i++)
		delete _inventory[i];
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = copy._inventory[i];
	return (*this);
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
		{
			cout << RED << "Destroyed character: " << BOLD << this->_name << DEFAULT << std::endl;
			delete this->_inventory[i];
		}
	}
}

// Character::Character(const Character& copy) {
// 	*this = copy;
// }

ostream& operator<<(ostream& s, const Character& param) {
	s << LIGHTER_BLUE << "Character name: " << BOLD << param.getName() << DEFAULT;
	return (s);
}

std::string	const	&Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (size_t i = 0; i < 4; i++)
	{
		if (m == NULL)
		{
			cout << GREEN << this->_name << YELLOW << " couldn't equip Materia, it doesn't exist!" << DEFAULT << endl;
			return ;
		}
		if (i == 3 && this->_inventory[i])
			cout << GREEN << this->_name << YELLOW << " couldn't equip Materia: " << LIGHT_CYAN << m->getType() << YELLOW << " because the inventory is full!" << DEFAULT << endl;
		else if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			cout << GREEN << this->_name << YELLOW << " equipd Materia: " << LIGHT_CYAN << m->getType() << YELLOW << " at slot " << LIGHT_BLUE << i << DEFAULT << endl;
			return ;
		}
		
	}
	
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
	{
		cout << GREEN << this->_name << CYAN << " couldn't unequip Materia at slot " << LIGHT_BLUE << idx << CYAN << " Character only has 4 slots!" << DEFAULT << endl;
		return ;
	}
	AMateria *ptr = _inventory[idx];
	if (ptr == NULL)
		return;
	cout << GREEN << this->_name << CYAN << " unequipped Materia: " << LIGHT_CYAN << *this->_inventory[idx] << DEFAULT CYAN << " at slot " << LIGHT_BLUE << idx << DEFAULT << endl;
	ptr->drop();
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
	{
		cout << ORANGE << "Couldn't use Materia at slot " << LIGHT_BLUE << idx << ORANGE << ": Character only has 4 slots!" << DEFAULT << endl;
		return ;
	}
	if (!this->_inventory[idx])
		cout << ORANGE << "Couldn't use Materia at slot " << LIGHT_BLUE << idx << ORANGE << ": Slot is empty!" << DEFAULT << endl;
	cout << GREEN << this->_name;
	_inventory[idx]->use(target);
}

