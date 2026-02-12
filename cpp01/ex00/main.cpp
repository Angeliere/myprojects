#include <Zombie.hpp>

Zombie::~Zombie()
{
    std::cout << _name << " was destroyed" << std::endl;
} 
int main(int argc , char** argv)
{
    if(argc != 2)
    {
        std::cout << "invalide number of arguments";
        return(1);
    }
    std::string name = argv[1];
    Zombie* nZombie = newZombie(name);
    nZombie->announce();
    delete nZombie;

    randomChump(name); 


}