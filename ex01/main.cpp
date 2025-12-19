#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");

    if (!horde)
    {
        std::cout << "Erreur : impossible de créer la horde." << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;

    return 0;
}
