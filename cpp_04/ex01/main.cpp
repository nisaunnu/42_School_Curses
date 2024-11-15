#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\n>> Creating Dog and Cat objects on the Heap <<" << std::endl;
	Dog* dog1 = new Dog();
	Cat* cat1 = new Cat();

	std::cout << "\nDog and Cat sounds :" << std::endl;
	dog1->makeSound();
	cat1->makeSound();

	std::cout << "\n>> Dog copying to test Deep Copy operation <<" << std::endl;
	Dog dog2 = *dog1;

	std::cout << "\nDog2's voice (copy of dog1):" << std::endl;
	dog2.makeSound();

	std::cout << "\n>> Copy Cat to test Deep Copy operation <<" << std::endl;
	Cat cat2 = *cat1;

	std::cout << "\nAudio of cat2 (copy of cat1):" << std::endl;
	cat2.makeSound();

	std::cout << "\n>> Testing Dog's Deep Copy <<" << std::endl;
	dog1->getBrain()->setIdea(0, "Dog1's first idea.");
	std::cout << PINK << "Dog1's first idea             : " << RESET << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << PINK << "Initial idea of ​​Dog2 (copied) : " << RESET << dog2.getBrain()->getIdea(0) << std::endl;
	dog2.getBrain()->setIdea(0, "Dog2's first idea.");
	std::cout << PINK << "\nDog1's first modified idea : " << RESET << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << PINK << "Dog2's new first idea        : " << RESET << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n>> Testing Cat's Deep Copy <<" << std::endl;
	cat1->getBrain()->setIdea(0, "Cat1's first idea.");
	std::cout << PINK << "Cat1's first idea             : " << RESET << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << PINK << "Initial idea of Cat2 (copied) : " << RESET << cat2.getBrain()->getIdea(0) << std::endl;
	cat2.getBrain()->setIdea(0, "Cat2's first idea.");
	std::cout << PINK << "\nCat1's first modified idea : " << RESET << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << PINK << "Cat2's new first idea        : " << RESET << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n>> Deleting Dog and Cat objects on the Heap <<" << std::endl;
	delete dog1;
	delete cat1;

	return 0;
}
