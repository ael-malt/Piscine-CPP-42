//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	{
		AMateria *materia1, *materia2;

		Character character1("Wolf");
		Character character2("Chicken");
		// m = new AMateria("Fire"); -> Triggers Error [Abstract class cannot be allocated]
		materia1 = new Ice();
		materia2 = new Cure();
		materia1->use(character1);
		materia2->use(character1);
		cout << character1 << endl;
		cout << character2 << endl;

		delete (materia1);
		delete (materia2);
	}
	{
		Character character1("Dog");
		Character c2("Little Kid");
		cout << character1 << endl;
		character1.equip(new Cure());
		character1.equip(new Ice());
		character1.equip(new Ice());
		character1.equip(new Cure());
		character1.unequip(3);
		character1.unequip(2);
		character1.use(1, c2);
		character1.use(0, c2);
		AMateria::clean();
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	return (0);
}
