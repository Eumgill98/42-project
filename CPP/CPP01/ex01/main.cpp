#include "Zombie.hpp"

int main(void)
{
    int numZombie = 10;
    Zombie *zombies;

    zombies = zombieHorde(numZombie, "Horde Zombies");
    if (zombies == NULL)
        return (1);
    int idx = 0;
    while (idx < numZombie)
    {
        std::cout << "[" << idx + 1 << " / " << numZombie << "]" << std::endl;; 
        zombies[idx].announce();
        idx++;
    }
    delete[] zombies;
    return (0);
}