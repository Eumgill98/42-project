#include "Zombie.hpp"

int main(void)
{
    Zombie *heap_zombie;

    heap_zombie = newZombie("heap zombie");
    heap_zombie->announce();
    randomChump("stack zombie");
    delete heap_zombie;
    return (0);
}