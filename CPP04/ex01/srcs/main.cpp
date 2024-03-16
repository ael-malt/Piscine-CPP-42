# include "Animal.hpp"
# include "WrongAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main()
{
	Animal* animals[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			animals[i] = new Cat();
			if (i % 2)
				animals[i]->addIdea("Me cat, me hungry!");
			else
				animals[i]->addIdea("Prrrrrr, me sleeeepyyyy");
		}
		else
		{
			animals[i] = new Dog();
			if (i % 2)
				animals[i]->addIdea("DOGGO SEE CAT, DOGGO EAT!");
			else
				animals[i]->addIdea("Wouf wouf, you won't sleep you silly cat!");
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		animals[i]->printIdeas();
	}
	
	
	
	for (size_t i = 0; i < 10; i++)
	{
		delete animals[i];
	}
	
	return 0;
}
