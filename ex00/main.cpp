#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie* heapZombie = newZombie("Foo");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Bar");

	return (0);
}