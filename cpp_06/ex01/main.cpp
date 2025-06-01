#include <iostream>
#include "Serializer.hpp"

int main()
{
	try
	{
		Data*	original = new Data();
		original->setName("Test");
		original->setAge(25);
		original->setScore(95.5);

		std::cout << "Original pointer: " << original << std::endl;
		std::cout << "Original data" << std::endl;
		std::cout << "   - Name  : " << original->getName() << std::endl;
		std::cout << "   - Age   : " << original->getAge() << std::endl;
		std::cout << "   - Score : " << original->getScore() << std::endl << std::endl;

		uintptr_t	serialized = Serializer::serialize(original);
		std::cout << "Serialized value: " << serialized << std::endl << std::endl;

		Data*	deserialized = Serializer::deserialize(serialized);
		std::cout << "Deserialized pointer: " << deserialized << std::endl;
		std::cout << "Deserialized data" << std::endl;
		std::cout << "   - Name  : " << deserialized->getName() << std::endl;
		std::cout << "   - Age   : " << deserialized->getAge() << std::endl;
		std::cout << "   - Score : " << deserialized->getScore() << std::endl << std::endl;

		if (original == deserialized)
			std::cout << "Pointers are equal!" << std::endl;
		else
			std::cout << "Pointers are not equal!" << std::endl;

		delete original;
	}
	catch (std::exception& e) {
		std::cerr << "Error:  " << e.what() << std::endl;
	}

	return 0;
}
