#include <Zombie.hpp>

Zombie* newZombie(std::string name)
{
    Zombie* zombiePtr = new Zombie();
    zombiePtr->setName(name);
    return zombiePtr;
}