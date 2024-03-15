# include "Animal.hpp"
# include "WrongAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main()
{
	const Animal* animals[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			animals[i] = new Cat();

		}
		else
		{
			animals[i] = new Dog();

		}
	}
	
	
	delete animals;
	return 0;
}
