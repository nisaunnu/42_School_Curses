#include "Zombie.hpp"

int main()
{
	std::cout << YELLOW;
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	std::cout << PINK;
	randomChump("StackZombie");

	delete heapZombie;

	return 0;
}
