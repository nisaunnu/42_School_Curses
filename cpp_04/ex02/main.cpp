#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const AAnimal*	dog = new Dog();
	const AAnimal*	cat = new Cat();

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << "\nTesting array of AAnimals:\n" << std::endl;
	const int	AAnimalCount = 4;
	AAnimal* AAnimals[AAnimalCount];

	for (int i = 0; i < AAnimalCount / 2; ++i)
		AAnimals[i] = new Dog();

	for (int i = AAnimalCount / 2; i < AAnimalCount; ++i)
		AAnimals[i] = new Cat();

	for (int i = 0; i < AAnimalCount; ++i)
		AAnimals[i]->makeSound();

	for (int i = 0; i < AAnimalCount; ++i)
		delete AAnimals[i];

	return 0;
}
