# include "Animal.hpp"
# include "WrongAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* WrongI = new WrongCat();

	std::cout << WrongMeta->getType() << " " << std::endl;
	std::cout << WrongI->getType() << " " << std::endl;
	WrongMeta->makeSound(); //will output the cat sound!
	WrongI->makeSound();

	delete WrongI;
	delete WrongMeta;
	delete j;
	delete i;
	delete meta;
	return 0;
}
