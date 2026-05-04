#include "Zombie.hpp"

int main(int argc , char** argv)
{
    if(argc != 2)
    {
        std::cout << "invalide number of arguments" << std::endl;
        return(1);
    }
    std::string name = argv[1];
    Zombie* nZombie = newZombie(name);
    nZombie->announce();
    delete nZombie;

    randomChump(name); 
    return(0);
}