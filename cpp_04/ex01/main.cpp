#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << "\nTesting array of Animals:\n" << std::endl;
	const int	animalCount = 4;
	Animal* animals[animalCount];

	for (int i = 0; i < animalCount / 2; ++i)
		animals[i] = new Dog();

	for (int i = animalCount / 2; i < animalCount; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < animalCount; ++i)
		animals[i]->makeSound();

	for (int i = 0; i < animalCount; ++i)
		delete animals[i];

	return 0;
}
